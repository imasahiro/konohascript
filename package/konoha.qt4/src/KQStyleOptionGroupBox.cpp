//QStyleOptionGroupBox QStyleOptionGroupBox.new();
KMETHOD QStyleOptionGroupBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionGroupBox *ret_v = new KQStyleOptionGroupBox();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionGroupBox QStyleOptionGroupBox.new(QStyleOptionGroupBox other);
KMETHOD QStyleOptionGroupBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionGroupBox  other = *RawPtr_to(const QStyleOptionGroupBox *, sfp[1]);
	KQStyleOptionGroupBox *ret_v = new KQStyleOptionGroupBox(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionGroupBox::DummyQStyleOptionGroupBox()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionGroupBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionGroupBox::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionGroupBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionGroupBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionGroupBox::event_map->bigin();
	if ((itr = DummyQStyleOptionGroupBox::event_map->find(str)) == DummyQStyleOptionGroupBox::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionGroupBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionGroupBox::slot_map->bigin();
	if ((itr = DummyQStyleOptionGroupBox::slot_map->find(str)) == DummyQStyleOptionGroupBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStyleOptionGroupBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQStyleOptionComplex::reftrace(ctx, p, tail_);
}

void DummyQStyleOptionGroupBox::connection(QObject *o)
{
	QStyleOptionGroupBox *p = dynamic_cast<QStyleOptionGroupBox*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionComplex::connection(o);
}

KQStyleOptionGroupBox::KQStyleOptionGroupBox() : QStyleOptionGroupBox()
{
	self = NULL;
	dummy = new DummyQStyleOptionGroupBox();
}

KMETHOD QStyleOptionGroupBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionGroupBox *qp = RawPtr_to(KQStyleOptionGroupBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionGroupBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionGroupBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionGroupBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionGroupBox *qp = RawPtr_to(KQStyleOptionGroupBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionGroupBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionGroupBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionGroupBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionGroupBox *qp = (KQStyleOptionGroupBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionGroupBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionGroupBox *qp = (KQStyleOptionGroupBox *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionGroupBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionGroupBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionGroupBoxConstInt[] = {
	{"Type", QStyleOptionGroupBox::Type},
	{"Version", QStyleOptionGroupBox::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionGroupBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionGroupBoxConstInt);
}


DEFAPI(void) defQStyleOptionGroupBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionGroupBox";
	cdef->free = QStyleOptionGroupBox_free;
	cdef->reftrace = QStyleOptionGroupBox_reftrace;
	cdef->compareTo = QStyleOptionGroupBox_compareTo;
}


