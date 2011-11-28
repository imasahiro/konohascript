#ifndef QT_COMMON_HPP
#define QT_COMMON_HPP
#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#include <QtOpenGL/QtOpenGL>
#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#define getClassTBL(CLASS) lctx->share->ClassTBL[knh_getcid(lctx, STEXT(#CLASS))]
#define new_RawPtrFromClass(CLASS, o) new_RawPtr(lctx, getClassTBL(CLASS), o)
#include <map>
#define new_QRawPtr(lctx, T, v) new_QRawPtr_(lctx, getClassTBL(T), v)
#define new_empty_QRawPtr(lctx, T) new_QRawPtr_(lctx, getClassTBL(T), (void*)NULL)
//#define QRawPtrNull_to(T, a) ((((a.p)->rawptr) != NULL) ? (*RawPtr_to(T, a)) : 0)

#define initFlag(NAME, T, a) T NAME;QRawPtrNull_to(NAME, T, a);
#define QRawPtrNull_to(NAME, T, a) if (((a.p)->rawptr) != NULL) { \
(NAME) = *RawPtr_to(T*, a);								          \
} else {														  \
(NAME) = 0;														  \
}

#define G_MAGIC_NUM 39543

// template<class T>
// inline kRawPtr *new_QRawPtr(CTX lctx, T *v)
// {
// 	return new_RawPtrFromClass(T, v);
// }

// template<class T>
// inline kRawPtr *new_QRawPtr(CTX lctx, const T *v)
// {
// 	return new_RawPtrFromClass(T, (void *)v);
// }

// template<class T>
// inline kRawPtr *new_QRawPtr(CTX lctx, T &v)
// {
// 	T *v_ = new T(v);
// 	return new_RawPtrFromClass(T, v_);
// }

// template<class T>
// inline kRawPtr *new_QRawPtr(CTX lctx, const T &v)
// {
// 	T *v_ = new T(v);
// 	return new_RawPtrFromClass(T, v_);
// }

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, T *v)
{
	return new_RawPtr(lctx, ct, v);
//return new_RawPtrFromClass(T, v);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, const T *v)
{
//return new_RawPtrFromClass(T, (void *)v);
	return new_RawPtr(lctx, ct, (void *)v);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, T &v)
{
	T *v_ = new T(v);
	return new_RawPtr(lctx, ct, v_);
//return new_RawPtrFromClass(T, v_);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, const T &v)
{
	T *v_ = new T(v);
//return new_RawPtrFromClass(T, v_);
	return new_RawPtr(lctx, ct, v_);
}

#endif //QT_COMMON_HPP

