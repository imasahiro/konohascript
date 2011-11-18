//QPen QPen.new();
KMETHOD QPen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPen *ret_v = new KQPen();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPen QPen.new(int style);
KMETHOD QPen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::PenStyle style = Int_to(Qt::PenStyle, sfp[1]);
	KQPen *ret_v = new KQPen(style);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPen QPen.new(QColor color);
KMETHOD QPen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
	KQPen *ret_v = new KQPen(color);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPen QPen.new(QBrush brush, float width, int style, int cap, int join);
KMETHOD QPen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
	qreal width = Float_to(qreal, sfp[2]);
	Qt::PenStyle style = Int_to(Qt::PenStyle, sfp[3]);
	Qt::PenCapStyle cap = Int_to(Qt::PenCapStyle, sfp[4]);
	Qt::PenJoinStyle join = Int_to(Qt::PenJoinStyle, sfp[5]);
	KQPen *ret_v = new KQPen(brush, width, style, cap, join);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPen QPen.new(QPen pen);
KMETHOD QPen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPen  pen = *RawPtr_to(const QPen *, sfp[1]);
	KQPen *ret_v = new KQPen(pen);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QBrush QPen.getBrush();
KMETHOD QPen_getBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		QBrush ret_v = qp->brush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPen.getCapStyle();
KMETHOD QPen_getCapStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		Qt::PenCapStyle ret_v = qp->capStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QColor QPen.getColor();
KMETHOD QPen_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->color();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QPen.dashOffset();
KMETHOD QPen_dashOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->dashOffset();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QPen.isCosmetic();
KMETHOD QPen_isCosmetic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCosmetic();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPen.isSolid();
KMETHOD QPen_isSolid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSolid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPen.getJoinStyle();
KMETHOD QPen_getJoinStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		Qt::PenJoinStyle ret_v = qp->joinStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QPen.getMiterLimit();
KMETHOD QPen_getMiterLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->miterLimit();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QPen.setBrush(QBrush brush);
KMETHOD QPen_setBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBrush(brush);
	}
	RETURNvoid_();
}

//void QPen.setCapStyle(int style);
KMETHOD QPen_setCapStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		Qt::PenCapStyle style = Int_to(Qt::PenCapStyle, sfp[1]);
		qp->setCapStyle(style);
	}
	RETURNvoid_();
}

//void QPen.setColor(QColor color);
KMETHOD QPen_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->setColor(color);
	}
	RETURNvoid_();
}

//void QPen.setCosmetic(boolean cosmetic);
KMETHOD QPen_setCosmetic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		bool cosmetic = Boolean_to(bool, sfp[1]);
		qp->setCosmetic(cosmetic);
	}
	RETURNvoid_();
}

//void QPen.setDashOffset(float offset);
KMETHOD QPen_setDashOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		qreal offset = Float_to(qreal, sfp[1]);
		qp->setDashOffset(offset);
	}
	RETURNvoid_();
}

//void QPen.setJoinStyle(int style);
KMETHOD QPen_setJoinStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		Qt::PenJoinStyle style = Int_to(Qt::PenJoinStyle, sfp[1]);
		qp->setJoinStyle(style);
	}
	RETURNvoid_();
}

//void QPen.setMiterLimit(float limit);
KMETHOD QPen_setMiterLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		qreal limit = Float_to(qreal, sfp[1]);
		qp->setMiterLimit(limit);
	}
	RETURNvoid_();
}

//void QPen.setStyle(int style);
KMETHOD QPen_setStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		Qt::PenStyle style = Int_to(Qt::PenStyle, sfp[1]);
		qp->setStyle(style);
	}
	RETURNvoid_();
}

//void QPen.setWidth(int width);
KMETHOD QPen_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}

//void QPen.setWidthF(float width);
KMETHOD QPen_setWidthF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setWidthF(width);
	}
	RETURNvoid_();
}

//int QPen.getStyle();
KMETHOD QPen_getStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		Qt::PenStyle ret_v = qp->style();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPen.getWidth();
KMETHOD QPen_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		int ret_v = qp->width();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QPen.getWidthF();
KMETHOD QPen_getWidthF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *  qp = RawPtr_to(QPen *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->widthF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QPen.parents();
KMETHOD QPen_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPen *qp = RawPtr_to(QPen*, sfp[0]);
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

DummyQPen::DummyQPen()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQPen::~DummyQPen()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQPen::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPen::self = ptr;
}

bool DummyQPen::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPen::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPen::event_map->bigin();
	if ((itr = DummyQPen::event_map->find(str)) == DummyQPen::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPen::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPen::slot_map->bigin();
	if ((itr = DummyQPen::slot_map->find(str)) == DummyQPen::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPen::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPen::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQPen::connection(QObject *o)
{
	QPen *p = dynamic_cast<QPen*>(o);
	if (p != NULL) {
	}
}

KQPen::KQPen() : QPen()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQPen();
}

KQPen::~KQPen()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QPen_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPen *qp = RawPtr_to(KQPen *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPen]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPen]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPen_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPen *qp = RawPtr_to(KQPen *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPen]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPen]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPen_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQPen *qp = (KQPen *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QPen*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QPen_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQPen *qp = (KQPen *)p->rawptr;
		KQPen *qp = static_cast<KQPen*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPen_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QPen*>(p1->rawptr) == *static_cast<QPen*>(p2->rawptr) ? 0 : 1);
}

void KQPen::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQPen(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPen";
	cdef->free = QPen_free;
	cdef->reftrace = QPen_reftrace;
	cdef->compareTo = QPen_compareTo;
}


