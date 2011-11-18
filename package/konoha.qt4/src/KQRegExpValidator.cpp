//@Virtual @Override int QRegExpValidator.validate(String input, int pos);
KMETHOD QRegExpValidator_validate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExpValidator *  qp = RawPtr_to(QRegExpValidator *, sfp[0]);
	if (qp) {
		QString input = String_to(QString, sfp[1]);
		int pos = Int_to(int, sfp[2]);
		QValidator::State ret_v = qp->validate(input, pos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRegExpValidator QRegExpValidator.new(QObject parent);
KMETHOD QRegExpValidator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQRegExpValidator *ret_v = new KQRegExpValidator(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QRegExpValidator QRegExpValidator.new(QRegExp rx, QObject parent);
KMETHOD QRegExpValidator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRegExp  rx = *RawPtr_to(const QRegExp *, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQRegExpValidator *ret_v = new KQRegExpValidator(rx, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QRegExp QRegExpValidator.getRegExp();
KMETHOD QRegExpValidator_getRegExp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExpValidator *  qp = RawPtr_to(QRegExpValidator *, sfp[0]);
	if (qp) {
		const QRegExp ret_v = qp->regExp();
		QRegExp *ret_v_ = new QRegExp(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QRegExpValidator.setRegExp(QRegExp rx);
KMETHOD QRegExpValidator_setRegExp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegExpValidator *  qp = RawPtr_to(QRegExpValidator *, sfp[0]);
	if (qp) {
		const QRegExp  rx = *RawPtr_to(const QRegExp *, sfp[1]);
		qp->setRegExp(rx);
	}
	RETURNvoid_();
}


DummyQRegExpValidator::DummyQRegExpValidator()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQRegExpValidator::~DummyQRegExpValidator()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQRegExpValidator::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRegExpValidator::self = ptr;
	DummyQValidator::setSelf(ptr);
}

bool DummyQRegExpValidator::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQValidator::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQRegExpValidator::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRegExpValidator::event_map->bigin();
	if ((itr = DummyQRegExpValidator::event_map->find(str)) == DummyQRegExpValidator::event_map->end()) {
		bool ret = false;
		ret = DummyQValidator::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRegExpValidator::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRegExpValidator::slot_map->bigin();
	if ((itr = DummyQRegExpValidator::slot_map->find(str)) == DummyQRegExpValidator::slot_map->end()) {
		bool ret = false;
		ret = DummyQValidator::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQRegExpValidator::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQRegExpValidator::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQValidator::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQRegExpValidator::connection(QObject *o)
{
	QRegExpValidator *p = dynamic_cast<QRegExpValidator*>(o);
	if (p != NULL) {
	}
	DummyQValidator::connection(o);
}

KQRegExpValidator::KQRegExpValidator(QObject* parent) : QRegExpValidator(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQRegExpValidator();
	dummy->connection((QObject*)this);
}

KQRegExpValidator::~KQRegExpValidator()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QRegExpValidator_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRegExpValidator *qp = RawPtr_to(KQRegExpValidator *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRegExpValidator]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRegExpValidator]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QRegExpValidator_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRegExpValidator *qp = RawPtr_to(KQRegExpValidator *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRegExpValidator]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRegExpValidator]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRegExpValidator_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQRegExpValidator *qp = (KQRegExpValidator *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QRegExpValidator*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QRegExpValidator_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQRegExpValidator *qp = (KQRegExpValidator *)p->rawptr;
		KQRegExpValidator *qp = static_cast<KQRegExpValidator*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QRegExpValidator_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQRegExpValidator::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQRegExpValidator::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QRegExpValidator::event(event);
		return false;
	}
//	QRegExpValidator::event(event);
	return true;
}



DEFAPI(void) defQRegExpValidator(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRegExpValidator";
	cdef->free = QRegExpValidator_free;
	cdef->reftrace = QRegExpValidator_reftrace;
	cdef->compareTo = QRegExpValidator_compareTo;
}


