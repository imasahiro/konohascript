//QSize QSize.new();
KMETHOD QSize_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSize *ret_v = new KQSize();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSize QSize.new(int width, int height);
KMETHOD QSize_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	KQSize *ret_v = new KQSize(width, height);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QSize QSize.boundedTo(QSize otherSize);
KMETHOD QSize_boundedTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		const QSize  otherSize = *RawPtr_to(const QSize *, sfp[1]);
		QSize ret_v = qp->boundedTo(otherSize);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QSize.expandedTo(QSize otherSize);
KMETHOD QSize_expandedTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		const QSize  otherSize = *RawPtr_to(const QSize *, sfp[1]);
		QSize ret_v = qp->expandedTo(otherSize);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSize.getHeight();
KMETHOD QSize_getHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		int ret_v = qp->height();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QSize.isEmpty();
KMETHOD QSize_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSize.rheight();
KMETHOD QSize_rheight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		int ret_v = qp->rheight();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSize.rwidth();
KMETHOD QSize_rwidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		int ret_v = qp->rwidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSize.scale(int width, int height, int mode);
KMETHOD QSize_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		int height = Int_to(int, sfp[2]);
		Qt::AspectRatioMode mode = Int_to(Qt::AspectRatioMode, sfp[3]);
		qp->scale(width, height, mode);
	}
	RETURNvoid_();
}

/*
//void QSize.scale(QSize size, int mode);
KMETHOD QSize_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		Qt::AspectRatioMode mode = Int_to(Qt::AspectRatioMode, sfp[2]);
		qp->scale(size, mode);
	}
	RETURNvoid_();
}
*/
//void QSize.setHeight(int height);
KMETHOD QSize_setHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		int height = Int_to(int, sfp[1]);
		qp->setHeight(height);
	}
	RETURNvoid_();
}

//void QSize.setWidth(int width);
KMETHOD QSize_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}

//void QSize.transpose();
KMETHOD QSize_transpose(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		qp->transpose();
	}
	RETURNvoid_();
}

//int QSize.getWidth();
KMETHOD QSize_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *  qp = RawPtr_to(QSize *, sfp[0]);
	if (qp) {
		int ret_v = qp->width();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QSize.parents();
KMETHOD QSize_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSize *qp = RawPtr_to(QSize*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQSize::DummyQSize()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSize::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSize::self = ptr;
}

bool DummyQSize::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSize::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSize::event_map->bigin();
	if ((itr = DummyQSize::event_map->find(str)) == DummyQSize::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSize::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSize::slot_map->bigin();
	if ((itr = DummyQSize::slot_map->find(str)) == DummyQSize::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQSize::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQSize::connection(QObject *o)
{
	QSize *p = dynamic_cast<QSize*>(o);
	if (p != NULL) {
	}
}

KQSize::KQSize() : QSize()
{
	self = NULL;
	dummy = new DummyQSize();
}

KMETHOD QSize_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSize *qp = RawPtr_to(KQSize *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSize]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSize]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSize_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSize *qp = RawPtr_to(KQSize *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSize]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSize]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSize_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSize *qp = (KQSize *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSize_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSize *qp = (KQSize *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSize_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QSize*>(p1->rawptr) == *static_cast<QSize*>(p2->rawptr) ? 0 : 1);
}

void KQSize::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQSize(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSize";
	cdef->free = QSize_free;
	cdef->reftrace = QSize_reftrace;
	cdef->compareTo = QSize_compareTo;
}


