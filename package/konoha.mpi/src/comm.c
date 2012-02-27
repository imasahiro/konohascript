#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.getRank();
KMETHOD MPIComm_getRank(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNi_(MPIC_RANK((kMPIComm*)sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.getSize();
KMETHOD MPIComm_getSize(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNi_(MPIC_SIZE((kMPIComm*)sfp[0].o));
}

/* ------------------------------------------------------------------------ */
//## method String MPIComm.getProcessorName();
KMETHOD MPIComm_getProcessorName(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(new_String(ctx, (const char*)(((kMPIComm*)sfp[0].o)->proc_name)));
}

/* ------------------------------------------------------------------------ */
//## method Int MPIComm.barrier();
KMETHOD MPIComm_barrier(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNi_(MPI_Barrier(MPIC_COMM((kMPIComm*)sfp[0].o)));
}

/* ------------------------------------------------------------------------ */
//## method MPIComm MPIComm.create(IArray ranks);

KMETHOD MPIComm_create(CTX ctx, ksfp_t *sfp _RIX)
{
	MPI_Group base, newg;
	MPIC(comm, sfp[0].o);
	kArray *ids = sfp[1].a;
	MPIC(newc, new_O(MPIComm, O_cid(sfp[0].o)));
	int maxprocs = MPIC_SIZE(comm);
	int len = knh_Array_size(ids);
	if (len > 0) {
		int i, ranks[len], r_max = 0;
		for (i = 0; i < len; i++) {
			kint_t r = (kint_t)knh_Array_n(ids, i);
			ranks[i] = (int)r;
			if (r_max < r) r_max = r;
		}
		if (r_max < maxprocs) {
			MPI_Comm_group(MPIC_COMM(comm), &base);
			MPI_Group_incl(base, len, ranks, &newg);
			MPI_Comm_create(MPIC_COMM(comm), newg, &MPIC_COMM(newc));
			MPIC_INITV(newc, MPIC_COMM(newc));
			MPIC_PROC(newc) = strdup(MPIC_PROC(comm)); // to be free
			MPI_Group_free(&newg);
		}
		else {
			KNH_NTHROW2(ctx, sfp, "Script!!", "invalid rank assigned", K_FAILED, KNH_LDATA0);
		}
	}
	RETURN_(newc);
}
