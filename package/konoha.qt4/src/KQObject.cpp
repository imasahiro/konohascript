//QObject QObject.new(QObject parent);
KMETHOD QObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQObject *ret_v = new KQObject(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QObject.blockSignals(boolean block);
KMETHOD QObject_blockSignals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		bool block = Boolean_to(bool, sfp[1]);
		bool ret_v = qp->blockSignals(block);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QObjectList QObject.children();
KMETHOD QObject_children(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const QObjectList ret_v = qp->children();
		QObjectList *ret_v_ = new QObjectList(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QObject.connect(QObject sender, String signal, String method, int type);
KMETHOD QObject_connect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const QObject*  sender = RawPtr_to(const QObject*, sfp[1]);
		const char*  signal = RawPtr_to(const char*, sfp[2]);
		const char*  method = RawPtr_to(const char*, sfp[3]);
		Qt::ConnectionType type = Int_to(Qt::ConnectionType, sfp[4]);
		bool ret_v = qp->connect(sender, signal, method, type);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QObject.disconnect(String signal, QObject receiver, String method);
KMETHOD QObject_disconnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const char*  signal = RawPtr_to(const char*, sfp[1]);
		const QObject*  receiver = RawPtr_to(const QObject*, sfp[2]);
		const char*  method = RawPtr_to(const char*, sfp[3]);
		bool ret_v = qp->disconnect(signal, receiver, method);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QObject.disconnect(QObject receiver, String method);
KMETHOD QObject_disconnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const QObject*  receiver = RawPtr_to(const QObject*, sfp[1]);
		const char*  method = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->disconnect(receiver, method);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QObject.dumpObjectInfo();
KMETHOD QObject_dumpObjectInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		qp->dumpObjectInfo();
	}
	RETURNvoid_();
}

//void QObject.dumpObjectTree();
KMETHOD QObject_dumpObjectTree(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		qp->dumpObjectTree();
	}
	RETURNvoid_();
}

//Array<QByteArray> QObject.dynamicPropertyNames();
KMETHOD QObject_dynamicPropertyNames(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		QList<QByteArray>ret_v = qp->dynamicPropertyNames();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QByteArray"));
		for (int n = 0; n < list_size; n++) {
			QByteArray *ret_v_ = new QByteArray(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//@Virtual boolean QObject.event(QEvent e);
KMETHOD QObject_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		QEvent*  e = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(e);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QObject.eventFilter(QObject watched, QEvent event);
KMETHOD QObject_eventFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		QObject*  watched = RawPtr_to(QObject*, sfp[1]);
		QEvent*  event = RawPtr_to(QEvent*, sfp[2]);
		bool ret_v = qp->eventFilter(watched, event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QObject.inherits(String className);
KMETHOD QObject_inherits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const char*  className = RawPtr_to(const char*, sfp[1]);
		bool ret_v = qp->inherits(className);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QObject.isWidgetType();
KMETHOD QObject_isWidgetType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isWidgetType();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QObject.killTimer(int id);
KMETHOD QObject_killTimer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		int id = Int_to(int, sfp[1]);
		qp->killTimer(id);
	}
	RETURNvoid_();
}

//@Virtual QMetaObject QObject.metaObject();
KMETHOD QObject_metaObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const QMetaObject* ret_v = qp->metaObject();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMetaObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QObject.moveToThread(QThread targetThread);
KMETHOD QObject_moveToThread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		QThread*  targetThread = RawPtr_to(QThread*, sfp[1]);
		qp->moveToThread(targetThread);
	}
	RETURNvoid_();
}

//String QObject.getObjectName();
KMETHOD QObject_getObjectName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->objectName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QObject QObject.getParent();
KMETHOD QObject_getParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		QObject* ret_v = qp->parent();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariant QObject.getProperty(String name);
KMETHOD QObject_getProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		QVariant ret_v = qp->property(name);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QObject.setObjectName(String name);
KMETHOD QObject_setObjectName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const QString name = String_to(const QString, sfp[1]);
		qp->setObjectName(name);
	}
	RETURNvoid_();
}

//void QObject.setParent(QObject parent);
KMETHOD QObject_setParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		QObject*  parent = RawPtr_to(QObject*, sfp[1]);
		qp->setParent(parent);
	}
	RETURNvoid_();
}

//boolean QObject.setProperty(String name, QVariant value);
KMETHOD QObject_setProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		bool ret_v = qp->setProperty(name, value);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QObject.signalsBlocked();
KMETHOD QObject_signalsBlocked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->signalsBlocked();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QObject.startTimer(int interval);
KMETHOD QObject_startTimer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		int interval = Int_to(int, sfp[1]);
		int ret_v = qp->startTimer(interval);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QThread QObject.thread();
KMETHOD QObject_thread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		QThread* ret_v = qp->thread();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QThread*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//boolean QObject.connect(QObject sender, String signal, QObject receiver, String method, int type);
KMETHOD QObject_connect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const QObject*  sender = RawPtr_to(const QObject*, sfp[1]);
		const char*  signal = RawPtr_to(const char*, sfp[2]);
		const QObject*  receiver = RawPtr_to(const QObject*, sfp[3]);
		const char*  method = RawPtr_to(const char*, sfp[4]);
		Qt::ConnectionType type = Int_to(Qt::ConnectionType, sfp[5]);
		bool ret_v = qp->connect(sender, signal, receiver, method, type);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QObject.disconnect(QObject sender, String signal, QObject receiver, String method);
KMETHOD QObject_disconnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const QObject*  sender = RawPtr_to(const QObject*, sfp[1]);
		const char*  signal = RawPtr_to(const char*, sfp[2]);
		const QObject*  receiver = RawPtr_to(const QObject*, sfp[3]);
		const char*  method = RawPtr_to(const char*, sfp[4]);
		bool ret_v = qp->disconnect(sender, signal, receiver, method);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//String QObject.tr(String sourceText, String disambiguation, int n);
KMETHOD QObject_tr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const char*  sourceText = RawPtr_to(const char*, sfp[1]);
		const char*  disambiguation = RawPtr_to(const char*, sfp[2]);
		int n = Int_to(int, sfp[3]);
		QString ret_v = qp->tr(sourceText, disambiguation, n);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QObject.trUtf8(String sourceText, String disambiguation, int n);
KMETHOD QObject_trUtf8(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		const char*  sourceText = RawPtr_to(const char*, sfp[1]);
		const char*  disambiguation = RawPtr_to(const char*, sfp[2]);
		int n = Int_to(int, sfp[3]);
		QString ret_v = qp->trUtf8(sourceText, disambiguation, n);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QObject.deleteLater();
KMETHOD QObject_deleteLater(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject *  qp = RawPtr_to(QObject *, sfp[0]);
	if (qp != NULL) {
		qp->deleteLater();
	}
	RETURNvoid_();
}


DummyQObject::DummyQObject()
{
	self = NULL;
	child_event_func = NULL;
	custom_event_func = NULL;
	timer_event_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("child-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("custom-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("timer-event", NULL));
}

void DummyQObject::setSelf(knh_RawPtr_t *ptr)
{
	DummyQObject::self = ptr;
}

bool DummyQObject::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
		ret = childEvent(dynamic_cast<QChildEvent*>(event));
		break;
		ret = customEvent(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::Timer:
		ret = timerEvent(dynamic_cast<QTimerEvent*>(event));
		break;
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQObject::childEvent(QChildEvent* event)
{
	if (child_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QChildEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, child_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQObject::customEvent(QEvent* event)
{
	if (custom_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, custom_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQObject::timerEvent(QTimerEvent* event)
{
	if (timer_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QTimerEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, timer_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQObject::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQObject::event_map->bigin();
	if ((itr = DummyQObject::event_map->find(str)) == DummyQObject::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		child_event_func = (*event_map)["child-event"];
		custom_event_func = (*event_map)["custom-event"];
		timer_event_func = (*event_map)["timer-event"];
		return true;
	}
}

bool DummyQObject::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQObject::slot_map->bigin();
	if ((itr = DummyQObject::event_map->find(str)) == DummyQObject::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQObject::KQObject(QObject* parent) : QObject(parent)
{
	self = NULL;
}

KMETHOD QObject_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQObject *qp = RawPtr_to(KQObject *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QObject]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQObject::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QObject]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QObject_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQObject *qp = RawPtr_to(KQObject *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QObject]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQObject::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QObject]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QObject_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQObject *qp = (KQObject *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QObject_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQObject *qp = (KQObject *)p->rawptr;
//		(void)qp;
		if (qp->child_event_func != NULL) {
			KNH_ADDREF(ctx, qp->child_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->custom_event_func != NULL) {
			KNH_ADDREF(ctx, qp->custom_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->timer_event_func != NULL) {
			KNH_ADDREF(ctx, qp->timer_event_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QObject_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQObject::event(QEvent *event)
{
	if (!DummyQObject::eventDispatcher(event)) {
		QObject::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQObject(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QObject";
	cdef->free = QObject_free;
	cdef->reftrace = QObject_reftrace;
	cdef->compareTo = QObject_compareTo;
}


