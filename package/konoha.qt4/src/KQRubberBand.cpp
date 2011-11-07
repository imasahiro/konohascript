//QRubberBand QRubberBand.new(int s, QWidget p);
KMETHOD QRubberBand_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRubberBand::Shape s = Int_to(QRubberBand::Shape, sfp[1]);
	QWidget*  p = RawPtr_to(QWidget*, sfp[2]);
	KQRubberBand *ret_v = new KQRubberBand(s, p);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QRubberBand.move(int x, int y);
KMETHOD QRubberBand_move(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRubberBand *  qp = RawPtr_to(QRubberBand *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		qp->move(x, y);
	}
	RETURNvoid_();
}

/*
//void QRubberBand.move(QPoint p);
KMETHOD QRubberBand_move(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRubberBand *  qp = RawPtr_to(QRubberBand *, sfp[0]);
	if (qp) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		qp->move(p);
	}
	RETURNvoid_();
}
*/
//void QRubberBand.resize(int width, int height);
KMETHOD QRubberBand_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRubberBand *  qp = RawPtr_to(QRubberBand *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		int height = Int_to(int, sfp[2]);
		qp->resize(width, height);
	}
	RETURNvoid_();
}

/*
//void QRubberBand.resize(QSize size);
KMETHOD QRubberBand_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRubberBand *  qp = RawPtr_to(QRubberBand *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->resize(size);
	}
	RETURNvoid_();
}
*/
//void QRubberBand.setGeometry(QRect rect);
KMETHOD QRubberBand_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRubberBand *  qp = RawPtr_to(QRubberBand *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

/*
//void QRubberBand.setGeometry(int x, int y, int width, int height);
KMETHOD QRubberBand_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRubberBand *  qp = RawPtr_to(QRubberBand *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		qp->setGeometry(x, y, width, height);
	}
	RETURNvoid_();
}
*/
//int QRubberBand.shape();
KMETHOD QRubberBand_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRubberBand *  qp = RawPtr_to(QRubberBand *, sfp[0]);
	if (qp) {
		QRubberBand::Shape ret_v = qp->shape();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQRubberBand::DummyQRubberBand()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQRubberBand::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRubberBand::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQRubberBand::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQRubberBand::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRubberBand::event_map->bigin();
	if ((itr = DummyQRubberBand::event_map->find(str)) == DummyQRubberBand::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRubberBand::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRubberBand::slot_map->bigin();
	if ((itr = DummyQRubberBand::slot_map->find(str)) == DummyQRubberBand::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQRubberBand::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQWidget::reftrace(ctx, p, tail_);
}

void DummyQRubberBand::connection(QObject *o)
{
	QRubberBand *p = dynamic_cast<QRubberBand*>(o);
	if (p != NULL) {
	}
	DummyQWidget::connection(o);
}

KQRubberBand::KQRubberBand(QRubberBand::Shape s, QWidget* p) : QRubberBand(s, p)
{
	self = NULL;
	dummy = new DummyQRubberBand();
	dummy->connection((QObject*)this);
}

KMETHOD QRubberBand_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRubberBand *qp = RawPtr_to(KQRubberBand *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRubberBand]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRubberBand]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QRubberBand_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRubberBand *qp = RawPtr_to(KQRubberBand *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRubberBand]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRubberBand]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRubberBand_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQRubberBand *qp = (KQRubberBand *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QRubberBand_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQRubberBand *qp = (KQRubberBand *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QRubberBand_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQRubberBand::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQRubberBand::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QRubberBand::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QRubberBandConstInt[] = {
	{"Line", QRubberBand::Line},
	{"Rectangle", QRubberBand::Rectangle},
	{NULL, 0}
};

DEFAPI(void) constQRubberBand(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QRubberBandConstInt);
}


DEFAPI(void) defQRubberBand(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRubberBand";
	cdef->free = QRubberBand_free;
	cdef->reftrace = QRubberBand_reftrace;
	cdef->compareTo = QRubberBand_compareTo;
}


