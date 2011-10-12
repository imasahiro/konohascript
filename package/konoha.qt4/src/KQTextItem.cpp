//float QTextItem.ascent();
KMETHOD QTextItem_ascent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextItem.renderFlags();
KMETHOD QTextItem_renderFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp != NULL) {
		QTextItem::RenderFlags ret_v = qp->renderFlags();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTextItem.text();
KMETHOD QTextItem_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextItem *  qp = RawPtr_to(QTextItem *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
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
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextItem::slot_map->bigin();
	if ((itr = DummyQTextItem::event_map->find(str)) == DummyQTextItem::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextItem::KQTextItem() : QTextItem()
{
	self = NULL;
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
		if (!qp->DummyQTextItem::addEvent(callback_func, str)) {
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
		if (!qp->DummyQTextItem::signalConnect(callback_func, str)) {
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
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextItem *qp = (KQTextItem *)p->rawptr;
		(void)qp;
	}
}

static int QTextItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTextItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextItem";
	cdef->free = QTextItem_free;
	cdef->reftrace = QTextItem_reftrace;
	cdef->compareTo = QTextItem_compareTo;
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

