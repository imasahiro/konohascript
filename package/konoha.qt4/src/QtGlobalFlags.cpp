//## QtAlignment QtAlignment.new(int value);
KMETHOD QtAlignment_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::AlignmentFlag i = Int_to(Qt::AlignmentFlag, sfp[1]);
	Qt::Alignment *ret_v = new Qt::Alignment(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtAlignment QtAlignment.and(int mask);
KMETHOD QtAlignment_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Alignment *qp = RawPtr_to(Qt::Alignment*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::Alignment ret = ((*qp) & i);
		Qt::Alignment *ret_ = new Qt::Alignment(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtAlignment QtAlignment.iand(Qt::QtAlignment other);
KMETHOD QtAlignment_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Alignment *qp = RawPtr_to(Qt::Alignment*, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment *other = RawPtr_to(Qt::Alignment *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtAlignment QtAlignment.or(QtAlignment f);
KMETHOD QtAlignment_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Alignment *qp = RawPtr_to(Qt::Alignment*, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment *f = RawPtr_to(Qt::Alignment*, sfp[1]);
		Qt::Alignment ret = ((*qp) | (*f));
		Qt::Alignment *ret_ = new Qt::Alignment(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtAlignment QtAlignment.ior(Qt::QtAlignment other);
KMETHOD QtAlignment_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Alignment *qp = RawPtr_to(Qt::Alignment*, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment *other = RawPtr_to(Qt::Alignment *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtAlignment QtAlignment.xor(QtAlignment f);
KMETHOD QtAlignment_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Alignment *qp = RawPtr_to(Qt::Alignment*, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment *f = RawPtr_to(Qt::Alignment*, sfp[1]);
		Qt::Alignment ret = ((*qp) ^ (*f));
		Qt::Alignment *ret_ = new Qt::Alignment(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtAlignment QtAlignment.ixor(Qt::QtAlignment other);
KMETHOD QtAlignment_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Alignment *qp = RawPtr_to(Qt::Alignment*, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment *other = RawPtr_to(Qt::Alignment *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtAlignment.testFlag(int flag);
KMETHOD QtAlignment_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Alignment *qp = RawPtr_to(Qt::Alignment *, sfp[0]);
	if (qp != NULL) {
		Qt::AlignmentFlag flag = Int_to(Qt::AlignmentFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtAlignment.value();
KMETHOD QtAlignment_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Alignment *qp = RawPtr_to(Qt::Alignment *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtAlignment_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::Alignment *qp = (Qt::Alignment *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtAlignment_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::Alignment *qp = (Qt::Alignment *)p->rawptr;
		(void)qp;
	}
}

static int QtAlignment_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::Alignment*)p1->rawptr);
//		int v2 = int(*(Qt::Alignment*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::Alignment v1 = *(Qt::Alignment*)p1->rawptr;
		Qt::Alignment v2 = *(Qt::Alignment*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtAlignment(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtAlignment";
	cdef->free = QtAlignment_free;
	cdef->reftrace = QtAlignment_reftrace;
	cdef->compareTo = QtAlignment_compareTo;
}
//## QtDockWidgetAreas QtDockWidgetAreas.new(int value);
KMETHOD QtDockWidgetAreas_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DockWidgetArea i = Int_to(Qt::DockWidgetArea, sfp[1]);
	Qt::DockWidgetAreas *ret_v = new Qt::DockWidgetAreas(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtDockWidgetAreas QtDockWidgetAreas.and(int mask);
KMETHOD QtDockWidgetAreas_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DockWidgetAreas *qp = RawPtr_to(Qt::DockWidgetAreas*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::DockWidgetAreas ret = ((*qp) & i);
		Qt::DockWidgetAreas *ret_ = new Qt::DockWidgetAreas(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDockWidgetAreas QtDockWidgetAreas.iand(Qt::QtDockWidgetAreas other);
KMETHOD QtDockWidgetAreas_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DockWidgetAreas *qp = RawPtr_to(Qt::DockWidgetAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetAreas *other = RawPtr_to(Qt::DockWidgetAreas *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDockWidgetAreas QtDockWidgetAreas.or(QtDockWidgetAreas f);
KMETHOD QtDockWidgetAreas_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::DockWidgetAreas *qp = RawPtr_to(Qt::DockWidgetAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetAreas *f = RawPtr_to(Qt::DockWidgetAreas*, sfp[1]);
		Qt::DockWidgetAreas ret = ((*qp) | (*f));
		Qt::DockWidgetAreas *ret_ = new Qt::DockWidgetAreas(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDockWidgetAreas QtDockWidgetAreas.ior(Qt::QtDockWidgetAreas other);
KMETHOD QtDockWidgetAreas_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DockWidgetAreas *qp = RawPtr_to(Qt::DockWidgetAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetAreas *other = RawPtr_to(Qt::DockWidgetAreas *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDockWidgetAreas QtDockWidgetAreas.xor(QtDockWidgetAreas f);
KMETHOD QtDockWidgetAreas_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::DockWidgetAreas *qp = RawPtr_to(Qt::DockWidgetAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetAreas *f = RawPtr_to(Qt::DockWidgetAreas*, sfp[1]);
		Qt::DockWidgetAreas ret = ((*qp) ^ (*f));
		Qt::DockWidgetAreas *ret_ = new Qt::DockWidgetAreas(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDockWidgetAreas QtDockWidgetAreas.ixor(Qt::QtDockWidgetAreas other);
KMETHOD QtDockWidgetAreas_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DockWidgetAreas *qp = RawPtr_to(Qt::DockWidgetAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetAreas *other = RawPtr_to(Qt::DockWidgetAreas *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtDockWidgetAreas.testFlag(int flag);
KMETHOD QtDockWidgetAreas_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DockWidgetAreas *qp = RawPtr_to(Qt::DockWidgetAreas *, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetArea flag = Int_to(Qt::DockWidgetArea, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtDockWidgetAreas.value();
KMETHOD QtDockWidgetAreas_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DockWidgetAreas *qp = RawPtr_to(Qt::DockWidgetAreas *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtDockWidgetAreas_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::DockWidgetAreas *qp = (Qt::DockWidgetAreas *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtDockWidgetAreas_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::DockWidgetAreas *qp = (Qt::DockWidgetAreas *)p->rawptr;
		(void)qp;
	}
}

static int QtDockWidgetAreas_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::DockWidgetAreas*)p1->rawptr);
//		int v2 = int(*(Qt::DockWidgetAreas*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::DockWidgetAreas v1 = *(Qt::DockWidgetAreas*)p1->rawptr;
		Qt::DockWidgetAreas v2 = *(Qt::DockWidgetAreas*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtDockWidgetAreas(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtDockWidgetAreas";
	cdef->free = QtDockWidgetAreas_free;
	cdef->reftrace = QtDockWidgetAreas_reftrace;
	cdef->compareTo = QtDockWidgetAreas_compareTo;
}
//## QtDropActions QtDropActions.new(int value);
KMETHOD QtDropActions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DropAction i = Int_to(Qt::DropAction, sfp[1]);
	Qt::DropActions *ret_v = new Qt::DropActions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtDropActions QtDropActions.and(int mask);
KMETHOD QtDropActions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DropActions *qp = RawPtr_to(Qt::DropActions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::DropActions ret = ((*qp) & i);
		Qt::DropActions *ret_ = new Qt::DropActions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDropActions QtDropActions.iand(Qt::QtDropActions other);
KMETHOD QtDropActions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DropActions *qp = RawPtr_to(Qt::DropActions*, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions *other = RawPtr_to(Qt::DropActions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDropActions QtDropActions.or(QtDropActions f);
KMETHOD QtDropActions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::DropActions *qp = RawPtr_to(Qt::DropActions*, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions *f = RawPtr_to(Qt::DropActions*, sfp[1]);
		Qt::DropActions ret = ((*qp) | (*f));
		Qt::DropActions *ret_ = new Qt::DropActions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDropActions QtDropActions.ior(Qt::QtDropActions other);
KMETHOD QtDropActions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DropActions *qp = RawPtr_to(Qt::DropActions*, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions *other = RawPtr_to(Qt::DropActions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDropActions QtDropActions.xor(QtDropActions f);
KMETHOD QtDropActions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::DropActions *qp = RawPtr_to(Qt::DropActions*, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions *f = RawPtr_to(Qt::DropActions*, sfp[1]);
		Qt::DropActions ret = ((*qp) ^ (*f));
		Qt::DropActions *ret_ = new Qt::DropActions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtDropActions QtDropActions.ixor(Qt::QtDropActions other);
KMETHOD QtDropActions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DropActions *qp = RawPtr_to(Qt::DropActions*, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions *other = RawPtr_to(Qt::DropActions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtDropActions.testFlag(int flag);
KMETHOD QtDropActions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DropActions *qp = RawPtr_to(Qt::DropActions *, sfp[0]);
	if (qp != NULL) {
		Qt::DropAction flag = Int_to(Qt::DropAction, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtDropActions.value();
KMETHOD QtDropActions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::DropActions *qp = RawPtr_to(Qt::DropActions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtDropActions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::DropActions *qp = (Qt::DropActions *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtDropActions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::DropActions *qp = (Qt::DropActions *)p->rawptr;
		(void)qp;
	}
}

static int QtDropActions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::DropActions*)p1->rawptr);
//		int v2 = int(*(Qt::DropActions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::DropActions v1 = *(Qt::DropActions*)p1->rawptr;
		Qt::DropActions v2 = *(Qt::DropActions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtDropActions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtDropActions";
	cdef->free = QtDropActions_free;
	cdef->reftrace = QtDropActions_reftrace;
	cdef->compareTo = QtDropActions_compareTo;
}
//## QtGestureFlags QtGestureFlags.new(int value);
KMETHOD QtGestureFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::GestureFlag i = Int_to(Qt::GestureFlag, sfp[1]);
	Qt::GestureFlags *ret_v = new Qt::GestureFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtGestureFlags QtGestureFlags.and(int mask);
KMETHOD QtGestureFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::GestureFlags *qp = RawPtr_to(Qt::GestureFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::GestureFlags ret = ((*qp) & i);
		Qt::GestureFlags *ret_ = new Qt::GestureFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtGestureFlags QtGestureFlags.iand(Qt::QtGestureFlags other);
KMETHOD QtGestureFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::GestureFlags *qp = RawPtr_to(Qt::GestureFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::GestureFlags *other = RawPtr_to(Qt::GestureFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtGestureFlags QtGestureFlags.or(QtGestureFlags f);
KMETHOD QtGestureFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::GestureFlags *qp = RawPtr_to(Qt::GestureFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::GestureFlags *f = RawPtr_to(Qt::GestureFlags*, sfp[1]);
		Qt::GestureFlags ret = ((*qp) | (*f));
		Qt::GestureFlags *ret_ = new Qt::GestureFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtGestureFlags QtGestureFlags.ior(Qt::QtGestureFlags other);
KMETHOD QtGestureFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::GestureFlags *qp = RawPtr_to(Qt::GestureFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::GestureFlags *other = RawPtr_to(Qt::GestureFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtGestureFlags QtGestureFlags.xor(QtGestureFlags f);
KMETHOD QtGestureFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::GestureFlags *qp = RawPtr_to(Qt::GestureFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::GestureFlags *f = RawPtr_to(Qt::GestureFlags*, sfp[1]);
		Qt::GestureFlags ret = ((*qp) ^ (*f));
		Qt::GestureFlags *ret_ = new Qt::GestureFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtGestureFlags QtGestureFlags.ixor(Qt::QtGestureFlags other);
KMETHOD QtGestureFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::GestureFlags *qp = RawPtr_to(Qt::GestureFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::GestureFlags *other = RawPtr_to(Qt::GestureFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtGestureFlags.testFlag(int flag);
KMETHOD QtGestureFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::GestureFlags *qp = RawPtr_to(Qt::GestureFlags *, sfp[0]);
	if (qp != NULL) {
		Qt::GestureFlag flag = Int_to(Qt::GestureFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtGestureFlags.value();
KMETHOD QtGestureFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::GestureFlags *qp = RawPtr_to(Qt::GestureFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtGestureFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::GestureFlags *qp = (Qt::GestureFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtGestureFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::GestureFlags *qp = (Qt::GestureFlags *)p->rawptr;
		(void)qp;
	}
}

static int QtGestureFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::GestureFlags*)p1->rawptr);
//		int v2 = int(*(Qt::GestureFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::GestureFlags v1 = *(Qt::GestureFlags*)p1->rawptr;
		Qt::GestureFlags v2 = *(Qt::GestureFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtGestureFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtGestureFlags";
	cdef->free = QtGestureFlags_free;
	cdef->reftrace = QtGestureFlags_reftrace;
	cdef->compareTo = QtGestureFlags_compareTo;
}
//## QtImageConversionFlags QtImageConversionFlags.new(int value);
KMETHOD QtImageConversionFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ImageConversionFlag i = Int_to(Qt::ImageConversionFlag, sfp[1]);
	Qt::ImageConversionFlags *ret_v = new Qt::ImageConversionFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtImageConversionFlags QtImageConversionFlags.and(int mask);
KMETHOD QtImageConversionFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ImageConversionFlags *qp = RawPtr_to(Qt::ImageConversionFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::ImageConversionFlags ret = ((*qp) & i);
		Qt::ImageConversionFlags *ret_ = new Qt::ImageConversionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtImageConversionFlags QtImageConversionFlags.iand(Qt::QtImageConversionFlags other);
KMETHOD QtImageConversionFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ImageConversionFlags *qp = RawPtr_to(Qt::ImageConversionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ImageConversionFlags *other = RawPtr_to(Qt::ImageConversionFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtImageConversionFlags QtImageConversionFlags.or(QtImageConversionFlags f);
KMETHOD QtImageConversionFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::ImageConversionFlags *qp = RawPtr_to(Qt::ImageConversionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ImageConversionFlags *f = RawPtr_to(Qt::ImageConversionFlags*, sfp[1]);
		Qt::ImageConversionFlags ret = ((*qp) | (*f));
		Qt::ImageConversionFlags *ret_ = new Qt::ImageConversionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtImageConversionFlags QtImageConversionFlags.ior(Qt::QtImageConversionFlags other);
KMETHOD QtImageConversionFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ImageConversionFlags *qp = RawPtr_to(Qt::ImageConversionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ImageConversionFlags *other = RawPtr_to(Qt::ImageConversionFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtImageConversionFlags QtImageConversionFlags.xor(QtImageConversionFlags f);
KMETHOD QtImageConversionFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::ImageConversionFlags *qp = RawPtr_to(Qt::ImageConversionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ImageConversionFlags *f = RawPtr_to(Qt::ImageConversionFlags*, sfp[1]);
		Qt::ImageConversionFlags ret = ((*qp) ^ (*f));
		Qt::ImageConversionFlags *ret_ = new Qt::ImageConversionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtImageConversionFlags QtImageConversionFlags.ixor(Qt::QtImageConversionFlags other);
KMETHOD QtImageConversionFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ImageConversionFlags *qp = RawPtr_to(Qt::ImageConversionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ImageConversionFlags *other = RawPtr_to(Qt::ImageConversionFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtImageConversionFlags.testFlag(int flag);
KMETHOD QtImageConversionFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ImageConversionFlags *qp = RawPtr_to(Qt::ImageConversionFlags *, sfp[0]);
	if (qp != NULL) {
		Qt::ImageConversionFlag flag = Int_to(Qt::ImageConversionFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtImageConversionFlags.value();
KMETHOD QtImageConversionFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ImageConversionFlags *qp = RawPtr_to(Qt::ImageConversionFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtImageConversionFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::ImageConversionFlags *qp = (Qt::ImageConversionFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtImageConversionFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::ImageConversionFlags *qp = (Qt::ImageConversionFlags *)p->rawptr;
		(void)qp;
	}
}

static int QtImageConversionFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::ImageConversionFlags*)p1->rawptr);
//		int v2 = int(*(Qt::ImageConversionFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::ImageConversionFlags v1 = *(Qt::ImageConversionFlags*)p1->rawptr;
		Qt::ImageConversionFlags v2 = *(Qt::ImageConversionFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtImageConversionFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtImageConversionFlags";
	cdef->free = QtImageConversionFlags_free;
	cdef->reftrace = QtImageConversionFlags_reftrace;
	cdef->compareTo = QtImageConversionFlags_compareTo;
}
//## QtInputMethodHints QtInputMethodHints.new(int value);
KMETHOD QtInputMethodHints_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::InputMethodHint i = Int_to(Qt::InputMethodHint, sfp[1]);
	Qt::InputMethodHints *ret_v = new Qt::InputMethodHints(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtInputMethodHints QtInputMethodHints.and(int mask);
KMETHOD QtInputMethodHints_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::InputMethodHints *qp = RawPtr_to(Qt::InputMethodHints*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::InputMethodHints ret = ((*qp) & i);
		Qt::InputMethodHints *ret_ = new Qt::InputMethodHints(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtInputMethodHints QtInputMethodHints.iand(Qt::QtInputMethodHints other);
KMETHOD QtInputMethodHints_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::InputMethodHints *qp = RawPtr_to(Qt::InputMethodHints*, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodHints *other = RawPtr_to(Qt::InputMethodHints *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtInputMethodHints QtInputMethodHints.or(QtInputMethodHints f);
KMETHOD QtInputMethodHints_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::InputMethodHints *qp = RawPtr_to(Qt::InputMethodHints*, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodHints *f = RawPtr_to(Qt::InputMethodHints*, sfp[1]);
		Qt::InputMethodHints ret = ((*qp) | (*f));
		Qt::InputMethodHints *ret_ = new Qt::InputMethodHints(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtInputMethodHints QtInputMethodHints.ior(Qt::QtInputMethodHints other);
KMETHOD QtInputMethodHints_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::InputMethodHints *qp = RawPtr_to(Qt::InputMethodHints*, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodHints *other = RawPtr_to(Qt::InputMethodHints *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtInputMethodHints QtInputMethodHints.xor(QtInputMethodHints f);
KMETHOD QtInputMethodHints_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::InputMethodHints *qp = RawPtr_to(Qt::InputMethodHints*, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodHints *f = RawPtr_to(Qt::InputMethodHints*, sfp[1]);
		Qt::InputMethodHints ret = ((*qp) ^ (*f));
		Qt::InputMethodHints *ret_ = new Qt::InputMethodHints(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtInputMethodHints QtInputMethodHints.ixor(Qt::QtInputMethodHints other);
KMETHOD QtInputMethodHints_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::InputMethodHints *qp = RawPtr_to(Qt::InputMethodHints*, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodHints *other = RawPtr_to(Qt::InputMethodHints *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtInputMethodHints.testFlag(int flag);
KMETHOD QtInputMethodHints_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::InputMethodHints *qp = RawPtr_to(Qt::InputMethodHints *, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodHint flag = Int_to(Qt::InputMethodHint, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtInputMethodHints.value();
KMETHOD QtInputMethodHints_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::InputMethodHints *qp = RawPtr_to(Qt::InputMethodHints *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtInputMethodHints_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::InputMethodHints *qp = (Qt::InputMethodHints *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtInputMethodHints_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::InputMethodHints *qp = (Qt::InputMethodHints *)p->rawptr;
		(void)qp;
	}
}

static int QtInputMethodHints_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::InputMethodHints*)p1->rawptr);
//		int v2 = int(*(Qt::InputMethodHints*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::InputMethodHints v1 = *(Qt::InputMethodHints*)p1->rawptr;
		Qt::InputMethodHints v2 = *(Qt::InputMethodHints*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtInputMethodHints(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtInputMethodHints";
	cdef->free = QtInputMethodHints_free;
	cdef->reftrace = QtInputMethodHints_reftrace;
	cdef->compareTo = QtInputMethodHints_compareTo;
}
//## QtItemFlags QtItemFlags.new(int value);
KMETHOD QtItemFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ItemFlag i = Int_to(Qt::ItemFlag, sfp[1]);
	Qt::ItemFlags *ret_v = new Qt::ItemFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtItemFlags QtItemFlags.and(int mask);
KMETHOD QtItemFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ItemFlags *qp = RawPtr_to(Qt::ItemFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::ItemFlags ret = ((*qp) & i);
		Qt::ItemFlags *ret_ = new Qt::ItemFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtItemFlags QtItemFlags.iand(Qt::QtItemFlags other);
KMETHOD QtItemFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ItemFlags *qp = RawPtr_to(Qt::ItemFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ItemFlags *other = RawPtr_to(Qt::ItemFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtItemFlags QtItemFlags.or(QtItemFlags f);
KMETHOD QtItemFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::ItemFlags *qp = RawPtr_to(Qt::ItemFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ItemFlags *f = RawPtr_to(Qt::ItemFlags*, sfp[1]);
		Qt::ItemFlags ret = ((*qp) | (*f));
		Qt::ItemFlags *ret_ = new Qt::ItemFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtItemFlags QtItemFlags.ior(Qt::QtItemFlags other);
KMETHOD QtItemFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ItemFlags *qp = RawPtr_to(Qt::ItemFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ItemFlags *other = RawPtr_to(Qt::ItemFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtItemFlags QtItemFlags.xor(QtItemFlags f);
KMETHOD QtItemFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::ItemFlags *qp = RawPtr_to(Qt::ItemFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ItemFlags *f = RawPtr_to(Qt::ItemFlags*, sfp[1]);
		Qt::ItemFlags ret = ((*qp) ^ (*f));
		Qt::ItemFlags *ret_ = new Qt::ItemFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtItemFlags QtItemFlags.ixor(Qt::QtItemFlags other);
KMETHOD QtItemFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ItemFlags *qp = RawPtr_to(Qt::ItemFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::ItemFlags *other = RawPtr_to(Qt::ItemFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtItemFlags.testFlag(int flag);
KMETHOD QtItemFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ItemFlags *qp = RawPtr_to(Qt::ItemFlags *, sfp[0]);
	if (qp != NULL) {
		Qt::ItemFlag flag = Int_to(Qt::ItemFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtItemFlags.value();
KMETHOD QtItemFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ItemFlags *qp = RawPtr_to(Qt::ItemFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtItemFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::ItemFlags *qp = (Qt::ItemFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtItemFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::ItemFlags *qp = (Qt::ItemFlags *)p->rawptr;
		(void)qp;
	}
}

static int QtItemFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::ItemFlags*)p1->rawptr);
//		int v2 = int(*(Qt::ItemFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::ItemFlags v1 = *(Qt::ItemFlags*)p1->rawptr;
		Qt::ItemFlags v2 = *(Qt::ItemFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtItemFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtItemFlags";
	cdef->free = QtItemFlags_free;
	cdef->reftrace = QtItemFlags_reftrace;
	cdef->compareTo = QtItemFlags_compareTo;
}
//## QtKeyboardModifiers QtKeyboardModifiers.new(int value);
KMETHOD QtKeyboardModifiers_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::KeyboardModifier i = Int_to(Qt::KeyboardModifier, sfp[1]);
	Qt::KeyboardModifiers *ret_v = new Qt::KeyboardModifiers(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtKeyboardModifiers QtKeyboardModifiers.and(int mask);
KMETHOD QtKeyboardModifiers_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::KeyboardModifiers *qp = RawPtr_to(Qt::KeyboardModifiers*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::KeyboardModifiers ret = ((*qp) & i);
		Qt::KeyboardModifiers *ret_ = new Qt::KeyboardModifiers(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtKeyboardModifiers QtKeyboardModifiers.iand(Qt::QtKeyboardModifiers other);
KMETHOD QtKeyboardModifiers_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::KeyboardModifiers *qp = RawPtr_to(Qt::KeyboardModifiers*, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifiers *other = RawPtr_to(Qt::KeyboardModifiers *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtKeyboardModifiers QtKeyboardModifiers.or(QtKeyboardModifiers f);
KMETHOD QtKeyboardModifiers_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::KeyboardModifiers *qp = RawPtr_to(Qt::KeyboardModifiers*, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifiers *f = RawPtr_to(Qt::KeyboardModifiers*, sfp[1]);
		Qt::KeyboardModifiers ret = ((*qp) | (*f));
		Qt::KeyboardModifiers *ret_ = new Qt::KeyboardModifiers(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtKeyboardModifiers QtKeyboardModifiers.ior(Qt::QtKeyboardModifiers other);
KMETHOD QtKeyboardModifiers_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::KeyboardModifiers *qp = RawPtr_to(Qt::KeyboardModifiers*, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifiers *other = RawPtr_to(Qt::KeyboardModifiers *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtKeyboardModifiers QtKeyboardModifiers.xor(QtKeyboardModifiers f);
KMETHOD QtKeyboardModifiers_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::KeyboardModifiers *qp = RawPtr_to(Qt::KeyboardModifiers*, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifiers *f = RawPtr_to(Qt::KeyboardModifiers*, sfp[1]);
		Qt::KeyboardModifiers ret = ((*qp) ^ (*f));
		Qt::KeyboardModifiers *ret_ = new Qt::KeyboardModifiers(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtKeyboardModifiers QtKeyboardModifiers.ixor(Qt::QtKeyboardModifiers other);
KMETHOD QtKeyboardModifiers_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::KeyboardModifiers *qp = RawPtr_to(Qt::KeyboardModifiers*, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifiers *other = RawPtr_to(Qt::KeyboardModifiers *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtKeyboardModifiers.testFlag(int flag);
KMETHOD QtKeyboardModifiers_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::KeyboardModifiers *qp = RawPtr_to(Qt::KeyboardModifiers *, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifier flag = Int_to(Qt::KeyboardModifier, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtKeyboardModifiers.value();
KMETHOD QtKeyboardModifiers_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::KeyboardModifiers *qp = RawPtr_to(Qt::KeyboardModifiers *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtKeyboardModifiers_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::KeyboardModifiers *qp = (Qt::KeyboardModifiers *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtKeyboardModifiers_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::KeyboardModifiers *qp = (Qt::KeyboardModifiers *)p->rawptr;
		(void)qp;
	}
}

static int QtKeyboardModifiers_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::KeyboardModifiers*)p1->rawptr);
//		int v2 = int(*(Qt::KeyboardModifiers*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::KeyboardModifiers v1 = *(Qt::KeyboardModifiers*)p1->rawptr;
		Qt::KeyboardModifiers v2 = *(Qt::KeyboardModifiers*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtKeyboardModifiers(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtKeyboardModifiers";
	cdef->free = QtKeyboardModifiers_free;
	cdef->reftrace = QtKeyboardModifiers_reftrace;
	cdef->compareTo = QtKeyboardModifiers_compareTo;
}
//## QtMatchFlags QtMatchFlags.new(int value);
KMETHOD QtMatchFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MatchFlag i = Int_to(Qt::MatchFlag, sfp[1]);
	Qt::MatchFlags *ret_v = new Qt::MatchFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtMatchFlags QtMatchFlags.and(int mask);
KMETHOD QtMatchFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MatchFlags *qp = RawPtr_to(Qt::MatchFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::MatchFlags ret = ((*qp) & i);
		Qt::MatchFlags *ret_ = new Qt::MatchFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMatchFlags QtMatchFlags.iand(Qt::QtMatchFlags other);
KMETHOD QtMatchFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MatchFlags *qp = RawPtr_to(Qt::MatchFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::MatchFlags *other = RawPtr_to(Qt::MatchFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMatchFlags QtMatchFlags.or(QtMatchFlags f);
KMETHOD QtMatchFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::MatchFlags *qp = RawPtr_to(Qt::MatchFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::MatchFlags *f = RawPtr_to(Qt::MatchFlags*, sfp[1]);
		Qt::MatchFlags ret = ((*qp) | (*f));
		Qt::MatchFlags *ret_ = new Qt::MatchFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMatchFlags QtMatchFlags.ior(Qt::QtMatchFlags other);
KMETHOD QtMatchFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MatchFlags *qp = RawPtr_to(Qt::MatchFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::MatchFlags *other = RawPtr_to(Qt::MatchFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMatchFlags QtMatchFlags.xor(QtMatchFlags f);
KMETHOD QtMatchFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::MatchFlags *qp = RawPtr_to(Qt::MatchFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::MatchFlags *f = RawPtr_to(Qt::MatchFlags*, sfp[1]);
		Qt::MatchFlags ret = ((*qp) ^ (*f));
		Qt::MatchFlags *ret_ = new Qt::MatchFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMatchFlags QtMatchFlags.ixor(Qt::QtMatchFlags other);
KMETHOD QtMatchFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MatchFlags *qp = RawPtr_to(Qt::MatchFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::MatchFlags *other = RawPtr_to(Qt::MatchFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtMatchFlags.testFlag(int flag);
KMETHOD QtMatchFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MatchFlags *qp = RawPtr_to(Qt::MatchFlags *, sfp[0]);
	if (qp != NULL) {
		Qt::MatchFlag flag = Int_to(Qt::MatchFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtMatchFlags.value();
KMETHOD QtMatchFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MatchFlags *qp = RawPtr_to(Qt::MatchFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtMatchFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::MatchFlags *qp = (Qt::MatchFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtMatchFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::MatchFlags *qp = (Qt::MatchFlags *)p->rawptr;
		(void)qp;
	}
}

static int QtMatchFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::MatchFlags*)p1->rawptr);
//		int v2 = int(*(Qt::MatchFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::MatchFlags v1 = *(Qt::MatchFlags*)p1->rawptr;
		Qt::MatchFlags v2 = *(Qt::MatchFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtMatchFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtMatchFlags";
	cdef->free = QtMatchFlags_free;
	cdef->reftrace = QtMatchFlags_reftrace;
	cdef->compareTo = QtMatchFlags_compareTo;
}
//## QtMouseButtons QtMouseButtons.new(int value);
KMETHOD QtMouseButtons_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MouseButton i = Int_to(Qt::MouseButton, sfp[1]);
	Qt::MouseButtons *ret_v = new Qt::MouseButtons(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtMouseButtons QtMouseButtons.and(int mask);
KMETHOD QtMouseButtons_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MouseButtons *qp = RawPtr_to(Qt::MouseButtons*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::MouseButtons ret = ((*qp) & i);
		Qt::MouseButtons *ret_ = new Qt::MouseButtons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMouseButtons QtMouseButtons.iand(Qt::QtMouseButtons other);
KMETHOD QtMouseButtons_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MouseButtons *qp = RawPtr_to(Qt::MouseButtons*, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButtons *other = RawPtr_to(Qt::MouseButtons *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMouseButtons QtMouseButtons.or(QtMouseButtons f);
KMETHOD QtMouseButtons_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::MouseButtons *qp = RawPtr_to(Qt::MouseButtons*, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButtons *f = RawPtr_to(Qt::MouseButtons*, sfp[1]);
		Qt::MouseButtons ret = ((*qp) | (*f));
		Qt::MouseButtons *ret_ = new Qt::MouseButtons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMouseButtons QtMouseButtons.ior(Qt::QtMouseButtons other);
KMETHOD QtMouseButtons_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MouseButtons *qp = RawPtr_to(Qt::MouseButtons*, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButtons *other = RawPtr_to(Qt::MouseButtons *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMouseButtons QtMouseButtons.xor(QtMouseButtons f);
KMETHOD QtMouseButtons_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::MouseButtons *qp = RawPtr_to(Qt::MouseButtons*, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButtons *f = RawPtr_to(Qt::MouseButtons*, sfp[1]);
		Qt::MouseButtons ret = ((*qp) ^ (*f));
		Qt::MouseButtons *ret_ = new Qt::MouseButtons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtMouseButtons QtMouseButtons.ixor(Qt::QtMouseButtons other);
KMETHOD QtMouseButtons_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MouseButtons *qp = RawPtr_to(Qt::MouseButtons*, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButtons *other = RawPtr_to(Qt::MouseButtons *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtMouseButtons.testFlag(int flag);
KMETHOD QtMouseButtons_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MouseButtons *qp = RawPtr_to(Qt::MouseButtons *, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButton flag = Int_to(Qt::MouseButton, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtMouseButtons.value();
KMETHOD QtMouseButtons_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::MouseButtons *qp = RawPtr_to(Qt::MouseButtons *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtMouseButtons_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::MouseButtons *qp = (Qt::MouseButtons *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtMouseButtons_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::MouseButtons *qp = (Qt::MouseButtons *)p->rawptr;
		(void)qp;
	}
}

static int QtMouseButtons_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::MouseButtons*)p1->rawptr);
//		int v2 = int(*(Qt::MouseButtons*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::MouseButtons v1 = *(Qt::MouseButtons*)p1->rawptr;
		Qt::MouseButtons v2 = *(Qt::MouseButtons*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtMouseButtons(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtMouseButtons";
	cdef->free = QtMouseButtons_free;
	cdef->reftrace = QtMouseButtons_reftrace;
	cdef->compareTo = QtMouseButtons_compareTo;
}
//## QtOrientations QtOrientations.new(int value);
KMETHOD QtOrientations_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Orientation i = Int_to(Qt::Orientation, sfp[1]);
	Qt::Orientations *ret_v = new Qt::Orientations(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtOrientations QtOrientations.and(int mask);
KMETHOD QtOrientations_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Orientations *qp = RawPtr_to(Qt::Orientations*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::Orientations ret = ((*qp) & i);
		Qt::Orientations *ret_ = new Qt::Orientations(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtOrientations QtOrientations.iand(Qt::QtOrientations other);
KMETHOD QtOrientations_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Orientations *qp = RawPtr_to(Qt::Orientations*, sfp[0]);
	if (qp != NULL) {
		Qt::Orientations *other = RawPtr_to(Qt::Orientations *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtOrientations QtOrientations.or(QtOrientations f);
KMETHOD QtOrientations_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientations *qp = RawPtr_to(Qt::Orientations*, sfp[0]);
	if (qp != NULL) {
		Qt::Orientations *f = RawPtr_to(Qt::Orientations*, sfp[1]);
		Qt::Orientations ret = ((*qp) | (*f));
		Qt::Orientations *ret_ = new Qt::Orientations(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtOrientations QtOrientations.ior(Qt::QtOrientations other);
KMETHOD QtOrientations_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Orientations *qp = RawPtr_to(Qt::Orientations*, sfp[0]);
	if (qp != NULL) {
		Qt::Orientations *other = RawPtr_to(Qt::Orientations *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtOrientations QtOrientations.xor(QtOrientations f);
KMETHOD QtOrientations_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientations *qp = RawPtr_to(Qt::Orientations*, sfp[0]);
	if (qp != NULL) {
		Qt::Orientations *f = RawPtr_to(Qt::Orientations*, sfp[1]);
		Qt::Orientations ret = ((*qp) ^ (*f));
		Qt::Orientations *ret_ = new Qt::Orientations(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtOrientations QtOrientations.ixor(Qt::QtOrientations other);
KMETHOD QtOrientations_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Orientations *qp = RawPtr_to(Qt::Orientations*, sfp[0]);
	if (qp != NULL) {
		Qt::Orientations *other = RawPtr_to(Qt::Orientations *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtOrientations.testFlag(int flag);
KMETHOD QtOrientations_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Orientations *qp = RawPtr_to(Qt::Orientations *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation flag = Int_to(Qt::Orientation, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtOrientations.value();
KMETHOD QtOrientations_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::Orientations *qp = RawPtr_to(Qt::Orientations *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtOrientations_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::Orientations *qp = (Qt::Orientations *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtOrientations_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::Orientations *qp = (Qt::Orientations *)p->rawptr;
		(void)qp;
	}
}

static int QtOrientations_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::Orientations*)p1->rawptr);
//		int v2 = int(*(Qt::Orientations*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::Orientations v1 = *(Qt::Orientations*)p1->rawptr;
		Qt::Orientations v2 = *(Qt::Orientations*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtOrientations(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtOrientations";
	cdef->free = QtOrientations_free;
	cdef->reftrace = QtOrientations_reftrace;
	cdef->compareTo = QtOrientations_compareTo;
}
//## QtTextInteractionFlags QtTextInteractionFlags.new(int value);
KMETHOD QtTextInteractionFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TextInteractionFlag i = Int_to(Qt::TextInteractionFlag, sfp[1]);
	Qt::TextInteractionFlags *ret_v = new Qt::TextInteractionFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtTextInteractionFlags QtTextInteractionFlags.and(int mask);
KMETHOD QtTextInteractionFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TextInteractionFlags *qp = RawPtr_to(Qt::TextInteractionFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::TextInteractionFlags ret = ((*qp) & i);
		Qt::TextInteractionFlags *ret_ = new Qt::TextInteractionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTextInteractionFlags QtTextInteractionFlags.iand(Qt::QtTextInteractionFlags other);
KMETHOD QtTextInteractionFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TextInteractionFlags *qp = RawPtr_to(Qt::TextInteractionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::TextInteractionFlags *other = RawPtr_to(Qt::TextInteractionFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTextInteractionFlags QtTextInteractionFlags.or(QtTextInteractionFlags f);
KMETHOD QtTextInteractionFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::TextInteractionFlags *qp = RawPtr_to(Qt::TextInteractionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::TextInteractionFlags *f = RawPtr_to(Qt::TextInteractionFlags*, sfp[1]);
		Qt::TextInteractionFlags ret = ((*qp) | (*f));
		Qt::TextInteractionFlags *ret_ = new Qt::TextInteractionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTextInteractionFlags QtTextInteractionFlags.ior(Qt::QtTextInteractionFlags other);
KMETHOD QtTextInteractionFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TextInteractionFlags *qp = RawPtr_to(Qt::TextInteractionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::TextInteractionFlags *other = RawPtr_to(Qt::TextInteractionFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTextInteractionFlags QtTextInteractionFlags.xor(QtTextInteractionFlags f);
KMETHOD QtTextInteractionFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::TextInteractionFlags *qp = RawPtr_to(Qt::TextInteractionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::TextInteractionFlags *f = RawPtr_to(Qt::TextInteractionFlags*, sfp[1]);
		Qt::TextInteractionFlags ret = ((*qp) ^ (*f));
		Qt::TextInteractionFlags *ret_ = new Qt::TextInteractionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTextInteractionFlags QtTextInteractionFlags.ixor(Qt::QtTextInteractionFlags other);
KMETHOD QtTextInteractionFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TextInteractionFlags *qp = RawPtr_to(Qt::TextInteractionFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::TextInteractionFlags *other = RawPtr_to(Qt::TextInteractionFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtTextInteractionFlags.testFlag(int flag);
KMETHOD QtTextInteractionFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TextInteractionFlags *qp = RawPtr_to(Qt::TextInteractionFlags *, sfp[0]);
	if (qp != NULL) {
		Qt::TextInteractionFlag flag = Int_to(Qt::TextInteractionFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtTextInteractionFlags.value();
KMETHOD QtTextInteractionFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TextInteractionFlags *qp = RawPtr_to(Qt::TextInteractionFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtTextInteractionFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::TextInteractionFlags *qp = (Qt::TextInteractionFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtTextInteractionFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::TextInteractionFlags *qp = (Qt::TextInteractionFlags *)p->rawptr;
		(void)qp;
	}
}

static int QtTextInteractionFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::TextInteractionFlags*)p1->rawptr);
//		int v2 = int(*(Qt::TextInteractionFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::TextInteractionFlags v1 = *(Qt::TextInteractionFlags*)p1->rawptr;
		Qt::TextInteractionFlags v2 = *(Qt::TextInteractionFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtTextInteractionFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtTextInteractionFlags";
	cdef->free = QtTextInteractionFlags_free;
	cdef->reftrace = QtTextInteractionFlags_reftrace;
	cdef->compareTo = QtTextInteractionFlags_compareTo;
}
//## QtToolBarAreas QtToolBarAreas.new(int value);
KMETHOD QtToolBarAreas_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ToolBarArea i = Int_to(Qt::ToolBarArea, sfp[1]);
	Qt::ToolBarAreas *ret_v = new Qt::ToolBarAreas(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtToolBarAreas QtToolBarAreas.and(int mask);
KMETHOD QtToolBarAreas_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ToolBarAreas *qp = RawPtr_to(Qt::ToolBarAreas*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::ToolBarAreas ret = ((*qp) & i);
		Qt::ToolBarAreas *ret_ = new Qt::ToolBarAreas(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtToolBarAreas QtToolBarAreas.iand(Qt::QtToolBarAreas other);
KMETHOD QtToolBarAreas_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ToolBarAreas *qp = RawPtr_to(Qt::ToolBarAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarAreas *other = RawPtr_to(Qt::ToolBarAreas *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtToolBarAreas QtToolBarAreas.or(QtToolBarAreas f);
KMETHOD QtToolBarAreas_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::ToolBarAreas *qp = RawPtr_to(Qt::ToolBarAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarAreas *f = RawPtr_to(Qt::ToolBarAreas*, sfp[1]);
		Qt::ToolBarAreas ret = ((*qp) | (*f));
		Qt::ToolBarAreas *ret_ = new Qt::ToolBarAreas(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtToolBarAreas QtToolBarAreas.ior(Qt::QtToolBarAreas other);
KMETHOD QtToolBarAreas_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ToolBarAreas *qp = RawPtr_to(Qt::ToolBarAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarAreas *other = RawPtr_to(Qt::ToolBarAreas *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtToolBarAreas QtToolBarAreas.xor(QtToolBarAreas f);
KMETHOD QtToolBarAreas_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::ToolBarAreas *qp = RawPtr_to(Qt::ToolBarAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarAreas *f = RawPtr_to(Qt::ToolBarAreas*, sfp[1]);
		Qt::ToolBarAreas ret = ((*qp) ^ (*f));
		Qt::ToolBarAreas *ret_ = new Qt::ToolBarAreas(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtToolBarAreas QtToolBarAreas.ixor(Qt::QtToolBarAreas other);
KMETHOD QtToolBarAreas_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ToolBarAreas *qp = RawPtr_to(Qt::ToolBarAreas*, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarAreas *other = RawPtr_to(Qt::ToolBarAreas *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtToolBarAreas.testFlag(int flag);
KMETHOD QtToolBarAreas_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ToolBarAreas *qp = RawPtr_to(Qt::ToolBarAreas *, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarArea flag = Int_to(Qt::ToolBarArea, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtToolBarAreas.value();
KMETHOD QtToolBarAreas_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::ToolBarAreas *qp = RawPtr_to(Qt::ToolBarAreas *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtToolBarAreas_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::ToolBarAreas *qp = (Qt::ToolBarAreas *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtToolBarAreas_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::ToolBarAreas *qp = (Qt::ToolBarAreas *)p->rawptr;
		(void)qp;
	}
}

static int QtToolBarAreas_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::ToolBarAreas*)p1->rawptr);
//		int v2 = int(*(Qt::ToolBarAreas*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::ToolBarAreas v1 = *(Qt::ToolBarAreas*)p1->rawptr;
		Qt::ToolBarAreas v2 = *(Qt::ToolBarAreas*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtToolBarAreas(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtToolBarAreas";
	cdef->free = QtToolBarAreas_free;
	cdef->reftrace = QtToolBarAreas_reftrace;
	cdef->compareTo = QtToolBarAreas_compareTo;
}
//## QtTouchPointStates QtTouchPointStates.new(int value);
KMETHOD QtTouchPointStates_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TouchPointState i = Int_to(Qt::TouchPointState, sfp[1]);
	Qt::TouchPointStates *ret_v = new Qt::TouchPointStates(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtTouchPointStates QtTouchPointStates.and(int mask);
KMETHOD QtTouchPointStates_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TouchPointStates *qp = RawPtr_to(Qt::TouchPointStates*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::TouchPointStates ret = ((*qp) & i);
		Qt::TouchPointStates *ret_ = new Qt::TouchPointStates(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTouchPointStates QtTouchPointStates.iand(Qt::QtTouchPointStates other);
KMETHOD QtTouchPointStates_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TouchPointStates *qp = RawPtr_to(Qt::TouchPointStates*, sfp[0]);
	if (qp != NULL) {
		Qt::TouchPointStates *other = RawPtr_to(Qt::TouchPointStates *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTouchPointStates QtTouchPointStates.or(QtTouchPointStates f);
KMETHOD QtTouchPointStates_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::TouchPointStates *qp = RawPtr_to(Qt::TouchPointStates*, sfp[0]);
	if (qp != NULL) {
		Qt::TouchPointStates *f = RawPtr_to(Qt::TouchPointStates*, sfp[1]);
		Qt::TouchPointStates ret = ((*qp) | (*f));
		Qt::TouchPointStates *ret_ = new Qt::TouchPointStates(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTouchPointStates QtTouchPointStates.ior(Qt::QtTouchPointStates other);
KMETHOD QtTouchPointStates_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TouchPointStates *qp = RawPtr_to(Qt::TouchPointStates*, sfp[0]);
	if (qp != NULL) {
		Qt::TouchPointStates *other = RawPtr_to(Qt::TouchPointStates *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTouchPointStates QtTouchPointStates.xor(QtTouchPointStates f);
KMETHOD QtTouchPointStates_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::TouchPointStates *qp = RawPtr_to(Qt::TouchPointStates*, sfp[0]);
	if (qp != NULL) {
		Qt::TouchPointStates *f = RawPtr_to(Qt::TouchPointStates*, sfp[1]);
		Qt::TouchPointStates ret = ((*qp) ^ (*f));
		Qt::TouchPointStates *ret_ = new Qt::TouchPointStates(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtTouchPointStates QtTouchPointStates.ixor(Qt::QtTouchPointStates other);
KMETHOD QtTouchPointStates_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TouchPointStates *qp = RawPtr_to(Qt::TouchPointStates*, sfp[0]);
	if (qp != NULL) {
		Qt::TouchPointStates *other = RawPtr_to(Qt::TouchPointStates *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtTouchPointStates.testFlag(int flag);
KMETHOD QtTouchPointStates_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TouchPointStates *qp = RawPtr_to(Qt::TouchPointStates *, sfp[0]);
	if (qp != NULL) {
		Qt::TouchPointState flag = Int_to(Qt::TouchPointState, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtTouchPointStates.value();
KMETHOD QtTouchPointStates_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::TouchPointStates *qp = RawPtr_to(Qt::TouchPointStates *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtTouchPointStates_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::TouchPointStates *qp = (Qt::TouchPointStates *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtTouchPointStates_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::TouchPointStates *qp = (Qt::TouchPointStates *)p->rawptr;
		(void)qp;
	}
}

static int QtTouchPointStates_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::TouchPointStates*)p1->rawptr);
//		int v2 = int(*(Qt::TouchPointStates*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::TouchPointStates v1 = *(Qt::TouchPointStates*)p1->rawptr;
		Qt::TouchPointStates v2 = *(Qt::TouchPointStates*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtTouchPointStates(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtTouchPointStates";
	cdef->free = QtTouchPointStates_free;
	cdef->reftrace = QtTouchPointStates_reftrace;
	cdef->compareTo = QtTouchPointStates_compareTo;
}
//## QtWindowFlags QtWindowFlags.new(int value);
KMETHOD QtWindowFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowType i = Int_to(Qt::WindowType, sfp[1]);
	Qt::WindowFlags *ret_v = new Qt::WindowFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtWindowFlags QtWindowFlags.and(int mask);
KMETHOD QtWindowFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowFlags *qp = RawPtr_to(Qt::WindowFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::WindowFlags ret = ((*qp) & i);
		Qt::WindowFlags *ret_ = new Qt::WindowFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowFlags QtWindowFlags.iand(Qt::QtWindowFlags other);
KMETHOD QtWindowFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowFlags *qp = RawPtr_to(Qt::WindowFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowFlags *other = RawPtr_to(Qt::WindowFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowFlags QtWindowFlags.or(QtWindowFlags f);
KMETHOD QtWindowFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::WindowFlags *qp = RawPtr_to(Qt::WindowFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowFlags *f = RawPtr_to(Qt::WindowFlags*, sfp[1]);
		Qt::WindowFlags ret = ((*qp) | (*f));
		Qt::WindowFlags *ret_ = new Qt::WindowFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowFlags QtWindowFlags.ior(Qt::QtWindowFlags other);
KMETHOD QtWindowFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowFlags *qp = RawPtr_to(Qt::WindowFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowFlags *other = RawPtr_to(Qt::WindowFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowFlags QtWindowFlags.xor(QtWindowFlags f);
KMETHOD QtWindowFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::WindowFlags *qp = RawPtr_to(Qt::WindowFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowFlags *f = RawPtr_to(Qt::WindowFlags*, sfp[1]);
		Qt::WindowFlags ret = ((*qp) ^ (*f));
		Qt::WindowFlags *ret_ = new Qt::WindowFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowFlags QtWindowFlags.ixor(Qt::QtWindowFlags other);
KMETHOD QtWindowFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowFlags *qp = RawPtr_to(Qt::WindowFlags*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowFlags *other = RawPtr_to(Qt::WindowFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtWindowFlags.testFlag(int flag);
KMETHOD QtWindowFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowFlags *qp = RawPtr_to(Qt::WindowFlags *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowType flag = Int_to(Qt::WindowType, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtWindowFlags.value();
KMETHOD QtWindowFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowFlags *qp = RawPtr_to(Qt::WindowFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtWindowFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::WindowFlags *qp = (Qt::WindowFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtWindowFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::WindowFlags *qp = (Qt::WindowFlags *)p->rawptr;
		(void)qp;
	}
}

static int QtWindowFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::WindowFlags*)p1->rawptr);
//		int v2 = int(*(Qt::WindowFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::WindowFlags v1 = *(Qt::WindowFlags*)p1->rawptr;
		Qt::WindowFlags v2 = *(Qt::WindowFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return ((v1 & Qt::WindowType_Mask) == (v2 & Qt::WindowType_Mask) ? 0 : 1);

	}
}

DEFAPI(void) defQtWindowFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtWindowFlags";
	cdef->free = QtWindowFlags_free;
	cdef->reftrace = QtWindowFlags_reftrace;
	cdef->compareTo = QtWindowFlags_compareTo;
}
//## QtWindowStates QtWindowStates.new(int value);
KMETHOD QtWindowStates_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowState i = Int_to(Qt::WindowState, sfp[1]);
	Qt::WindowStates *ret_v = new Qt::WindowStates(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QtWindowStates QtWindowStates.and(int mask);
KMETHOD QtWindowStates_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowStates *qp = RawPtr_to(Qt::WindowStates*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		Qt::WindowStates ret = ((*qp) & i);
		Qt::WindowStates *ret_ = new Qt::WindowStates(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowStates QtWindowStates.iand(Qt::QtWindowStates other);
KMETHOD QtWindowStates_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowStates *qp = RawPtr_to(Qt::WindowStates*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowStates *other = RawPtr_to(Qt::WindowStates *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowStates QtWindowStates.or(QtWindowStates f);
KMETHOD QtWindowStates_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::WindowStates *qp = RawPtr_to(Qt::WindowStates*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowStates *f = RawPtr_to(Qt::WindowStates*, sfp[1]);
		Qt::WindowStates ret = ((*qp) | (*f));
		Qt::WindowStates *ret_ = new Qt::WindowStates(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowStates QtWindowStates.ior(Qt::QtWindowStates other);
KMETHOD QtWindowStates_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowStates *qp = RawPtr_to(Qt::WindowStates*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowStates *other = RawPtr_to(Qt::WindowStates *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowStates QtWindowStates.xor(QtWindowStates f);
KMETHOD QtWindowStates_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::WindowStates *qp = RawPtr_to(Qt::WindowStates*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowStates *f = RawPtr_to(Qt::WindowStates*, sfp[1]);
		Qt::WindowStates ret = ((*qp) ^ (*f));
		Qt::WindowStates *ret_ = new Qt::WindowStates(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QtWindowStates QtWindowStates.ixor(Qt::QtWindowStates other);
KMETHOD QtWindowStates_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowStates *qp = RawPtr_to(Qt::WindowStates*, sfp[0]);
	if (qp != NULL) {
		Qt::WindowStates *other = RawPtr_to(Qt::WindowStates *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QtWindowStates.testFlag(int flag);
KMETHOD QtWindowStates_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowStates *qp = RawPtr_to(Qt::WindowStates *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowState flag = Int_to(Qt::WindowState, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QtWindowStates.value();
KMETHOD QtWindowStates_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	Qt::WindowStates *qp = RawPtr_to(Qt::WindowStates *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QtWindowStates_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		Qt::WindowStates *qp = (Qt::WindowStates *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QtWindowStates_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		Qt::WindowStates *qp = (Qt::WindowStates *)p->rawptr;
		(void)qp;
	}
}

static int QtWindowStates_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(Qt::WindowStates*)p1->rawptr);
//		int v2 = int(*(Qt::WindowStates*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		Qt::WindowStates v1 = *(Qt::WindowStates*)p1->rawptr;
		Qt::WindowStates v2 = *(Qt::WindowStates*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQtWindowStates(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QtWindowStates";
	cdef->free = QtWindowStates_free;
	cdef->reftrace = QtWindowStates_reftrace;
	cdef->compareTo = QtWindowStates_compareTo;
}

