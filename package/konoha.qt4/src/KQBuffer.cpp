//@Virtual @Override boolean QBuffer.atEnd();
KMETHOD QBuffer_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->atEnd();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QBuffer.canReadLine();
KMETHOD QBuffer_canReadLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->canReadLine();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override void QBuffer.close();
KMETHOD QBuffer_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		qp->close();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QBuffer.open(int flags);
KMETHOD QBuffer_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		QBuffer::OpenMode  flags = *RawPtr_to(QBuffer::OpenMode *, sfp[1]);
		bool ret_v = qp->open(flags);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QBuffer.pos();
KMETHOD QBuffer_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		qint64 ret_v = qp->pos();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QBuffer.seek(int pos);
KMETHOD QBuffer_seek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		qint64 pos = Int_to(qint64, sfp[1]);
		bool ret_v = qp->seek(pos);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QBuffer.size();
KMETHOD QBuffer_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		qint64 ret_v = qp->size();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBuffer QBuffer.new(QObject parent);
KMETHOD QBuffer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQBuffer *ret_v = new KQBuffer(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QBuffer QBuffer.new(QByteArray byteArray, QObject parent);
KMETHOD QBuffer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray*  byteArray = RawPtr_to(QByteArray*, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQBuffer *ret_v = new KQBuffer(byteArray, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QByteArray QBuffer.getBuffer();
KMETHOD QBuffer_getBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		QByteArray ret_v = qp->buffer();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QBuffer.getBuffer();
KMETHOD QBuffer_getBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		const QByteArray ret_v = qp->buffer();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QByteArray QBuffer.getData();
KMETHOD QBuffer_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		const QByteArray ret_v = qp->data();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QBuffer.setBuffer(QByteArray byteArray);
KMETHOD QBuffer_setBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		QByteArray*  byteArray = RawPtr_to(QByteArray*, sfp[1]);
		qp->setBuffer(byteArray);
	}
	RETURNvoid_();
}

//void QBuffer.setData(QByteArray data);
KMETHOD QBuffer_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setData(data);
	}
	RETURNvoid_();
}

/*
//void QBuffer.setData(String data, int size);
KMETHOD QBuffer_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBuffer *  qp = RawPtr_to(QBuffer *, sfp[0]);
	if (qp != NULL) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		int size = Int_to(int, sfp[2]);
		qp->setData(data, size);
	}
	RETURNvoid_();
}
*/

DummyQBuffer::DummyQBuffer()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQBuffer::setSelf(knh_RawPtr_t *ptr)
{
	DummyQBuffer::self = ptr;
	DummyQIODevice::setSelf(ptr);
}

bool DummyQBuffer::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQIODevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQBuffer::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBuffer::event_map->bigin();
	if ((itr = DummyQBuffer::event_map->find(str)) == DummyQBuffer::event_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQBuffer::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBuffer::slot_map->bigin();
	if ((itr = DummyQBuffer::slot_map->find(str)) == DummyQBuffer::slot_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQBuffer::connection(QObject *o)
{
	DummyQIODevice::connection(o);
}

KQBuffer::KQBuffer(QObject* parent) : QBuffer(parent)
{
	self = NULL;
	dummy = new DummyQBuffer();
	dummy->connection((QObject*)this);
}

KMETHOD QBuffer_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBuffer *qp = RawPtr_to(KQBuffer *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QBuffer]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBuffer]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QBuffer_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBuffer *qp = RawPtr_to(KQBuffer *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QBuffer]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBuffer]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QBuffer_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQBuffer *qp = (KQBuffer *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QBuffer_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQBuffer *qp = (KQBuffer *)p->rawptr;
		(void)qp;
	}
}

static int QBuffer_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQBuffer::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQBuffer::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QBuffer::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQBuffer(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QBuffer";
	cdef->free = QBuffer_free;
	cdef->reftrace = QBuffer_reftrace;
	cdef->compareTo = QBuffer_compareTo;
}


