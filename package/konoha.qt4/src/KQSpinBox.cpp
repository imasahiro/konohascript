//QSpinBox QSpinBox.new(QWidget parent);
KMETHOD QSpinBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQSpinBox *ret_v = new KQSpinBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QSpinBox.cleanText();
KMETHOD QSpinBox_cleanText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->cleanText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSpinBox.getMaximum();
KMETHOD QSpinBox_getMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->maximum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSpinBox.getMinimum();
KMETHOD QSpinBox_getMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->minimum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QSpinBox.getPrefix();
KMETHOD QSpinBox_getPrefix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->prefix();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QSpinBox.setMaximum(int max);
KMETHOD QSpinBox_setMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int max = Int_to(int, sfp[1]);
		qp->setMaximum(max);
	}
	RETURNvoid_();
}

//void QSpinBox.setMinimum(int min);
KMETHOD QSpinBox_setMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int min = Int_to(int, sfp[1]);
		qp->setMinimum(min);
	}
	RETURNvoid_();
}

//void QSpinBox.setPrefix(String prefix);
KMETHOD QSpinBox_setPrefix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		const QString prefix = String_to(const QString, sfp[1]);
		qp->setPrefix(prefix);
	}
	RETURNvoid_();
}

//void QSpinBox.setRange(int minimum, int maximum);
KMETHOD QSpinBox_setRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int minimum = Int_to(int, sfp[1]);
		int maximum = Int_to(int, sfp[2]);
		qp->setRange(minimum, maximum);
	}
	RETURNvoid_();
}

//void QSpinBox.setSingleStep(int val);
KMETHOD QSpinBox_setSingleStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int val = Int_to(int, sfp[1]);
		qp->setSingleStep(val);
	}
	RETURNvoid_();
}

//void QSpinBox.setSuffix(String suffix);
KMETHOD QSpinBox_setSuffix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		const QString suffix = String_to(const QString, sfp[1]);
		qp->setSuffix(suffix);
	}
	RETURNvoid_();
}

//int QSpinBox.getSingleStep();
KMETHOD QSpinBox_getSingleStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->singleStep();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QSpinBox.getSuffix();
KMETHOD QSpinBox_getSuffix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->suffix();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSpinBox.getValue();
KMETHOD QSpinBox_getValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->value();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSpinBox.setValue(int val);
KMETHOD QSpinBox_setValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpinBox *  qp = RawPtr_to(QSpinBox *, sfp[0]);
	if (qp != NULL) {
		int val = Int_to(int, sfp[1]);
		qp->setValue(val);
	}
	RETURNvoid_();
}


DummyQSpinBox::DummyQSpinBox()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSpinBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSpinBox::self = ptr;
	DummyQAbstractSpinBox::setSelf(ptr);
}

bool DummyQSpinBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractSpinBox::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSpinBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSpinBox::event_map->bigin();
	if ((itr = DummyQSpinBox::event_map->find(str)) == DummyQSpinBox::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSpinBox::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSpinBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSpinBox::slot_map->bigin();
	if ((itr = DummyQSpinBox::slot_map->find(str)) == DummyQSpinBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSpinBox::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQSpinBox::connection(QObject *o)
{
	DummyQAbstractSpinBox::connection(o);
}

KQSpinBox::KQSpinBox(QWidget* parent) : QSpinBox(parent)
{
	self = NULL;
	dummy = new DummyQSpinBox();
	dummy->connection((QObject*)this);
}

KMETHOD QSpinBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSpinBox *qp = RawPtr_to(KQSpinBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSpinBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSpinBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSpinBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSpinBox *qp = RawPtr_to(KQSpinBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSpinBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSpinBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSpinBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSpinBox *qp = (KQSpinBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSpinBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQSpinBox *qp = (KQSpinBox *)p->rawptr;
		(void)qp;
	}
}

static int QSpinBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSpinBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSpinBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSpinBox::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQSpinBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSpinBox";
	cdef->free = QSpinBox_free;
	cdef->reftrace = QSpinBox_reftrace;
	cdef->compareTo = QSpinBox_compareTo;
}


