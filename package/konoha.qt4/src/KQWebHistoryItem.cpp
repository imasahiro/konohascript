//QWebHistoryItem QWebHistoryItem.new(QWebHistoryItem other);
KMETHOD QWebHistoryItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QWebHistoryItem  other = *RawPtr_to(const QWebHistoryItem *, sfp[1]);
	KQWebHistoryItem *ret_v = new KQWebHistoryItem(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QIcon QWebHistoryItem.icon();
KMETHOD QWebHistoryItem_icon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryItem *  qp = RawPtr_to(QWebHistoryItem *, sfp[0]);
	if (qp) {
		QIcon ret_v = qp->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QWebHistoryItem.lastVisited();
KMETHOD QWebHistoryItem_lastVisited(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryItem *  qp = RawPtr_to(QWebHistoryItem *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->lastVisited();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QWebHistoryItem.originalUrl();
KMETHOD QWebHistoryItem_originalUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryItem *  qp = RawPtr_to(QWebHistoryItem *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->originalUrl();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebHistoryItem.setUserData(QVariant userData);
KMETHOD QWebHistoryItem_setUserData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryItem *  qp = RawPtr_to(QWebHistoryItem *, sfp[0]);
	if (qp) {
		const QVariant  userData = *RawPtr_to(const QVariant *, sfp[1]);
		qp->setUserData(userData);
	}
	RETURNvoid_();
}

//String QWebHistoryItem.title();
KMETHOD QWebHistoryItem_title(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryItem *  qp = RawPtr_to(QWebHistoryItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->title();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QWebHistoryItem.url();
KMETHOD QWebHistoryItem_url(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryItem *  qp = RawPtr_to(QWebHistoryItem *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->url();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariant QWebHistoryItem.getUserData();
KMETHOD QWebHistoryItem_getUserData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryItem *  qp = RawPtr_to(QWebHistoryItem *, sfp[0]);
	if (qp) {
		QVariant ret_v = qp->userData();
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QWebHistoryItem.parents();
KMETHOD QWebHistoryItem_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebHistoryItem *qp = RawPtr_to(QWebHistoryItem*, sfp[0]);
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

DummyQWebHistoryItem::DummyQWebHistoryItem()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQWebHistoryItem::~DummyQWebHistoryItem()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQWebHistoryItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebHistoryItem::self = ptr;
}

bool DummyQWebHistoryItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWebHistoryItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebHistoryItem::event_map->bigin();
	if ((itr = DummyQWebHistoryItem::event_map->find(str)) == DummyQWebHistoryItem::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebHistoryItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebHistoryItem::slot_map->bigin();
	if ((itr = DummyQWebHistoryItem::slot_map->find(str)) == DummyQWebHistoryItem::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebHistoryItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebHistoryItem::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQWebHistoryItem::connection(QObject *o)
{
	QWebHistoryItem *p = dynamic_cast<QWebHistoryItem*>(o);
	if (p != NULL) {
	}
}

KQWebHistoryItem::KQWebHistoryItem(const QWebHistoryItem other) : QWebHistoryItem(other)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQWebHistoryItem();
}

KQWebHistoryItem::~KQWebHistoryItem()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QWebHistoryItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHistoryItem *qp = RawPtr_to(KQWebHistoryItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebHistoryItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebHistoryItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebHistoryItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebHistoryItem *qp = RawPtr_to(KQWebHistoryItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebHistoryItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebHistoryItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebHistoryItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQWebHistoryItem *qp = (KQWebHistoryItem *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QWebHistoryItem*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QWebHistoryItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQWebHistoryItem *qp = (KQWebHistoryItem *)p->rawptr;
		KQWebHistoryItem *qp = static_cast<KQWebHistoryItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebHistoryItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebHistoryItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWebHistoryItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebHistoryItem";
	cdef->free = QWebHistoryItem_free;
	cdef->reftrace = QWebHistoryItem_reftrace;
	cdef->compareTo = QWebHistoryItem_compareTo;
}


