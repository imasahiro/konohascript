//QItemEditorFactory QItemEditorFactory.new();
KMETHOD QItemEditorFactory_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQItemEditorFactory *ret_v = new KQItemEditorFactory();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//@Virtual QWidget QItemEditorFactory.createEditor(int type, QWidget parent);
KMETHOD QItemEditorFactory_createEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *  qp = RawPtr_to(QItemEditorFactory *, sfp[0]);
	if (qp != NULL) {
		QVariant::Type type = Int_to(QVariant::Type, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		QWidget* ret_v = qp->createEditor(type, parent);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QItemEditorFactory.registerEditor(int type, QItemEditorCreatorBase creator);
KMETHOD QItemEditorFactory_registerEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *  qp = RawPtr_to(QItemEditorFactory *, sfp[0]);
	if (qp != NULL) {
		QVariant::Type type = Int_to(QVariant::Type, sfp[1]);
		QItemEditorCreatorBase*  creator = RawPtr_to(QItemEditorCreatorBase*, sfp[2]);
		qp->registerEditor(type, creator);
	}
	RETURNvoid_();
}

//@Virtual QByteArray QItemEditorFactory.valuePropertyName(int type);
KMETHOD QItemEditorFactory_valuePropertyName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *  qp = RawPtr_to(QItemEditorFactory *, sfp[0]);
	if (qp != NULL) {
		QVariant::Type type = Int_to(QVariant::Type, sfp[1]);
		QByteArray ret_v = qp->valuePropertyName(type);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QItemEditorFactory QItemEditorFactory.getDefaultFactory();
KMETHOD QItemEditorFactory_getDefaultFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *  qp = RawPtr_to(QItemEditorFactory *, sfp[0]);
	if (qp != NULL) {
		const QItemEditorFactory* ret_v = qp->defaultFactory();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QItemEditorFactory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QItemEditorFactory.setDefaultFactory(QItemEditorFactory factory);
KMETHOD QItemEditorFactory_setDefaultFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QItemEditorFactory *  qp = RawPtr_to(QItemEditorFactory *, sfp[0]);
	if (qp != NULL) {
		QItemEditorFactory*  factory = RawPtr_to(QItemEditorFactory*, sfp[1]);
		qp->setDefaultFactory(factory);
	}
	RETURNvoid_();
}


DummyQItemEditorFactory::DummyQItemEditorFactory()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQItemEditorFactory::setSelf(knh_RawPtr_t *ptr)
{
	DummyQItemEditorFactory::self = ptr;
}

bool DummyQItemEditorFactory::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQItemEditorFactory::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQItemEditorFactory::event_map->bigin();
	if ((itr = DummyQItemEditorFactory::event_map->find(str)) == DummyQItemEditorFactory::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQItemEditorFactory::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQItemEditorFactory::slot_map->bigin();
	if ((itr = DummyQItemEditorFactory::slot_map->find(str)) == DummyQItemEditorFactory::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQItemEditorFactory::connection(QObject *o)
{
	return;
}

KQItemEditorFactory::KQItemEditorFactory() : QItemEditorFactory()
{
	self = NULL;
	dummy = new DummyQItemEditorFactory();
	dummy->connection((QObject*)this);
}

KMETHOD QItemEditorFactory_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQItemEditorFactory *qp = RawPtr_to(KQItemEditorFactory *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QItemEditorFactory]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QItemEditorFactory]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QItemEditorFactory_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQItemEditorFactory *qp = RawPtr_to(KQItemEditorFactory *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QItemEditorFactory]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QItemEditorFactory]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QItemEditorFactory_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQItemEditorFactory *qp = (KQItemEditorFactory *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QItemEditorFactory_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQItemEditorFactory *qp = (KQItemEditorFactory *)p->rawptr;
		(void)qp;
	}
}

static int QItemEditorFactory_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQItemEditorFactory::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQItemEditorFactory(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QItemEditorFactory";
	cdef->free = QItemEditorFactory_free;
	cdef->reftrace = QItemEditorFactory_reftrace;
	cdef->compareTo = QItemEditorFactory_compareTo;
}


