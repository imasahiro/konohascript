//QBitArray QBitArray.new();
KMETHOD QBitArray_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBitArray *ret_v = new KQBitArray();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QBitArray QBitArray.new(int size, boolean value);
KMETHOD QBitArray_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int size = Int_to(int, sfp[1]);
	bool value = Boolean_to(bool, sfp[2]);
	KQBitArray *ret_v = new KQBitArray(size, value);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QBitArray QBitArray.new(QBitArray other);
KMETHOD QBitArray_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QBitArray  other = *RawPtr_to(const QBitArray *, sfp[1]);
	KQBitArray *ret_v = new KQBitArray(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QBitArray.at(int i);
KMETHOD QBitArray_at(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		bool ret_v = qp->at(i);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QBitArray.clear();
KMETHOD QBitArray_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QBitArray.clearBit(int i);
KMETHOD QBitArray_clearBit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		qp->clearBit(i);
	}
	RETURNvoid_();
}

//int QBitArray.count();
KMETHOD QBitArray_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QBitArray.count(boolean on);
KMETHOD QBitArray_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		bool on = Boolean_to(bool, sfp[1]);
		int ret_v = qp->count(on);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//boolean QBitArray.fill(boolean value, int size);
KMETHOD QBitArray_fill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		bool value = Boolean_to(bool, sfp[1]);
		int size = Int_to(int, sfp[2]);
		bool ret_v = qp->fill(value, size);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//void QBitArray.fill(boolean value, int begin, int end);
KMETHOD QBitArray_fill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		bool value = Boolean_to(bool, sfp[1]);
		int begin = Int_to(int, sfp[2]);
		int end = Int_to(int, sfp[3]);
		qp->fill(value, begin, end);
	}
	RETURNvoid_();
}
*/
//boolean QBitArray.isEmpty();
KMETHOD QBitArray_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QBitArray.isNull();
KMETHOD QBitArray_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QBitArray.resize(int size);
KMETHOD QBitArray_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int size = Int_to(int, sfp[1]);
		qp->resize(size);
	}
	RETURNvoid_();
}

//void QBitArray.setBit(int i);
KMETHOD QBitArray_setBit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		qp->setBit(i);
	}
	RETURNvoid_();
}

/*
//void QBitArray.setBit(int i, boolean value);
KMETHOD QBitArray_setBit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		bool value = Boolean_to(bool, sfp[2]);
		qp->setBit(i, value);
	}
	RETURNvoid_();
}
*/
//int QBitArray.size();
KMETHOD QBitArray_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->size();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QBitArray.testBit(int i);
KMETHOD QBitArray_testBit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		bool ret_v = qp->testBit(i);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QBitArray.toggleBit(int i);
KMETHOD QBitArray_toggleBit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		bool ret_v = qp->toggleBit(i);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QBitArray.truncate(int pos);
KMETHOD QBitArray_truncate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBitArray *  qp = RawPtr_to(QBitArray *, sfp[0]);
	if (qp != NULL) {
		int pos = Int_to(int, sfp[1]);
		qp->truncate(pos);
	}
	RETURNvoid_();
}


DummyQBitArray::DummyQBitArray()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQBitArray::setSelf(knh_RawPtr_t *ptr)
{
	DummyQBitArray::self = ptr;
}

bool DummyQBitArray::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQBitArray::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBitArray::event_map->bigin();
	if ((itr = DummyQBitArray::event_map->find(str)) == DummyQBitArray::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQBitArray::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBitArray::slot_map->bigin();
	if ((itr = DummyQBitArray::event_map->find(str)) == DummyQBitArray::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQBitArray::KQBitArray() : QBitArray()
{
	self = NULL;
}

KMETHOD QBitArray_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBitArray *qp = RawPtr_to(KQBitArray *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QBitArray]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQBitArray::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBitArray]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QBitArray_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBitArray *qp = RawPtr_to(KQBitArray *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QBitArray]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQBitArray::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBitArray]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QBitArray_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQBitArray *qp = (KQBitArray *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QBitArray_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQBitArray *qp = (KQBitArray *)p->rawptr;
		(void)qp;
	}
}

static int QBitArray_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QBitArray*>(p1->rawptr) == *static_cast<QBitArray*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQBitArray(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QBitArray";
	cdef->free = QBitArray_free;
	cdef->reftrace = QBitArray_reftrace;
	cdef->compareTo = QBitArray_compareTo;
}


