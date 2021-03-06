//QPicture QPicture.new(int formatVersion);
KMETHOD QPicture_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int formatVersion = Int_to(int, sfp[1]);
	KQPicture *ret_v = new KQPicture(formatVersion);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPicture QPicture.new(QPicture pic);
KMETHOD QPicture_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPicture  pic = *RawPtr_to(const QPicture *, sfp[1]);
	KQPicture *ret_v = new KQPicture(pic);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QRect QPicture.getBoundingRect();
KMETHOD QPicture_getBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->boundingRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QPicture.getData();
KMETHOD QPicture_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->data();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPicture.load(String fileName, String fmt);
KMETHOD QPicture_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->load(fileName, format);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QPicture.load(QIODevice dev, String fmt);
KMETHOD QPicture_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		QIODevice*  dev = RawPtr_to(QIODevice*, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->load(dev, format);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QPicture.play(QPainter painter);
KMETHOD QPicture_play(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		bool ret_v = qp->play(painter);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPicture.save(String fileName, String fmt);
KMETHOD QPicture_save(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->save(fileName, format);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QPicture.save(QIODevice dev, String fmt);
KMETHOD QPicture_save(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		QIODevice*  dev = RawPtr_to(QIODevice*, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->save(dev, format);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QPicture.setBoundingRect(QRect r);
KMETHOD QPicture_setBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
		qp->setBoundingRect(r);
	}
	RETURNvoid_();
}

//@Virtual void QPicture.setData(String data, int size);
KMETHOD QPicture_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		uint  size = *RawPtr_to(uint *, sfp[2]);
		qp->setData(data, size);
	}
	RETURNvoid_();
}

//int QPicture.size();
KMETHOD QPicture_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPicture *  qp = RawPtr_to(QPicture *, sfp[0]);
	if (qp) {
		uint ret_v = qp->size();
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQPicture::DummyQPicture()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQPicture::~DummyQPicture()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQPicture::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPicture::self = ptr;
	DummyQPaintDevice::setSelf(ptr);
}

bool DummyQPicture::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPaintDevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPicture::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPicture::event_map->bigin();
	if ((itr = DummyQPicture::event_map->find(str)) == DummyQPicture::event_map->end()) {
		bool ret = false;
		ret = DummyQPaintDevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPicture::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPicture::slot_map->bigin();
	if ((itr = DummyQPicture::slot_map->find(str)) == DummyQPicture::slot_map->end()) {
		bool ret = false;
		ret = DummyQPaintDevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPicture::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPicture::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQPaintDevice::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQPicture::connection(QObject *o)
{
	QPicture *p = dynamic_cast<QPicture*>(o);
	if (p != NULL) {
	}
	DummyQPaintDevice::connection(o);
}

KQPicture::KQPicture(int formatVersion) : QPicture(formatVersion)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQPicture();
}

KQPicture::~KQPicture()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QPicture_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPicture *qp = RawPtr_to(KQPicture *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPicture]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPicture]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPicture_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPicture *qp = RawPtr_to(KQPicture *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPicture]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPicture]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPicture_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQPicture *qp = (KQPicture *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QPicture*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QPicture_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQPicture *qp = (KQPicture *)p->rawptr;
		KQPicture *qp = static_cast<KQPicture*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPicture_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPicture::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQPicture(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPicture";
	cdef->free = QPicture_free;
	cdef->reftrace = QPicture_reftrace;
	cdef->compareTo = QPicture_compareTo;
}


