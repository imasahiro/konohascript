//QShortcut QShortcut.new(QWidget parent);
KMETHOD QShortcut_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQShortcut *ret_v = new KQShortcut(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QShortcut QShortcut.new(QKeySequence key, QWidget parent, String member, String ambiguousMember, int context);
KMETHOD QShortcut_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QKeySequence  key = *RawPtr_to(const QKeySequence *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	const char*  member = RawPtr_to(const char*, sfp[3]);
	const char*  ambiguousMember = RawPtr_to(const char*, sfp[4]);
	Qt::ShortcutContext context = Int_to(Qt::ShortcutContext, sfp[5]);
	KQShortcut *ret_v = new KQShortcut(key, parent, member, ambiguousMember, context);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QShortcut.getAutoRepeat();
KMETHOD QShortcut_getAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoRepeat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QShortcut.getContext();
KMETHOD QShortcut_getContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		Qt::ShortcutContext ret_v = qp->context();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QShortcut.id();
KMETHOD QShortcut_id(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		int ret_v = qp->id();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QShortcut.isEnabled();
KMETHOD QShortcut_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QKeySequence QShortcut.getKey();
KMETHOD QShortcut_getKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		QKeySequence ret_v = qp->key();
		QKeySequence *ret_v_ = new QKeySequence(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QShortcut.parentWidget();
KMETHOD QShortcut_parentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->parentWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QShortcut.setAutoRepeat(boolean on);
KMETHOD QShortcut_setAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setAutoRepeat(on);
	}
	RETURNvoid_();
}

//void QShortcut.setContext(int context);
KMETHOD QShortcut_setContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		Qt::ShortcutContext context = Int_to(Qt::ShortcutContext, sfp[1]);
		qp->setContext(context);
	}
	RETURNvoid_();
}

//void QShortcut.setEnabled(boolean enable);
KMETHOD QShortcut_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setEnabled(enable);
	}
	RETURNvoid_();
}

//void QShortcut.setKey(QKeySequence key);
KMETHOD QShortcut_setKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		const QKeySequence  key = *RawPtr_to(const QKeySequence *, sfp[1]);
		qp->setKey(key);
	}
	RETURNvoid_();
}

//void QShortcut.setWhatsThis(String text);
KMETHOD QShortcut_setWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setWhatsThis(text);
	}
	RETURNvoid_();
}

//String QShortcut.getWhatsThis();
KMETHOD QShortcut_getWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcut *  qp = RawPtr_to(QShortcut *, sfp[0]);
	if (qp) {
		QString ret_v = qp->whatsThis();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQShortcut::DummyQShortcut()
{
	self = NULL;
	activated_func = NULL;
	activated_ambiguously_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("activated", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("activated-ambiguously", NULL));
}

void DummyQShortcut::setSelf(knh_RawPtr_t *ptr)
{
	DummyQShortcut::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQShortcut::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQShortcut::activatedSlot()
{
	if (activated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, activated_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQShortcut::activatedAmbiguouslySlot()
{
	if (activated_ambiguously_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, activated_ambiguously_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQShortcut::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQShortcut::event_map->bigin();
	if ((itr = DummyQShortcut::event_map->find(str)) == DummyQShortcut::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQShortcut::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQShortcut::slot_map->bigin();
	if ((itr = DummyQShortcut::slot_map->find(str)) == DummyQShortcut::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		activated_func = (*slot_map)["activated"];
		activated_ambiguously_func = (*slot_map)["activated-ambiguously"];
		return true;
	}
}

void DummyQShortcut::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, activated_func);
	KNH_ADDNNREF(ctx, activated_ambiguously_func);

	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQShortcut::connection(QObject *o)
{
	QShortcut *p = dynamic_cast<QShortcut*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(activated()), this, SLOT(activatedSlot()));
		connect(p, SIGNAL(activatedAmbiguously()), this, SLOT(activatedAmbiguouslySlot()));
	}
	DummyQObject::connection(o);
}

KQShortcut::KQShortcut(QWidget* parent) : QShortcut(parent)
{
	self = NULL;
	dummy = new DummyQShortcut();
	dummy->connection((QObject*)this);
}

KMETHOD QShortcut_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQShortcut *qp = RawPtr_to(KQShortcut *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QShortcut]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QShortcut]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QShortcut_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQShortcut *qp = RawPtr_to(KQShortcut *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QShortcut]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QShortcut]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QShortcut_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQShortcut *qp = (KQShortcut *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QShortcut_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQShortcut *qp = (KQShortcut *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QShortcut_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQShortcut::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQShortcut::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QShortcut::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQShortcut(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QShortcut";
	cdef->free = QShortcut_free;
	cdef->reftrace = QShortcut_reftrace;
	cdef->compareTo = QShortcut_compareTo;
}


