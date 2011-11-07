//QWebElementCollection QWebElementCollection.new();
KMETHOD QWebElementCollection_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebElementCollection *ret_v = new KQWebElementCollection();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QWebElementCollection QWebElementCollection.new(QWebElement contextElement, String query);
KMETHOD QWebElementCollection_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QWebElement  contextElement = *RawPtr_to(const QWebElement *, sfp[1]);
	const QString query = String_to(const QString, sfp[2]);
	KQWebElementCollection *ret_v = new KQWebElementCollection(contextElement, query);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QWebElementCollection QWebElementCollection.new(QWebElementCollection other);
KMETHOD QWebElementCollection_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QWebElementCollection  other = *RawPtr_to(const QWebElementCollection *, sfp[1]);
	KQWebElementCollection *ret_v = new KQWebElementCollection(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QWebElementCollection.append(QWebElementCollection other);
KMETHOD QWebElementCollection_append(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElementCollection *  qp = RawPtr_to(QWebElementCollection *, sfp[0]);
	if (qp) {
		const QWebElementCollection  other = *RawPtr_to(const QWebElementCollection *, sfp[1]);
		qp->append(other);
	}
	RETURNvoid_();
}

//QWebElement QWebElementCollection.at(int i);
KMETHOD QWebElementCollection_at(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElementCollection *  qp = RawPtr_to(QWebElementCollection *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		QWebElement ret_v = qp->at(i);
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebElementCollection.count();
KMETHOD QWebElementCollection_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElementCollection *  qp = RawPtr_to(QWebElementCollection *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWebElement QWebElementCollection.first();
KMETHOD QWebElementCollection_first(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElementCollection *  qp = RawPtr_to(QWebElementCollection *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->first();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebElementCollection.last();
KMETHOD QWebElementCollection_last(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElementCollection *  qp = RawPtr_to(QWebElementCollection *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->last();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QWebElement> QWebElementCollection.toList();
KMETHOD QWebElementCollection_toList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElementCollection *  qp = RawPtr_to(QWebElementCollection *, sfp[0]);
	if (qp) {
		QList<QWebElement> ret_v = qp->toList();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QWebElement"));
		for (int n = 0; n < list_size; n++) {
			QWebElement *ret_v_ = new QWebElement(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<String> QWebElementCollection.parents();
KMETHOD QWebElementCollection_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElementCollection *qp = RawPtr_to(QWebElementCollection*, sfp[0]);
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

DummyQWebElementCollection::DummyQWebElementCollection()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWebElementCollection::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebElementCollection::self = ptr;
}

bool DummyQWebElementCollection::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWebElementCollection::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebElementCollection::event_map->bigin();
	if ((itr = DummyQWebElementCollection::event_map->find(str)) == DummyQWebElementCollection::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebElementCollection::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebElementCollection::slot_map->bigin();
	if ((itr = DummyQWebElementCollection::slot_map->find(str)) == DummyQWebElementCollection::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQWebElementCollection::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQWebElementCollection::connection(QObject *o)
{
	QWebElementCollection *p = dynamic_cast<QWebElementCollection*>(o);
	if (p != NULL) {
	}
}

KQWebElementCollection::KQWebElementCollection() : QWebElementCollection()
{
	self = NULL;
	dummy = new DummyQWebElementCollection();
}

KMETHOD QWebElementCollection_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebElementCollection *qp = RawPtr_to(KQWebElementCollection *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebElementCollection]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebElementCollection]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebElementCollection_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebElementCollection *qp = RawPtr_to(KQWebElementCollection *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebElementCollection]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebElementCollection]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebElementCollection_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWebElementCollection *qp = (KQWebElementCollection *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWebElementCollection_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWebElementCollection *qp = (KQWebElementCollection *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebElementCollection_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebElementCollection::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWebElementCollection(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebElementCollection";
	cdef->free = QWebElementCollection_free;
	cdef->reftrace = QWebElementCollection_reftrace;
	cdef->compareTo = QWebElementCollection_compareTo;
}


