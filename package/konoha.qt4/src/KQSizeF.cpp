//QSizeF QSizeF.new();
KMETHOD QSizeF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizeF *ret_v = new KQSizeF();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSizeF QSizeF.new(QSize size);
KMETHOD QSizeF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	KQSizeF *ret_v = new KQSizeF(size);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QSizeF QSizeF.new(float width, float height);
KMETHOD QSizeF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal width = Float_to(qreal, sfp[1]);
	qreal height = Float_to(qreal, sfp[2]);
	KQSizeF *ret_v = new KQSizeF(width, height);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QSizeF QSizeF.boundedTo(QSizeF otherSize);
KMETHOD QSizeF_boundedTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		const QSizeF  otherSize = *RawPtr_to(const QSizeF *, sfp[1]);
		QSizeF ret_v = qp->boundedTo(otherSize);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSizeF QSizeF.expandedTo(QSizeF otherSize);
KMETHOD QSizeF_expandedTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		const QSizeF  otherSize = *RawPtr_to(const QSizeF *, sfp[1]);
		QSizeF ret_v = qp->expandedTo(otherSize);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QSizeF.getHeight();
KMETHOD QSizeF_getHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->height();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QSizeF.isEmpty();
KMETHOD QSizeF_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QSizeF.isNull();
KMETHOD QSizeF_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QSizeF.isValid();
KMETHOD QSizeF_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QSizeF.rheight();
KMETHOD QSizeF_rheight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->rheight();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QSizeF.rwidth();
KMETHOD QSizeF_rwidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->rwidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QSizeF.scale(float width, float height, int mode);
KMETHOD QSizeF_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qreal height = Float_to(qreal, sfp[2]);
		Qt::AspectRatioMode mode = Int_to(Qt::AspectRatioMode, sfp[3]);
		qp->scale(width, height, mode);
	}
	RETURNvoid_();
}

/*
//void QSizeF.scale(QSizeF size, int mode);
KMETHOD QSizeF_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[1]);
		Qt::AspectRatioMode mode = Int_to(Qt::AspectRatioMode, sfp[2]);
		qp->scale(size, mode);
	}
	RETURNvoid_();
}
*/
//void QSizeF.setHeight(float height);
KMETHOD QSizeF_setHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		qreal height = Float_to(qreal, sfp[1]);
		qp->setHeight(height);
	}
	RETURNvoid_();
}

//void QSizeF.setWidth(float width);
KMETHOD QSizeF_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}

//QSize QSizeF.toSize();
KMETHOD QSizeF_toSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->toSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QSizeF.transpose();
KMETHOD QSizeF_transpose(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		qp->transpose();
	}
	RETURNvoid_();
}

//float QSizeF.getWidth();
KMETHOD QSizeF_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeF *  qp = RawPtr_to(QSizeF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQSizeF::DummyQSizeF()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSizeF::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSizeF::self = ptr;
}

bool DummyQSizeF::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSizeF::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSizeF::event_map->bigin();
	if ((itr = DummyQSizeF::event_map->find(str)) == DummyQSizeF::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSizeF::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSizeF::slot_map->bigin();
	if ((itr = DummyQSizeF::event_map->find(str)) == DummyQSizeF::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSizeF::KQSizeF() : QSizeF()
{
	self = NULL;
}

KMETHOD QSizeF_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizeF *qp = RawPtr_to(KQSizeF *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSizeF]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQSizeF::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSizeF]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QSizeF_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizeF *qp = RawPtr_to(KQSizeF *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSizeF]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQSizeF::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSizeF]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSizeF_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSizeF *qp = (KQSizeF *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSizeF_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSizeF *qp = (KQSizeF *)p->rawptr;
		(void)qp;
	}
}

static int QSizeF_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQSizeF(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSizeF";
	cdef->free = QSizeF_free;
	cdef->reftrace = QSizeF_reftrace;
	cdef->compareTo = QSizeF_compareTo;
}


