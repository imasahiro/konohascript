//int QPixmapCache.getCacheLimit();
KMETHOD QPixmapCache_getCacheLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QPixmapCache::cacheLimit();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPixmapCache.clear();
KMETHOD QPixmapCache_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QPixmapCache::clear();
	}
	RETURNvoid_();
}

//boolean QPixmapCache.find(String key, QPixmap pixmap);
KMETHOD QPixmapCache_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString key = String_to(const QString, sfp[1]);
		QPixmap*  pixmap = RawPtr_to(QPixmap*, sfp[2]);
		bool ret_v = QPixmapCache::find(key, pixmap);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPixmapCache.insert(String key, QPixmap pixmap);
KMETHOD QPixmapCache_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString key = String_to(const QString, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		bool ret_v = QPixmapCache::insert(key, pixmap);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QPixmapCache.remove(String key);
KMETHOD QPixmapCache_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString key = String_to(const QString, sfp[1]);
		QPixmapCache::remove(key);
	}
	RETURNvoid_();
}

//void QPixmapCache.setCacheLimit(int n);
KMETHOD QPixmapCache_setCacheLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int n = Int_to(int, sfp[1]);
		QPixmapCache::setCacheLimit(n);
	}
	RETURNvoid_();
}

//Array<String> QPixmapCache.parents();
KMETHOD QPixmapCache_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmapCache *qp = RawPtr_to(QPixmapCache*, sfp[0]);
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

DummyQPixmapCache::DummyQPixmapCache()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQPixmapCache::~DummyQPixmapCache()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

knh_Object_t** DummyQPixmapCache::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPixmapCache::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQPixmapCache::connection(QObject *o)
{
	QPixmapCache *p = dynamic_cast<QPixmapCache*>(o);
	if (p != NULL) {
	}
}

KQPixmapCache::~KQPixmapCache()
{
	delete dummy;
	dummy = NULL;
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
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQPixmapCache *qp = (KQPixmapCache *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QPixmapCache*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QPixmapCache_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQPixmapCache *qp = (KQPixmapCache *)p->rawptr;
		KQPixmapCache *qp = static_cast<KQPixmapCache*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
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


