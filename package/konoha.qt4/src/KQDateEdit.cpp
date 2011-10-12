//QDateEdit QDateEdit.new(QWidget parent);
KMETHOD QDateEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQDateEdit *ret_v = new KQDateEdit(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDateEdit QDateEdit.new(QDate date, QWidget parent);
KMETHOD QDateEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQDateEdit *ret_v = new KQDateEdit(date, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQDateEdit::DummyQDateEdit()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDateEdit::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDateEdit::self = ptr;
	DummyQDateTimeEdit::setSelf(ptr);
}

bool DummyQDateEdit::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDateTimeEdit::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDateEdit::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDateEdit::event_map->bigin();
	if ((itr = DummyQDateEdit::event_map->find(str)) == DummyQDateEdit::event_map->end()) {
		bool ret;
		ret = DummyQDateTimeEdit::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDateEdit::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDateEdit::slot_map->bigin();
	if ((itr = DummyQDateEdit::event_map->find(str)) == DummyQDateEdit::slot_map->end()) {
		bool ret;
		ret = DummyQDateTimeEdit::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQDateEdit::KQDateEdit(QWidget* parent) : QDateEdit(parent)
{
	self = NULL;
}

KMETHOD QDateEdit_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDateEdit *qp = RawPtr_to(KQDateEdit *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDateEdit]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQDateEdit::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDateEdit]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QDateEdit_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDateEdit *qp = RawPtr_to(KQDateEdit *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDateEdit]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQDateEdit::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDateEdit]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDateEdit_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDateEdit *qp = (KQDateEdit *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDateEdit_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQDateEdit *qp = (KQDateEdit *)p->rawptr;
		(void)qp;
	}
}

static int QDateEdit_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQDateEdit::event(QEvent *event)
{
	if (!DummyQDateEdit::eventDispatcher(event)) {
		QDateEdit::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQDateEdit(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDateEdit";
	cdef->free = QDateEdit_free;
	cdef->reftrace = QDateEdit_reftrace;
	cdef->compareTo = QDateEdit_compareTo;
}


