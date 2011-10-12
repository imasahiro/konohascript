//QMargins QMargins.new();
KMETHOD QMargins_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMargins *ret_v = new KQMargins();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QMargins QMargins.new(int left, int top, int right, int bottom);
KMETHOD QMargins_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int left = Int_to(int, sfp[1]);
	int top = Int_to(int, sfp[2]);
	int right = Int_to(int, sfp[3]);
	int bottom = Int_to(int, sfp[4]);
	KQMargins *ret_v = new KQMargins(left, top, right, bottom);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QMargins.getBottom();
KMETHOD QMargins_getBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->bottom();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

////boolean QMargins.isNull();
KMETHOD QMargins_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QMargins.getLeft();
KMETHOD QMargins_getLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->left();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMargins.getRight();
KMETHOD QMargins_getRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->right();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QMargins.setBottom(int bottom);
KMETHOD QMargins_setBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		int bottom = Int_to(int, sfp[1]);
		qp->setBottom(bottom);
	}
	RETURNvoid_();
}

//void QMargins.setLeft(int left);
KMETHOD QMargins_setLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		int left = Int_to(int, sfp[1]);
		qp->setLeft(left);
	}
	RETURNvoid_();
}

//void QMargins.setRight(int right);
KMETHOD QMargins_setRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		int right = Int_to(int, sfp[1]);
		qp->setRight(right);
	}
	RETURNvoid_();
}

//void QMargins.settop(int top);
KMETHOD QMargins_setTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		int Top = Int_to(int, sfp[1]);
		qp->setTop(Top);
	}
	RETURNvoid_();
}

//int QMargins.gettop();
KMETHOD QMargins_getTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMargins *  qp = RawPtr_to(QMargins *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->top();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQMargins::DummyQMargins()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMargins::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMargins::self = ptr;
}

bool DummyQMargins::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQMargins::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMargins::event_map->bigin();
	if ((itr = DummyQMargins::event_map->find(str)) == DummyQMargins::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMargins::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMargins::slot_map->bigin();
	if ((itr = DummyQMargins::event_map->find(str)) == DummyQMargins::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQMargins::KQMargins() : QMargins()
{
	self = NULL;
}

KMETHOD QMargins_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMargins *qp = RawPtr_to(KQMargins *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMargins]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQMargins::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMargins]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QMargins_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMargins *qp = RawPtr_to(KQMargins *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMargins]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQMargins::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMargins]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMargins_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMargins *qp = (KQMargins *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMargins_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQMargins *qp = (KQMargins *)p->rawptr;
		(void)qp;
	}
}

static int QMargins_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQMargins(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMargins";
	cdef->free = QMargins_free;
	cdef->reftrace = QMargins_reftrace;
	cdef->compareTo = QMargins_compareTo;
}


