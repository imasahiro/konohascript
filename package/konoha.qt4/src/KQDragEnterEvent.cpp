//QDragEnterEvent QDragEnterEvent.new(QPoint point, int actions, QMimeData data, int buttons, int modifiers);
KMETHOD QDragEnterEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
	Qt::DropActions actions = Int_to(Qt::DropActions, sfp[2]);
	const QMimeData*  data = RawPtr_to(const QMimeData*, sfp[3]);
	Qt::MouseButtons buttons = Int_to(Qt::MouseButtons, sfp[4]);
	Qt::KeyboardModifiers modifiers = Int_to(Qt::KeyboardModifiers, sfp[5]);
	KQDragEnterEvent *ret_v = new KQDragEnterEvent(point, actions, data, buttons, modifiers);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQDragEnterEvent::DummyQDragEnterEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDragEnterEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDragEnterEvent::self = ptr;
	DummyQDragMoveEvent::setSelf(ptr);
}

bool DummyQDragEnterEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDragMoveEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDragEnterEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDragEnterEvent::event_map->bigin();
	if ((itr = DummyQDragEnterEvent::event_map->find(str)) == DummyQDragEnterEvent::event_map->end()) {
		bool ret;
		ret = DummyQDragMoveEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDragEnterEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDragEnterEvent::slot_map->bigin();
	if ((itr = DummyQDragEnterEvent::event_map->find(str)) == DummyQDragEnterEvent::slot_map->end()) {
		bool ret;
		ret = DummyQDragMoveEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQDragEnterEvent::KQDragEnterEvent(const QPoint point, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers) : QDragEnterEvent(point, actions, data, buttons, modifiers)
{
	self = NULL;
}

KMETHOD QDragEnterEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDragEnterEvent *qp = RawPtr_to(KQDragEnterEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDragEnterEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQDragEnterEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDragEnterEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QDragEnterEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDragEnterEvent *qp = RawPtr_to(KQDragEnterEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDragEnterEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQDragEnterEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDragEnterEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDragEnterEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDragEnterEvent *qp = (KQDragEnterEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDragEnterEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQDragEnterEvent *qp = (KQDragEnterEvent *)p->rawptr;
		(void)qp;
	}
}

static int QDragEnterEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQDragEnterEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDragEnterEvent";
	cdef->free = QDragEnterEvent_free;
	cdef->reftrace = QDragEnterEvent_reftrace;
	cdef->compareTo = QDragEnterEvent_compareTo;
}


