#ifndef QT_COMMON_HPP
#define QT_COMMON_HPP
#include <QtCore>
#include <QtGui>
#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#define getClassTBL(CLASS) lctx->share->ClassTBL[knh_getcid(lctx, STEXT(#CLASS))]
#define new_RawPtrFromClass(CLASS, o) new_RawPtr(lctx, getClassTBL(CLASS), o)
#include <map>
#define new_QRawPtr(lctx, T, v) new_QRawPtr_(lctx, getClassTBL(T), v)

// template<class T>
// inline knh_RawPtr_t *new_QRawPtr(CTX lctx, T *v)
// {
// 	return new_RawPtrFromClass(T, v);
// }

// template<class T>
// inline knh_RawPtr_t *new_QRawPtr(CTX lctx, const T *v)
// {
// 	return new_RawPtrFromClass(T, (void *)v);
// }

// template<class T>
// inline knh_RawPtr_t *new_QRawPtr(CTX lctx, T &v)
// {
// 	T *v_ = new T(v);
// 	return new_RawPtrFromClass(T, v_);
// }

// template<class T>
// inline knh_RawPtr_t *new_QRawPtr(CTX lctx, const T &v)
// {
// 	T *v_ = new T(v);
// 	return new_RawPtrFromClass(T, v_);
// }

template<class T>
inline knh_RawPtr_t *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, T *v)
{
	return new_RawPtr(lctx, ct, v);
//return new_RawPtrFromClass(T, v);
}

template<class T>
inline knh_RawPtr_t *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, const T *v)
{
//return new_RawPtrFromClass(T, (void *)v);
	return new_RawPtr(lctx, ct, (void *)v);
}

template<class T>
inline knh_RawPtr_t *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, T &v)
{
	T *v_ = new T(v);
	return new_RawPtr(lctx, ct, v_);
//return new_RawPtrFromClass(T, v_);
}

template<class T>
inline knh_RawPtr_t *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, const T &v)
{
	T *v_ = new T(v);
//return new_RawPtrFromClass(T, v_);
	return new_RawPtr(lctx, ct, v_);
}

#endif //QT_COMMON_HPP

