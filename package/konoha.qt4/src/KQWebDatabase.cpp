//QWebDatabase QWebDatabase.new(QWebDatabase other);
KMETHOD QWebDatabase_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QWebDatabase  other = *RawPtr_to(const QWebDatabase *, sfp[1]);
	KQWebDatabase *ret_v = new KQWebDatabase(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QWebDatabase.displayName();
KMETHOD QWebDatabase_displayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebDatabase *  qp = RawPtr_to(QWebDatabase *, sfp[0]);
	if (qp) {
		QString ret_v = qp->displayName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebDatabase.expectedSize();
KMETHOD QWebDatabase_expectedSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebDatabase *  qp = RawPtr_to(QWebDatabase *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->expectedSize();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebDatabase.fileName();
KMETHOD QWebDatabase_fileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebDatabase *  qp = RawPtr_to(QWebDatabase *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebDatabase.name();
KMETHOD QWebDatabase_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebDatabase *  qp = RawPtr_to(QWebDatabase *, sfp[0]);
	if (qp) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebSecurityOrigin QWebDatabase.origin();
KMETHOD QWebDatabase_origin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebDatabase *  qp = RawPtr_to(QWebDatabase *, sfp[0]);
	if (qp) {
		QWebSecurityOrigin ret_v = qp->origin();
		QWebSecurityOrigin *ret_v_ = new QWebSecurityOrigin(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebDatabase.size();
KMETHOD QWebDatabase_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebDatabase *  qp = RawPtr_to(QWebDatabase *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->size();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebDatabase.removeAllDatabases();
KMETHOD QWebDatabase_removeAllDatabases(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWebDatabase::removeAllDatabases();
	}
	RETURNvoid_();
}

//void QWebDatabase.removeDatabase(QWebDatabase db);
KMETHOD QWebDatabase_removeDatabase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QWebDatabase  db = *RawPtr_to(const QWebDatabase *, sfp[1]);
		QWebDatabase::removeDatabase(db);
	}
	RETURNvoid_();
}

//Array<String> QWebDatabase.parents();
KMETHOD QWebDatabase_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebDatabase *qp = RawPtr_to(QWebDatabase*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQWebDatabase::DummyQWebDatabase()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWebDatabase::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebDatabase::self = ptr;
}

bool DummyQWebDatabase::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWebDatabase::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebDatabase::event_map->bigin();
	if ((itr = DummyQWebDatabase::event_map->find(str)) == DummyQWebDatabase::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebDatabase::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebDatabase::slot_map->bigin();
	if ((itr = DummyQWebDatabase::slot_map->find(str)) == DummyQWebDatabase::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebDatabase::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebDatabase::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQWebDatabase::connection(QObject *o)
{
	QWebDatabase *p = dynamic_cast<QWebDatabase*>(o);
	if (p != NULL) {
	}
}

KQWebDatabase::KQWebDatabase(const QWebDatabase other) : QWebDatabase(other)
{
	self = NULL;
	dummy = new DummyQWebDatabase();
}

KMETHOD QWebDatabase_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebDatabase *qp = RawPtr_to(KQWebDatabase *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebDatabase]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebDatabase]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebDatabase_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebDatabase *qp = RawPtr_to(KQWebDatabase *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebDatabase]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebDatabase]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebDatabase_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWebDatabase *qp = (KQWebDatabase *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWebDatabase_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWebDatabase *qp = (KQWebDatabase *)p->rawptr;
//		KQWebDatabase *qp = static_cast<KQWebDatabase*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebDatabase_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebDatabase::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWebDatabase(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebDatabase";
	cdef->free = QWebDatabase_free;
	cdef->reftrace = QWebDatabase_reftrace;
	cdef->compareTo = QWebDatabase_compareTo;
}


