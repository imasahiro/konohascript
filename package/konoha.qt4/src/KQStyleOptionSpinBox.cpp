//QStyleOptionSpinBox QStyleOptionSpinBox.new();
KMETHOD QStyleOptionSpinBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSpinBox *ret_v = new KQStyleOptionSpinBox();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionSpinBox QStyleOptionSpinBox.new(QStyleOptionSpinBox other);
KMETHOD QStyleOptionSpinBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionSpinBox  other = *RawPtr_to(const QStyleOptionSpinBox *, sfp[1]);
	KQStyleOptionSpinBox *ret_v = new KQStyleOptionSpinBox(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionSpinBox::DummyQStyleOptionSpinBox()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionSpinBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionSpinBox::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionSpinBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionSpinBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionSpinBox::event_map->bigin();
	if ((itr = DummyQStyleOptionSpinBox::event_map->find(str)) == DummyQStyleOptionSpinBox::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionSpinBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionSpinBox::slot_map->bigin();
	if ((itr = DummyQStyleOptionSpinBox::slot_map->find(str)) == DummyQStyleOptionSpinBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionSpinBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionSpinBox::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionComplex::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionSpinBox::connection(QObject *o)
{
	QStyleOptionSpinBox *p = dynamic_cast<QStyleOptionSpinBox*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionComplex::connection(o);
}

KQStyleOptionSpinBox::KQStyleOptionSpinBox() : QStyleOptionSpinBox()
{
	self = NULL;
	dummy = new DummyQStyleOptionSpinBox();
}

KMETHOD QStyleOptionSpinBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSpinBox *qp = RawPtr_to(KQStyleOptionSpinBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionSpinBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionSpinBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionSpinBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSpinBox *qp = RawPtr_to(KQStyleOptionSpinBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionSpinBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionSpinBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionSpinBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionSpinBox *qp = (KQStyleOptionSpinBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionSpinBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionSpinBox *qp = (KQStyleOptionSpinBox *)p->rawptr;
//		KQStyleOptionSpinBox *qp = static_cast<KQStyleOptionSpinBox*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionSpinBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionSpinBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionSpinBoxConstInt[] = {
	{"Type", QStyleOptionSpinBox::Type},
	{"Version", QStyleOptionSpinBox::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionSpinBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionSpinBoxConstInt);
}


DEFAPI(void) defQStyleOptionSpinBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionSpinBox";
	cdef->free = QStyleOptionSpinBox_free;
	cdef->reftrace = QStyleOptionSpinBox_reftrace;
	cdef->compareTo = QStyleOptionSpinBox_compareTo;
}


