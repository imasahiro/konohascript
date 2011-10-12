//@Virtual @Override void QSizeGrip.setVisible(boolean visible);
KMETHOD QSizeGrip_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeGrip *  qp = RawPtr_to(QSizeGrip *, sfp[0]);
	if (qp != NULL) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QSizeGrip.sizeHint();
KMETHOD QSizeGrip_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizeGrip *  qp = RawPtr_to(QSizeGrip *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSizeGrip QSizeGrip.new(QWidget parent);
KMETHOD QSizeGrip_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQSizeGrip *ret_v = new KQSizeGrip(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQSizeGrip::DummyQSizeGrip()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSizeGrip::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSizeGrip::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQSizeGrip::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSizeGrip::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSizeGrip::event_map->bigin();
	if ((itr = DummyQSizeGrip::event_map->find(str)) == DummyQSizeGrip::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSizeGrip::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSizeGrip::slot_map->bigin();
	if ((itr = DummyQSizeGrip::event_map->find(str)) == DummyQSizeGrip::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSizeGrip::KQSizeGrip(QWidget* parent) : QSizeGrip(parent)
{
	self = NULL;
}

KMETHOD QSizeGrip_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizeGrip *qp = RawPtr_to(KQSizeGrip *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSizeGrip]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQSizeGrip::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSizeGrip]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QSizeGrip_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizeGrip *qp = RawPtr_to(KQSizeGrip *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSizeGrip]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQSizeGrip::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSizeGrip]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSizeGrip_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSizeGrip *qp = (KQSizeGrip *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSizeGrip_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSizeGrip *qp = (KQSizeGrip *)p->rawptr;
		(void)qp;
	}
}

static int QSizeGrip_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQSizeGrip::event(QEvent *event)
{
	if (!DummyQSizeGrip::eventDispatcher(event)) {
		QSizeGrip::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQSizeGrip(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSizeGrip";
	cdef->free = QSizeGrip_free;
	cdef->reftrace = QSizeGrip_reftrace;
	cdef->compareTo = QSizeGrip_compareTo;
}


