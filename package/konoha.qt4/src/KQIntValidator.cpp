//@Virtual @Override void QIntValidator.fixup(String input);
KMETHOD QIntValidator_fixup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp != NULL) {
		QString input = String_to(QString, sfp[1]);
		qp->fixup(input);
	}
	RETURNvoid_();
}

//@Virtual @Override int QIntValidator.validate(String input, int pos);
KMETHOD QIntValidator_validate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp != NULL) {
		QString input = String_to(QString, sfp[1]);
		int pos = Int_to(int, sfp[2]);
		QValidator::State ret_v = qp->validate(input, pos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QIntValidator QIntValidator.new(QObject parent);
KMETHOD QIntValidator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQIntValidator *ret_v = new KQIntValidator(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QIntValidator QIntValidator.new(int minimum, int maximum, QObject parent);
KMETHOD QIntValidator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int minimum = Int_to(int, sfp[1]);
	int maximum = Int_to(int, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQIntValidator *ret_v = new KQIntValidator(minimum, maximum, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QIntValidator.getBottom();
KMETHOD QIntValidator_getBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->bottom();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QIntValidator.setBottom(int arg0);
KMETHOD QIntValidator_setBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setBottom(arg0);
	}
	RETURNvoid_();
}

//@Virtual void QIntValidator.setRange(int bottom, int top);
KMETHOD QIntValidator_setRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp != NULL) {
		int bottom = Int_to(int, sfp[1]);
		int top = Int_to(int, sfp[2]);
		qp->setRange(bottom, top);
	}
	RETURNvoid_();
}

//void QIntValidator.settop(int arg0);
KMETHOD QIntValidator_setTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setTop(arg0);
	}
	RETURNvoid_();
}

//int QIntValidator.gettop();
KMETHOD QIntValidator_getTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->top();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQIntValidator::DummyQIntValidator()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQIntValidator::setSelf(knh_RawPtr_t *ptr)
{
	DummyQIntValidator::self = ptr;
	DummyQValidator::setSelf(ptr);
}

bool DummyQIntValidator::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQValidator::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQIntValidator::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIntValidator::event_map->bigin();
	if ((itr = DummyQIntValidator::event_map->find(str)) == DummyQIntValidator::event_map->end()) {
		bool ret = false;
		ret = DummyQValidator::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQIntValidator::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIntValidator::slot_map->bigin();
	if ((itr = DummyQIntValidator::slot_map->find(str)) == DummyQIntValidator::slot_map->end()) {
		bool ret = false;
		ret = DummyQValidator::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQIntValidator::connection(QObject *o)
{
	DummyQValidator::connection(o);
}

KQIntValidator::KQIntValidator(QObject* parent) : QIntValidator(parent)
{
	self = NULL;
	dummy = new DummyQIntValidator();
	dummy->connection((QObject*)this);
}

KMETHOD QIntValidator_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIntValidator *qp = RawPtr_to(KQIntValidator *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QIntValidator]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIntValidator]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QIntValidator_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIntValidator *qp = RawPtr_to(KQIntValidator *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QIntValidator]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIntValidator]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QIntValidator_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQIntValidator *qp = (KQIntValidator *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QIntValidator_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQIntValidator *qp = (KQIntValidator *)p->rawptr;
		(void)qp;
	}
}

static int QIntValidator_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQIntValidator::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQIntValidator::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QIntValidator::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQIntValidator(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QIntValidator";
	cdef->free = QIntValidator_free;
	cdef->reftrace = QIntValidator_reftrace;
	cdef->compareTo = QIntValidator_compareTo;
}


