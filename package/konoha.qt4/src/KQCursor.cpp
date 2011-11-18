//QCursor QCursor.new();
KMETHOD QCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCursor *ret_v = new KQCursor();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QCursor QCursor.new(int shape);
KMETHOD QCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::CursorShape shape = Int_to(Qt::CursorShape, sfp[1]);
	KQCursor *ret_v = new KQCursor(shape);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QCursor QCursor.new(QBitmap bitmap, QBitmap mask, int hotX, int hotY);
KMETHOD QCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QBitmap  bitmap = *RawPtr_to(const QBitmap *, sfp[1]);
	const QBitmap  mask = *RawPtr_to(const QBitmap *, sfp[2]);
	int hotX = Int_to(int, sfp[3]);
	int hotY = Int_to(int, sfp[4]);
	KQCursor *ret_v = new KQCursor(bitmap, mask, hotX, hotY);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QCursor QCursor.new(QPixmap pixmap, int hotX, int hotY);
KMETHOD QCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
	int hotX = Int_to(int, sfp[2]);
	int hotY = Int_to(int, sfp[3]);
	KQCursor *ret_v = new KQCursor(pixmap, hotX, hotY);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QCursor QCursor.new(QCursor c);
KMETHOD QCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QCursor  c = *RawPtr_to(const QCursor *, sfp[1]);
	KQCursor *ret_v = new KQCursor(c);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QCursor QCursor.new(HCURSOR cursor);
KMETHOD QCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	HCURSOR  cursor = *RawPtr_to(HCURSOR *, sfp[1]);
	KQCursor *ret_v = new KQCursor(cursor);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QBitmap QCursor.bitmap();
KMETHOD QCursor_bitmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCursor *  qp = RawPtr_to(QCursor *, sfp[0]);
	if (qp) {
		const QBitmap* ret_v = qp->bitmap();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QBitmap*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QCursor.hotSpot();
KMETHOD QCursor_hotSpot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCursor *  qp = RawPtr_to(QCursor *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->hotSpot();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBitmap QCursor.mask();
KMETHOD QCursor_mask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCursor *  qp = RawPtr_to(QCursor *, sfp[0]);
	if (qp) {
		const QBitmap* ret_v = qp->mask();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QBitmap*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QCursor.pixmap();
KMETHOD QCursor_pixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCursor *  qp = RawPtr_to(QCursor *, sfp[0]);
	if (qp) {
		QPixmap ret_v = qp->pixmap();
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QCursor.setShape(int shape);
KMETHOD QCursor_setShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCursor *  qp = RawPtr_to(QCursor *, sfp[0]);
	if (qp) {
		Qt::CursorShape shape = Int_to(Qt::CursorShape, sfp[1]);
		qp->setShape(shape);
	}
	RETURNvoid_();
}

//int QCursor.getShape();
KMETHOD QCursor_getShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCursor *  qp = RawPtr_to(QCursor *, sfp[0]);
	if (qp) {
		Qt::CursorShape ret_v = qp->shape();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QCursor.getPos();
KMETHOD QCursor_getPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QPoint ret_v = QCursor::pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QCursor.setPos(int x, int y);
KMETHOD QCursor_setPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QCursor::setPos(x, y);
	}
	RETURNvoid_();
}

/*
//void QCursor.setPos(QPoint p);
KMETHOD QCursor_setPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		QCursor::setPos(p);
	}
	RETURNvoid_();
}
*/
//Array<String> QCursor.parents();
KMETHOD QCursor_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCursor *qp = RawPtr_to(QCursor*, sfp[0]);
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

DummyQCursor::DummyQCursor()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQCursor::~DummyQCursor()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQCursor::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCursor::self = ptr;
}

bool DummyQCursor::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQCursor::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCursor::event_map->bigin();
	if ((itr = DummyQCursor::event_map->find(str)) == DummyQCursor::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCursor::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCursor::slot_map->bigin();
	if ((itr = DummyQCursor::slot_map->find(str)) == DummyQCursor::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQCursor::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQCursor::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQCursor::connection(QObject *o)
{
	QCursor *p = dynamic_cast<QCursor*>(o);
	if (p != NULL) {
	}
}

KQCursor::KQCursor() : QCursor()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQCursor();
}

KQCursor::~KQCursor()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QCursor_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCursor *qp = RawPtr_to(KQCursor *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCursor]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCursor]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QCursor_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCursor *qp = RawPtr_to(KQCursor *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCursor]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCursor]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCursor_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQCursor *qp = (KQCursor *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QCursor*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QCursor_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQCursor *qp = (KQCursor *)p->rawptr;
		KQCursor *qp = static_cast<KQCursor*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QCursor_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQCursor::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQCursor(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCursor";
	cdef->free = QCursor_free;
	cdef->reftrace = QCursor_reftrace;
	cdef->compareTo = QCursor_compareTo;
}


