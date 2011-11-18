//QDateEdit QDateEdit.new(QWidget parent);
KMETHOD QDateEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQDateEdit *ret_v = new KQDateEdit(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQDateEdit::DummyQDateEdit()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQDateEdit::~DummyQDateEdit()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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
		bool ret = false;
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
	if ((itr = DummyQDateEdit::slot_map->find(str)) == DummyQDateEdit::slot_map->end()) {
		bool ret = false;
		ret = DummyQDateTimeEdit::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQDateEdit::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDateEdit::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQDateTimeEdit::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQDateEdit::connection(QObject *o)
{
	QDateEdit *p = dynamic_cast<QDateEdit*>(o);
	if (p != NULL) {
	}
	DummyQDateTimeEdit::connection(o);
}

KQDateEdit::KQDateEdit(QWidget* parent) : QDateEdit(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQDateEdit();
	dummy->connection((QObject*)this);
}

KQDateEdit::~KQDateEdit()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDateEdit]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDateEdit_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQDateEdit *qp = (KQDateEdit *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QDateEdit*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QDateEdit_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQDateEdit *qp = (KQDateEdit *)p->rawptr;
		KQDateEdit *qp = static_cast<KQDateEdit*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDateEdit_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDateEdit::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDateEdit::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDateEdit::event(event);
		return false;
	}
//	QDateEdit::event(event);
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


