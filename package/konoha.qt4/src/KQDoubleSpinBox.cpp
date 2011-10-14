//@Virtual @Override void QDoubleSpinBox.fixup(String input);
KMETHOD QDoubleSpinBox_fixup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		QString input = String_to(QString, sfp[1]);
		qp->fixup(input);
	}
	RETURNvoid_();
}

//@Virtual @Override int QDoubleSpinBox.validate(String text, int pos);
KMETHOD QDoubleSpinBox_validate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		QString text = String_to(QString, sfp[1]);
		int pos = Int_to(int, sfp[2]);
		QValidator::State ret_v = qp->validate(text, pos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDoubleSpinBox QDoubleSpinBox.new(QWidget parent);
KMETHOD QDoubleSpinBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQDoubleSpinBox *ret_v = new KQDoubleSpinBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QDoubleSpinBox.cleanText();
KMETHOD QDoubleSpinBox_cleanText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->cleanText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDoubleSpinBox.getDecimals();
KMETHOD QDoubleSpinBox_getDecimals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->decimals();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//double QDoubleSpinBox.getMaximum();
KMETHOD QDoubleSpinBox_getMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double ret_v = qp->maximum();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//double QDoubleSpinBox.getMinimum();
KMETHOD QDoubleSpinBox_getMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double ret_v = qp->minimum();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDoubleSpinBox.getPrefix();
KMETHOD QDoubleSpinBox_getPrefix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->prefix();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QDoubleSpinBox.setDecimals(int prec);
KMETHOD QDoubleSpinBox_setDecimals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		int prec = Int_to(int, sfp[1]);
		qp->setDecimals(prec);
	}
	RETURNvoid_();
}

//void QDoubleSpinBox.setMaximum(double max);
KMETHOD QDoubleSpinBox_setMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double  max = *RawPtr_to(double *, sfp[1]);
		qp->setMaximum(max);
	}
	RETURNvoid_();
}

//void QDoubleSpinBox.setMinimum(double min);
KMETHOD QDoubleSpinBox_setMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double  min = *RawPtr_to(double *, sfp[1]);
		qp->setMinimum(min);
	}
	RETURNvoid_();
}

//void QDoubleSpinBox.setPrefix(String prefix);
KMETHOD QDoubleSpinBox_setPrefix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		const QString prefix = String_to(const QString, sfp[1]);
		qp->setPrefix(prefix);
	}
	RETURNvoid_();
}

//void QDoubleSpinBox.setRange(double minimum, double maximum);
KMETHOD QDoubleSpinBox_setRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double  minimum = *RawPtr_to(double *, sfp[1]);
		double  maximum = *RawPtr_to(double *, sfp[2]);
		qp->setRange(minimum, maximum);
	}
	RETURNvoid_();
}

//void QDoubleSpinBox.setSingleStep(double val);
KMETHOD QDoubleSpinBox_setSingleStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double  val = *RawPtr_to(double *, sfp[1]);
		qp->setSingleStep(val);
	}
	RETURNvoid_();
}

//void QDoubleSpinBox.setSuffix(String suffix);
KMETHOD QDoubleSpinBox_setSuffix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		const QString suffix = String_to(const QString, sfp[1]);
		qp->setSuffix(suffix);
	}
	RETURNvoid_();
}

//double QDoubleSpinBox.getSingleStep();
KMETHOD QDoubleSpinBox_getSingleStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double ret_v = qp->singleStep();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDoubleSpinBox.getSuffix();
KMETHOD QDoubleSpinBox_getSuffix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->suffix();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual String QDoubleSpinBox.textFromValue(double value);
KMETHOD QDoubleSpinBox_textFromValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double  value = *RawPtr_to(double *, sfp[1]);
		QString ret_v = qp->textFromValue(value);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//double QDoubleSpinBox.getValue();
KMETHOD QDoubleSpinBox_getValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double ret_v = qp->value();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual double QDoubleSpinBox.valueFromText(String text);
KMETHOD QDoubleSpinBox_valueFromText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		double ret_v = qp->valueFromText(text);
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QDoubleSpinBox.setValue(double val);
KMETHOD QDoubleSpinBox_setValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDoubleSpinBox *  qp = RawPtr_to(QDoubleSpinBox *, sfp[0]);
	if (qp != NULL) {
		double  val = *RawPtr_to(double *, sfp[1]);
		qp->setValue(val);
	}
	RETURNvoid_();
}


DummyQDoubleSpinBox::DummyQDoubleSpinBox()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDoubleSpinBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDoubleSpinBox::self = ptr;
	DummyQAbstractSpinBox::setSelf(ptr);
}

bool DummyQDoubleSpinBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractSpinBox::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDoubleSpinBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDoubleSpinBox::event_map->bigin();
	if ((itr = DummyQDoubleSpinBox::event_map->find(str)) == DummyQDoubleSpinBox::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSpinBox::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDoubleSpinBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDoubleSpinBox::slot_map->bigin();
	if ((itr = DummyQDoubleSpinBox::slot_map->find(str)) == DummyQDoubleSpinBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSpinBox::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQDoubleSpinBox::connection(QObject *o)
{
	DummyQAbstractSpinBox::connection(o);
}

KQDoubleSpinBox::KQDoubleSpinBox(QWidget* parent) : QDoubleSpinBox(parent)
{
	self = NULL;
	dummy = new DummyQDoubleSpinBox();
	dummy->connection((QObject*)this);
}

KMETHOD QDoubleSpinBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDoubleSpinBox *qp = RawPtr_to(KQDoubleSpinBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDoubleSpinBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDoubleSpinBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDoubleSpinBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDoubleSpinBox *qp = RawPtr_to(KQDoubleSpinBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDoubleSpinBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDoubleSpinBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDoubleSpinBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDoubleSpinBox *qp = (KQDoubleSpinBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDoubleSpinBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQDoubleSpinBox *qp = (KQDoubleSpinBox *)p->rawptr;
		(void)qp;
	}
}

static int QDoubleSpinBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDoubleSpinBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDoubleSpinBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDoubleSpinBox::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQDoubleSpinBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDoubleSpinBox";
	cdef->free = QDoubleSpinBox_free;
	cdef->reftrace = QDoubleSpinBox_reftrace;
	cdef->compareTo = QDoubleSpinBox_compareTo;
}


