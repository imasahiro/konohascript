//
//@Virtual Array<QAction> QInputContext.actions();
KMETHOD QInputContext_actions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		QList<QAction*> ret_v = qp->actions();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAction"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//@Virtual boolean QInputContext.filterEvent(QEvent event);
KMETHOD QInputContext_filterEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		const QEvent*  event = RawPtr_to(const QEvent*, sfp[1]);
		bool ret_v = qp->filterEvent(event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWidget QInputContext.getFocusWidget();
KMETHOD QInputContext_getFocusWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->focusWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QFont QInputContext.font();
KMETHOD QInputContext_font(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual String QInputContext.identifierName();
KMETHOD QInputContext_identifierName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		QString ret_v = qp->identifierName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QInputContext.isComposing();
KMETHOD QInputContext_isComposing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isComposing();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual String QInputContext.language();
KMETHOD QInputContext_language(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		QString ret_v = qp->language();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QInputContext.mouseHandler(int x, QMouseEvent event);
KMETHOD QInputContext_mouseHandler(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		QMouseEvent*  event = RawPtr_to(QMouseEvent*, sfp[2]);
		qp->mouseHandler(x, event);
	}
	RETURNvoid_();
}

//@Virtual void QInputContext.reset();
KMETHOD QInputContext_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		qp->reset();
	}
	RETURNvoid_();
}

//void QInputContext.sendEvent(QInputMethodEvent event);
KMETHOD QInputContext_sendEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		const QInputMethodEvent  event = *RawPtr_to(const QInputMethodEvent *, sfp[1]);
		qp->sendEvent(event);
	}
	RETURNvoid_();
}

//@Virtual void QInputContext.setFocusWidget(QWidget widget);
KMETHOD QInputContext_setFocusWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setFocusWidget(widget);
	}
	RETURNvoid_();
}

//QTextFormat QInputContext.standardFormat(int s);
KMETHOD QInputContext_standardFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		QInputContext::StandardFormat s = Int_to(QInputContext::StandardFormat, sfp[1]);
		QTextFormat ret_v = qp->standardFormat(s);
		QTextFormat *ret_v_ = new QTextFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QInputContext.update();
KMETHOD QInputContext_update(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		qp->update();
	}
	RETURNvoid_();
}

//@Virtual void QInputContext.widgetDestroyed(QWidget widget);
KMETHOD QInputContext_widgetDestroyed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContext *  qp = RawPtr_to(QInputContext *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->widgetDestroyed(widget);
	}
	RETURNvoid_();
}


DummyQInputContext::DummyQInputContext()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQInputContext::setSelf(knh_RawPtr_t *ptr)
{
	DummyQInputContext::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQInputContext::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQInputContext::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputContext::event_map->bigin();
	if ((itr = DummyQInputContext::event_map->find(str)) == DummyQInputContext::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQInputContext::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputContext::slot_map->bigin();
	if ((itr = DummyQInputContext::slot_map->find(str)) == DummyQInputContext::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQInputContext::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQInputContext::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQInputContext::connection(QObject *o)
{
	QInputContext *p = dynamic_cast<QInputContext*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQInputContext::KQInputContext(QObject* parent) : QInputContext(parent)
{
	self = NULL;
	dummy = new DummyQInputContext();
	dummy->connection((QObject*)this);
}

KMETHOD QInputContext_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputContext *qp = RawPtr_to(KQInputContext *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QInputContext]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputContext]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QInputContext_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputContext *qp = RawPtr_to(KQInputContext *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QInputContext]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputContext]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QInputContext_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQInputContext *qp = (KQInputContext *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QInputContext_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQInputContext *qp = (KQInputContext *)p->rawptr;
//		KQInputContext *qp = static_cast<KQInputContext*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QInputContext_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQInputContext::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQInputContext::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QInputContext::event(event);
		return false;
	}
//	QInputContext::event(event);
	return true;
}

static knh_IntData_t QInputContextConstInt[] = {
	{"PreeditFormat", QInputContext::PreeditFormat},
	{"SelectionFormat", QInputContext::SelectionFormat},
	{NULL, 0}
};

DEFAPI(void) constQInputContext(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QInputContextConstInt);
}


DEFAPI(void) defQInputContext(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QInputContext";
	cdef->free = QInputContext_free;
	cdef->reftrace = QInputContext_reftrace;
	cdef->compareTo = QInputContext_compareTo;
}


