//@Virtual @Override void QIntValidator.fixup(String input);
KMETHOD QIntValidator_fixup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		int bottom = Int_to(int, sfp[1]);
		int top = Int_to(int, sfp[2]);
		qp->setRange(bottom, top);
	}
	RETURNvoid_();
}

//void QIntValidator.setTop(int arg0);
KMETHOD QIntValidator_setTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setTop(arg0);
	}
	RETURNvoid_();
}

//int QIntValidator.getTop();
KMETHOD QIntValidator_getTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIntValidator *  qp = RawPtr_to(QIntValidator *, sfp[0]);
	if (qp) {
		int ret_v = qp->top();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQIntValidator::DummyQIntValidator()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQIntValidator::~DummyQIntValidator()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

knh_Object_t** DummyQIntValidator::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQIntValidator::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQValidator::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQIntValidator::connection(QObject *o)
{
	QIntValidator *p = dynamic_cast<QIntValidator*>(o);
	if (p != NULL) {
	}
	DummyQValidator::connection(o);
}

KQIntValidator::KQIntValidator(QObject* parent) : QIntValidator(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQIntValidator();
	dummy->connection((QObject*)this);
}

KQIntValidator::~KQIntValidator()
{
	delete dummy;
	dummy = NULL;
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
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQIntValidator *qp = (KQIntValidator *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QIntValidator*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QIntValidator_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQIntValidator *qp = (KQIntValidator *)p->rawptr;
		KQIntValidator *qp = static_cast<KQIntValidator*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
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
//	QIntValidator::event(event);
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


