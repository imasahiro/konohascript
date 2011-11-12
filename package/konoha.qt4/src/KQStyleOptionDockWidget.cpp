//QStyleOptionDockWidget QStyleOptionDockWidget.new();
KMETHOD QStyleOptionDockWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionDockWidget *ret_v = new KQStyleOptionDockWidget();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionDockWidget QStyleOptionDockWidget.new(QStyleOptionDockWidget other);
KMETHOD QStyleOptionDockWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionDockWidget  other = *RawPtr_to(const QStyleOptionDockWidget *, sfp[1]);
	KQStyleOptionDockWidget *ret_v = new KQStyleOptionDockWidget(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionDockWidget::DummyQStyleOptionDockWidget()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionDockWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionDockWidget::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionDockWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionDockWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionDockWidget::event_map->bigin();
	if ((itr = DummyQStyleOptionDockWidget::event_map->find(str)) == DummyQStyleOptionDockWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionDockWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionDockWidget::slot_map->bigin();
	if ((itr = DummyQStyleOptionDockWidget::slot_map->find(str)) == DummyQStyleOptionDockWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionDockWidget::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionDockWidget::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOption::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionDockWidget::connection(QObject *o)
{
	QStyleOptionDockWidget *p = dynamic_cast<QStyleOptionDockWidget*>(o);
	if (p != NULL) {
	}
	DummyQStyleOption::connection(o);
}

KQStyleOptionDockWidget::KQStyleOptionDockWidget() : QStyleOptionDockWidget()
{
	self = NULL;
	dummy = new DummyQStyleOptionDockWidget();
}

KMETHOD QStyleOptionDockWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionDockWidget *qp = RawPtr_to(KQStyleOptionDockWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionDockWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionDockWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionDockWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionDockWidget *qp = RawPtr_to(KQStyleOptionDockWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionDockWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionDockWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionDockWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionDockWidget *qp = (KQStyleOptionDockWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionDockWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionDockWidget *qp = (KQStyleOptionDockWidget *)p->rawptr;
//		KQStyleOptionDockWidget *qp = static_cast<KQStyleOptionDockWidget*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionDockWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionDockWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionDockWidgetConstInt[] = {
	{"Type", QStyleOptionDockWidget::Type},
	{"Version", QStyleOptionDockWidget::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionDockWidget(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionDockWidgetConstInt);
}


DEFAPI(void) defQStyleOptionDockWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionDockWidget";
	cdef->free = QStyleOptionDockWidget_free;
	cdef->reftrace = QStyleOptionDockWidget_reftrace;
	cdef->compareTo = QStyleOptionDockWidget_compareTo;
}


