//@Virtual int QAbstractNetworkCache.cacheSize();
KMETHOD QAbstractNetworkCache_cacheSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractNetworkCache *  qp = RawPtr_to(QAbstractNetworkCache *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->cacheSize();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QIODevice QAbstractNetworkCache.data(QUrl url);
KMETHOD QAbstractNetworkCache_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractNetworkCache *  qp = RawPtr_to(QAbstractNetworkCache *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		QIODevice* ret_v = qp->data(url);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QAbstractNetworkCache.insert(QIODevice device);
KMETHOD QAbstractNetworkCache_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractNetworkCache *  qp = RawPtr_to(QAbstractNetworkCache *, sfp[0]);
	if (qp) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		qp->insert(device);
	}
	RETURNvoid_();
}

//@Virtual QNetworkCacheMetaData QAbstractNetworkCache.metaData(QUrl url);
KMETHOD QAbstractNetworkCache_metaData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractNetworkCache *  qp = RawPtr_to(QAbstractNetworkCache *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		QNetworkCacheMetaData ret_v = qp->metaData(url);
		QNetworkCacheMetaData *ret_v_ = new QNetworkCacheMetaData(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QIODevice QAbstractNetworkCache.prepare(QNetworkCacheMetaData metaData);
KMETHOD QAbstractNetworkCache_prepare(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractNetworkCache *  qp = RawPtr_to(QAbstractNetworkCache *, sfp[0]);
	if (qp) {
		const QNetworkCacheMetaData  metaData = *RawPtr_to(const QNetworkCacheMetaData *, sfp[1]);
		QIODevice* ret_v = qp->prepare(metaData);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QAbstractNetworkCache.remove(QUrl url);
KMETHOD QAbstractNetworkCache_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractNetworkCache *  qp = RawPtr_to(QAbstractNetworkCache *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		bool ret_v = qp->remove(url);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QAbstractNetworkCache.updateMetaData(QNetworkCacheMetaData metaData);
KMETHOD QAbstractNetworkCache_updateMetaData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractNetworkCache *  qp = RawPtr_to(QAbstractNetworkCache *, sfp[0]);
	if (qp) {
		const QNetworkCacheMetaData  metaData = *RawPtr_to(const QNetworkCacheMetaData *, sfp[1]);
		qp->updateMetaData(metaData);
	}
	RETURNvoid_();
}

//@Virtual void QAbstractNetworkCache.clear();
KMETHOD QAbstractNetworkCache_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractNetworkCache *  qp = RawPtr_to(QAbstractNetworkCache *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}


DummyQAbstractNetworkCache::DummyQAbstractNetworkCache()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractNetworkCache::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractNetworkCache::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAbstractNetworkCache::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractNetworkCache::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractNetworkCache::event_map->bigin();
	if ((itr = DummyQAbstractNetworkCache::event_map->find(str)) == DummyQAbstractNetworkCache::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractNetworkCache::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractNetworkCache::slot_map->bigin();
	if ((itr = DummyQAbstractNetworkCache::slot_map->find(str)) == DummyQAbstractNetworkCache::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQAbstractNetworkCache::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQAbstractNetworkCache::connection(QObject *o)
{
	QAbstractNetworkCache *p = dynamic_cast<QAbstractNetworkCache*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KMETHOD QAbstractNetworkCache_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractNetworkCache *qp = RawPtr_to(KQAbstractNetworkCache *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractNetworkCache]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractNetworkCache]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractNetworkCache_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractNetworkCache *qp = RawPtr_to(KQAbstractNetworkCache *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractNetworkCache]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractNetworkCache]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractNetworkCache_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractNetworkCache *qp = (KQAbstractNetworkCache *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractNetworkCache_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAbstractNetworkCache *qp = (KQAbstractNetworkCache *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractNetworkCache_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractNetworkCache::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractNetworkCache::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractNetworkCache::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQAbstractNetworkCache(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractNetworkCache";
	cdef->free = QAbstractNetworkCache_free;
	cdef->reftrace = QAbstractNetworkCache_reftrace;
	cdef->compareTo = QAbstractNetworkCache_compareTo;
}


