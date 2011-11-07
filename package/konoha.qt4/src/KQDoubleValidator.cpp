//@Virtual @Override int QDoubleValidator.validate(String input, int pos);
KMETHOD QDoubleValidator_validate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		QString input = String_to(QString, sfp[1]);
		int pos = Int_to(int, sfp[2]);
		QValidator::State ret_v = qp->validate(input, pos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDoubleValidator QDoubleValidator.new(QObject parent);
KMETHOD QDoubleValidator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQDoubleValidator *ret_v = new KQDoubleValidator(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDoubleValidator QDoubleValidator.new(double bottom, double top, int decimals, QObject parent);
KMETHOD QDoubleValidator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	double  bottom = *RawPtr_to(double *, sfp[1]);
	double  top = *RawPtr_to(double *, sfp[2]);
	int decimals = Int_to(int, sfp[3]);
	QObject*  parent = RawPtr_to(QObject*, sfp[4]);
	KQDoubleValidator *ret_v = new KQDoubleValidator(bottom, top, decimals, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//double QDoubleValidator.getBottom();
KMETHOD QDoubleValidator_getBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		double ret_v = qp->bottom();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDoubleValidator.getDecimals();
KMETHOD QDoubleValidator_getDecimals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		int ret_v = qp->decimals();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDoubleValidator.getNotation();
KMETHOD QDoubleValidator_getNotation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		QDoubleValidator::Notation ret_v = qp->notation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDoubleValidator.setBottom(double arg0);
KMETHOD QDoubleValidator_setBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		double  arg0 = *RawPtr_to(double *, sfp[1]);
		qp->setBottom(arg0);
	}
	RETURNvoid_();
}

//void QDoubleValidator.setDecimals(int arg0);
KMETHOD QDoubleValidator_setDecimals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setDecimals(arg0);
	}
	RETURNvoid_();
}

//void QDoubleValidator.setNotation(int arg0);
KMETHOD QDoubleValidator_setNotation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		QDoubleValidator::Notation arg0 = Int_to(QDoubleValidator::Notation, sfp[1]);
		qp->setNotation(arg0);
	}
	RETURNvoid_();
}

//@Virtual void QDoubleValidator.setRange(double minimum, double maximum, int decimals);
KMETHOD QDoubleValidator_setRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		double  minimum = *RawPtr_to(double *, sfp[1]);
		double  maximum = *RawPtr_to(double *, sfp[2]);
		int decimals = Int_to(int, sfp[3]);
		qp->setRange(minimum, maximum, decimals);
	}
	RETURNvoid_();
}

//void QDoubleValidator.setTop(double arg0);
KMETHOD QDoubleValidator_setTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		double  arg0 = *RawPtr_to(double *, sfp[1]);
		qp->setTop(arg0);
	}
	RETURNvoid_();
}

//double QDoubleValidator.getTop();
KMETHOD QDoubleValidator_getTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleValidator *  qp = RawPtr_to(QDoubleValidator *, sfp[0]);
	if (qp) {
		double ret_v = qp->top();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQDoubleValidator::DummyQDoubleValidator()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDoubleValidator::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDoubleValidator::self = ptr;
	DummyQValidator::setSelf(ptr);
}

bool DummyQDoubleValidator::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQValidator::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDoubleValidator::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDoubleValidator::event_map->bigin();
	if ((itr = DummyQDoubleValidator::event_map->find(str)) == DummyQDoubleValidator::event_map->end()) {
		bool ret = false;
		ret = DummyQValidator::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDoubleValidator::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDoubleValidator::slot_map->bigin();
	if ((itr = DummyQDoubleValidator::slot_map->find(str)) == DummyQDoubleValidator::slot_map->end()) {
		bool ret = false;
		ret = DummyQValidator::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQDoubleValidator::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQValidator::reftrace(ctx, p, tail_);
}

void DummyQDoubleValidator::connection(QObject *o)
{
	QDoubleValidator *p = dynamic_cast<QDoubleValidator*>(o);
	if (p != NULL) {
	}
	DummyQValidator::connection(o);
}

KQDoubleValidator::KQDoubleValidator(QObject* parent) : QDoubleValidator(parent)
{
	self = NULL;
	dummy = new DummyQDoubleValidator();
	dummy->connection((QObject*)this);
}

KMETHOD QDoubleValidator_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDoubleValidator *qp = RawPtr_to(KQDoubleValidator *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDoubleValidator]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDoubleValidator]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDoubleValidator_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDoubleValidator *qp = RawPtr_to(KQDoubleValidator *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDoubleValidator]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDoubleValidator]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDoubleValidator_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDoubleValidator *qp = (KQDoubleValidator *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDoubleValidator_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQDoubleValidator *qp = (KQDoubleValidator *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDoubleValidator_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDoubleValidator::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDoubleValidator::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDoubleValidator::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QDoubleValidatorConstInt[] = {
	{"StandardNotation", QDoubleValidator::StandardNotation},
	{"ScientificNotation", QDoubleValidator::ScientificNotation},
	{NULL, 0}
};

DEFAPI(void) constQDoubleValidator(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDoubleValidatorConstInt);
}


DEFAPI(void) defQDoubleValidator(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDoubleValidator";
	cdef->free = QDoubleValidator_free;
	cdef->reftrace = QDoubleValidator_reftrace;
	cdef->compareTo = QDoubleValidator_compareTo;
}


