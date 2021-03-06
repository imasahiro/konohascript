//
//@Virtual void QValidator.fixup(String input);
KMETHOD QValidator_fixup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QValidator *  qp = RawPtr_to(QValidator *, sfp[0]);
	if (qp) {
		QString input = String_to(QString, sfp[1]);
		qp->fixup(input);
	}
	RETURNvoid_();
}

//QLocale QValidator.getLocale();
KMETHOD QValidator_getLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QValidator *  qp = RawPtr_to(QValidator *, sfp[0]);
	if (qp) {
		QLocale ret_v = qp->locale();
		QLocale *ret_v_ = new QLocale(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QValidator.setLocale(QLocale locale);
KMETHOD QValidator_setLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QValidator *  qp = RawPtr_to(QValidator *, sfp[0]);
	if (qp) {
		const QLocale  locale = *RawPtr_to(const QLocale *, sfp[1]);
		qp->setLocale(locale);
	}
	RETURNvoid_();
}

//@Virtual int QValidator.validate(String input, int pos);
KMETHOD QValidator_validate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QValidator *  qp = RawPtr_to(QValidator *, sfp[0]);
	if (qp) {
		QString input = String_to(QString, sfp[1]);
		int pos = Int_to(int, sfp[2]);
		QValidator::State ret_v = qp->validate(input, pos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQValidator::DummyQValidator()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQValidator::~DummyQValidator()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQValidator::setSelf(knh_RawPtr_t *ptr)
{
	DummyQValidator::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQValidator::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQValidator::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQValidator::event_map->bigin();
	if ((itr = DummyQValidator::event_map->find(str)) == DummyQValidator::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQValidator::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQValidator::slot_map->bigin();
	if ((itr = DummyQValidator::slot_map->find(str)) == DummyQValidator::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQValidator::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQValidator::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQValidator::connection(QObject *o)
{
	QValidator *p = dynamic_cast<QValidator*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQValidator::KQValidator(QObject* parent) : QValidator(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQValidator();
	dummy->connection((QObject*)this);
}

KQValidator::~KQValidator()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QValidator_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQValidator *qp = RawPtr_to(KQValidator *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QValidator]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QValidator]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QValidator_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQValidator *qp = RawPtr_to(KQValidator *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QValidator]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QValidator]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QValidator_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQValidator *qp = (KQValidator *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QValidator*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QValidator_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQValidator *qp = (KQValidator *)p->rawptr;
		KQValidator *qp = static_cast<KQValidator*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QValidator_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQValidator::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQValidator::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QValidator::event(event);
		return false;
	}
//	QValidator::event(event);
	return true;
}

static knh_IntData_t QValidatorConstInt[] = {
	{"Invalid", QValidator::Invalid},
	{"Intermediate", QValidator::Intermediate},
	{"Acceptable", QValidator::Acceptable},
	{NULL, 0}
};

DEFAPI(void) constQValidator(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QValidatorConstInt);
}


DEFAPI(void) defQValidator(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QValidator";
	cdef->free = QValidator_free;
	cdef->reftrace = QValidator_reftrace;
	cdef->compareTo = QValidator_compareTo;
}


