#include "../konoha_mpi.h"

/* ------------------------------------------------------------------------ */
//## method void Array.print();

static int idx1(int _x, int _y, int _z, int _w, int x, int xy, int xyz)
{
	return _x;
}

static int idx2(int _x, int _y, int _z, int _w, int x, int xy, int xyz)
{
	return x * _y + _x;
}

static int idx3(int _x, int _y, int _z, int _w, int x, int xy, int xyz)
{
	return xy * _z + x * _y + _x;
}

static int idx4(int _x, int _y, int _z, int _w, int x, int xy, int xyz)
{
	return xyz * _w + xy * _z + x * _y + _x;
}

static void printIA(knh_Array_t *base, int nidx, int _x)
{
	static const char *ifmt[2] = {"%4d", ", %4d"};
	printf(ifmt[(_x == 0)?0:1], base->nlist[nidx]);
}

static void printFA(knh_Array_t *base, int nidx, int _x)
{
	static const char *ffmt[2] = {"%4f", ", %4f"};
	printf(ffmt[(_x == 0)?0:1], base->nlist[nidx]);
}

typedef int (*idx_func)(int _x, int _y, int _z, int _w, int x, int xy, int xyz);
typedef void (*print_func)(knh_Array_t *base, int nidx, int _x);

KMETHOD Array_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *base = sfp[0].a;
	knh_dim_t* dim = (knh_dim_t*)base->dim;
	print_func pfunc = NULL;
	if (IS_IArray(base)) {
		pfunc = printIA;
	} else if (IS_FArray(base)) {
		pfunc = printFA;
	}
	if (pfunc != NULL) {
		int d   = dim->dim;
		int x   = dim->x;
		int xy  = dim->xy;
		int xyz = dim->xyz;
		int y   = xy / x;
		int z   = xyz / xy;
		int w   = knh_Array_size(base) / xyz;
		int _x = 0, _y = 0, _z = 0, _w = 0;
		static idx_func idxN[4] = { idx1, idx2, idx3, idx4 };
		idx_func idx = idxN[d-1];
		do {
			do {
				do {
					do {
						pfunc(base, idx(_x, _y, _z, _w, x, xy, xyz), _x);
					} while (d > 0 && (++_x < x));
				} while (d > 1 && (printf("\n"), _x = 0, ++_y < y));
			} while (d > 2 && (printf("\n"), _y = 0, ++_z < z));
		} while (d > 3 && (printf("\n"), _z = 0, ++_w < w));
		if (d == 1) printf("\n");
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method IArray Array.getShape();

KMETHOD Array_getShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *base = sfp[0].a;
	knh_dim_t* dim = (knh_dim_t*)base->dim;
	int d = dim->dim;
	knh_Array_t *ret = IA_new(d);
	if (d > 0) {
		int x, y, z, w, xy, xyz;
		BEGIN_LOCAL(ctx, lsfp, d);
		x = dim->x;
		lsfp[d-1].ivalue = x;
		if (d > 1) { // dim == 2..
			xy = dim->xy;
			y = xy / x;
			lsfp[d-2].ivalue = y;
			if (d > 2) { // dim == 3..
				xyz = dim->xyz;
				z = dim->xyz / xy;
				lsfp[d-3].ivalue = z;
				if (d > 3) { // dim == 4
					w = knh_Array_size(base) / xyz;
					lsfp[d-4].ivalue = w;
				}
			}
		}
		ret->api->multiadd(ctx, ret, lsfp);
		END_LOCAL(ctx, lsfp);
	}
	RETURN_(ret);
}

/* ------------------------------------------------------------------------ */
//## method void Array.reshape(IArray shape);

KMETHOD Array_reshape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	IA(ia, sfp[0].a);
	IA(dims, sfp[1].a);
	int d = knh_Array_size(dims);
	if (d > 0) {
		knh_dim_t* dim = (knh_dim_t*)ia->dim;
		int len = knh_Array_size(ia);
		size_t *axmuls[3] = { &dim->x, &dim->xy, &dim->xyz };
		int i, t = 1;
		for (i = 1; i <= d; i++) {
			t = t * (int)dims->nlist[d-i];
			if (t > len) break;
			dim->dim = i;
			if (i < 4) *axmuls[i-1] = t;
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method var Array.rows(int start, int end);

KMETHOD Array_rows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *base = sfp[0].a;
	knh_Array_t *ret = base;
	int s = Int_to(int, sfp[1]);
	int e = Int_to(int, sfp[2]);
	knh_class_t retcid = 0; // CLASS_Tvoid
	if (IS_IArray(base)) {
		retcid = CLASS_Int;
	} else if (IS_FArray(base)) {
		retcid = CLASS_Float;
	}
	if (retcid > 0) {
		knh_dim_t *dim = (knh_dim_t*)base->dim;
		int cwidth = dim->x;
		int cmax = dim->xy / cwidth;
		size_t csize = base->dim->wsize * cwidth;
		if (e < cmax) {
			int clen = 1;
			if (s < e) clen += (e - s);
			ret = new_Array(ctx, retcid, clen * cwidth);
			char *from = ((char*)base->list) + (s * csize);
			char *to = (char*)ret->list;
			knh_memcpy(to, from, clen * csize);
			knh_Array_size(ret) = clen * cwidth;
			knh_dim_t *rdim = (knh_dim_t*)ret->dim;
			rdim->dim = 1;
			rdim->x = cwidth;
			if (e > 0) {
				rdim->dim = 2;
				rdim->xy = cwidth * clen;
			}
		}
	}
	RETURN_(ret);
}

/* ------------------------------------------------------------------------ */
//## method var Array.cols(int start, int end);

KMETHOD Array_cols(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *base = sfp[0].a;
	knh_Array_t *ret = base;
	int s = Int_to(int, sfp[1]);
	int e = Int_to(int, sfp[2]);
	knh_class_t retcid = 0; // CLASS_Tvoid
	if (IS_IArray(base)) {
		retcid = CLASS_Int;
	} else if (IS_FArray(base)) {
		retcid = CLASS_Float;
	}
	if (retcid > 0) {
		knh_dim_t *dim = (knh_dim_t*)base->dim;
		int rwidth = dim->x;
		int rmax = dim->xy / rwidth;
		if (e < rmax) {
			int rlen = 1;
			if (s < e) rlen += (e - s);
			ret = new_Array(ctx, retcid, rlen * rwidth);
			size_t wsize = base->dim->wsize;
			size_t rsize = wsize * rlen;
			char *from = (char*)base->list + (s * wsize);
			char *to = (char*)ret->list;
			int r;
			for (r = 0; r < rwidth; r++) {
				knh_memcpy(to, from, rsize);
				from += rwidth * wsize;
				to += rsize;
			}
			knh_Array_size(ret) = rlen * rwidth;
			knh_dim_t *rdim = (knh_dim_t*)ret->dim;
			rdim->dim = 1;
			rdim->x = rlen;
			if (e > 0) {
				rdim->dim = 2;
				rdim->xy = rwidth * rlen;
			}
		}
	}
	RETURN_(ret);
}

/* ------------------------------------------------------------------------ */
//## method var Array.cycle(int rank, int size);

KMETHOD Array_cycle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *base = sfp[0].a;
	knh_Array_t *ret = base;
	int rank = Int_to(int, sfp[1]);
	int size = Int_to(int, sfp[2]);
	knh_class_t retcid = 0; // CLASS_Tvoid
	if (IS_IArray(base)) {
		retcid = CLASS_Int;
	} else if (IS_FArray(base)) {
		retcid = CLASS_Float;
	}
	if (retcid > 0) {
		knh_dim_t *dim = (knh_dim_t*)base->dim;
		int cwidth = dim->x;
		int cmax = dim->xy / cwidth;
		int r, rows = cmax / size;
		size_t csize = base->dim->wsize * cwidth;
		if (rank < cmax) {
			if (cmax % size > rank) rows++;
			ret = new_Array(ctx, retcid, rows * cwidth);
			char *from = ((char*)base->list) + (rank * csize);
			char *to = (char*)ret->list;
			for (r = 0; r < rows; r++) {
				knh_memcpy(to, from, csize);
				knh_Array_size(ret) += cwidth;
				from += (size * csize);
				to += csize;
			}
			knh_dim_t *rdim = (knh_dim_t*)ret->dim;
			rdim->dim = 1;
			rdim->x = cwidth;
			if (rows > 1) {
				rdim->dim = 2;
				rdim->xy = cwidth * rows;
			}
		}
	}
	RETURN_(ret);
}

/* ------------------------------------------------------------------------ */
//## method var Array.trans();

KMETHOD Array_trans(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *base = sfp[0].a;
	knh_Array_t *ret = base;
	knh_class_t retcid = 0; // CLASS_Tvoid
	if (IS_IArray(base)) {
		retcid = CLASS_Int;
	} else if (IS_FArray(base)) {
		retcid = CLASS_Float;
	}
	if (retcid > 0) {
		knh_dim_t *dim = (knh_dim_t*)base->dim;
		if (dim->dim == 2) {
			int cwidth = dim->x;
			int rwidth = dim->xy / cwidth;
			int i, j, n;
			ret = new_Array(ctx, retcid, rwidth * cwidth);
			for (i = 0; i < cwidth; i++) {
				for (j = 0; j < rwidth; j++) {
					n = cwidth * j + i;
					knh_Array_add(ctx, ret, knh_Array_n(base, n));
				}
			}
			knh_dim_t *rdim = (knh_dim_t*)ret->dim;
			rdim->dim = 2;
			rdim->x = rwidth;
			rdim->xy = cwidth * rwidth;
		}
	}
	RETURN_(ret);
}

