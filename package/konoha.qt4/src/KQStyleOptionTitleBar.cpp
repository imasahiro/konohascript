//QStyleOptionTitleBar QStyleOptionTitleBar.new();
KMETHOD QStyleOptionTitleBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTitleBar *ret_v = new KQStyleOptionTitleBar();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTitleBar QStyleOptionTitleBar.new(QStyleOptionTitleBar other);
KMETHOD QStyleOptionTitleBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTitleBar  other = *RawPtr_to(const QStyleOptionTitleBar *, sfp[1]);
	KQStyleOptionTitleBar *ret_v = new KQStyleOptionTitleBar(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTitleBar::DummyQStyleOptionTitleBar()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionTitleBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTitleBar::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionTitleBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTitleBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTitleBar::event_map->bigin();
	if ((itr = DummyQStyleOptionTitleBar::event_map->find(str)) == DummyQStyleOptionTitleBar::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTitleBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTitleBar::slot_map->bigin();
	if ((itr = DummyQStyleOptionTitleBar::slot_map->find(str)) == DummyQStyleOptionTitleBar::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionTitleBar::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionTitleBar::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionComplex::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionTitleBar::connection(QObject *o)
{
	QStyleOptionTitleBar *p = dynamic_cast<QStyleOptionTitleBar*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionComplex::connection(o);
}

KQStyleOptionTitleBar::KQStyleOptionTitleBar() : QStyleOptionTitleBar()
{
	self = NULL;
	dummy = new DummyQStyleOptionTitleBar();
}

KMETHOD QStyleOptionTitleBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTitleBar *qp = RawPtr_to(KQStyleOptionTitleBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTitleBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTitleBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTitleBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTitleBar *qp = RawPtr_to(KQStyleOptionTitleBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTitleBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTitleBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTitleBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionTitleBar *qp = (KQStyleOptionTitleBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionTitleBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionTitleBar *qp = (KQStyleOptionTitleBar *)p->rawptr;
//		KQStyleOptionTitleBar *qp = static_cast<KQStyleOptionTitleBar*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionTitleBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTitleBar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionTitleBarConstInt[] = {
	{"Type", QStyleOptionTitleBar::Type},
	{"Version", QStyleOptionTitleBar::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTitleBar(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTitleBarConstInt);
}


DEFAPI(void) defQStyleOptionTitleBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTitleBar";
	cdef->free = QStyleOptionTitleBar_free;
	cdef->reftrace = QStyleOptionTitleBar_reftrace;
	cdef->compareTo = QStyleOptionTitleBar_compareTo;
}


