#define PKGInt_to(T, I)   ((T) sfp[I].ivalue)
#define PKGFloat_to(T, I) ((T) sfp[I].fvalue)
#define PKGString_to(T, I) ((T) sfp[I].s); assert(0)
#define PKG_Error_to(T, I) ((T)0); assert(0)
#define RETURN_error(V) ((void)V); assert(0)