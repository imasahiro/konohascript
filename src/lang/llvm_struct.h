#ifdef __cplusplus
extern "C" {
#endif
// THIS FILE WAS AUTOMATICALLY GENERATED

static const struct codeasm_field F_KNH_HOBJECT_T[] = {
	{"magicflag", ASMCODE_TYPE_LONG},
	{"cTBL", ASMCODE_TYPE_VOIDPTR},
	{"refckuintptr_t", ASMCODE_TYPE_LONG},
	{"meta", ASMCODE_TYPE_VOIDPTR}
};
#define SIZE_F_KNH_HOBJECT_T 4
static const struct cstruct STRUCT_KNH_HOBJECT_T = {
	"kObjectHeader",
	SIZE_F_KNH_HOBJECT_T,
	F_KNH_HOBJECT_T
};
static const struct codeasm_field F_KNH_OBJECT_T[] = {
	{"h", ASMCODE_TYPE_HOBJECT},
	{"ref", ASMCODE_TYPE_VOIDPTR},
	{"ref2_unused", ASMCODE_TYPE_VOIDPTR},
	{"ref3_unused", ASMCODE_TYPE_VOIDPTR},
	{"ref4_tail", ASMCODE_TYPE_OBJECTPTR}
};
#define SIZE_F_KNH_OBJECT_T 5
static const struct cstruct STRUCT_KNH_OBJECT_T = {
	"kObject",
	SIZE_F_KNH_OBJECT_T,
	F_KNH_OBJECT_T
};
static const struct codeasm_field F_KNH_ARRAY_T[] = {
	{"h", ASMCODE_TYPE_HOBJECT},
	{"nlistkint_t*", ASMCODE_TYPE_VOIDPTR},
	{"size", ASMCODE_TYPE_LONG},
	{"dim", ASMCODE_TYPE_VOIDPTR},
	{"api", ASMCODE_TYPE_VOIDPTR}
};
#define SIZE_F_KNH_ARRAY_T 5
static const struct cstruct STRUCT_KNH_ARRAY_T = {
	"kArray",
	SIZE_F_KNH_ARRAY_T,
	F_KNH_ARRAY_T
};
static const struct codeasm_field F_KNH_OBJECTFIELD_T[] = {
	{"h", ASMCODE_TYPE_HOBJECT},
	{"fields", ASMCODE_TYPE_OBJECTPTRPTR},
	{"smallobject", ASMCODE_TYPE_OBJECTPTR}
};
#define SIZE_F_KNH_OBJECTFIELD_T 3
static const struct cstruct STRUCT_KNH_OBJECTFIELD_T = {
	"kObject",
	SIZE_F_KNH_OBJECTFIELD_T,
	F_KNH_OBJECTFIELD_T
};
static const struct codeasm_field F_KNH_OUTPUTSTREAM_T[] = {
	{"h", ASMCODE_TYPE_HOBJECT},
	{"b", ASMCODE_TYPE_VOIDPTR},
	{"uline", ASMCODE_TYPE_LONG},
	{"dspi", ASMCODE_TYPE_VOIDPTR},
	{"encNULL", ASMCODE_TYPE_VOIDPTR}
};
#define SIZE_F_KNH_OUTPUTSTREAM_T 5
static const struct cstruct STRUCT_KNH_OUTPUTSTREAM_T = {
	"kOutputStream",
	SIZE_F_KNH_OUTPUTSTREAM_T,
	F_KNH_OUTPUTSTREAM_T
};
static const struct codeasm_field F_KNH_INPUTSTREAM_T[] = {
	{"h", ASMCODE_TYPE_HOBJECT},
	{"b", ASMCODE_TYPE_VOIDPTR},
	{"uline", ASMCODE_TYPE_LONG},
	{"dspi", ASMCODE_TYPE_VOIDPTR},
	{"decNULL", ASMCODE_TYPE_VOIDPTR}
};
#define SIZE_F_KNH_INPUTSTREAM_T 5
static const struct cstruct STRUCT_KNH_INPUTSTREAM_T = {
	"kInputStream",
	SIZE_F_KNH_INPUTSTREAM_T,
	F_KNH_INPUTSTREAM_T
};
static const struct codeasm_field F_KNH_SFP_T[] = {
	{"onh_Int_t*", ASMCODE_TYPE_OBJECTPTR},
	{"ndatanh_bool_t", ASMCODE_TYPE_INT64}
};
#define SIZE_F_KNH_SFP_T 2
static const struct cstruct STRUCT_KNH_SFP_T = {
	"ksfp_t",
	SIZE_F_KNH_SFP_T,
	F_KNH_SFP_T
};
static const struct codeasm_field F_KNH_SYSTEMEX_T[] = {
	{"sysid", ASMCODE_TYPE_LONG},
	{"ctxcount", ASMCODE_TYPE_LONG},
	{"props", ASMCODE_TYPE_VOIDPTR},
	{"in", ASMCODE_TYPE_INSPTR},
	{"out", ASMCODE_TYPE_OUSPTR},
	{"err", ASMCODE_TYPE_OUSPTR},
	{"enc", ASMCODE_TYPE_VOIDPTR},
	{"tokenDictSet", ASMCODE_TYPE_VOIDPTR},
	{"nameDictCaseSet", ASMCODE_TYPE_VOIDPTR},
	{"namecapacity", ASMCODE_TYPE_LONG},
	{"nameinfo", ASMCODE_TYPE_VOIDPTR},
	{"urnDictSet", ASMCODE_TYPE_VOIDPTR},
	{"urns", ASMCODE_TYPE_ARRAYPTR},
	{"ClassNameDictSet", ASMCODE_TYPE_VOIDPTR},
	{"EventDictCaseSet", ASMCODE_TYPE_VOIDPTR},
	{"PackageDictMap", ASMCODE_TYPE_VOIDPTR},
	{"URNAliasDictMap", ASMCODE_TYPE_VOIDPTR},
	{"dspiDictSet", ASMCODE_TYPE_VOIDPTR}
};
#define SIZE_F_KNH_SYSTEMEX_T 18
static const struct cstruct STRUCT_KNH_SYSTEMEX_T = {
	"knh_SystemEX_t",
	SIZE_F_KNH_SYSTEMEX_T,
	F_KNH_SYSTEMEX_T
};
static const struct codeasm_field F_KNH_SYSTEM_T[] = {
	{"h", ASMCODE_TYPE_HOBJECT},
	{"b", ASMCODE_TYPE_SYSB}
};
#define SIZE_F_KNH_SYSTEM_T 2
static const struct cstruct STRUCT_KNH_SYSTEM_T = {
	"kSystem",
	SIZE_F_KNH_SYSTEM_T,
	F_KNH_SYSTEM_T
};
static const struct codeasm_field F_KNH_METHOD_T[] = {
	{"h", ASMCODE_TYPE_HOBJECT},
	{"b", ASMCODE_TYPE_VOIDPTR},
	{"cid", ASMCODE_TYPE_SHORT},
	{"mn", ASMCODE_TYPE_SHORT},
	{"fcall_1", ASMCODE_TYPE_FUNCTION},
	{"pc_start", ASMCODE_TYPE_VOIDPTR}
};
#define SIZE_F_KNH_METHOD_T 6
static const struct cstruct STRUCT_KNH_METHOD_T = {
	"kMethod",
	SIZE_F_KNH_METHOD_T,
	F_KNH_METHOD_T
};
static const struct codeasm_field F_KNH_ITERATOR_T[] = {
	{"h", ASMCODE_TYPE_HOBJECT},
	{"b", ASMCODE_TYPE_VOIDPTR},
	{"fnext_1", ASMCODE_TYPE_FUNCTION}
};
#define SIZE_F_KNH_ITERATOR_T 3
static const struct cstruct STRUCT_KNH_ITERATOR_T = {
	"kIterator",
	SIZE_F_KNH_ITERATOR_T,
	F_KNH_ITERATOR_T
};
static const struct codeasm_field F_KNH_CONTEXT_T[] = {
	{"sharekshare_t*", ASMCODE_TYPE_VOIDPTR},
	{"stat", ASMCODE_TYPE_VOIDPTR},
	{"spi", ASMCODE_TYPE_VOIDPTR},
	{"api2", ASMCODE_TYPE_VOIDPTR},
	{"sys", ASMCODE_TYPE_SYSPTR},
	{"script", ASMCODE_TYPE_VOIDPTR},
	{"stack", ASMCODE_TYPE_SFPPTR},
	{"esp", ASMCODE_TYPE_SFPPTR},
	{"stacksize", ASMCODE_TYPE_LONG},
	{"stack_uplimt", ASMCODE_TYPE_SFPPTR},
	{"cstack_bottom", ASMCODE_TYPE_VOIDPTR},
	{"e", ASMCODE_TYPE_VOIDPTR},
	{"freeObjectList", ASMCODE_TYPE_OBJECTPTR},
	{"freeObjectTail", ASMCODE_TYPE_OBJECTPTR},
	{"freeObjectListSize", ASMCODE_TYPE_LONG},
	{"mscheck", ASMCODE_TYPE_LONG},
	{"freeMemoryList", ASMCODE_TYPE_VOIDPTR},
	{"freeMemoryTail", ASMCODE_TYPE_VOIDPTR},
	{"mtdcache", ASMCODE_TYPE_VOIDPTR},
	{"tmrcache", ASMCODE_TYPE_VOIDPTR},
	{"refs", ASMCODE_TYPE_OBJECTPTRPTR},
	{"ref_size", ASMCODE_TYPE_LONG},
	{"ref_buf", ASMCODE_TYPE_OBJECTPTRPTR},
	{"ref_capacity", ASMCODE_TYPE_LONG},
	{"queue", ASMCODE_TYPE_OBJECTPTRPTR},
	{"queue_capacity", ASMCODE_TYPE_LONG},
	{"queue_log2", ASMCODE_TYPE_LONG},
	{"enc", ASMCODE_TYPE_VOIDPTR},
	{"in", ASMCODE_TYPE_INSPTR},
	{"out", ASMCODE_TYPE_OUSPTR},
	{"err", ASMCODE_TYPE_OUSPTR},
	{"bufa", ASMCODE_TYPE_VOIDPTR},
	{"bufw", ASMCODE_TYPE_OUSPTR},
	{"gma", ASMCODE_TYPE_VOIDPTR},
	{"_UNUSED_symbolDictMap", ASMCODE_TYPE_VOIDPTR},
	{"_UNUSED_constPools", ASMCODE_TYPE_VOIDPTR},
	{"flag", ASMCODE_TYPE_SHORT},
	{"ctxid", ASMCODE_TYPE_SHORT},
	{"ctxobjNC", ASMCODE_TYPE_VOIDPTR},
	{"parent", ASMCODE_TYPE_VOIDPTR},
	{"ctxlock", ASMCODE_TYPE_VOIDPTR},
	{"trace", ASMCODE_TYPE_VEC16},
	{"seq", ASMCODE_TYPE_INT64},
	{"ehdrNC", ASMCODE_TYPE_VOIDPTR},
	{"evaled", ASMCODE_TYPE_OBJECTPTR},
	{"signal", ASMCODE_TYPE_VOIDPTR},
	{"siginfo", ASMCODE_TYPE_VOIDPTR},
	{"sighandlers", ASMCODE_TYPE_VOIDPTR}
};
#define SIZE_F_KNH_CONTEXT_T 48
static const struct cstruct STRUCT_KNH_CONTEXT_T = {
	"kcontext_t",
	SIZE_F_KNH_CONTEXT_T,
	F_KNH_CONTEXT_T
};
#ifdef __cplusplus
}
#endif

// THIS FILE WAS AUTOMATICALLY GENERATED. DON'T EDIT.

