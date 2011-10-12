//QTileRules QTileRules.new(int horizontalRule, int verticalRule);
KMETHOD QTileRules_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::TileRule horizontalRule = Int_to(Qt::TileRule, sfp[1]);
	Qt::TileRule verticalRule = Int_to(Qt::TileRule, sfp[2]);
	KQTileRules *ret_v = new KQTileRules(horizontalRule, verticalRule);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTileRules QTileRules.new(int rule);
KMETHOD QTileRules_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::TileRule rule = Int_to(Qt::TileRule, sfp[1]);
	KQTileRules *ret_v = new KQTileRules(rule);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQTileRules::DummyQTileRules()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTileRules::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTileRules::self = ptr;
}

bool DummyQTileRules::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTileRules::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTileRules::event_map->bigin();
	if ((itr = DummyQTileRules::event_map->find(str)) == DummyQTileRules::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTileRules::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTileRules::slot_map->bigin();
	if ((itr = DummyQTileRules::event_map->find(str)) == DummyQTileRules::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTileRules::KQTileRules(Qt::TileRule horizontalRule, Qt::TileRule verticalRule) : QTileRules(horizontalRule, verticalRule)
{
	self = NULL;
}

KMETHOD QTileRules_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTileRules *qp = RawPtr_to(KQTileRules *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTileRules]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTileRules::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTileRules]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTileRules_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTileRules *qp = RawPtr_to(KQTileRules *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTileRules]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTileRules::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTileRules]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTileRules_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTileRules *qp = (KQTileRules *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTileRules_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTileRules *qp = (KQTileRules *)p->rawptr;
		(void)qp;
	}
}

static int QTileRules_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTileRules(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTileRules";
	cdef->free = QTileRules_free;
	cdef->reftrace = QTileRules_reftrace;
	cdef->compareTo = QTileRules_compareTo;
}


