//QTimeEdit QTimeEdit.new(QWidget parent);
KMETHOD QTimeEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQTimeEdit *ret_v = new KQTimeEdit(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTimeEdit QTimeEdit.new(QTime time, QWidget parent);
KMETHOD QTimeEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTime  time = *RawPtr_to(const QTime *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQTimeEdit *ret_v = new KQTimeEdit(time, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQTimeEdit::DummyQTimeEdit()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTimeEdit::~DummyQTimeEdit()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTimeEdit::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTimeEdit::self = ptr;
	DummyQDateTimeEdit::setSelf(ptr);
}

bool DummyQTimeEdit::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDateTimeEdit::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTimeEdit::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTimeEdit::event_map->bigin();
	if ((itr = DummyQTimeEdit::event_map->find(str)) == DummyQTimeEdit::event_map->end()) {
		bool ret = false;
		ret = DummyQDateTimeEdit::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTimeEdit::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTimeEdit::slot_map->bigin();
	if ((itr = DummyQTimeEdit::slot_map->find(str)) == DummyQTimeEdit::slot_map->end()) {
		bool ret = false;
		ret = DummyQDateTimeEdit::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTimeEdit::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTimeEdit::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQDateTimeEdit::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTimeEdit::connection(QObject *o)
{
	QTimeEdit *p = dynamic_cast<QTimeEdit*>(o);
	if (p != NULL) {
	}
	DummyQDateTimeEdit::connection(o);
}

KQTimeEdit::KQTimeEdit(QWidget* parent) : QTimeEdit(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTimeEdit();
	dummy->connection((QObject*)this);
}

KQTimeEdit::~KQTimeEdit()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTimeEdit_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTimeEdit *qp = RawPtr_to(KQTimeEdit *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTimeEdit]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTimeEdit]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTimeEdit_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTimeEdit *qp = RawPtr_to(KQTimeEdit *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTimeEdit]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTimeEdit]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTimeEdit_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTimeEdit *qp = (KQTimeEdit *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTimeEdit*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTimeEdit_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTimeEdit *qp = (KQTimeEdit *)p->rawptr;
		KQTimeEdit *qp = static_cast<KQTimeEdit*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTimeEdit_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTimeEdit::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTimeEdit::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTimeEdit::event(event);
		return false;
	}
//	QTimeEdit::event(event);
	return true;
}



DEFAPI(void) defQTimeEdit(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTimeEdit";
	cdef->free = QTimeEdit_free;
	cdef->reftrace = QTimeEdit_reftrace;
	cdef->compareTo = QTimeEdit_compareTo;
}


