//QColormap QColormap.new(QColormap colormap);
KMETHOD QColormap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QColormap  colormap = *RawPtr_to(const QColormap *, sfp[1]);
	KQColormap *ret_v = new KQColormap(colormap);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QColor QColormap.colorAt(int pixel);
KMETHOD QColormap_colorAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColormap *  qp = RawPtr_to(QColormap *, sfp[0]);
	if (qp) {
		uint  pixel = *RawPtr_to(uint *, sfp[1]);
		const QColor ret_v = qp->colorAt(pixel);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QColormap.depth();
KMETHOD QColormap_depth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColormap *  qp = RawPtr_to(QColormap *, sfp[0]);
	if (qp) {
		int ret_v = qp->depth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QColormap.mode();
KMETHOD QColormap_mode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColormap *  qp = RawPtr_to(QColormap *, sfp[0]);
	if (qp) {
		QColormap::Mode ret_v = qp->mode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QColormap.pixel(QColor color);
KMETHOD QColormap_pixel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColormap *  qp = RawPtr_to(QColormap *, sfp[0]);
	if (qp) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		uint ret_v = qp->pixel(color);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QColormap.size();
KMETHOD QColormap_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColormap *  qp = RawPtr_to(QColormap *, sfp[0]);
	if (qp) {
		int ret_v = qp->size();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QColormap QColormap.instance(int screen);
KMETHOD QColormap_instance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int screen = Int_to(int, sfp[1]);
		QColormap ret_v = QColormap::instance(screen);
		QColormap *ret_v_ = new QColormap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QColormap.parents();
KMETHOD QColormap_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColormap *qp = RawPtr_to(QColormap*, sfp[0]);
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

DummyQColormap::DummyQColormap()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQColormap::setSelf(knh_RawPtr_t *ptr)
{
	DummyQColormap::self = ptr;
}

bool DummyQColormap::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQColormap::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColormap::event_map->bigin();
	if ((itr = DummyQColormap::event_map->find(str)) == DummyQColormap::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQColormap::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColormap::slot_map->bigin();
	if ((itr = DummyQColormap::slot_map->find(str)) == DummyQColormap::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQColormap::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQColormap::connection(QObject *o)
{
	QColormap *p = dynamic_cast<QColormap*>(o);
	if (p != NULL) {
	}
}

KQColormap::KQColormap(const QColormap colormap) : QColormap(colormap)
{
	self = NULL;
	dummy = new DummyQColormap();
}

KMETHOD QColormap_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColormap *qp = RawPtr_to(KQColormap *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QColormap]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColormap]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QColormap_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColormap *qp = RawPtr_to(KQColormap *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QColormap]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColormap]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QColormap_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQColormap *qp = (KQColormap *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QColormap_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQColormap *qp = (KQColormap *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QColormap_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQColormap::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QColormapConstInt[] = {
	{"Direct", QColormap::Direct},
	{"Indexed", QColormap::Indexed},
	{"Gray", QColormap::Gray},
	{NULL, 0}
};

DEFAPI(void) constQColormap(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QColormapConstInt);
}


DEFAPI(void) defQColormap(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QColormap";
	cdef->free = QColormap_free;
	cdef->reftrace = QColormap_reftrace;
	cdef->compareTo = QColormap_compareTo;
}


