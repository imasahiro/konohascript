//@Virtual @Override QVariant QTextBrowser.loadResource(int type, QUrl name);
KMETHOD QTextBrowser_loadResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		int type = Int_to(int, sfp[1]);
		const QUrl  name = *RawPtr_to(const QUrl *, sfp[2]);
		QVariant ret_v = qp->loadResource(type, name);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBrowser QTextBrowser.new(QWidget parent);
KMETHOD QTextBrowser_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQTextBrowser *ret_v = new KQTextBrowser(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTextBrowser.backwardHistoryCount();
KMETHOD QTextBrowser_backwardHistoryCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->backwardHistoryCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextBrowser.clearHistory();
KMETHOD QTextBrowser_clearHistory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		qp->clearHistory();
	}
	RETURNvoid_();
}

//int QTextBrowser.forwardHistoryCount();
KMETHOD QTextBrowser_forwardHistoryCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->forwardHistoryCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTextBrowser.historyTitle(int i);
KMETHOD QTextBrowser_historyTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QString ret_v = qp->historyTitle(i);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QTextBrowser.historyUrl(int i);
KMETHOD QTextBrowser_historyUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QUrl ret_v = qp->historyUrl(i);
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTextBrowser.isBackwardAvailable();
KMETHOD QTextBrowser_isBackwardAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isBackwardAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextBrowser.isForwardAvailable();
KMETHOD QTextBrowser_isForwardAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isForwardAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextBrowser.getOpenExternalLinks();
KMETHOD QTextBrowser_getOpenExternalLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->openExternalLinks();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextBrowser.getOpenLinks();
KMETHOD QTextBrowser_getOpenLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->openLinks();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextBrowser.setOpenExternalLinks(boolean open);
KMETHOD QTextBrowser_setOpenExternalLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		bool open = Boolean_to(bool, sfp[1]);
		qp->setOpenExternalLinks(open);
	}
	RETURNvoid_();
}

//void QTextBrowser.setOpenLinks(boolean open);
KMETHOD QTextBrowser_setOpenLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		bool open = Boolean_to(bool, sfp[1]);
		qp->setOpenLinks(open);
	}
	RETURNvoid_();
}

//QUrl QTextBrowser.getSource();
KMETHOD QTextBrowser_getSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		QUrl ret_v = qp->source();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QTextBrowser.backward();
KMETHOD QTextBrowser_backward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		qp->backward();
	}
	RETURNvoid_();
}

//@Virtual void QTextBrowser.forward();
KMETHOD QTextBrowser_forward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		qp->forward();
	}
	RETURNvoid_();
}

//@Virtual void QTextBrowser.home();
KMETHOD QTextBrowser_home(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		qp->home();
	}
	RETURNvoid_();
}

//@Virtual void QTextBrowser.reload();
KMETHOD QTextBrowser_reload(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		qp->reload();
	}
	RETURNvoid_();
}

//@Virtual void QTextBrowser.setSource(QUrl name);
KMETHOD QTextBrowser_setSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBrowser *  qp = RawPtr_to(QTextBrowser *, sfp[0]);
	if (qp != NULL) {
		const QUrl  name = *RawPtr_to(const QUrl *, sfp[1]);
		qp->setSource(name);
	}
	RETURNvoid_();
}


DummyQTextBrowser::DummyQTextBrowser()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextBrowser::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextBrowser::self = ptr;
	DummyQTextEdit::setSelf(ptr);
}

bool DummyQTextBrowser::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextEdit::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextBrowser::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBrowser::event_map->bigin();
	if ((itr = DummyQTextBrowser::event_map->find(str)) == DummyQTextBrowser::event_map->end()) {
		bool ret;
		ret = DummyQTextEdit::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextBrowser::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBrowser::slot_map->bigin();
	if ((itr = DummyQTextBrowser::event_map->find(str)) == DummyQTextBrowser::slot_map->end()) {
		bool ret;
		ret = DummyQTextEdit::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextBrowser::KQTextBrowser(QWidget* parent) : QTextBrowser(parent)
{
	self = NULL;
}

KMETHOD QTextBrowser_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBrowser *qp = RawPtr_to(KQTextBrowser *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBrowser]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextBrowser::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBrowser]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextBrowser_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBrowser *qp = RawPtr_to(KQTextBrowser *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBrowser]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextBrowser::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBrowser]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextBrowser_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextBrowser *qp = (KQTextBrowser *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextBrowser_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextBrowser *qp = (KQTextBrowser *)p->rawptr;
		(void)qp;
	}
}

static int QTextBrowser_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQTextBrowser::event(QEvent *event)
{
	if (!DummyQTextBrowser::eventDispatcher(event)) {
		QTextBrowser::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTextBrowser(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBrowser";
	cdef->free = QTextBrowser_free;
	cdef->reftrace = QTextBrowser_reftrace;
	cdef->compareTo = QTextBrowser_compareTo;
}


