//QGLColormap QGLColormap.new();
KMETHOD QGLColormap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLColormap *ret_v = new KQGLColormap();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLColormap QGLColormap.new(QGLColormap map);
KMETHOD QGLColormap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QGLColormap  map = *RawPtr_to(const QGLColormap *, sfp[1]);
	KQGLColormap *ret_v = new KQGLColormap(map);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QColor QGLColormap.entryColor(int idx);
KMETHOD QGLColormap_entryColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		int idx = Int_to(int, sfp[1]);
		QColor ret_v = qp->entryColor(idx);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRgb QGLColormap.entryRgb(int idx);
KMETHOD QGLColormap_entryRgb(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		int idx = Int_to(int, sfp[1]);
		QRgb ret_v = qp->entryRgb(idx);
		QRgb *ret_v_ = new QRgb(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGLColormap.find(QRgb color);
KMETHOD QGLColormap_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		QRgb  color = *RawPtr_to(QRgb *, sfp[1]);
		int ret_v = qp->find(color);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGLColormap.findNearest(QRgb color);
KMETHOD QGLColormap_findNearest(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		QRgb  color = *RawPtr_to(QRgb *, sfp[1]);
		int ret_v = qp->findNearest(color);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLColormap.isEmpty();
KMETHOD QGLColormap_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLColormap.setEntries(int count, QRgb colors, int base);
KMETHOD QGLColormap_setEntries(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		int count = Int_to(int, sfp[1]);
		const QRgb*  colors = RawPtr_to(const QRgb*, sfp[2]);
		int base = Int_to(int, sfp[3]);
		qp->setEntries(count, colors, base);
	}
	RETURNvoid_();
}

//void QGLColormap.setEntry(int idx, QRgb color);
KMETHOD QGLColormap_setEntry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		int idx = Int_to(int, sfp[1]);
		QRgb  color = *RawPtr_to(QRgb *, sfp[2]);
		qp->setEntry(idx, color);
	}
	RETURNvoid_();
}

/*
//void QGLColormap.setEntry(int idx, QColor color);
KMETHOD QGLColormap_setEntry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		int idx = Int_to(int, sfp[1]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[2]);
		qp->setEntry(idx, color);
	}
	RETURNvoid_();
}
*/
//int QGLColormap.size();
KMETHOD QGLColormap_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *  qp = RawPtr_to(QGLColormap *, sfp[0]);
	if (qp) {
		int ret_v = qp->size();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QGLColormap.parents();
KMETHOD QGLColormap_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLColormap *qp = RawPtr_to(QGLColormap*, sfp[0]);
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

DummyQGLColormap::DummyQGLColormap()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGLColormap::~DummyQGLColormap()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGLColormap::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLColormap::self = ptr;
}

bool DummyQGLColormap::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGLColormap::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLColormap::event_map->bigin();
	if ((itr = DummyQGLColormap::event_map->find(str)) == DummyQGLColormap::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLColormap::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLColormap::slot_map->bigin();
	if ((itr = DummyQGLColormap::slot_map->find(str)) == DummyQGLColormap::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLColormap::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLColormap::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQGLColormap::connection(QObject *o)
{
	QGLColormap *p = dynamic_cast<QGLColormap*>(o);
	if (p != NULL) {
	}
}

KQGLColormap::KQGLColormap() : QGLColormap()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGLColormap();
}

KQGLColormap::~KQGLColormap()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGLColormap_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLColormap *qp = RawPtr_to(KQGLColormap *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLColormap]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLColormap]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLColormap_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLColormap *qp = RawPtr_to(KQGLColormap *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLColormap]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLColormap]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLColormap_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGLColormap *qp = (KQGLColormap *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGLColormap*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGLColormap_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGLColormap *qp = (KQGLColormap *)p->rawptr;
		KQGLColormap *qp = static_cast<KQGLColormap*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLColormap_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGLColormap::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGLColormap(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLColormap";
	cdef->free = QGLColormap_free;
	cdef->reftrace = QGLColormap_reftrace;
	cdef->compareTo = QGLColormap_compareTo;
}


