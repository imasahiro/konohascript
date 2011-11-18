//QBitmap QBitmap.new();
KMETHOD QBitmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBitmap *ret_v = new KQBitmap();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QBitmap QBitmap.new(QPixmap pixmap);
KMETHOD QBitmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
	KQBitmap *ret_v = new KQBitmap(pixmap);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QBitmap QBitmap.new(int width, int height);
KMETHOD QBitmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	KQBitmap *ret_v = new KQBitmap(width, height);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QBitmap QBitmap.new(QSize size);
KMETHOD QBitmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	KQBitmap *ret_v = new KQBitmap(size);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QBitmap QBitmap.new(String fileName, String fmt);
KMETHOD QBitmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	const char*  format = RawPtr_to(const char*, sfp[2]);
	KQBitmap *ret_v = new KQBitmap(fileName, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QBitmap.clear();
KMETHOD QBitmap_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitmap *  qp = RawPtr_to(QBitmap *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//QBitmap QBitmap.fromData(QSize size, String bits, int monoFormat);
KMETHOD QBitmap_fromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		const uchar*  bits = RawPtr_to(const uchar*, sfp[2]);
		QImage::Format monoFormat = Int_to(QImage::Format, sfp[3]);
		QBitmap ret_v = QBitmap::fromData(size, bits, monoFormat);
		QBitmap *ret_v_ = new QBitmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBitmap QBitmap.fromImage(QImage image, QtImageConversionFlags flags);
KMETHOD QBitmap_fromImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		initFlag(flags, Qt::ImageConversionFlags, sfp[2]);
		QBitmap ret_v = QBitmap::fromImage(image, flags);
		QBitmap *ret_v_ = new QBitmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQBitmap::DummyQBitmap()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQBitmap::~DummyQBitmap()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQBitmap::setSelf(knh_RawPtr_t *ptr)
{
	DummyQBitmap::self = ptr;
	DummyQPixmap::setSelf(ptr);
}

bool DummyQBitmap::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPixmap::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQBitmap::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBitmap::event_map->bigin();
	if ((itr = DummyQBitmap::event_map->find(str)) == DummyQBitmap::event_map->end()) {
		bool ret = false;
		ret = DummyQPixmap::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQBitmap::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBitmap::slot_map->bigin();
	if ((itr = DummyQBitmap::slot_map->find(str)) == DummyQBitmap::slot_map->end()) {
		bool ret = false;
		ret = DummyQPixmap::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQBitmap::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQBitmap::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQPixmap::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQBitmap::connection(QObject *o)
{
	QBitmap *p = dynamic_cast<QBitmap*>(o);
	if (p != NULL) {
	}
	DummyQPixmap::connection(o);
}

KQBitmap::KQBitmap() : QBitmap()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQBitmap();
}

KQBitmap::~KQBitmap()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QBitmap_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBitmap *qp = RawPtr_to(KQBitmap *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QBitmap]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBitmap]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QBitmap_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBitmap *qp = RawPtr_to(KQBitmap *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QBitmap]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBitmap]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QBitmap_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQBitmap *qp = (KQBitmap *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QBitmap*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QBitmap_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQBitmap *qp = (KQBitmap *)p->rawptr;
		KQBitmap *qp = static_cast<KQBitmap*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QBitmap_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQBitmap::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQBitmap(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QBitmap";
	cdef->free = QBitmap_free;
	cdef->reftrace = QBitmap_reftrace;
	cdef->compareTo = QBitmap_compareTo;
}


