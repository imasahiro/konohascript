//QNetworkCookieJar QNetworkCookieJar.new(QObject parent);
KMETHOD QNetworkCookieJar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQNetworkCookieJar *ret_v = new KQNetworkCookieJar(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//@Virtual Array<QNetworkCookie> QNetworkCookieJar.cookiesForUrl(QUrl url);
KMETHOD QNetworkCookieJar_cookiesForUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookieJar *  qp = RawPtr_to(QNetworkCookieJar *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		QList<QNetworkCookie> ret_v = qp->cookiesForUrl(url);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QNetworkCookie"));
		for (int n = 0; n < list_size; n++) {
			QNetworkCookie *ret_v_ = new QNetworkCookie(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//@Virtual boolean QNetworkCookieJar.setCookiesFromUrl(Array<QNetworkCookie> cookieList, QUrl url);
KMETHOD QNetworkCookieJar_setCookiesFromUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookieJar *  qp = RawPtr_to(QNetworkCookieJar *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QNetworkCookie> cookieList;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			cookieList.append(*(QNetworkCookie*)p->rawptr);
		}
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[2]);
		bool ret_v = qp->setCookiesFromUrl(cookieList, url);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQNetworkCookieJar::DummyQNetworkCookieJar()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQNetworkCookieJar::~DummyQNetworkCookieJar()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQNetworkCookieJar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkCookieJar::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQNetworkCookieJar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQNetworkCookieJar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkCookieJar::event_map->bigin();
	if ((itr = DummyQNetworkCookieJar::event_map->find(str)) == DummyQNetworkCookieJar::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkCookieJar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkCookieJar::slot_map->bigin();
	if ((itr = DummyQNetworkCookieJar::slot_map->find(str)) == DummyQNetworkCookieJar::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkCookieJar::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkCookieJar::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQNetworkCookieJar::connection(QObject *o)
{
	QNetworkCookieJar *p = dynamic_cast<QNetworkCookieJar*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQNetworkCookieJar::KQNetworkCookieJar(QObject* parent) : QNetworkCookieJar(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQNetworkCookieJar();
	dummy->connection((QObject*)this);
}

KQNetworkCookieJar::~KQNetworkCookieJar()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QNetworkCookieJar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkCookieJar *qp = RawPtr_to(KQNetworkCookieJar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkCookieJar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkCookieJar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkCookieJar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkCookieJar *qp = RawPtr_to(KQNetworkCookieJar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkCookieJar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkCookieJar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkCookieJar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQNetworkCookieJar *qp = (KQNetworkCookieJar *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QNetworkCookieJar*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QNetworkCookieJar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQNetworkCookieJar *qp = (KQNetworkCookieJar *)p->rawptr;
		KQNetworkCookieJar *qp = static_cast<KQNetworkCookieJar*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkCookieJar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQNetworkCookieJar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQNetworkCookieJar::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QNetworkCookieJar::event(event);
		return false;
	}
//	QNetworkCookieJar::event(event);
	return true;
}



DEFAPI(void) defQNetworkCookieJar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkCookieJar";
	cdef->free = QNetworkCookieJar_free;
	cdef->reftrace = QNetworkCookieJar_reftrace;
	cdef->compareTo = QNetworkCookieJar_compareTo;
}


