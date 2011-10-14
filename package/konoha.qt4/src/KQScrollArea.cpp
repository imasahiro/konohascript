//@Virtual @Override boolean QScrollArea.focusNextPrevChild(boolean next);
KMETHOD QScrollArea_focusNextPrevChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		bool next = Boolean_to(bool, sfp[1]);
		bool ret_v = qp->focusNextPrevChild(next);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QScrollArea.sizeHint();
KMETHOD QScrollArea_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QScrollArea QScrollArea.new(QWidget parent);
KMETHOD QScrollArea_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQScrollArea *ret_v = new KQScrollArea(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QScrollArea.getAlignment();
KMETHOD QScrollArea_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment ret_v = qp->alignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QScrollArea.ensureVisible(int x, int y, int xmargin, int ymargin);
KMETHOD QScrollArea_ensureVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int xmargin = Int_to(int, sfp[3]);
		int ymargin = Int_to(int, sfp[4]);
		qp->ensureVisible(x, y, xmargin, ymargin);
	}
	RETURNvoid_();
}

//void QScrollArea.ensureWidgetVisible(QWidget childWidget, int xmargin, int ymargin);
KMETHOD QScrollArea_ensureWidgetVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget*  childWidget = RawPtr_to(QWidget*, sfp[1]);
		int xmargin = Int_to(int, sfp[2]);
		int ymargin = Int_to(int, sfp[3]);
		qp->ensureWidgetVisible(childWidget, xmargin, ymargin);
	}
	RETURNvoid_();
}

//void QScrollArea.setAlignment(int arg0);
KMETHOD QScrollArea_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment arg0 = Int_to(Qt::Alignment, sfp[1]);
		qp->setAlignment(arg0);
	}
	RETURNvoid_();
}

//void QScrollArea.setWidget(QWidget widget);
KMETHOD QScrollArea_setWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setWidget(widget);
	}
	RETURNvoid_();
}

//void QScrollArea.setWidgetResizable(boolean resizable);
KMETHOD QScrollArea_setWidgetResizable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		bool resizable = Boolean_to(bool, sfp[1]);
		qp->setWidgetResizable(resizable);
	}
	RETURNvoid_();
}

//QWidget QScrollArea.takeWidget();
KMETHOD QScrollArea_takeWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->takeWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QScrollArea.getWidget();
KMETHOD QScrollArea_getWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QScrollArea.getWidgetResizable();
KMETHOD QScrollArea_getWidgetResizable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollArea *  qp = RawPtr_to(QScrollArea *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->widgetResizable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQScrollArea::DummyQScrollArea()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQScrollArea::setSelf(knh_RawPtr_t *ptr)
{
	DummyQScrollArea::self = ptr;
	DummyQAbstractScrollArea::setSelf(ptr);
}

bool DummyQScrollArea::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractScrollArea::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQScrollArea::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQScrollArea::event_map->bigin();
	if ((itr = DummyQScrollArea::event_map->find(str)) == DummyQScrollArea::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractScrollArea::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQScrollArea::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQScrollArea::slot_map->bigin();
	if ((itr = DummyQScrollArea::slot_map->find(str)) == DummyQScrollArea::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractScrollArea::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQScrollArea::connection(QObject *o)
{
	DummyQAbstractScrollArea::connection(o);
}

KQScrollArea::KQScrollArea(QWidget* parent) : QScrollArea(parent)
{
	self = NULL;
	dummy = new DummyQScrollArea();
	dummy->connection((QObject*)this);
}

KMETHOD QScrollArea_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQScrollArea *qp = RawPtr_to(KQScrollArea *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QScrollArea]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QScrollArea]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QScrollArea_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQScrollArea *qp = RawPtr_to(KQScrollArea *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QScrollArea]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QScrollArea]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QScrollArea_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQScrollArea *qp = (KQScrollArea *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QScrollArea_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQScrollArea *qp = (KQScrollArea *)p->rawptr;
		(void)qp;
	}
}

static int QScrollArea_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQScrollArea::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQScrollArea::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QScrollArea::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQScrollArea(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QScrollArea";
	cdef->free = QScrollArea_free;
	cdef->reftrace = QScrollArea_reftrace;
	cdef->compareTo = QScrollArea_compareTo;
}


