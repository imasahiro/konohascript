#ifndef QT_COMMON_HPP
#define QT_COMMON_HPP
#include <map>
#define new_QRawPtr(lctx, T, v) new_QRawPtr_(lctx, getClassTBL(lctx, T), v)
#define new_empty_QRawPtr(lctx, T) new_QRawPtr_(lctx, getClassTBL(lctx, T), (void*)NULL)
//#define QRawPtrNull_to(T, a) ((((a.p)->rawptr) != NULL) ? (*RawPtr_to(T, a)) : 0)

#define initFlag(NAME, T, a) T NAME;QRawPtrNull_to(NAME, T, a);
#define QRawPtrNull_to(NAME, T, a) if (((a.p)->rawptr) != NULL) { \
(NAME) = *RawPtr_to(T*, a);								          \
} else {														  \
(NAME) = 0;														  \
}

#define G_MAGIC_NUM 39543

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, T *v)
{
	return new_RawPtr(lctx, ct, v);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, const T *v)
{
	return new_RawPtr(lctx, ct, (void *)v);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, T &v)
{
	T *v_ = new T(v);
	return new_RawPtr(lctx, ct, v_);
}

template<class T>
inline kRawPtr *new_QRawPtr_(CTX lctx, const knh_ClassTBL_t *ct, const T &v)
{
	T *v_ = new T(v);
	return new_RawPtr(lctx, ct, v_);
}

#endif //QT_COMMON_HPP

