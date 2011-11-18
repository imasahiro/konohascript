//QFontMetricsF QFontMetricsF.new(QFont font);
KMETHOD QFontMetricsF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
	KQFontMetricsF *ret_v = new KQFontMetricsF(font);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QFontMetricsF QFontMetricsF.new(QFont font, QPaintDevice paintdevice);
KMETHOD QFontMetricsF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
	QPaintDevice*  paintdevice = RawPtr_to(QPaintDevice*, sfp[2]);
	KQFontMetricsF *ret_v = new KQFontMetricsF(font, paintdevice);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QFontMetricsF QFontMetricsF.new(QFontMetrics fontMetrics);
KMETHOD QFontMetricsF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFontMetrics  fontMetrics = *RawPtr_to(const QFontMetrics *, sfp[1]);
	KQFontMetricsF *ret_v = new KQFontMetricsF(fontMetrics);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QFontMetricsF QFontMetricsF.new(QFontMetricsF fm);
KMETHOD QFontMetricsF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFontMetricsF  fm = *RawPtr_to(const QFontMetricsF *, sfp[1]);
	KQFontMetricsF *ret_v = new KQFontMetricsF(fm);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//float QFontMetricsF.ascent();
KMETHOD QFontMetricsF_ascent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->ascent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.averageCharWidth();
KMETHOD QFontMetricsF_averageCharWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->averageCharWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QRectF QFontMetricsF.boundingRect(String text);
KMETHOD QFontMetricsF_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		QRectF ret_v = qp->boundingRect(text);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QFontMetricsF.boundingRect(QChar ch);
KMETHOD QFontMetricsF_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		QRectF ret_v = qp->boundingRect(ch);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QRectF QFontMetricsF.boundingRect(QRectF rect, int flags, String text, int tabStops, int tabArray);
KMETHOD QFontMetricsF_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		int tabStops = Int_to(int, sfp[4]);
		int* tabArray = Int_to(int*, sfp[5]);
		QRectF ret_v = qp->boundingRect(rect, flags, text, tabStops, tabArray);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//float QFontMetricsF.descent();
KMETHOD QFontMetricsF_descent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->descent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//String QFontMetricsF.elidedText(String text, int mode, float width, int flags);
KMETHOD QFontMetricsF_elidedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		Qt::TextElideMode mode = Int_to(Qt::TextElideMode, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		int flags = Int_to(int, sfp[4]);
		QString ret_v = qp->elidedText(text, mode, width, flags);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QFontMetricsF.height();
KMETHOD QFontMetricsF_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->height();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QFontMetricsF.inFont(QChar ch);
KMETHOD QFontMetricsF_inFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		bool ret_v = qp->inFont(ch);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QFontMetricsF.leading();
KMETHOD QFontMetricsF_leading(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->leading();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.leftBearing(QChar ch);
KMETHOD QFontMetricsF_leftBearing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		qreal ret_v = qp->leftBearing(ch);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.lineSpacing();
KMETHOD QFontMetricsF_lineSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->lineSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.lineWidth();
KMETHOD QFontMetricsF_lineWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->lineWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.maxWidth();
KMETHOD QFontMetricsF_maxWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->maxWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.minLeftBearing();
KMETHOD QFontMetricsF_minLeftBearing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->minLeftBearing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.minRightBearing();
KMETHOD QFontMetricsF_minRightBearing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->minRightBearing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.overlinePos();
KMETHOD QFontMetricsF_overlinePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->overlinePos();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.rightBearing(QChar ch);
KMETHOD QFontMetricsF_rightBearing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		qreal ret_v = qp->rightBearing(ch);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QSizeF QFontMetricsF.size(int flags, String text, int tabStops, int tabArray);
KMETHOD QFontMetricsF_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		int flags = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		int tabStops = Int_to(int, sfp[3]);
		int* tabArray = Int_to(int*, sfp[4]);
		QSizeF ret_v = qp->size(flags, text, tabStops, tabArray);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QFontMetricsF.strikeOutPos();
KMETHOD QFontMetricsF_strikeOutPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->strikeOutPos();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QRectF QFontMetricsF.tightBoundingRect(String text);
KMETHOD QFontMetricsF_tightBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		QRectF ret_v = qp->tightBoundingRect(text);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QFontMetricsF.underlinePos();
KMETHOD QFontMetricsF_underlinePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->underlinePos();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QFontMetricsF.width(String text);
KMETHOD QFontMetricsF_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qreal ret_v = qp->width(text);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

/*
//float QFontMetricsF.width(QChar ch);
KMETHOD QFontMetricsF_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		qreal ret_v = qp->width(ch);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}
*/
//float QFontMetricsF.xHeight();
KMETHOD QFontMetricsF_xHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *  qp = RawPtr_to(QFontMetricsF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->xHeight();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QFontMetricsF.parents();
KMETHOD QFontMetricsF_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetricsF *qp = RawPtr_to(QFontMetricsF*, sfp[0]);
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

DummyQFontMetricsF::DummyQFontMetricsF()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQFontMetricsF::~DummyQFontMetricsF()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQFontMetricsF::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFontMetricsF::self = ptr;
}

bool DummyQFontMetricsF::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQFontMetricsF::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontMetricsF::event_map->bigin();
	if ((itr = DummyQFontMetricsF::event_map->find(str)) == DummyQFontMetricsF::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFontMetricsF::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontMetricsF::slot_map->bigin();
	if ((itr = DummyQFontMetricsF::slot_map->find(str)) == DummyQFontMetricsF::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQFontMetricsF::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQFontMetricsF::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQFontMetricsF::connection(QObject *o)
{
	QFontMetricsF *p = dynamic_cast<QFontMetricsF*>(o);
	if (p != NULL) {
	}
}

KQFontMetricsF::KQFontMetricsF(const QFont font) : QFontMetricsF(font)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQFontMetricsF();
}

KQFontMetricsF::~KQFontMetricsF()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QFontMetricsF_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontMetricsF *qp = RawPtr_to(KQFontMetricsF *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFontMetricsF]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontMetricsF]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFontMetricsF_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontMetricsF *qp = RawPtr_to(KQFontMetricsF *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFontMetricsF]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontMetricsF]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFontMetricsF_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQFontMetricsF *qp = (KQFontMetricsF *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QFontMetricsF*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QFontMetricsF_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQFontMetricsF *qp = (KQFontMetricsF *)p->rawptr;
		KQFontMetricsF *qp = static_cast<KQFontMetricsF*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFontMetricsF_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QFontMetricsF*>(p1->rawptr) == *static_cast<QFontMetricsF*>(p2->rawptr) ? 0 : 1);
}

void KQFontMetricsF::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQFontMetricsF(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontMetricsF";
	cdef->free = QFontMetricsF_free;
	cdef->reftrace = QFontMetricsF_reftrace;
	cdef->compareTo = QFontMetricsF_compareTo;
}


