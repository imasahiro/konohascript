#ifndef _KNH_ON_T2K
#include "../konoha_mpi.h"
#include <konoha1/konohalang.h>
#else
#include "../../konoha1/konohalang.h"
#endif

#define ArrayMNFunc(X) {MN_##X , __Array_##X}

/* ------------------------------------------------------------------------ */
/* Array Index */

static KMETHOD __Array_new__ARRAY(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = sfp[0].a;
	kint_t init, x = 0, y = 1, z = 1, w = 1;
	size_t dim = knh_stack_argc(ctx, sfp+1);
	switch(dim) {
		case 4: w = sfp[dim-4+1].ivalue;
		case 3: z = sfp[dim-3+1].ivalue;
		case 2: y = sfp[dim-2+1].ivalue;
		case 1: x = sfp[dim-1+1].ivalue;
	}
	init = x * y * z * w;
	DBG_P("x=%d,y=%d,z=%d,w=%d,dim=%d,init=%d",x,y,z,w,dim, init);
	if(0 <= init && init < LONG_MAX) {
		knh_Array_grow(ctx, a, (size_t)init, 0);
		a->size = (size_t)init;
		if(!Array_isNDATA(a)) {
			kclass_t p1 = O_p1(a);
			Object *v = knh_getClassDefaultValue(ctx, p1);
			size_t i;
			for(i = 0; i < a->size; i++) {
				KNH_INITv(a->list[i], v);
			}
		}
	}
	else if(unlikely(init < 0)) {
		THROW_OutOfRange(ctx, sfp, init, 0);
	}
	if(init > 0 && dim > 1) {
		((kdim_t*)a->dim)->dim = dim;
		((kdim_t*)a->dim)->x = (size_t)x;
		((kdim_t*)a->dim)->xy = (size_t)(x * y);
		((kdim_t*)a->dim)->xyz = (size_t)(x * y * z);
	}
	RETURN_(a);
}

static KMETHOD __Array_get2(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = sfp[0].a;
	const kdim_t *dim = a->dim;
	kint_t n = sfp[2].ivalue + (sfp[1].ivalue * dim->x);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

static KMETHOD __Array_get3(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = sfp[0].a;
	const kdim_t *dim = a->dim;
	kint_t n = sfp[3].ivalue + (sfp[2].ivalue * dim->x) + (sfp[1].ivalue * dim->xy);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

static KMETHOD __Array_get4(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = sfp[0].a;
	const kdim_t *dim = a->dim;
	kint_t n = sfp[4].ivalue + (sfp[3].ivalue * dim->x) + (sfp[2].ivalue * dim->xy) + (sfp[1].ivalue * dim->xyz);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

static KMETHOD __Array_set2(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = sfp[0].a;
	const kdim_t *dim = (sfp[0].a)->dim;
	kint_t n = sfp[2].ivalue + (sfp[1].ivalue * dim->x);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+3);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

static KMETHOD __Array_set3(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = sfp[0].a;
	const kdim_t *dim = (sfp[0].a)->dim;
	kint_t n = sfp[3].ivalue + (sfp[2].ivalue * dim->x) + (sfp[1].ivalue * dim->xy);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+4);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

static KMETHOD __Array_set4(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = sfp[0].a;
	const kdim_t *dim = (sfp[0].a)->dim;
	kint_t n = sfp[4].ivalue + (sfp[3].ivalue * dim->x) + (sfp[2].ivalue * dim->xy) + (sfp[1].ivalue * dim->xyz);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+5);
	a->api->fastget(ctx, sfp, n2, K_RIX);
}

typedef struct {
	kmethodn_t mn;
	knh_Fmethod func;
} knh_MNFunc_t;

static const knh_MNFunc_t ARRAY_APIs[] = {
	ArrayMNFunc(new__ARRAY),
	ArrayMNFunc(get2),
	ArrayMNFunc(get3),
	ArrayMNFunc(get4),
	ArrayMNFunc(set2),
	ArrayMNFunc(set3),
	ArrayMNFunc(set4),
	{-1, NULL}
};

void knh_MPI_initArrayFuncData(CTX ctx)
{
	const knh_ClassTBL_t* tbl = ClassTBL(CLASS_Array);
	kArray *methods = tbl->methods;
	int i, len = knh_Array_size(methods);
	for (i = 0; i < len; i++) {
		kMethod *mtd = (kMethod*)knh_Array_n(methods, i);
		kmethodn_t base = mtd->mn;
		const knh_MNFunc_t *nfunc = ARRAY_APIs;
		while (nfunc->mn != -1) {
			if (nfunc->mn == base) {
				mtd->fcall_1 = nfunc->func;
			}
			nfunc++;
		}
	}
}

/* ------------------------------------------------------------------------ */
/* Array Print */

// idx
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

typedef int (*idx_func)(int _x, int _y, int _z, int _w, int x, int xy, int xyz);

static idx_func getIdxFunc(int n)
{
	static idx_func idxN[4] = { idx1, idx2, idx3, idx4 };
	return (n < 5) ? idxN[n-1] : NULL;
}

static void printIA(CTX ctx, kOutputStream *out, kArray *base, size_t len, size_t nidx)
{
	if (nidx < len)
		knh_write_ifmt(ctx, out, KINT_FMT, base->ilist[nidx]);
	else
		knh_putc(ctx, out, '-');
}

static void printFA(CTX ctx, kOutputStream *out, kArray *base, size_t len, size_t nidx)
{
	if (nidx < len)
		knh_write_ffmt(ctx, out, KFLOAT_FMT, base->flist[nidx]);
	else
		knh_putc(ctx, out, '-');
}

static void printOA(CTX ctx, kOutputStream *out, kArray *base, size_t len, size_t nidx)
{
	if (nidx < len)
		knh_write_Object(ctx, out, base->list[nidx], FMT_line);
	else
		knh_putc(ctx, out, '-');
}

typedef void (*print_func)(CTX ctx, kOutputStream *out, kArray *base, size_t len, size_t nidx);

static print_func getPrintFunc(kArray *base)
{
	if (IS_ArrayInt(base))
		return printIA;
	else if (IS_ArrayFloat(base))
		return printFA;
	else
		return printOA;
}

static void knh_MPI_Array_p(CTX ctx, kOutputStream *out, kRawPtr *o, int level)
{
	kArray *base = (kArray*)o;
	kdim_t* dim = (kdim_t*)base->dim;
	int d = dim->dim;
	idx_func f_idx = getIdxFunc(d);
	print_func f_print = getPrintFunc(base);
	if (f_idx != NULL && f_print != NULL) {
		int len = knh_Array_size(base);
		int x   = dim->x;
		int xy  = dim->xy;
		int xyz = dim->xyz;
		int y   = xy / x;
		int z   = xyz / xy;
		int w   = len / xyz;
		int _x, _y, _z, _w, nidx = 0;
		_w = 0;
		PRINT_W:
		_z = 0;
		if (d > 3) knh_printf(ctx, out, "( ");
		PRINT_Z:
		_y = 0;
		if (d > 2) knh_printf(ctx, out, "{ ");
		PRINT_Y:
		_x = 0;
		knh_printf(ctx, out, "[ ");
		PRINT_X:
		nidx = f_idx(_x, _y, _z, _w, x, xy, xyz);
		f_print(ctx, out, base, len, nidx);
		if (d > 0) {
			if (++_x < x) {
				knh_printf(ctx, out, ", ");
				goto PRINT_X;
			}
		}
		knh_printf(ctx, out, " ]");
		if (d > 1) {
			if (++_y < y) {
				knh_putc(ctx, out, '\n');
				if (d == 3)
					knh_printf(ctx, out, "  ");
				else if (d > 3)
					knh_printf(ctx, out, "    ");
				goto PRINT_Y;
			}
		}
		if (d > 2) {
			knh_printf(ctx, out, " }");
			if (++_z < z) {
				knh_putc(ctx, out, '\n');
				if (d > 3)
					knh_printf(ctx, out, "  ");
				goto PRINT_Z;
			}
		}
		if (d > 3) {
			knh_printf(ctx, out, " )");
			if (++_w < w) {
				knh_printf(ctx, out, "\n");
				goto PRINT_W;
			}
		}
	}
}

void knh_MPI_initArrayPrintFunc(CTX ctx)
{
#ifdef K_USING_MACOSX_
	const knh_ClassTBL_t* tbl = ClassTBL(CLASS_Array);
	kclassdef_t *ArrayDef = (kclassdef_t*)tbl->cdef;
	ArrayDef->p = knh_MPI_Array_p;
#endif
}

/* ------------------------------------------------------------------------ */
//## method IArray Array.getShape();

KMETHOD Array_getShape(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *base = sfp[0].a;
	kdim_t* dim = (kdim_t*)base->dim;
	int d = dim->dim;
	kArray *ret = new_Array(ctx, CLASS_Int, d);
	kdim_t *rdim = (kdim_t*)ret->dim;
	rdim->x = d;
	if (d > 0) {
		int x, y, z, w, xy, xyz;
		BEGIN_LOCAL(ctx, lsfp, d);
		x = dim->x;
		lsfp[d-1].ivalue = x;
		if (d > 1) { // dim == 2..
			xy = dim->xy;
			y = xy / x;
			lsfp[d-2].ivalue = y;
		}
		if (d > 2) { // dim == 3..
			xyz = dim->xyz;
			z = dim->xyz / xy;
			lsfp[d-3].ivalue = z;
		}
		if (d > 3) { // dim == 4
			w = knh_Array_size(base) / xyz;
			lsfp[d-4].ivalue = w;
		}
		ret->api->multiadd(ctx, ret, lsfp);
		END_LOCAL(ctx, lsfp);
	}
	RETURN_(ret);
}

/* ------------------------------------------------------------------------ */
//## method void Array.reshape(IArray shape);

KMETHOD Array_reshape(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *base = sfp[0].a;
	kArray *dims = sfp[1].a;
	int d = knh_Array_size(dims);
	if (d > 0 && d < 5) {
		kint_t i, t;
		kdim_t* dim = (kdim_t*)base->dim;
		size_t *axmuls[3] = { &dim->x, &dim->xy, &dim->xyz };
		dim->dim = d;
		for (i = 1, t = 1; i <= d; i++) {
			t = t * (kint_t)knh_Array_n(dims, d-i);
			if (i < 4) *axmuls[i-1] = t;
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method This Array.rows(int start, int end);

KMETHOD Array_rows(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *base = sfp[0].a;
	kArray *ret = base;
	int s = Int_to(int, sfp[1]);
	int e = Int_to(int, sfp[2]);
	if (IS_bArray(base)) {
		kclass_t rcid = O_p1(base);
		kdim_t *dim = (kdim_t*)base->dim;
		int cwidth = dim->x;
		int cmax = dim->xy / cwidth;
		size_t csize = base->dim->wsize * cwidth;
		if (s < cmax && e < cmax) {
			int clen = 1;
			if (s < e) clen += (e - s);
			ret = new_Array(ctx, rcid, clen * cwidth);
			char *from = ((char*)base->list) + (s * csize);
			char *to = (char*)ret->list;
			knh_memcpy(to, from, clen * csize);
			knh_Array_size(ret) = clen * cwidth;
			kdim_t *rdim = (kdim_t*)ret->dim;
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
//## method This Array.cols(int start, int end);

KMETHOD Array_cols(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *base = sfp[0].a;
	kArray *ret = base;
	int s = Int_to(int, sfp[1]);
	int e = Int_to(int, sfp[2]);
	if (IS_bArray(base)) {
		kclass_t rcid = O_p1(base);
		kdim_t *dim = (kdim_t*)base->dim;
		int rwidth = dim->x;
		int rmax = dim->xy / rwidth;
		if (s < rmax && e < rmax) {
			int rlen = 1;
			if (s < e) rlen += (e - s);
			ret = new_Array(ctx, rcid, rlen * rwidth);
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
			kdim_t *rdim = (kdim_t*)ret->dim;
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
//## method This Array.cycle(int rank, int size);

KMETHOD Array_cycle(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *base = sfp[0].a;
	kArray *ret = base;
	int rank = Int_to(int, sfp[1]);
	int size = Int_to(int, sfp[2]);
	if (IS_bArray(base)) {
		kclass_t rcid = O_p1(base);
		kdim_t *dim = (kdim_t*)base->dim;
		int cwidth = dim->x;
		int cmax = dim->xy / cwidth;
		int r, rows = cmax / size;
		size_t csize = base->dim->wsize * cwidth;
		if (rank < cmax) {
			if (cmax % size > rank) rows++;
			ret = new_Array(ctx, rcid, rows * cwidth);
			char *from = ((char*)base->list) + (rank * csize);
			char *to = (char*)ret->list;
			for (r = 0; r < rows; r++) {
				knh_memcpy(to, from, csize);
				knh_Array_size(ret) += cwidth;
				from += (size * csize);
				to += csize;
			}
			kdim_t *rdim = (kdim_t*)ret->dim;
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
//## method This Array.trans();

KMETHOD Array_trans(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *base = sfp[0].a;
	kArray *ret = base;
	if (IS_bArray(base)) {
		kclass_t rcid = O_p1(base);
		kdim_t *dim = (kdim_t*)base->dim;
		if (dim->dim == 2) {
			int len = knh_Array_size(base);
			int cwidth = dim->x;
			int rwidth = dim->xy / cwidth;
			int i, j, n = 0;
			BEGIN_LOCAL(ctx, lsfp, len);
			ret = new_Array(ctx, rcid, len);
			for (i = 0; i < cwidth; i++) {
				for (j = 0; j < rwidth; j++) {
					lsfp[n++].ndata = base->nlist[cwidth * j + i];
				}
			}
			ret->api->multiadd(ctx, ret, lsfp);
			END_LOCAL(ctx, lsfp);
			kdim_t *rdim = (kdim_t*)ret->dim;
			rdim->dim = 2;
			rdim->x = rwidth;
			rdim->xy = cwidth * rwidth;
		}
	}
	RETURN_(ret);
}
