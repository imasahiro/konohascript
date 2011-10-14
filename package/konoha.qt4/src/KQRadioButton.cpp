//@Virtual @Override QSize QRadioButton.sizeHint();
KMETHOD QRadioButton_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadioButton *  qp = RawPtr_to(QRadioButton *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRadioButton QRadioButton.new(QWidget parent);
KMETHOD QRadioButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQRadioButton *ret_v = new KQRadioButton(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QRadioButton QRadioButton.new(String text, QWidget parent);
KMETHOD QRadioButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQRadioButton *ret_v = new KQRadioButton(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQRadioButton::DummyQRadioButton()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQRadioButton::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRadioButton::self = ptr;
	DummyQAbstractButton::setSelf(ptr);
}

bool DummyQRadioButton::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractButton::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQRadioButton::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRadioButton::event_map->bigin();
	if ((itr = DummyQRadioButton::event_map->find(str)) == DummyQRadioButton::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractButton::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRadioButton::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRadioButton::slot_map->bigin();
	if ((itr = DummyQRadioButton::slot_map->find(str)) == DummyQRadioButton::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractButton::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQRadioButton::connection(QObject *o)
{
	DummyQAbstractButton::connection(o);
}

KQRadioButton::KQRadioButton(QWidget* parent) : QRadioButton(parent)
{
	self = NULL;
	dummy = new DummyQRadioButton();
	dummy->connection((QObject*)this);
}

KMETHOD QRadioButton_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRadioButton *qp = RawPtr_to(KQRadioButton *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRadioButton]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRadioButton]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QRadioButton_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRadioButton *qp = RawPtr_to(KQRadioButton *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRadioButton]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRadioButton]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRadioButton_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQRadioButton *qp = (KQRadioButton *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QRadioButton_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQRadioButton *qp = (KQRadioButton *)p->rawptr;
		(void)qp;
	}
}

static int QRadioButton_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQRadioButton::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQRadioButton::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QRadioButton::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQRadioButton(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRadioButton";
	cdef->free = QRadioButton_free;
	cdef->reftrace = QRadioButton_reftrace;
	cdef->compareTo = QRadioButton_compareTo;
}


