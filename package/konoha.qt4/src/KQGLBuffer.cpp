//QGLBuffer QGLBuffer.new();
KMETHOD QGLBuffer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLBuffer *ret_v = new KQGLBuffer();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLBuffer QGLBuffer.new(int type);
KMETHOD QGLBuffer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer::Type type = Int_to(QGLBuffer::Type, sfp[1]);
	KQGLBuffer *ret_v = new KQGLBuffer(type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGLBuffer QGLBuffer.new(QGLBuffer other);
KMETHOD QGLBuffer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QGLBuffer  other = *RawPtr_to(const QGLBuffer *, sfp[1]);
	KQGLBuffer *ret_v = new KQGLBuffer(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QGLBuffer.allocate(void data, int count);
KMETHOD QGLBuffer_allocate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		const void*  data = RawPtr_to(const void*, sfp[1]);
		int count = Int_to(int, sfp[2]);
		qp->allocate(data, count);
	}
	RETURNvoid_();
}

/*
//void QGLBuffer.allocate(int count);
KMETHOD QGLBuffer_allocate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		int count = Int_to(int, sfp[1]);
		qp->allocate(count);
	}
	RETURNvoid_();
}
*/
//boolean QGLBuffer.bind();
KMETHOD QGLBuffer_bind(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->bind();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//GLuint QGLBuffer.bufferId();
KMETHOD QGLBuffer_bufferId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		GLuint ret_v = qp->bufferId();
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGLBuffer.create();
KMETHOD QGLBuffer_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->create();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLBuffer.destroy();
KMETHOD QGLBuffer_destroy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		qp->destroy();
	}
	RETURNvoid_();
}

//boolean QGLBuffer.isCreated();
KMETHOD QGLBuffer_isCreated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCreated();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLBuffer.map(int access);
KMETHOD QGLBuffer_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		QGLBuffer::Access access = Int_to(QGLBuffer::Access, sfp[1]);
		void* ret_v = qp->map(access);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGLBuffer.read(int offset, void data, int count);
KMETHOD QGLBuffer_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		int offset = Int_to(int, sfp[1]);
		void*  data = RawPtr_to(void*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		bool ret_v = qp->read(offset, data, count);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLBuffer.release();
KMETHOD QGLBuffer_release(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		qp->release();
	}
	RETURNvoid_();
}

//void QGLBuffer.setUsagePattern(int value);
KMETHOD QGLBuffer_setUsagePattern(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		QGLBuffer::UsagePattern value = Int_to(QGLBuffer::UsagePattern, sfp[1]);
		qp->setUsagePattern(value);
	}
	RETURNvoid_();
}

//int QGLBuffer.size();
KMETHOD QGLBuffer_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		int ret_v = qp->size();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGLBuffer.type();
KMETHOD QGLBuffer_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		QGLBuffer::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLBuffer.unmap();
KMETHOD QGLBuffer_unmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->unmap();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLBuffer.getUsagePattern();
KMETHOD QGLBuffer_getUsagePattern(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		QGLBuffer::UsagePattern ret_v = qp->usagePattern();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGLBuffer.write(int offset, void data, int count);
KMETHOD QGLBuffer_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *  qp = RawPtr_to(QGLBuffer *, sfp[0]);
	if (qp) {
		int offset = Int_to(int, sfp[1]);
		const void*  data = RawPtr_to(const void*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->write(offset, data, count);
	}
	RETURNvoid_();
}

/*
//void QGLBuffer.release(int type);
KMETHOD QGLBuffer_release(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QGLBuffer::Type type = Int_to(QGLBuffer::Type, sfp[1]);
		QGLBuffer::release(type);
	}
	RETURNvoid_();
}
*/
//Array<String> QGLBuffer.parents();
KMETHOD QGLBuffer_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLBuffer *qp = RawPtr_to(QGLBuffer*, sfp[0]);
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

DummyQGLBuffer::DummyQGLBuffer()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGLBuffer::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLBuffer::self = ptr;
}

bool DummyQGLBuffer::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGLBuffer::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLBuffer::event_map->bigin();
	if ((itr = DummyQGLBuffer::event_map->find(str)) == DummyQGLBuffer::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLBuffer::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLBuffer::slot_map->bigin();
	if ((itr = DummyQGLBuffer::slot_map->find(str)) == DummyQGLBuffer::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLBuffer::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLBuffer::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQGLBuffer::connection(QObject *o)
{
	QGLBuffer *p = dynamic_cast<QGLBuffer*>(o);
	if (p != NULL) {
	}
}

KQGLBuffer::KQGLBuffer() : QGLBuffer()
{
	self = NULL;
	dummy = new DummyQGLBuffer();
}

KMETHOD QGLBuffer_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLBuffer *qp = RawPtr_to(KQGLBuffer *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLBuffer]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLBuffer]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLBuffer_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLBuffer *qp = RawPtr_to(KQGLBuffer *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLBuffer]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLBuffer]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLBuffer_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGLBuffer *qp = (KQGLBuffer *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGLBuffer_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGLBuffer *qp = (KQGLBuffer *)p->rawptr;
//		KQGLBuffer *qp = static_cast<KQGLBuffer*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLBuffer_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGLBuffer::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QGLBufferConstInt[] = {
	{"ReadOnly", QGLBuffer::ReadOnly},
	{"WriteOnly", QGLBuffer::WriteOnly},
	{"ReadWrite", QGLBuffer::ReadWrite},
	{"VertexBuffer", QGLBuffer::VertexBuffer},
	{"IndexBuffer", QGLBuffer::IndexBuffer},
	{"PixelPackBuffer", QGLBuffer::PixelPackBuffer},
	{"PixelUnpackBuffer", QGLBuffer::PixelUnpackBuffer},
	{"StreamDraw", QGLBuffer::StreamDraw},
	{"StreamRead", QGLBuffer::StreamRead},
	{"StreamCopy", QGLBuffer::StreamCopy},
	{"StaticDraw", QGLBuffer::StaticDraw},
	{"StaticRead", QGLBuffer::StaticRead},
	{"StaticCopy", QGLBuffer::StaticCopy},
	{"DynamicDraw", QGLBuffer::DynamicDraw},
	{"DynamicRead", QGLBuffer::DynamicRead},
	{"DynamicCopy", QGLBuffer::DynamicCopy},
	{NULL, 0}
};

DEFAPI(void) constQGLBuffer(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGLBufferConstInt);
}


DEFAPI(void) defQGLBuffer(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLBuffer";
	cdef->free = QGLBuffer_free;
	cdef->reftrace = QGLBuffer_reftrace;
	cdef->compareTo = QGLBuffer_compareTo;
}


