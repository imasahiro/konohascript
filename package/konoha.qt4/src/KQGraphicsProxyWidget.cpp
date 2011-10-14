//@Virtual @Override void QGraphicsProxyWidget.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsProxyWidget_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsProxyWidget *  qp = RawPtr_to(QGraphicsProxyWidget *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override void QGraphicsProxyWidget.setGeometry(QRectF rect);
KMETHOD QGraphicsProxyWidget_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsProxyWidget *  qp = RawPtr_to(QGraphicsProxyWidget *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//@Virtual @Override int QGraphicsProxyWidget.type();
KMETHOD QGraphicsProxyWidget_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsProxyWidget *  qp = RawPtr_to(QGraphicsProxyWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsProxyWidget QGraphicsProxyWidget.new(QGraphicsItem parent, int wFlags);
KMETHOD QGraphicsProxyWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	Qt::WindowFlags wFlags = Int_to(Qt::WindowFlags, sfp[2]);
	KQGraphicsProxyWidget *ret_v = new KQGraphicsProxyWidget(parent, wFlags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QGraphicsProxyWidget QGraphicsProxyWidget.createProxyForChildWidget(QWidget child);
KMETHOD QGraphicsProxyWidget_createProxyForChildWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsProxyWidget *  qp = RawPtr_to(QGraphicsProxyWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  child = RawPtr_to(QWidget*, sfp[1]);
		QGraphicsProxyWidget* ret_v = qp->createProxyForChildWidget(child);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsProxyWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsProxyWidget.setWidget(QWidget widget);
KMETHOD QGraphicsProxyWidget_setWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsProxyWidget *  qp = RawPtr_to(QGraphicsProxyWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setWidget(widget);
	}
	RETURNvoid_();
}

//QRectF QGraphicsProxyWidget.subWidgetRect(QWidget widget);
KMETHOD QGraphicsProxyWidget_subWidgetRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsProxyWidget *  qp = RawPtr_to(QGraphicsProxyWidget *, sfp[0]);
	if (qp != NULL) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		QRectF ret_v = qp->subWidgetRect(widget);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QGraphicsProxyWidget.getWidget();
KMETHOD QGraphicsProxyWidget_getWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsProxyWidget *  qp = RawPtr_to(QGraphicsProxyWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGraphicsProxyWidget::DummyQGraphicsProxyWidget()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsProxyWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsProxyWidget::self = ptr;
	DummyQGraphicsWidget::setSelf(ptr);
}

bool DummyQGraphicsProxyWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsProxyWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsProxyWidget::event_map->bigin();
	if ((itr = DummyQGraphicsProxyWidget::event_map->find(str)) == DummyQGraphicsProxyWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsProxyWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsProxyWidget::slot_map->bigin();
	if ((itr = DummyQGraphicsProxyWidget::slot_map->find(str)) == DummyQGraphicsProxyWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQGraphicsProxyWidget::connection(QObject *o)
{
	DummyQGraphicsWidget::connection(o);
}

KQGraphicsProxyWidget::KQGraphicsProxyWidget(QGraphicsItem* parent, Qt::WindowFlags wFlags) : QGraphicsProxyWidget(parent, wFlags)
{
	self = NULL;
	dummy = new DummyQGraphicsProxyWidget();
	dummy->connection((QObject*)this);
}

KMETHOD QGraphicsProxyWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsProxyWidget *qp = RawPtr_to(KQGraphicsProxyWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsProxyWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsProxyWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsProxyWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsProxyWidget *qp = RawPtr_to(KQGraphicsProxyWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsProxyWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsProxyWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsProxyWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsProxyWidget *qp = (KQGraphicsProxyWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsProxyWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQGraphicsProxyWidget *qp = (KQGraphicsProxyWidget *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsProxyWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsProxyWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsProxyWidget::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsProxyWidget::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQGraphicsProxyWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsProxyWidget";
	cdef->free = QGraphicsProxyWidget_free;
	cdef->reftrace = QGraphicsProxyWidget_reftrace;
	cdef->compareTo = QGraphicsProxyWidget_compareTo;
}


