//QStyleOptionComboBox QStyleOptionComboBox.new();
KMETHOD QStyleOptionComboBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionComboBox *ret_v = new KQStyleOptionComboBox();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionComboBox QStyleOptionComboBox.new(QStyleOptionComboBox other);
KMETHOD QStyleOptionComboBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionComboBox  other = *RawPtr_to(const QStyleOptionComboBox *, sfp[1]);
	KQStyleOptionComboBox *ret_v = new KQStyleOptionComboBox(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionComboBox::DummyQStyleOptionComboBox()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionComboBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionComboBox::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionComboBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionComboBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionComboBox::event_map->bigin();
	if ((itr = DummyQStyleOptionComboBox::event_map->find(str)) == DummyQStyleOptionComboBox::event_map->end()) {
		bool ret;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionComboBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionComboBox::slot_map->bigin();
	if ((itr = DummyQStyleOptionComboBox::event_map->find(str)) == DummyQStyleOptionComboBox::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionComboBox::KQStyleOptionComboBox() : QStyleOptionComboBox()
{
	self = NULL;
}

KMETHOD QStyleOptionComboBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionComboBox *qp = RawPtr_to(KQStyleOptionComboBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionComboBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionComboBox::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionComboBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionComboBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionComboBox *qp = RawPtr_to(KQStyleOptionComboBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionComboBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionComboBox::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionComboBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionComboBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionComboBox *qp = (KQStyleOptionComboBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionComboBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionComboBox *qp = (KQStyleOptionComboBox *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionComboBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionComboBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionComboBox";
	cdef->free = QStyleOptionComboBox_free;
	cdef->reftrace = QStyleOptionComboBox_reftrace;
	cdef->compareTo = QStyleOptionComboBox_compareTo;
}

static knh_IntData_t QStyleOptionComboBoxConstInt[] = {
	{"Type", QStyleOptionComboBox::Type},
	{"Version", QStyleOptionComboBox::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionComboBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionComboBoxConstInt);
}

