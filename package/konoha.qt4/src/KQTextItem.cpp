//float QTextItem.ascent();
KMETHOD QTextItem_ascent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->ascent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextItem.descent();
KMETHOD QTextItem_descent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->descent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QFont QTextItem.font();
KMETHOD QTextItem_font(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextItemRenderFlags QTextItem.renderFlags();
KMETHOD QTextItem_renderFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp) {
		QTextItem::RenderFlags ret_v = qp->renderFlags();
		QTextItem::RenderFlags *ret_v_ = new QTextItem::RenderFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextItem.text();
KMETHOD QTextItem_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTextItem.width();
KMETHOD QTextItem_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QTextItem.parents();
KMETHOD QTextItem_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *qp = RawPtr_to(QTextItem*, sfp[0]);
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

DummyQTextItem::DummyQTextItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextItem::self = ptr;
}

bool DummyQTextItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextItem::event_map->bigin();
	if ((itr = DummyQTextItem::event_map->find(str)) == DummyQTextItem::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextItem::slot_map->bigin();
	if ((itr = DummyQTextItem::slot_map->find(str)) == DummyQTextItem::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQTextItem::connection(QObject *o)
{
	QTextItem *p = dynamic_cast<QTextItem*>(o);
	if (p != NULL) {
	}
}

KMETHOD QTextItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextItem *qp = RawPtr_to(KQTextItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextItem *qp = RawPtr_to(KQTextItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextItem *qp = (KQTextItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextItem *qp = (KQTextItem *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextItemConstInt[] = {
	{"RightToLeft", QTextItem::RightToLeft},
	{"Overline", QTextItem::Overline},
	{"Underline", QTextItem::Underline},
	{"StrikeOut", QTextItem::StrikeOut},
	{NULL, 0}
};

DEFAPI(void) constQTextItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextItemConstInt);
}


DEFAPI(void) defQTextItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextItem";
	cdef->free = QTextItem_free;
	cdef->reftrace = QTextItem_reftrace;
	cdef->compareTo = QTextItem_compareTo;
}

//## QTextItemRenderFlags QTextItemRenderFlags.new(int value);
KMETHOD QTextItemRenderFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextItem::RenderFlag i = Int_to(QTextItem::RenderFlag, sfp[1]);
	QTextItem::RenderFlags *ret_v = new QTextItem::RenderFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QTextItemRenderFlags QTextItemRenderFlags.and(int mask);
KMETHOD QTextItemRenderFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextItem::RenderFlags *qp = RawPtr_to(QTextItem::RenderFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextItem::RenderFlags ret = ((*qp) & i);
		QTextItem::RenderFlags *ret_ = new QTextItem::RenderFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextItemRenderFlags QTextItemRenderFlags.iand(QTextItem::QTextItemRenderFlags other);
KMETHOD QTextItemRenderFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextItem::RenderFlags *qp = RawPtr_to(QTextItem::RenderFlags*, sfp[0]);
	if (qp != NULL) {
		QTextItem::RenderFlags *other = RawPtr_to(QTextItem::RenderFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextItemRenderFlags QTextItemRenderFlags.or(QTextItemRenderFlags f);
KMETHOD QTextItemRenderFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem::RenderFlags *qp = RawPtr_to(QTextItem::RenderFlags*, sfp[0]);
	if (qp != NULL) {
		QTextItem::RenderFlags *f = RawPtr_to(QTextItem::RenderFlags*, sfp[1]);
		QTextItem::RenderFlags ret = ((*qp) | (*f));
		QTextItem::RenderFlags *ret_ = new QTextItem::RenderFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextItemRenderFlags QTextItemRenderFlags.ior(QTextItem::QTextItemRenderFlags other);
KMETHOD QTextItemRenderFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextItem::RenderFlags *qp = RawPtr_to(QTextItem::RenderFlags*, sfp[0]);
	if (qp != NULL) {
		QTextItem::RenderFlags *other = RawPtr_to(QTextItem::RenderFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextItemRenderFlags QTextItemRenderFlags.xor(QTextItemRenderFlags f);
KMETHOD QTextItemRenderFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem::RenderFlags *qp = RawPtr_to(QTextItem::RenderFlags*, sfp[0]);
	if (qp != NULL) {
		QTextItem::RenderFlags *f = RawPtr_to(QTextItem::RenderFlags*, sfp[1]);
		QTextItem::RenderFlags ret = ((*qp) ^ (*f));
		QTextItem::RenderFlags *ret_ = new QTextItem::RenderFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextItemRenderFlags QTextItemRenderFlags.ixor(QTextItem::QTextItemRenderFlags other);
KMETHOD QTextItemRenderFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextItem::RenderFlags *qp = RawPtr_to(QTextItem::RenderFlags*, sfp[0]);
	if (qp != NULL) {
		QTextItem::RenderFlags *other = RawPtr_to(QTextItem::RenderFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QTextItemRenderFlags.testFlag(int flag);
KMETHOD QTextItemRenderFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextItem::RenderFlags *qp = RawPtr_to(QTextItem::RenderFlags *, sfp[0]);
	if (qp != NULL) {
		QTextItem::RenderFlag flag = Int_to(QTextItem::RenderFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QTextItemRenderFlags.value();
KMETHOD QTextItemRenderFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextItem::RenderFlags *qp = RawPtr_to(QTextItem::RenderFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QTextItemRenderFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QTextItem::RenderFlags *qp = (QTextItem::RenderFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QTextItemRenderFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QTextItem::RenderFlags *qp = (QTextItem::RenderFlags *)p->rawptr;
		(void)qp;
	}
}

static int QTextItemRenderFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QTextItem::RenderFlags*)p1->rawptr);
//		int v2 = int(*(QTextItem::RenderFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QTextItem::RenderFlags v1 = *(QTextItem::RenderFlags*)p1->rawptr;
		QTextItem::RenderFlags v2 = *(QTextItem::RenderFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQTextItemRenderFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextItemRenderFlags";
	cdef->free = QTextItemRenderFlags_free;
	cdef->reftrace = QTextItemRenderFlags_reftrace;
	cdef->compareTo = QTextItemRenderFlags_compareTo;
}

