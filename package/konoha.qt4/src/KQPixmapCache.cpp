//int QPixmapCache.getCacheLimit();
KMETHOD QPixmapCache_getCacheLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->cacheLimit();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPixmapCache.clear();
KMETHOD QPixmapCache_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//boolean QPixmapCache.find(String key, QPixmap pixmap);
KMETHOD QPixmapCache_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		const QString key = String_to(const QString, sfp[1]);
		QPixmap*  pixmap = RawPtr_to(QPixmap*, sfp[2]);
		bool ret_v = qp->find(key, pixmap);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QPixmapCache.find(int key, QPixmap pixmap);
KMETHOD QPixmapCache_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		const QPixmapCache::Key  key = *RawPtr_to(const QPixmapCache::Key *, sfp[1]);
		QPixmap*  pixmap = RawPtr_to(QPixmap*, sfp[2]);
		bool ret_v = qp->find(key, pixmap);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QPixmapCache.insert(String key, QPixmap pixmap);
KMETHOD QPixmapCache_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		const QString key = String_to(const QString, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		bool ret_v = qp->insert(key, pixmap);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//int QPixmapCache.insert(QPixmap pixmap);
KMETHOD QPixmapCache_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		QPixmapCache::Key ret_v = qp->insert(pixmap);
		QPixmapCache::Key *ret_v_ = new QPixmapCache::Key(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QPixmapCache.remove(String key);
KMETHOD QPixmapCache_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		const QString key = String_to(const QString, sfp[1]);
		qp->remove(key);
	}
	RETURNvoid_();
}

/*
//void QPixmapCache.remove(int key);
KMETHOD QPixmapCache_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		const QPixmapCache::Key  key = *RawPtr_to(const QPixmapCache::Key *, sfp[1]);
		qp->remove(key);
	}
	RETURNvoid_();
}
*/
//boolean QPixmapCache.replace(int key, QPixmap pixmap);
KMETHOD QPixmapCache_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		const QPixmapCache::Key  key = *RawPtr_to(const QPixmapCache::Key *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		bool ret_v = qp->replace(key, pixmap);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QPixmapCache.setCacheLimit(int n);
KMETHOD QPixmapCache_setCacheLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *  qp = RawPtr_to(QPixmapCache *, sfp[0]);
	if (qp != NULL) {
		int n = Int_to(int, sfp[1]);
		qp->setCacheLimit(n);
	}
	RETURNvoid_();
}


DummyQPixmapCache::DummyQPixmapCache()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPixmapCache::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPixmapCache::self = ptr;
}

bool DummyQPixmapCache::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPixmapCache::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPixmapCache::event_map->bigin();
	if ((itr = DummyQPixmapCache::event_map->find(str)) == DummyQPixmapCache::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPixmapCache::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPixmapCache::slot_map->bigin();
	if ((itr = DummyQPixmapCache::slot_map->find(str)) == DummyQPixmapCache::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQPixmapCache::connection(QObject *o)
{
	return;
}

KQPixmapCache::KQPixmapCache() : QPixmapCache()
{
	self = NULL;
	dummy = new DummyQPixmapCache();
	dummy->connection((QObject*)this);
}

KMETHOD QPixmapCache_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPixmapCache *qp = RawPtr_to(KQPixmapCache *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPixmapCache]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPixmapCache]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPixmapCache_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPixmapCache *qp = RawPtr_to(KQPixmapCache *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPixmapCache]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPixmapCache]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPixmapCache_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPixmapCache *qp = (KQPixmapCache *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPixmapCache_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQPixmapCache *qp = (KQPixmapCache *)p->rawptr;
		(void)qp;
	}
}

static int QPixmapCache_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPixmapCache::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQPixmapCache(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPixmapCache";
	cdef->free = QPixmapCache_free;
	cdef->reftrace = QPixmapCache_reftrace;
	cdef->compareTo = QPixmapCache_compareTo;
}


