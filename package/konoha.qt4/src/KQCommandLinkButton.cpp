//QCommandLinkButton QCommandLinkButton.new(QWidget parent);
KMETHOD QCommandLinkButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQCommandLinkButton *ret_v = new KQCommandLinkButton(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QCommandLinkButton QCommandLinkButton.new(String text, QWidget parent);
KMETHOD QCommandLinkButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQCommandLinkButton *ret_v = new KQCommandLinkButton(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QCommandLinkButton QCommandLinkButton.new(String text, String description, QWidget parent);
KMETHOD QCommandLinkButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	const QString description = String_to(const QString, sfp[2]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
	KQCommandLinkButton *ret_v = new KQCommandLinkButton(text, description, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QCommandLinkButton.getDescription();
KMETHOD QCommandLinkButton_getDescription(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommandLinkButton *  qp = RawPtr_to(QCommandLinkButton *, sfp[0]);
	if (qp) {
		QString ret_v = qp->description();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QCommandLinkButton.setDescription(String description);
KMETHOD QCommandLinkButton_setDescription(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommandLinkButton *  qp = RawPtr_to(QCommandLinkButton *, sfp[0]);
	if (qp) {
		const QString description = String_to(const QString, sfp[1]);
		qp->setDescription(description);
	}
	RETURNvoid_();
}


DummyQCommandLinkButton::DummyQCommandLinkButton()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQCommandLinkButton::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCommandLinkButton::self = ptr;
	DummyQPushButton::setSelf(ptr);
}

bool DummyQCommandLinkButton::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPushButton::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQCommandLinkButton::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCommandLinkButton::event_map->bigin();
	if ((itr = DummyQCommandLinkButton::event_map->find(str)) == DummyQCommandLinkButton::event_map->end()) {
		bool ret = false;
		ret = DummyQPushButton::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCommandLinkButton::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCommandLinkButton::slot_map->bigin();
	if ((itr = DummyQCommandLinkButton::slot_map->find(str)) == DummyQCommandLinkButton::slot_map->end()) {
		bool ret = false;
		ret = DummyQPushButton::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQCommandLinkButton::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQPushButton::reftrace(ctx, p, tail_);
}

void DummyQCommandLinkButton::connection(QObject *o)
{
	QCommandLinkButton *p = dynamic_cast<QCommandLinkButton*>(o);
	if (p != NULL) {
	}
	DummyQPushButton::connection(o);
}

KQCommandLinkButton::KQCommandLinkButton(QWidget* parent) : QCommandLinkButton(parent)
{
	self = NULL;
	dummy = new DummyQCommandLinkButton();
	dummy->connection((QObject*)this);
}

KMETHOD QCommandLinkButton_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCommandLinkButton *qp = RawPtr_to(KQCommandLinkButton *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCommandLinkButton]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCommandLinkButton]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QCommandLinkButton_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCommandLinkButton *qp = RawPtr_to(KQCommandLinkButton *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCommandLinkButton]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCommandLinkButton]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCommandLinkButton_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQCommandLinkButton *qp = (KQCommandLinkButton *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QCommandLinkButton_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQCommandLinkButton *qp = (KQCommandLinkButton *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QCommandLinkButton_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQCommandLinkButton::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQCommandLinkButton::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QCommandLinkButton::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQCommandLinkButton(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCommandLinkButton";
	cdef->free = QCommandLinkButton_free;
	cdef->reftrace = QCommandLinkButton_reftrace;
	cdef->compareTo = QCommandLinkButton_compareTo;
}


