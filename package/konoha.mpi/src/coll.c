#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.bcastBytes(Bytes sdata, Int count, Int root_rank);

static int knh_MPI_BcastBytes(CTX ctx, knh_Object_t *c, knh_Object_t *odata, int count, int root_rank)
{
	COMM(comm, c);
	BA(data, odata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (KNH_MPI_RANK(comm) == root_rank) {
			if (count == 0) {
				count = BA_size(data);
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm)); /* bcast for buffer_length */
			}
			ret = MPI_Bcast(BA_buf(data), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
		} else {
			if (count == 0) {
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm)); /* bcast for buffer_length */
			}
			int incl = count - BA_size(data);
			if (incl <= 0) {
				ret = MPI_Bcast(BA_buf(data), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_BA_EXPAND(data, incl);
				ret = MPI_Bcast(BA_buf(data), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
				BA_size(data) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_bcastBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_BcastBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.bcastInt(IArray sdata, Int count, Int root_rank);

static int knh_MPI_BcastInt(CTX ctx, knh_Object_t *c, knh_Object_t *odata, int count, int root_rank)
{
	COMM(comm, c);
	IA(data, odata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (KNH_MPI_RANK(comm) == root_rank) {
			if (count == 0) {
				count = IA_size(data);
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm)); /* bcast for buffer_length */
			}
			ret = MPI_Bcast(IA_buf(data), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
		} else {
			if (count == 0) {
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm)); /* bcast for buffer_length */
			}
			int incl = count - IA_size(data);
			if (incl <= 0) {
				ret = MPI_Bcast(IA_buf(data), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_IA_EXPAND(data, incl);
				ret = MPI_Bcast(IA_buf(data), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
				IA_size(data) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_bcastInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_BcastInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.bcastFloat(FArray sdata, Int count, Int root_rank);

static int knh_MPI_BcastFloat(CTX ctx, knh_Object_t *c, knh_Object_t *odata, int count, int root_rank)
{
	COMM(comm, c);
	FA(data, odata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (KNH_MPI_RANK(comm) == root_rank) {
			if (count == 0) {
				count = FA_size(data);
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm)); /* bcast for buffer_length */
			}
			ret = MPI_Bcast(FA_buf(data), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
		} else {
			if (count == 0) {
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm)); /* bcast for buffer_length */
			}
			int incl = count - FA_size(data);
			if (incl <= 0) {
				ret = MPI_Bcast(FA_buf(data), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_FA_EXPAND(data, incl);
				ret = MPI_Bcast(FA_buf(data), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
				FA_size(data) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_bcastFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_BcastFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), Int_to(int, sfp[3])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.bcast(dynamic data, Int root_rank);

KMETHOD MPIComm_bcast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *odata = sfp[1].o;
	int ret = -1;
	if (IS_Bytes(odata)) {
		ret = knh_MPI_BcastBytes(ctx, sfp[0].o, odata, 0, Int_to(int, sfp[2]));
	} else if (IS_IArray(odata)) {
		ret = knh_MPI_BcastInt(ctx, sfp[0].o, odata, 0, Int_to(int, sfp[2]));
	} else if (IS_FArray(odata)) {
		ret = knh_MPI_BcastFloat(ctx, sfp[0].o, odata, 0, Int_to(int, sfp[2]));
	}
	RETURNi_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.scatterBytes(Bytes sdata, Int count, Bytes rdata, Int root_rank);

static int knh_MPI_ScatterBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata, int root_rank)
{
	COMM(comm, c);
	BA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_Bytes(sdata)) {
			BA(asdata, sdata);
			if (count == 0) {
				if (KNH_MPI_RANK(comm) == root_rank) {
					count = BA_size(asdata) / KNH_MPI_SIZE(comm);
					if (BA_size(asdata) % KNH_MPI_SIZE(comm) != 0) count++;
				}
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm));
			}
			int incl = count - BA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Scatter(BA_buf(asdata), count, BA_Type, BA_buf(ardata), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_BA_EXPAND(ardata, incl);
				ret = MPI_Scatter(BA_buf(asdata), count, BA_Type, BA_buf(ardata), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
				BA_size(ardata) += incl;
			}
		}
		else { /* IS_String(sdata) */
			SV(asdata, sdata);
			if (count == 0) {
				if (KNH_MPI_RANK(comm) == root_rank) {
					count = SV_size(asdata) / KNH_MPI_SIZE(comm);
					if (SV_size(asdata) % KNH_MPI_SIZE(comm) != 0) count++;
				}
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm));
			}
			int incl = count - BA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Scatter(SV_buf(asdata), count, SV_Type, BA_buf(ardata), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_BA_EXPAND(ardata, incl);
				ret = MPI_Scatter(SV_buf(asdata), count, SV_Type, BA_buf(ardata), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
				BA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_scatterBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_ScatterBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o, Int_to(int, sfp[4])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.scatterInt(IArray sdata, Int count, IArray rdata, Int root_rank);

static int knh_MPI_ScatterInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata, int root_rank)
{
	COMM(comm, c);
	IA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_IArray(sdata)) {
			IA(asdata, sdata);
			if (count == 0) {
				if (KNH_MPI_RANK(comm) == root_rank) {
					count = IA_size(asdata) / KNH_MPI_SIZE(comm);
					if (IA_size(asdata) % KNH_MPI_SIZE(comm) != 0) count++;
				}
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm));
			}
			int incl = count - IA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Scatter(IA_buf(asdata), count, IA_Type, IA_buf(ardata), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_IA_EXPAND(ardata, incl);
				ret = MPI_Scatter(IA_buf(asdata), count, IA_Type, IA_buf(ardata), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
				IA_size(ardata) += incl;
			}
		}
		else {
			IV(asdata, sdata);
			count = 1;
			int incl = count - IA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Scatter(IV_buf(asdata), count, IV_Type, IA_buf(ardata), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_IA_EXPAND(ardata, incl);
				ret = MPI_Scatter(IV_buf(asdata), count, IV_Type, IA_buf(ardata), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
				IA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_scatterInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_ScatterInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o, Int_to(int, sfp[4])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.scatterFloat(FArray sdata, Int count, FArray rdata, Int root_rank);

static int knh_MPI_ScatterFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata, int root_rank)
{
	COMM(comm, c);
	FA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_FArray(sdata)) {
			FA(asdata, sdata);
			if (count == 0) {
				if (KNH_MPI_RANK(comm) == root_rank) {
					count = FA_size(asdata) / KNH_MPI_SIZE(comm);
					if (FA_size(asdata) % KNH_MPI_SIZE(comm) != 0) count++;
				}
				MPI_Bcast(&count, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm));
			}
			int incl = count - FA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Scatter(FA_buf(asdata), count, FA_Type, FA_buf(ardata), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_FA_EXPAND(ardata, incl);
				ret = MPI_Scatter(FA_buf(asdata), count, FA_Type, FA_buf(ardata), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
				FA_size(ardata) += incl;
			}
		}
		else { /* IS_Float(sdata) */
			FV(asdata, sdata);
			count = 1;
			int incl = count - FA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Scatter(FV_buf(asdata), count, FV_Type, FA_buf(ardata), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
			} else {
				KNH_FA_EXPAND(ardata, incl);
				ret = MPI_Scatter(FV_buf(asdata), count, FV_Type, FA_buf(ardata), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
				FA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_scatterFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_ScatterFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o, Int_to(int, sfp[4])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.scatter(dynamic sdata, dynamic rdata, Int root_rank);

KMETHOD MPIComm_scatter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_Object_t *rdata = sfp[2].o;
	int ret = -1;
	if (IS_Bytes(sdata) && IS_Bytes(rdata)) {
		ret = knh_MPI_ScatterBytes(ctx, sfp[0].o, sdata, 0, rdata, Int_to(int, sfp[3]));
	} else if (IS_IArray(sdata) && IS_IArray(rdata)) {
		ret = knh_MPI_ScatterInt(ctx, sfp[0].o, sdata, 0, rdata, Int_to(int, sfp[3]));
	} else if (IS_FArray(sdata) && IS_FArray(rdata)) {
		ret = knh_MPI_ScatterFloat(ctx, sfp[0].o, sdata, 0, rdata, Int_to(int, sfp[3]));
	}
	RETURNi_(0);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.gatherBytes(Bytes sdata, Int count, Bytes rdata, Int root_rank);

static int knh_MPI_GatherBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata, int root_rank)
{
	COMM(comm, c);
	BA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_Bytes(sdata)) {
			BA(asdata, sdata);
			if (KNH_MPI_RANK(comm) == root_rank) {
				if (count > 0) {
					int rcount = count * KNH_MPI_SIZE(comm);
					int incl = rcount - BA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Gather(BA_buf(asdata), count, BA_Type, BA_buf(ardata), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
					} else {
						KNH_BA_EXPAND(ardata, incl);
						ret = MPI_Gather(BA_buf(asdata), count, BA_Type, BA_buf(ardata), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
						BA_size(ardata) += incl;
					}
				} else {
					int rcounts[KNH_MPI_SIZE(comm)];
					int rdispls[KNH_MPI_SIZE(comm)];
					ret = MPI_Gather(&BA_size(asdata), 1, MPI_INT, rcounts, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm));
					if (KNH_MPI_SUCCESS(ret)) {
						int i, rc, rcount;
						for (i = 0, rcount = 0; i < KNH_MPI_SIZE(comm); i++, rcount += rc) {
							rc = rcounts[i];
							rdispls[i] = rcount;
						}
						int incl = rcount - BA_size(ardata);
						if (incl <= 0) {
							ret = MPI_Gatherv(BA_buf(asdata), BA_size(asdata), BA_Type,
											  BA_buf(ardata), rcounts, rdispls, BA_Type, root_rank, KNH_MPI_COMM(comm));
						} else {
							KNH_BA_EXPAND(ardata, incl);
							ret = MPI_Gatherv(BA_buf(asdata), BA_size(asdata), BA_Type,
											  BA_buf(ardata), rcounts, rdispls, BA_Type, root_rank, KNH_MPI_COMM(comm));
							BA_size(ardata) += incl;
						}
					}
				}
			} else {
				if (count > 0) {
					ret = MPI_Gather(BA_buf(asdata), count, BA_Type, NULL, count, BA_Type, root_rank, KNH_MPI_COMM(comm));
				} else {
					ret = MPI_Gather(&BA_size(asdata), 1, MPI_INT, NULL, 0, MPI_INT, root_rank, KNH_MPI_COMM(comm));
					if (KNH_MPI_SUCCESS(ret)) {
						ret = MPI_Gatherv(BA_buf(asdata), BA_size(asdata), BA_Type, NULL, NULL, NULL, 0, root_rank, KNH_MPI_COMM(comm));
					}
				}
			}
		}
		else { /* IS_String(sdata) */
			SV(asdata, sdata);
			if (KNH_MPI_RANK(comm) == root_rank) {
				if (count > 0) {
					int rcount = count * KNH_MPI_SIZE(comm);
					int incl = rcount - BA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Gather(SV_buf(asdata), count, SV_Type, BA_buf(ardata), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
					} else {
						KNH_BA_EXPAND(ardata, incl);
						ret = MPI_Gather(SV_buf(asdata), count, SV_Type, BA_buf(ardata), count, BA_Type, root_rank, KNH_MPI_COMM(comm));
						BA_size(ardata) += incl;
					}
				} else {
					int rcounts[KNH_MPI_SIZE(comm)];
					int rdispls[KNH_MPI_SIZE(comm)];
					ret = MPI_Gather(&SV_size(asdata), 1, MPI_INT, rcounts, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm));
					if (KNH_MPI_SUCCESS(ret)) {
						int i, rc, rcount;
						for (i = 0, rcount = 0; i < KNH_MPI_SIZE(comm); i++, rcount += rc) {
							rc = rcounts[i];
							rdispls[i] = rcount;
						}
						int incl = rcount - BA_size(ardata);
						if (incl <= 0) {
							ret = MPI_Gatherv(SV_buf(asdata), SV_size(asdata), SV_Type,
											  BA_buf(ardata), rcounts, rdispls, BA_Type, root_rank, KNH_MPI_COMM(comm));
						} else {
							KNH_BA_EXPAND(ardata, incl);
							ret = MPI_Gatherv(SV_buf(asdata), SV_size(asdata), SV_Type,
											  BA_buf(ardata), rcounts, rdispls, BA_Type, root_rank, KNH_MPI_COMM(comm));
							BA_size(ardata) += incl;
						}
					}
				}
			} else {
				if (count > 0) {
					ret = MPI_Gather(SV_buf(asdata), count, SV_Type, NULL, count, BA_Type, root_rank, KNH_MPI_COMM(comm));
				} else {
					ret = MPI_Gather(&SV_size(asdata), 1, MPI_INT, NULL, 0, MPI_INT, root_rank, KNH_MPI_COMM(comm));
					if (KNH_MPI_SUCCESS(ret)) {
						ret = MPI_Gatherv(SV_buf(asdata), SV_size(asdata), SV_Type, NULL, NULL, NULL, 0, root_rank, KNH_MPI_COMM(comm));
					}
				}
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_gatherBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_GatherBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o, Int_to(int, sfp[4])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.gatherInt(IArray sdata, Int count, IArray rdata, Int root_rank);

static int knh_MPI_GatherInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata, int root_rank)
{
	COMM(comm, c);
	IA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_IArray(sdata)) {
			IA(asdata, sdata);
			if (KNH_MPI_RANK(comm) == root_rank) {
				if (count > 0) {
					int rcount = count * KNH_MPI_SIZE(comm);
					int incl = rcount - IA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Gather(IA_buf(asdata), count, IA_Type, IA_buf(ardata), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
					} else {
						KNH_IA_EXPAND(ardata, incl);
						ret = MPI_Gather(IA_buf(asdata), count, IA_Type, IA_buf(ardata), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
						IA_size(ardata) += incl;
					}
				} else {
					int rcounts[KNH_MPI_SIZE(comm)];
					int rdispls[KNH_MPI_SIZE(comm)];
					ret = MPI_Gather(&IA_size(asdata), 1, MPI_INT, rcounts, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm));
					if (KNH_MPI_SUCCESS(ret)) {
						int i, rc, rcount;
						for (i = 0, rcount = 0; i < KNH_MPI_SIZE(comm); i++, rcount += rc) {
							rc = rcounts[i];
							rdispls[i] = rcount;
						}
						int incl = rcount - IA_size(ardata);
						if (incl <= 0) {
							ret = MPI_Gatherv(IA_buf(asdata), IA_size(asdata), IA_Type,
											  IA_buf(ardata), rcounts, rdispls, IA_Type, root_rank, KNH_MPI_COMM(comm));
						} else {
							KNH_IA_EXPAND(ardata, incl);
							ret = MPI_Gatherv(IA_buf(asdata), IA_size(asdata), IA_Type,
											  IA_buf(ardata), rcounts, rdispls, IA_Type, root_rank, KNH_MPI_COMM(comm));
							IA_size(ardata) += incl;
						}
					}
				}
			} else {
				if (count > 0) {
					ret = MPI_Gather(IA_buf(asdata), count, IA_Type, NULL, count, IA_Type, root_rank, KNH_MPI_COMM(comm));
				} else {
					ret = MPI_Gather(&IA_size(asdata), 1, MPI_INT, NULL, 0, MPI_INT, root_rank, KNH_MPI_COMM(comm));
					if (KNH_MPI_SUCCESS(ret)) {
						ret = MPI_Gatherv(IA_buf(asdata), IA_size(asdata), IA_Type, NULL, NULL, NULL, 0, root_rank, KNH_MPI_COMM(comm));
					}
				}
			}
		}
		else { /* IS_Int(sdata) */
			IV(asdata, sdata);
			count = 1;
			if (KNH_MPI_RANK(comm) == root_rank) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - IA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Gather(IV_buf(asdata), count, IV_Type, IA_buf(ardata), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
				} else {
					KNH_IA_EXPAND(ardata, incl);
					ret = MPI_Gather(IV_buf(asdata), count, IV_Type, IA_buf(ardata), count, IA_Type, root_rank, KNH_MPI_COMM(comm));
					IA_size(ardata) += incl;
				}
			} else {
				ret = MPI_Gather(IV_buf(asdata), count, IV_Type, NULL, count, IA_Type, root_rank, KNH_MPI_COMM(comm));
			}

		}
	}
	return ret;
}

KMETHOD MPIComm_gatherInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_GatherInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o, Int_to(int, sfp[4])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.gatherFloat(FArray sdata, Int count, FArray rdata, Int root_rank);

static int knh_MPI_GatherFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata, int root_rank)
{
	COMM(comm, c);
	FA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_FArray(sdata)) {
			FA(asdata, sdata);
			if (KNH_MPI_RANK(comm) == root_rank) {
				if (count > 0) {
					int rcount = count * KNH_MPI_SIZE(comm);
					int incl = rcount - FA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Gather(FA_buf(asdata), count, FA_Type, FA_buf(ardata), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
					} else {
						KNH_FA_EXPAND(ardata, incl);
						ret = MPI_Gather(FA_buf(asdata), count, FA_Type, FA_buf(ardata), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
						FA_size(ardata) += incl;
					}
				} else {
					int rcounts[KNH_MPI_SIZE(comm)];
					int rdispls[KNH_MPI_SIZE(comm)];
					ret = MPI_Gather(&FA_size(asdata), 1, MPI_INT, rcounts, 1, MPI_INT, root_rank, KNH_MPI_COMM(comm));
					if (KNH_MPI_SUCCESS(ret)) {
						int i, rc, rcount;
						for (i = 0, rcount = 0; i < KNH_MPI_SIZE(comm); i++, rcount += rc) {
							rc = rcounts[i];
							rdispls[i] = rcount;
						}
						int incl = rcount - FA_size(ardata);
						if (incl <= 0) {
							ret = MPI_Gatherv(FA_buf(asdata), FA_size(asdata), FA_Type,
											  FA_buf(ardata), rcounts, rdispls, FA_Type, root_rank, KNH_MPI_COMM(comm));
						} else {
							KNH_FA_EXPAND(ardata, incl);
							ret = MPI_Gatherv(FA_buf(asdata), FA_size(asdata), FA_Type,
											  FA_buf(ardata), rcounts, rdispls, FA_Type, root_rank, KNH_MPI_COMM(comm));
							FA_size(ardata) += incl;
						}
					}
				}
			} else {
				if (count > 0) {
					ret = MPI_Gather(FA_buf(asdata), count, FA_Type, NULL, count, FA_Type, root_rank, KNH_MPI_COMM(comm));
				} else {
					ret = MPI_Gather(&FA_size(asdata), 1, MPI_INT, NULL, 0, MPI_INT, root_rank, KNH_MPI_COMM(comm));
					if (KNH_MPI_SUCCESS(ret)) {
						ret = MPI_Gatherv(FA_buf(asdata), FA_size(asdata), FA_Type, NULL, NULL, NULL, 0, root_rank, KNH_MPI_COMM(comm));
					}
				}
			}
		}
		else { /* IS_Float(sdata) */
			FV(asdata, sdata);
			count = 1;
			if (KNH_MPI_RANK(comm) == root_rank) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - FA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Gather(FV_buf(asdata), count, FV_Type, FA_buf(ardata), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
				} else {
					KNH_FA_EXPAND(ardata, incl);
					ret = MPI_Gather(FV_buf(asdata), count, FV_Type, FA_buf(ardata), count, FA_Type, root_rank, KNH_MPI_COMM(comm));
					FA_size(ardata) += incl;
				}
			} else {
				ret = MPI_Gather(FV_buf(asdata), count, FV_Type, NULL, count, FA_Type, root_rank, KNH_MPI_COMM(comm));
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_gatherFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_GatherFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o, Int_to(int, sfp[4])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.gather(dynamic sdata, dynamic rdata, Int root_rank);

KMETHOD MPIComm_gather(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_Object_t *rdata = sfp[2].o;
	int ret = -1;
	if (IS_Bytes(sdata) && IS_Bytes(rdata)) {
		ret = knh_MPI_GatherBytes(ctx, sfp[0].o, sdata, 0, sfp[2].o, Int_to(int, sfp[3]));
	} else if (IS_IArray(sdata) && IS_IArray(rdata)) {
		ret = knh_MPI_GatherInt(ctx, sfp[0].o, sdata, 0, sfp[2].o, Int_to(int, sfp[3]));
	} else if (IS_FArray(sdata) && IS_FArray(rdata)) {
		ret = knh_MPI_GatherFloat(ctx, sfp[0].o, sdata, 0, sfp[2].o, Int_to(int, sfp[3]));
	}
	RETURNi_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allGatherBytes(Bytes sdata, Int count, Bytes rdata);

static int knh_MPI_AllgatherBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata)
{
	COMM(comm, c);
	BA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_Bytes(sdata)) {
			BA(asdata, sdata);
			if (count > 0) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - BA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Allgather(BA_buf(asdata), count, BA_Type, BA_buf(ardata), count, BA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_BA_EXPAND(ardata, incl);
					ret = MPI_Allgather(BA_buf(asdata), count, BA_Type, BA_buf(ardata), count, BA_Type, KNH_MPI_COMM(comm));
					BA_size(ardata) += incl;
				}
			} else {
				int rcounts[KNH_MPI_SIZE(comm)];
				int rdispls[KNH_MPI_SIZE(comm)];
				ret = MPI_Allgather(&BA_size(asdata), 1, MPI_INT, rcounts, 1, MPI_INT, KNH_MPI_COMM(comm));
				if (KNH_MPI_SUCCESS(ret)) {
					int i, rc, rcount;
					for (i = 0, rcount = 0; i < KNH_MPI_SIZE(comm); i++, rcount += rc) {
						rc = rcounts[i];
						rdispls[i] = rcount;
					}
					int incl = rcount - BA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Allgatherv(BA_buf(asdata), BA_size(asdata), BA_Type, BA_buf(ardata), rcounts, rdispls, BA_Type, KNH_MPI_COMM(comm));
					} else {
						KNH_BA_EXPAND(ardata, incl);
						ret = MPI_Allgatherv(BA_buf(asdata), BA_size(asdata), BA_Type, BA_buf(ardata), rcounts, rdispls, BA_Type, KNH_MPI_COMM(comm));
						BA_size(ardata) += incl;
					}
				}
			}
		}
		else { /* IS_String(sdata) */
			SV(asdata, sdata);
			if (count > 0) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - BA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Allgather(SV_buf(asdata), count, SV_Type, BA_buf(ardata), count, BA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_BA_EXPAND(ardata, incl);
					ret = MPI_Allgather(SV_buf(asdata), count, SV_Type, BA_buf(ardata), count, BA_Type, KNH_MPI_COMM(comm));
					BA_size(ardata) += incl;
				}
			} else {
				int rcounts[KNH_MPI_SIZE(comm)];
				int rdispls[KNH_MPI_SIZE(comm)];
				ret = MPI_Allgather(&SV_size(asdata), 1, MPI_INT, rcounts, 1, MPI_INT, KNH_MPI_COMM(comm));
				if (KNH_MPI_SUCCESS(ret)) {
					int i, rc, rcount;
					for (i = 0, rcount = 0; i < KNH_MPI_SIZE(comm); i++, rcount += rc) {
						rc = rcounts[i];
						rdispls[i] = rcount;
					}
					int incl = rcount - BA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Allgatherv(SV_buf(asdata), SV_size(asdata), SV_Type, BA_buf(ardata), rcounts, rdispls, BA_Type, KNH_MPI_COMM(comm));
					} else {
						KNH_BA_EXPAND(ardata, incl);
						ret = MPI_Allgatherv(SV_buf(asdata), SV_size(asdata), SV_Type, BA_buf(ardata), rcounts, rdispls, BA_Type, KNH_MPI_COMM(comm));
						BA_size(ardata) += incl;
					}
				}
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allGatherBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AllgatherBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allGatherInt(IArray sdata, Int count, IArray rdata);

static int knh_MPI_AllgatherInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata)
{
	COMM(comm, c);
	IA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_IArray(sdata)) {
			IA(asdata, sdata);
			if (count > 0) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - IA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Allgather(IA_buf(asdata), count, IA_Type, IA_buf(ardata), count, IA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_IA_EXPAND(ardata, incl);
					ret = MPI_Allgather(IA_buf(asdata), count, IA_Type, IA_buf(ardata), count, IA_Type, KNH_MPI_COMM(comm));
					IA_size(ardata) += incl;
				}
			} else {
				int rcounts[KNH_MPI_SIZE(comm)];
				int rdispls[KNH_MPI_SIZE(comm)];
				ret = MPI_Allgather(&IA_size(asdata), 1, MPI_INT, rcounts, 1, MPI_INT, KNH_MPI_COMM(comm));
				if (KNH_MPI_SUCCESS(ret)) {
					int i, rc, rcount;
					for (i = 0, rcount = 0; i < KNH_MPI_SIZE(comm); i++, rcount += rc) {
						rc = rcounts[i];
						rdispls[i] = rcount;
					}
					int incl = rcount - IA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Allgatherv(IA_buf(asdata), IA_size(asdata), IA_Type, IA_buf(ardata), rcounts, rdispls, IA_Type, KNH_MPI_COMM(comm));
					} else {
					KNH_IA_EXPAND(ardata, incl);
					ret = MPI_Allgatherv(IA_buf(asdata), IA_size(asdata), IA_Type, IA_buf(ardata), rcounts, rdispls, IA_Type, KNH_MPI_COMM(comm));
					IA_size(ardata) += incl;
					}
				}
			}
		}
		else { /* IS_Int(sdata) */
			IV(asdata, sdata);
			count = 1;
			int rcount = count * KNH_MPI_SIZE(comm);
			int incl = rcount - IA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Allgather(IV_buf(asdata), count, IV_Type, IA_buf(ardata), count, IA_Type, KNH_MPI_COMM(comm));
			} else {
				KNH_IA_EXPAND(ardata, incl);
				ret = MPI_Allgather(IV_buf(asdata), count, IV_Type, IA_buf(ardata), count, IA_Type, KNH_MPI_COMM(comm));
				IA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allGatherInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AllgatherInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allGatherFloat(FArray sdata, Int count, FArray rdata);

static int knh_MPI_AllgatherFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata)
{
	COMM(comm, c);
	FA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_FArray(sdata)) {
			FA(asdata, sdata);
			if (count > 0) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - FA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Allgather(FA_buf(asdata), count, FA_Type, FA_buf(ardata), count, FA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_FA_EXPAND(ardata, incl);
					ret = MPI_Allgather(FA_buf(asdata), count, FA_Type, FA_buf(ardata), count, FA_Type, KNH_MPI_COMM(comm));
					FA_size(ardata) += incl;
				}
			} else {
				int rcounts[KNH_MPI_SIZE(comm)];
				int rdispls[KNH_MPI_SIZE(comm)];
				ret = MPI_Allgather(&FA_size(asdata), 1, MPI_INT, rcounts, 1, MPI_INT, KNH_MPI_COMM(comm));
				if (KNH_MPI_SUCCESS(ret)) {
					int i, rc, rcount;
					for (i = 0, rcount = 0; i < KNH_MPI_SIZE(comm); i++, rcount += rc) {
						rc = rcounts[i];
						rdispls[i] = rcount;
					}
					int incl = rcount - FA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Allgatherv(FA_buf(asdata), FA_size(asdata), FA_Type, FA_buf(ardata), rcounts, rdispls, FA_Type, KNH_MPI_COMM(comm));
					} else {
						KNH_FA_EXPAND(ardata, incl);
						ret = MPI_Allgatherv(FA_buf(asdata), FA_size(asdata), FA_Type, FA_buf(ardata), rcounts, rdispls, FA_Type, KNH_MPI_COMM(comm));
						FA_size(ardata) += incl;
					}
				}
			}
		}
		else { /* IS_Float(sdata) */
			FV(asdata, sdata);
			count = 1;
			int rcount = count * KNH_MPI_SIZE(comm);
			int incl = rcount - FA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Allgather(FV_buf(asdata), count, FV_Type, FA_buf(ardata), count, FA_Type, KNH_MPI_COMM(comm));
			} else {
				KNH_FA_EXPAND(ardata, incl);
				ret = MPI_Allgather(FV_buf(asdata), count, FV_Type, FA_buf(ardata), count, FA_Type, KNH_MPI_COMM(comm));
				FA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allGatherFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AllgatherFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allGather(dynamic sdata, dynamic rdata);

KMETHOD MPIComm_allGather(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_Object_t *rdata = sfp[2].o;
	int ret = -1;
	if (IS_Bytes(sdata) && IS_Bytes(rdata)) {
		ret = knh_MPI_AllgatherBytes(ctx, sfp[0].o, sdata, 0, rdata);
	} else if (IS_IArray(sdata) && IS_IArray(rdata)) {
		ret = knh_MPI_AllgatherInt(ctx, sfp[0].o, sdata, 0, rdata);
	} else if (IS_FArray(sdata) && IS_FArray(rdata)) {
		ret = knh_MPI_AllgatherFloat(ctx, sfp[0].o, sdata, 0, rdata);
	}
	RETURNi_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allToAllBytes(Bytes sdata, Int count, Bytes rdata);

static int knh_MPI_AlltoallBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata)
{
	COMM(comm, c);
	BA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_Bytes(sdata)) {
			BA(asdata, sdata);
			if (count > 0) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - BA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Alltoall(BA_buf(asdata), count, BA_Type, BA_buf(ardata), count, BA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_BA_EXPAND(ardata, incl);
					ret = MPI_Alltoall(BA_buf(asdata), count, BA_Type, BA_buf(ardata), count, BA_Type, KNH_MPI_COMM(comm));
					BA_size(ardata) += incl;
				}
			} else {
				size_t size = KNH_MPI_SIZE(comm);
				int scounts[size], sdispls[size], rcounts[size], rdispls[size];
				int r, wc, sum_count;
				int quot = BA_size(asdata) / size;
				int mod = BA_size(asdata) % size;
				for (r = 0, sum_count = 0; r < size; r++, sum_count += wc) {
					wc = quot + ((r < mod) ? 1 : 0);
					scounts[r] = wc;
					sdispls[r] = sum_count;
				}
				ret = MPI_Alltoall(scounts, 1, MPI_INT, rcounts, 1, MPI_INT, KNH_MPI_COMM(comm));
				if (KNH_MPI_SUCCESS(ret)) {
					for (r = 0, sum_count = 0; r < size; r++, sum_count += wc) {
						wc = rcounts[r];
						rdispls[r] = sum_count;
					}
					int incl = sum_count - BA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Alltoallv(BA_buf(asdata), scounts, sdispls, BA_Type, BA_buf(ardata), rcounts, rdispls, BA_Type, KNH_MPI_COMM(comm));
					} else {
						KNH_BA_EXPAND(ardata, incl);
						ret = MPI_Alltoallv(BA_buf(asdata), scounts, sdispls, BA_Type, BA_buf(ardata), rcounts, rdispls, BA_Type, KNH_MPI_COMM(comm));
						BA_size(ardata) += incl;
					}
				}
			}
		}
		else { /* IS_String(sdata) */
			SV(asdata, sdata);
			if (count > 0) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - BA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Alltoall(SV_buf(asdata), count, SV_Type, BA_buf(ardata), count, BA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_BA_EXPAND(ardata, incl);
					ret = MPI_Alltoall(SV_buf(asdata), count, SV_Type, BA_buf(ardata), count, BA_Type, KNH_MPI_COMM(comm));
					BA_size(ardata) += incl;
				}
			} else {
				size_t size = KNH_MPI_SIZE(comm);
				int scounts[size], sdispls[size], rcounts[size], rdispls[size];
				int r, wc, sum_count;
				int quot = SV_size(asdata) / size;
				int mod = SV_size(asdata) % size;
				for (r = 0, sum_count = 0; r < size; r++, sum_count += wc) {
					wc = quot + ((r < mod) ? 1 : 0);
					scounts[r] = wc;
					sdispls[r] = sum_count;
				}
				ret = MPI_Alltoall(scounts, 1, MPI_INT, rcounts, 1, MPI_INT, KNH_MPI_COMM(comm));
				if (KNH_MPI_SUCCESS(ret)) {
					for (r = 0, sum_count = 0; r < size; r++, sum_count += wc) {
						wc = rcounts[r];
						rdispls[r] = sum_count;
					}
					int incl = sum_count - BA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Alltoallv(SV_buf(asdata), scounts, sdispls, SV_Type, BA_buf(ardata), rcounts, rdispls, BA_Type, KNH_MPI_COMM(comm));
					} else {
						KNH_BA_EXPAND(ardata, incl);
						ret = MPI_Alltoallv(SV_buf(asdata), scounts, sdispls, SV_Type, BA_buf(ardata), rcounts, rdispls, BA_Type, KNH_MPI_COMM(comm));
						BA_size(ardata) += incl;
					}
				}
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allToAllBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AlltoallBytes(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allToAllInt(IArray sdata, Int count, IArray rdata);

static int knh_MPI_AlltoallInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata)
{
	COMM(comm, c);
	IA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_IArray(sdata)) {
			IA(asdata, sdata);
			if (count > 0) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - IA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Alltoall(IA_buf(asdata), count, IA_Type, IA_buf(ardata), count, IA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_IA_EXPAND(ardata, incl);
					ret = MPI_Alltoall(IA_buf(asdata), count, IA_Type, IA_buf(ardata), count, IA_Type, KNH_MPI_COMM(comm));
					IA_size(ardata) += incl;
				}
			} else {
			size_t size = KNH_MPI_SIZE(comm);
			int scounts[size], sdispls[size], rcounts[size], rdispls[size];
			int r, wc, sum_count;
			int quot = IA_size(asdata) / size;
			int mod = IA_size(asdata) % size;
			for (r = 0, sum_count = 0; r < size; r++, sum_count += wc) {
				wc = quot + ((r < mod) ? 1 : 0);
				scounts[r] = wc;
				sdispls[r] = sum_count;
			}
			ret = MPI_Alltoall(scounts, 1, MPI_INT, rcounts, 1, MPI_INT, KNH_MPI_COMM(comm));
			if (KNH_MPI_SUCCESS(ret)) {
				for (r = 0, sum_count = 0; r < size; r++, sum_count += wc) {
					wc = rcounts[r];
					rdispls[r] = sum_count;
				}
				int incl = sum_count - IA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Alltoallv(IA_buf(asdata), scounts, sdispls, IA_Type, IA_buf(ardata), rcounts, rdispls, IA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_IA_EXPAND(ardata, incl);
					ret = MPI_Alltoallv(IA_buf(asdata), scounts, sdispls, IA_Type, IA_buf(ardata), rcounts, rdispls, IA_Type, KNH_MPI_COMM(comm));
					IA_size(ardata) += incl;
				}
			}
		}
		}
		else { /* IS_Int(sdata) */
			IV(asdata, sdata);
			count = 1;
			int rcount = count * KNH_MPI_SIZE(comm);
			int incl = rcount - IA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Alltoall(IV_buf(asdata), count, IV_Type, IA_buf(ardata), count, IA_Type, KNH_MPI_COMM(comm));
			} else {
				KNH_IA_EXPAND(ardata, incl);
				ret = MPI_Alltoall(IV_buf(asdata), count, IV_Type, IA_buf(ardata), count, IA_Type, KNH_MPI_COMM(comm));
				IA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allToAllInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AlltoallInt(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allToAllFloat(FArray sdata, Int count, FArray rdata);

static int knh_MPI_AlltoallFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, int count, knh_Object_t *rdata)
{
	COMM(comm, c);
	FA(ardata, rdata);
	int ret = -1;
	if (KNH_ON_MPI(comm)) {
		if (IS_FArray(sdata)) {
			FA(asdata, sdata);
			if (count > 0) {
				int rcount = count * KNH_MPI_SIZE(comm);
				int incl = rcount - FA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Alltoall(FA_buf(asdata), count, FA_Type, FA_buf(ardata), count, FA_Type, KNH_MPI_COMM(comm));
				} else {
					KNH_FA_EXPAND(ardata, incl);
					ret = MPI_Alltoall(FA_buf(asdata), count, FA_Type, FA_buf(ardata), count, FA_Type, KNH_MPI_COMM(comm));
					FA_size(ardata) += incl;
				}
			} else {
				size_t size = KNH_MPI_SIZE(comm);
				int scounts[size], sdispls[size], rcounts[size], rdispls[size];
				int r, wc, sum_count;
				int quot = FA_size(asdata) / size;
				int mod = FA_size(asdata) % size;
				for (r = 0, sum_count = 0; r < size; r++, sum_count += wc) {
					wc = quot + ((r < mod) ? 1 : 0);
					scounts[r] = wc;
					sdispls[r] = sum_count;
				}
				ret = MPI_Alltoall(scounts, 1, MPI_INT, rcounts, 1, MPI_INT, KNH_MPI_COMM(comm));
				if (KNH_MPI_SUCCESS(ret)) {
					for (r = 0, sum_count = 0; r < size; r++, sum_count += wc) {
						wc = rcounts[r];
						rdispls[r] = sum_count;
					}
					int incl = sum_count - FA_size(ardata);
					if (incl <= 0) {
						ret = MPI_Alltoallv(FA_buf(asdata), scounts, sdispls, FA_Type, FA_buf(ardata), rcounts, rdispls, FA_Type, KNH_MPI_COMM(comm));
					} else {
						KNH_FA_EXPAND(ardata, incl);
						ret = MPI_Alltoallv(FA_buf(asdata), scounts, sdispls, FA_Type, FA_buf(ardata), rcounts, rdispls, FA_Type, KNH_MPI_COMM(comm));
						FA_size(ardata) += incl;
					}
				}
			}
		}
		else { /* IS_Float(sdata) */
			FV(asdata, sdata);
			count = 1;
			int rcount = count * KNH_MPI_SIZE(comm);
			int incl = rcount - FA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Alltoall(FV_buf(asdata), count, FV_Type, FA_buf(ardata), count, FA_Type, KNH_MPI_COMM(comm));
			} else {
				KNH_FA_EXPAND(ardata, incl);
				ret = MPI_Alltoall(FV_buf(asdata), count, FV_Type, FA_buf(ardata), count, FA_Type, KNH_MPI_COMM(comm));
				FA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allToAllFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AlltoallFloat(ctx, sfp[0].o, sfp[1].o, Int_to(int, sfp[2]), sfp[3].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allToAll(dynamic sdata, dynamic rdata);
KMETHOD MPIComm_allToAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_Object_t *rdata = sfp[2].o;
	int ret = -1;
	if (IS_Bytes(sdata) && IS_Bytes(rdata)) {
		ret = knh_MPI_AlltoallBytes(ctx, sfp[0].o, sfp[1].o, 0, sfp[2].o);
	} else if (IS_IArray(sdata) && IS_IArray(rdata)) {
		ret = knh_MPI_AlltoallInt(ctx, sfp[0].o, sfp[1].o, 0, sfp[2].o);
	} else if (IS_FArray(sdata) && IS_FArray(rdata)) {
		ret = knh_MPI_AlltoallFloat(ctx, sfp[0].o, sfp[1].o, 0, sfp[2].o);
	}
	RETURNi_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.reduceBytes(Bytes sdata, Bytes rdata, Int count, MPIOp op, Int root_rank);

static int knh_MPI_ReduceBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, knh_Object_t *rdata, int count, knh_Object_t *o, int root_rank)
{
	COMM(comm, c);
	BA(ardata, rdata);
	OP(op, o);
	int ret = -1;
	if (KNH_ON_MPI(comm) && !KNH_MPI_OP_IS_NULL(op)) {
		if (IS_Bytes(sdata)) {
			BA(asdata, sdata);
			if (count == 0) {
				ret = MPI_Allreduce(&BA_size(asdata), &count, 1, MPI_INT, MPI_MIN, KNH_MPI_COMM(comm)); /* get mininum data cont */
				if (!KNH_MPI_SUCCESS(ret)) return ret;
			}
			if (KNH_MPI_RANK(comm) == root_rank) {
				int incl = count - BA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Reduce(BA_buf(asdata), BA_buf(ardata), count, BA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
				} else {
					KNH_BA_EXPAND(ardata, incl);
					ret = MPI_Reduce(BA_buf(asdata), BA_buf(ardata), count, BA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
					BA_size(ardata) += incl;
				}
			} else {
				ret = MPI_Reduce(BA_buf(asdata), NULL, count, BA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
			}
		}
		else { /* IS_String(sdata) */
			SV(asdata, sdata);
			if (count == 0) {
				ret = MPI_Allreduce(&SV_size(asdata), &count, 1, MPI_INT, MPI_MIN, KNH_MPI_COMM(comm)); /* get mininum data cont */
				if (!KNH_MPI_SUCCESS(ret)) return ret;
			}
			if (KNH_MPI_RANK(comm) == root_rank) {
				int incl = count - BA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Reduce(SV_buf(asdata), BA_buf(ardata), count, SV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
				} else {
					KNH_BA_EXPAND(ardata, incl);
					ret = MPI_Reduce(SV_buf(asdata), BA_buf(ardata), count, SV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
					BA_size(ardata) += incl;
				}
			} else {
				ret = MPI_Reduce(SV_buf(asdata), NULL, count, SV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_reduceBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_ReduceBytes(ctx, sfp[0].o, sfp[1].o, sfp[2].o, Int_to(int, sfp[3]), sfp[4].o, Int_to(int, sfp[5])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.reduceInt(IArray sdata, IArray rdata, Int count, MPIOp op, Int root_rank);

static int knh_MPI_ReduceInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, knh_Object_t *rdata, int count, knh_Object_t *o, int root_rank)
{
	COMM(comm, c);
	IA(ardata, rdata);
	OP(op, o);
	int ret = -1;
	if (KNH_ON_MPI(comm) && !KNH_MPI_OP_IS_NULL(op)) {
		if (IS_IArray(sdata)) {
			IA(asdata, sdata);
			if (count == 0) {
				ret = MPI_Allreduce(&IA_size(asdata), &count, 1, MPI_INT, MPI_MIN, KNH_MPI_COMM(comm)); /* get mininum data cont */
				if (!KNH_MPI_SUCCESS(ret)) return ret;
			}
			if (KNH_MPI_RANK(comm) == root_rank) {
				int incl = count - IA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Reduce(IA_buf(asdata), IA_buf(ardata), count, IA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
				} else {
					KNH_IA_EXPAND(ardata, incl);
					ret = MPI_Reduce(IA_buf(asdata), IA_buf(ardata), count, IA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
					IA_size(ardata) += incl;
				}
			} else {
				ret = MPI_Reduce(IA_buf(asdata), NULL, count, IA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
			}
		}
		else { /* IS_Float(sdata) */
			IV(asdata, sdata);
			count = 1;
			if (KNH_MPI_RANK(comm) == root_rank) {
				int incl = count - IA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Reduce(IV_buf(asdata), IA_buf(ardata), count, IV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
				} else {
					KNH_IA_EXPAND(ardata, incl);
					ret = MPI_Reduce(IV_buf(asdata), IA_buf(ardata), count, IV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
					IA_size(ardata) += incl;
				}
			} else {
				ret = MPI_Reduce(IV_buf(asdata), NULL, count, IV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_reduceInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_ReduceInt(ctx, sfp[0].o, sfp[1].o, sfp[2].o, Int_to(int, sfp[3]), sfp[4].o, Int_to(int, sfp[5])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.reduceFloat(FArray sdata, FArray rdata, Int count, MPIOp op, Int root_rank);

static int knh_MPI_ReduceFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, knh_Object_t *rdata, int count, knh_Object_t *o, int root_rank)
{
	COMM(comm, c);
	OP(op, o);
	int ret = -1;
	if (KNH_ON_MPI(comm) && !KNH_MPI_OP_IS_NULL(op)) {
		FA(ardata, rdata);
		if (IS_FArray(sdata)) {
			FA(asdata, sdata);
			if (count == 0) {
				ret = MPI_Allreduce(&FA_size(asdata), &count, 1, MPI_INT, MPI_MIN, KNH_MPI_COMM(comm)); /* get mininum data cont */
				if (!KNH_MPI_SUCCESS(ret)) return ret;
			}
			if (KNH_MPI_RANK(comm) == root_rank) {
				int incl = count - FA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Reduce(FA_buf(asdata), FA_buf(ardata), count, FA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
				} else {
					KNH_FA_EXPAND(ardata, incl);
					ret = MPI_Reduce(FA_buf(asdata), FA_buf(ardata), count, FA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
					FA_size(ardata) += incl;
				}
			} else {
				ret = MPI_Reduce(FA_buf(asdata), NULL, count, FA_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
			}
		}
		else { /* IS_Float(sdata)*/
			FV(asdata, sdata);
			count = 1; // single float(double) value
			if (KNH_MPI_RANK(comm) == root_rank) {
				int incl = count - FA_size(ardata);
				if (incl <= 0) {
					ret = MPI_Reduce(FV_buf(asdata), FA_buf(ardata), count, FV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
				} else {
					KNH_FA_EXPAND(ardata, incl);
					ret = MPI_Reduce(FV_buf(asdata), FA_buf(ardata), count, FV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
					FA_size(ardata) += incl;
				}
			} else {
				ret = MPI_Reduce(FV_buf(asdata), NULL, count, FV_Type, KNH_MPI_OP(op), root_rank, KNH_MPI_COMM(comm));
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_reduceFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_ReduceFloat(ctx, sfp[0].o, sfp[1].o, sfp[2].o, Int_to(int, sfp[3]), sfp[4].o, Int_to(int, sfp[5])));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.reduce(dynamic sdata, dynamic rdata, MPIOp op, Int root_rank);
KMETHOD MPIComm_reduce(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_Object_t *rdata = sfp[2].o;
	int ret = -1;
	if (IS_Bytes(sdata) && IS_Bytes(rdata)) {
		ret = knh_MPI_ReduceBytes(ctx, sfp[0].o, sdata, rdata, 0, sfp[3].o, Int_to(int, sfp[4]));
	} else if (IS_IArray(sdata) && IS_IArray(rdata)) {
		ret = knh_MPI_ReduceInt(ctx, sfp[0].o, sdata, rdata, 0, sfp[3].o, Int_to(int, sfp[4]));
	} else if ((IS_FArray(sdata) || IS_Float(sdata)) && IS_FArray(rdata)) {
		ret = knh_MPI_ReduceFloat(ctx, sfp[0].o, sdata, rdata, 0, sfp[3].o, Int_to(int, sfp[4]));
	}
	RETURNi_(ret);
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allReduceBytes(Bytes sdata, Bytes rdata, Int count, MPIOp op);

static int knh_MPI_AllreduceBytes(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, knh_Object_t *rdata, int count, knh_Object_t *o)
{
	COMM(comm, c);
	BA(ardata, rdata);
	OP(op, o);
	int ret = -1;
	if (KNH_ON_MPI(comm) && !KNH_MPI_OP_IS_NULL(op)) {
		if (IS_Bytes(sdata)) {
			BA(asdata, sdata);
			if (count == 0) {
				ret = MPI_Allreduce(&BA_size(asdata), &count, 1, MPI_INT, MPI_MIN, KNH_MPI_COMM(comm)); /* get mininum data cont */
				if (!KNH_MPI_SUCCESS(ret)) return ret;
			}
			int incl = count - BA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Allreduce(BA_buf(asdata), BA_buf(ardata), count, BA_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
			} else {
				KNH_BA_EXPAND(ardata, incl);
				ret = MPI_Allreduce(BA_buf(asdata), BA_buf(ardata), count, BA_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
				BA_size(ardata) += incl;
			}
		}
		else { /* IS_String(sdata) */
			SV(asdata, sdata);
			if (count == 0) {
				ret = MPI_Allreduce(&SV_size(asdata), &count, 1, MPI_INT, MPI_MIN, KNH_MPI_COMM(comm)); /* get mininum data cont */
				if (!KNH_MPI_SUCCESS(ret)) return ret;
			}
			int incl = count - BA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Allreduce(SV_buf(asdata), BA_buf(ardata), count, SV_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
			} else {
				KNH_BA_EXPAND(ardata, incl);
				ret = MPI_Allreduce(SV_buf(asdata), BA_buf(ardata), count, SV_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
				BA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allReduceBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AllreduceBytes(ctx, sfp[0].o, sfp[1].o, sfp[2].o, Int_to(int, sfp[3]), sfp[4].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allReduceInt(IArray sdata, IArray rdata, Int count, MPIOp op);

static int knh_MPI_AllreduceInt(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, knh_Object_t *rdata, int count, knh_Object_t *o)
{
	COMM(comm, c);
	IA(ardata, rdata);
	OP(op, o);
	int ret = -1;
	if (KNH_ON_MPI(comm) && !KNH_MPI_OP_IS_NULL(op)) {
		if (IS_IArray(sdata)) {
			IA(asdata, sdata);
			if (count == 0) {
				ret = MPI_Allreduce(&IA_size(asdata), &count, 1, MPI_INT, MPI_MIN, KNH_MPI_COMM(comm)); /* get mininum data cont */
				if (!KNH_MPI_SUCCESS(ret)) return ret;
			}
			int incl = count - IA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Allreduce(IA_buf(asdata), IA_buf(ardata), count, IA_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
			} else {
				KNH_IA_EXPAND(ardata, incl);
				ret = MPI_Allreduce(IA_buf(asdata), IA_buf(ardata), count, IA_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
				IA_size(ardata) += incl;
			}
		}
		else { /* IS_Int(sdata) */
			IV(asdata, sdata);
			count = 1;
			int incl = count - IA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Allreduce(IV_buf(asdata), IA_buf(ardata), count, IV_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
			} else {
				KNH_IA_EXPAND(ardata, incl);
				ret = MPI_Allreduce(IV_buf(asdata), IA_buf(ardata), count, IV_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
				IA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allReduceInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AllreduceInt(ctx, sfp[0].o, sfp[1].o, sfp[2].o, Int_to(int, sfp[3]), sfp[4].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allReduceFloat(FArray sdata, FArray rdata, Int count, MPIOp op);

static int knh_MPI_AllreduceFloat(CTX ctx, knh_Object_t *c, knh_Object_t *sdata, knh_Object_t *rdata, int count, knh_Object_t *o)
{
	COMM(comm, c);
	FA(ardata, rdata);
	OP(op, o);
	int ret = -1;
	if (KNH_ON_MPI(comm) && !KNH_MPI_OP_IS_NULL(op)) {
		if (IS_FArray(sdata)) {
			FA(asdata, sdata);
			if (count == 0) {
				ret = MPI_Allreduce(&FA_size(asdata), &count, 1, MPI_INT, MPI_MIN, KNH_MPI_COMM(comm)); /* get mininum data cont */
				if (!KNH_MPI_SUCCESS(ret)) return ret;
			}
			int incl = count - FA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Allreduce(FA_buf(asdata), FA_buf(ardata), count, FA_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
			} else {
				KNH_FA_EXPAND(ardata, incl);
				ret = MPI_Allreduce(FA_buf(asdata), FA_buf(ardata), count, FA_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
				FA_size(ardata) += incl;
			}
		}
		else { /* IS_FArray(sdata) */
			FV(asdata, sdata);
			count = 1;
			int incl = count - FA_size(ardata);
			if (incl <= 0) {
				ret = MPI_Allreduce(FV_buf(asdata), FA_buf(ardata), count, FV_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
			} else {
				KNH_FA_EXPAND(ardata, incl);
				ret = MPI_Allreduce(FV_buf(asdata), FA_buf(ardata), count, FV_Type, KNH_MPI_OP(op), KNH_MPI_COMM(comm));
				FA_size(ardata) += incl;
			}
		}
	}
	return ret;
}

KMETHOD MPIComm_allReduceFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_MPI_AllreduceFloat(ctx, sfp[0].o, sfp[1].o, sfp[2].o, Int_to(int, sfp[3]), sfp[4].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.allReduce(dynamic sdata, dynamic rdata, MPIOp op);

KMETHOD MPIComm_allReduce(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Object_t *sdata = sfp[1].o;
	knh_Object_t *rdata = sfp[2].o;
	int ret = -1;
	if (IS_Bytes(sdata) && IS_Bytes(rdata)) {
		ret = knh_MPI_AllreduceBytes(ctx, sfp[0].o, sdata, rdata, 0, sfp[3].o);
	} else if (IS_IArray(sdata) && IS_IArray(rdata)) {
		ret = knh_MPI_AllreduceInt(ctx, sfp[0].o, sdata, rdata, 0, sfp[3].o);
	} else if (IS_FArray(sdata) && IS_FArray(rdata)) {
		ret = knh_MPI_AllreduceFloat(ctx, sfp[0].o, sdata, rdata, 0, sfp[3].o);
	}
	RETURNi_(ret);
}

