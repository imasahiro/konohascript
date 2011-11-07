//QTextFrame QTextFrame.new(QTextDocument document);
KMETHOD QTextFrame_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument*  document = RawPtr_to(QTextDocument*, sfp[1]);
	KQTextFrame *ret_v = new KQTextFrame(document);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//Array<QTextFrame> QTextFrame.childFrames();
KMETHOD QTextFrame_childFrames(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame *  qp = RawPtr_to(QTextFrame *, sfp[0]);
	if (qp) {
		QList<QTextFrame*> ret_v = qp->childFrames();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTextFrame"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QTextCursor QTextFrame.firstCursorPosition();
KMETHOD QTextFrame_firstCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame *  qp = RawPtr_to(QTextFrame *, sfp[0]);
	if (qp) {
		QTextCursor ret_v = qp->firstCursorPosition();
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextFrame.firstPosition();
KMETHOD QTextFrame_firstPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame *  qp = RawPtr_to(QTextFrame *, sfp[0]);
	if (qp) {
		int ret_v = qp->firstPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextFrameFormat QTextFrame.getFrameFormat();
KMETHOD QTextFrame_getFrameFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame *  qp = RawPtr_to(QTextFrame *, sfp[0]);
	if (qp) {
		QTextFrameFormat ret_v = qp->frameFormat();
		QTextFrameFormat *ret_v_ = new QTextFrameFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QTextFrame.lastCursorPosition();
KMETHOD QTextFrame_lastCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame *  qp = RawPtr_to(QTextFrame *, sfp[0]);
	if (qp) {
		QTextCursor ret_v = qp->lastCursorPosition();
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextFrame.lastPosition();
KMETHOD QTextFrame_lastPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame *  qp = RawPtr_to(QTextFrame *, sfp[0]);
	if (qp) {
		int ret_v = qp->lastPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextFrame QTextFrame.parentFrame();
KMETHOD QTextFrame_parentFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame *  qp = RawPtr_to(QTextFrame *, sfp[0]);
	if (qp) {
		QTextFrame* ret_v = qp->parentFrame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextFrame.setFrameFormat(QTextFrameFormat fmt);
KMETHOD QTextFrame_setFrameFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame *  qp = RawPtr_to(QTextFrame *, sfp[0]);
	if (qp) {
		const QTextFrameFormat  format = *RawPtr_to(const QTextFrameFormat *, sfp[1]);
		qp->setFrameFormat(format);
	}
	RETURNvoid_();
}


DummyQTextFrame::DummyQTextFrame()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextFrame::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextFrame::self = ptr;
	DummyQTextObject::setSelf(ptr);
}

bool DummyQTextFrame::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextFrame::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextFrame::event_map->bigin();
	if ((itr = DummyQTextFrame::event_map->find(str)) == DummyQTextFrame::event_map->end()) {
		bool ret = false;
		ret = DummyQTextObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextFrame::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextFrame::slot_map->bigin();
	if ((itr = DummyQTextFrame::slot_map->find(str)) == DummyQTextFrame::slot_map->end()) {
		bool ret = false;
		ret = DummyQTextObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextFrame::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQTextObject::reftrace(ctx, p, tail_);
}

void DummyQTextFrame::connection(QObject *o)
{
	QTextFrame *p = dynamic_cast<QTextFrame*>(o);
	if (p != NULL) {
	}
	DummyQTextObject::connection(o);
}

KQTextFrame::KQTextFrame(QTextDocument* document) : QTextFrame(document)
{
	self = NULL;
	dummy = new DummyQTextFrame();
	dummy->connection((QObject*)this);
}

KMETHOD QTextFrame_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFrame *qp = RawPtr_to(KQTextFrame *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextFrame]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextFrame]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextFrame_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFrame *qp = RawPtr_to(KQTextFrame *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextFrame]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextFrame]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextFrame_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextFrame *qp = (KQTextFrame *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextFrame_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextFrame *qp = (KQTextFrame *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextFrame_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextFrame::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTextFrame::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTextFrame::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQTextFrame(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextFrame";
	cdef->free = QTextFrame_free;
	cdef->reftrace = QTextFrame_reftrace;
	cdef->compareTo = QTextFrame_compareTo;
}


