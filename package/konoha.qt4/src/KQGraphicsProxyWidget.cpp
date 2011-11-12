//@Virtual @Override void QGraphicsProxyWidget.setGeometry(QRectF rect);
KMETHOD QGraphicsProxyWidget_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsProxyWidget *  qp = RawPtr_to(QGraphicsProxyWidget *, sfp[0]);
	if (qp) {
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
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsProxyWidget QGraphicsProxyWidget.new(QGraphicsItem parent, QtWindowFlags wFlags);
KMETHOD QGraphicsProxyWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	initFlag(wFlags, Qt::WindowFlags, sfp[2]);
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

// //@Virtual void QGraphicsProxyWidget.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
// KMETHOD QGraphicsProxyWidget_paint(CTX ctx, knh_sfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	KQGraphicsProxyWidget *  qp = RawPtr_to(KQGraphicsProxyWidget *, sfp[0]);
// 	if (qp) {
// 		if (qp->dummy->paint_func != NULL) {
// 			knh_Func_invoke(ctx, qp->dummy->paint_func, sfp, 4);
// 		}
// 	}
// 	RETURNvoid_();
// }

//@Virtual void QGraphicsProxyWidget.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsProxyWidget_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsProxyWidget *  qp = RawPtr_to(KQGraphicsProxyWidget *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

void KQGraphicsProxyWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (dummy->paint_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPainter, painter);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QStyleOptionGraphicsItem, option);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_RawPtr_t *p3 = new_QRawPtr(lctx, QWidget, widget);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, dummy->paint_func, lsfp, 4);
	} else {
		QGraphicsProxyWidget::paint(painter, option, widget);
	}
}

DummyQGraphicsProxyWidget::DummyQGraphicsProxyWidget()
{
	self = NULL;
	paint_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("paint", NULL));
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
		paint_func = (*event_map)["paint"];
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

knh_Object_t** DummyQGraphicsProxyWidget::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsProxyWidget::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGraphicsWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsProxyWidget::connection(QObject *o)
{
	QGraphicsProxyWidget *p = dynamic_cast<QGraphicsProxyWidget*>(o);
	if (p != NULL) {
	}
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
	if (p->rawptr != NULL) {
		KQGraphicsProxyWidget *qp = (KQGraphicsProxyWidget *)p->rawptr;
//		KQGraphicsProxyWidget *qp = static_cast<KQGraphicsProxyWidget*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
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

bool KQGraphicsProxyWidget::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsProxyWidget::sceneEvent(event);
		return false;
	}
//	QGraphicsProxyWidget::sceneEvent(event);
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


