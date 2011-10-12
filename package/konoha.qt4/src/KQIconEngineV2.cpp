//Array<QSize> QIconEngineV2.availableSizes(int mode, int state);
KMETHOD QIconEngineV2_availableSizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngineV2 *  qp = RawPtr_to(QIconEngineV2 *, sfp[0]);
	if (qp != NULL) {
		QIcon::Mode mode = Int_to(QIcon::Mode, sfp[1]);
		QIcon::State state = Int_to(QIcon::State, sfp[2]);
		QList<QSize>ret_v = qp->availableSizes(mode, state);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSize"));
		for (int n = 0; n < list_size; n++) {
			QSize *ret_v_ = new QSize(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//@Virtual QIconEngineV2 QIconEngineV2.clone();
KMETHOD QIconEngineV2_clone(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngineV2 *  qp = RawPtr_to(QIconEngineV2 *, sfp[0]);
	if (qp != NULL) {
		QIconEngineV2* ret_v = qp->clone();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIconEngineV2*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QIconEngineV2.iconName();
KMETHOD QIconEngineV2_iconName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngineV2 *  qp = RawPtr_to(QIconEngineV2 *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->iconName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual String QIconEngineV2.key();
KMETHOD QIconEngineV2_key(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngineV2 *  qp = RawPtr_to(QIconEngineV2 *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->key();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QIconEngineV2.virtual_hook(int id, void data);
KMETHOD QIconEngineV2_virtual_hook(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIconEngineV2 *  qp = RawPtr_to(QIconEngineV2 *, sfp[0]);
	if (qp != NULL) {
		int id = Int_to(int, sfp[1]);
		void*  data = RawPtr_to(void*, sfp[2]);
		qp->virtual_hook(id, data);
	}
	RETURNvoid_();
}


DummyQIconEngineV2::DummyQIconEngineV2()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQIconEngineV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQIconEngineV2::self = ptr;
	DummyQIconEngine::setSelf(ptr);
}

bool DummyQIconEngineV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQIconEngine::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQIconEngineV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIconEngineV2::event_map->bigin();
	if ((itr = DummyQIconEngineV2::event_map->find(str)) == DummyQIconEngineV2::event_map->end()) {
		bool ret;
		ret = DummyQIconEngine::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQIconEngineV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIconEngineV2::slot_map->bigin();
	if ((itr = DummyQIconEngineV2::event_map->find(str)) == DummyQIconEngineV2::slot_map->end()) {
		bool ret;
		ret = DummyQIconEngine::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQIconEngineV2::KQIconEngineV2() : QIconEngineV2()
{
	self = NULL;
}

KMETHOD QIconEngineV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIconEngineV2 *qp = RawPtr_to(KQIconEngineV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QIconEngineV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQIconEngineV2::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIconEngineV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QIconEngineV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIconEngineV2 *qp = RawPtr_to(KQIconEngineV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QIconEngineV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQIconEngineV2::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIconEngineV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QIconEngineV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQIconEngineV2 *qp = (KQIconEngineV2 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QIconEngineV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQIconEngineV2 *qp = (KQIconEngineV2 *)p->rawptr;
		(void)qp;
	}
}

static int QIconEngineV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQIconEngineV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QIconEngineV2";
	cdef->free = QIconEngineV2_free;
	cdef->reftrace = QIconEngineV2_reftrace;
	cdef->compareTo = QIconEngineV2_compareTo;
}

static knh_IntData_t QIconEngineV2ConstInt[] = {
	{"AvailableSizesHook", QIconEngineV2::AvailableSizesHook},
	{"IconNameHook", QIconEngineV2::IconNameHook},
	{NULL, 0}
};

DEFAPI(void) constQIconEngineV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QIconEngineV2ConstInt);
}

