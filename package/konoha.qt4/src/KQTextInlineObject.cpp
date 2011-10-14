//QTextInlineObject QTextInlineObject.new(int i, QTextEngine e);
KMETHOD QTextInlineObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int i = Int_to(int, sfp[1]);
	QTextEngine*  e = RawPtr_to(QTextEngine*, sfp[2]);
	KQTextInlineObject *ret_v = new KQTextInlineObject(i, e);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QTextInlineObject.getAscent();
KMETHOD QTextInlineObject_getAscent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->ascent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextInlineObject.getDescent();
KMETHOD QTextInlineObject_getDescent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->descent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QTextFormat QTextInlineObject.fmt();
KMETHOD QTextInlineObject_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		QTextFormat ret_v = qp->format();
		QTextFormat *ret_v_ = new QTextFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextInlineObject.formatIndex();
KMETHOD QTextInlineObject_formatIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->formatIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextInlineObject.height();
KMETHOD QTextInlineObject_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->height();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

////boolean QTextInlineObject.isValid();
KMETHOD QTextInlineObject_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QRectF QTextInlineObject.rect();
KMETHOD QTextInlineObject_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		QRectF ret_v = qp->rect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextInlineObject.setAscent(float a);
KMETHOD QTextInlineObject_setAscent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		qreal a = Float_to(qreal, sfp[1]);
		qp->setAscent(a);
	}
	RETURNvoid_();
}

//void QTextInlineObject.setDescent(float d);
KMETHOD QTextInlineObject_setDescent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		qreal d = Float_to(qreal, sfp[1]);
		qp->setDescent(d);
	}
	RETURNvoid_();
}

//void QTextInlineObject.setWidth(float w);
KMETHOD QTextInlineObject_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		qreal w = Float_to(qreal, sfp[1]);
		qp->setWidth(w);
	}
	RETURNvoid_();
}

//int QTextInlineObject.textDirection();
KMETHOD QTextInlineObject_textDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		Qt::LayoutDirection ret_v = qp->textDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextInlineObject.textPosition();
KMETHOD QTextInlineObject_textPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->textPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextInlineObject.getWidth();
KMETHOD QTextInlineObject_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextInlineObject *  qp = RawPtr_to(QTextInlineObject *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQTextInlineObject::DummyQTextInlineObject()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextInlineObject::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextInlineObject::self = ptr;
}

bool DummyQTextInlineObject::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextInlineObject::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextInlineObject::event_map->bigin();
	if ((itr = DummyQTextInlineObject::event_map->find(str)) == DummyQTextInlineObject::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextInlineObject::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextInlineObject::slot_map->bigin();
	if ((itr = DummyQTextInlineObject::slot_map->find(str)) == DummyQTextInlineObject::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQTextInlineObject::connection(QObject *o)
{
	return;
}

KQTextInlineObject::KQTextInlineObject(int i, QTextEngine* e) : QTextInlineObject(i, e)
{
	self = NULL;
	dummy = new DummyQTextInlineObject();
	dummy->connection((QObject*)this);
}

KMETHOD QTextInlineObject_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextInlineObject *qp = RawPtr_to(KQTextInlineObject *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextInlineObject]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextInlineObject]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextInlineObject_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextInlineObject *qp = RawPtr_to(KQTextInlineObject *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextInlineObject]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextInlineObject]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextInlineObject_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextInlineObject *qp = (KQTextInlineObject *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextInlineObject_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQTextInlineObject *qp = (KQTextInlineObject *)p->rawptr;
		(void)qp;
	}
}

static int QTextInlineObject_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextInlineObject::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQTextInlineObject(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextInlineObject";
	cdef->free = QTextInlineObject_free;
	cdef->reftrace = QTextInlineObject_reftrace;
	cdef->compareTo = QTextInlineObject_compareTo;
}


