//@Virtual @Override int QNetworkDiskCache.cacheSize();
KMETHOD QNetworkDiskCache_cacheSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->cacheSize();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QIODevice QNetworkDiskCache.data(QUrl url);
KMETHOD QNetworkDiskCache_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		QIODevice* ret_v = qp->data(url);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QNetworkDiskCache.insert(QIODevice device);
KMETHOD QNetworkDiskCache_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		qp->insert(device);
	}
	RETURNvoid_();
}

//@Virtual @Override QNetworkCacheMetaData QNetworkDiskCache.metaData(QUrl url);
KMETHOD QNetworkDiskCache_metaData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
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

//@Virtual @Override QIODevice QNetworkDiskCache.prepare(QNetworkCacheMetaData metaData);
KMETHOD QNetworkDiskCache_prepare(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		const QNetworkCacheMetaData  metaData = *RawPtr_to(const QNetworkCacheMetaData *, sfp[1]);
		QIODevice* ret_v = qp->prepare(metaData);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QNetworkDiskCache.remove(QUrl url);
KMETHOD QNetworkDiskCache_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		bool ret_v = qp->remove(url);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override void QNetworkDiskCache.updateMetaData(QNetworkCacheMetaData metaData);
KMETHOD QNetworkDiskCache_updateMetaData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		const QNetworkCacheMetaData  metaData = *RawPtr_to(const QNetworkCacheMetaData *, sfp[1]);
		qp->updateMetaData(metaData);
	}
	RETURNvoid_();
}

//QNetworkDiskCache QNetworkDiskCache.new(QObject parent);
KMETHOD QNetworkDiskCache_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQNetworkDiskCache *ret_v = new KQNetworkDiskCache(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QNetworkDiskCache.getCacheDirectory();
KMETHOD QNetworkDiskCache_getCacheDirectory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		QString ret_v = qp->cacheDirectory();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkCacheMetaData QNetworkDiskCache.fileMetaData(String fileName);
KMETHOD QNetworkDiskCache_fileMetaData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		QNetworkCacheMetaData ret_v = qp->fileMetaData(fileName);
		QNetworkCacheMetaData *ret_v_ = new QNetworkCacheMetaData(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkDiskCache.getMaximumCacheSize();
KMETHOD QNetworkDiskCache_getMaximumCacheSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->maximumCacheSize();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QNetworkDiskCache.setCacheDirectory(String cacheDir);
KMETHOD QNetworkDiskCache_setCacheDirectory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		const QString cacheDir = String_to(const QString, sfp[1]);
		qp->setCacheDirectory(cacheDir);
	}
	RETURNvoid_();
}

//void QNetworkDiskCache.setMaximumCacheSize(int size);
KMETHOD QNetworkDiskCache_setMaximumCacheSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		qint64 size = Int_to(qint64, sfp[1]);
		qp->setMaximumCacheSize(size);
	}
	RETURNvoid_();
}

//@Virtual void QNetworkDiskCache.clear();
KMETHOD QNetworkDiskCache_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkDiskCache *  qp = RawPtr_to(QNetworkDiskCache *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}


DummyQNetworkDiskCache::DummyQNetworkDiskCache()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQNetworkDiskCache::~DummyQNetworkDiskCache()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQNetworkDiskCache::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkDiskCache::self = ptr;
	DummyQAbstractNetworkCache::setSelf(ptr);
}

bool DummyQNetworkDiskCache::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractNetworkCache::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQNetworkDiskCache::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkDiskCache::event_map->bigin();
	if ((itr = DummyQNetworkDiskCache::event_map->find(str)) == DummyQNetworkDiskCache::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractNetworkCache::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkDiskCache::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkDiskCache::slot_map->bigin();
	if ((itr = DummyQNetworkDiskCache::slot_map->find(str)) == DummyQNetworkDiskCache::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractNetworkCache::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkDiskCache::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkDiskCache::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractNetworkCache::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQNetworkDiskCache::connection(QObject *o)
{
	QNetworkDiskCache *p = dynamic_cast<QNetworkDiskCache*>(o);
	if (p != NULL) {
	}
	DummyQAbstractNetworkCache::connection(o);
}

KQNetworkDiskCache::KQNetworkDiskCache(QObject* parent) : QNetworkDiskCache(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQNetworkDiskCache();
	dummy->connection((QObject*)this);
}

KQNetworkDiskCache::~KQNetworkDiskCache()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QNetworkDiskCache_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkDiskCache *qp = RawPtr_to(KQNetworkDiskCache *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkDiskCache]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkDiskCache]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkDiskCache_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkDiskCache *qp = RawPtr_to(KQNetworkDiskCache *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkDiskCache]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkDiskCache]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkDiskCache_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQNetworkDiskCache *qp = (KQNetworkDiskCache *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QNetworkDiskCache*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QNetworkDiskCache_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQNetworkDiskCache *qp = (KQNetworkDiskCache *)p->rawptr;
		KQNetworkDiskCache *qp = static_cast<KQNetworkDiskCache*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkDiskCache_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQNetworkDiskCache::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQNetworkDiskCache::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QNetworkDiskCache::event(event);
		return false;
	}
//	QNetworkDiskCache::event(event);
	return true;
}



DEFAPI(void) defQNetworkDiskCache(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkDiskCache";
	cdef->free = QNetworkDiskCache_free;
	cdef->reftrace = QNetworkDiskCache_reftrace;
	cdef->compareTo = QNetworkDiskCache_compareTo;
}


