//QFontMetrics QFontMetrics.new(QFont font);
KMETHOD QFontMetrics_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
	KQFontMetrics *ret_v = new KQFontMetrics(font);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QFontMetrics QFontMetrics.new(QFont font, QPaintDevice paintdevice);
KMETHOD QFontMetrics_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
	QPaintDevice*  paintdevice = RawPtr_to(QPaintDevice*, sfp[2]);
	KQFontMetrics *ret_v = new KQFontMetrics(font, paintdevice);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QFontMetrics QFontMetrics.new(QFontMetrics fm);
KMETHOD QFontMetrics_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFontMetrics  fm = *RawPtr_to(const QFontMetrics *, sfp[1]);
	KQFontMetrics *ret_v = new KQFontMetrics(fm);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QFontMetrics.ascent();
KMETHOD QFontMetrics_ascent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->ascent();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.averageCharWidth();
KMETHOD QFontMetrics_averageCharWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->averageCharWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QFontMetrics.boundingRect(QChar ch);
KMETHOD QFontMetrics_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		QRect ret_v = qp->boundingRect(ch);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRect QFontMetrics.boundingRect(String text);
KMETHOD QFontMetrics_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		QRect ret_v = qp->boundingRect(text);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QRect QFontMetrics.boundingRect(int x, int y, int width, int height, int flags, String text, int tabStops, int tabArray);
KMETHOD QFontMetrics_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		int flags = Int_to(int, sfp[5]);
		const QString text = String_to(const QString, sfp[6]);
		int tabStops = Int_to(int, sfp[7]);
		int* tabArray = Int_to(int*, sfp[8]);
		QRect ret_v = qp->boundingRect(x, y, width, height, flags, text, tabStops, tabArray);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QRect QFontMetrics.boundingRect(QRect rect, int flags, String text, int tabStops, int tabArray);
KMETHOD QFontMetrics_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		int tabStops = Int_to(int, sfp[4]);
		int* tabArray = Int_to(int*, sfp[5]);
		QRect ret_v = qp->boundingRect(rect, flags, text, tabStops, tabArray);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QFontMetrics.descent();
KMETHOD QFontMetrics_descent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->descent();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QFontMetrics.elidedText(String text, int mode, int width, int flags);
KMETHOD QFontMetrics_elidedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		Qt::TextElideMode mode = Int_to(Qt::TextElideMode, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int flags = Int_to(int, sfp[4]);
		QString ret_v = qp->elidedText(text, mode, width, flags);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFontMetrics.height();
KMETHOD QFontMetrics_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->height();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QFontMetrics.inFont(QChar ch);
KMETHOD QFontMetrics_inFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		bool ret_v = qp->inFont(ch);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFontMetrics.leading();
KMETHOD QFontMetrics_leading(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->leading();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.leftBearing(QChar ch);
KMETHOD QFontMetrics_leftBearing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		int ret_v = qp->leftBearing(ch);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.lineSpacing();
KMETHOD QFontMetrics_lineSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->lineSpacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.lineWidth();
KMETHOD QFontMetrics_lineWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->lineWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.maxWidth();
KMETHOD QFontMetrics_maxWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.minLeftBearing();
KMETHOD QFontMetrics_minLeftBearing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->minLeftBearing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.minRightBearing();
KMETHOD QFontMetrics_minRightBearing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->minRightBearing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.overlinePos();
KMETHOD QFontMetrics_overlinePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->overlinePos();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.rightBearing(QChar ch);
KMETHOD QFontMetrics_rightBearing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		int ret_v = qp->rightBearing(ch);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QFontMetrics.size(int flags, String text, int tabStops, int tabArray);
KMETHOD QFontMetrics_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int flags = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		int tabStops = Int_to(int, sfp[3]);
		int* tabArray = Int_to(int*, sfp[4]);
		QSize ret_v = qp->size(flags, text, tabStops, tabArray);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFontMetrics.strikeOutPos();
KMETHOD QFontMetrics_strikeOutPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->strikeOutPos();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QFontMetrics.tightBoundingRect(String text);
KMETHOD QFontMetrics_tightBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		QRect ret_v = qp->tightBoundingRect(text);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFontMetrics.underlinePos();
KMETHOD QFontMetrics_underlinePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->underlinePos();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFontMetrics.width(String text, int len);
KMETHOD QFontMetrics_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		int len = Int_to(int, sfp[2]);
		int ret_v = qp->width(text, len);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QFontMetrics.width(QChar ch);
KMETHOD QFontMetrics_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		int ret_v = qp->width(ch);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QFontMetrics.xHeight();
KMETHOD QFontMetrics_xHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *  qp = RawPtr_to(QFontMetrics *, sfp[0]);
	if (qp) {
		int ret_v = qp->xHeight();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QFontMetrics.parents();
KMETHOD QFontMetrics_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontMetrics *qp = RawPtr_to(QFontMetrics*, sfp[0]);
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

DummyQFontMetrics::DummyQFontMetrics()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQFontMetrics::~DummyQFontMetrics()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQFontMetrics::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFontMetrics::self = ptr;
}

bool DummyQFontMetrics::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQFontMetrics::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontMetrics::event_map->bigin();
	if ((itr = DummyQFontMetrics::event_map->find(str)) == DummyQFontMetrics::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFontMetrics::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontMetrics::slot_map->bigin();
	if ((itr = DummyQFontMetrics::slot_map->find(str)) == DummyQFontMetrics::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQFontMetrics::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQFontMetrics::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQFontMetrics::connection(QObject *o)
{
	QFontMetrics *p = dynamic_cast<QFontMetrics*>(o);
	if (p != NULL) {
	}
}

KQFontMetrics::KQFontMetrics(const QFont font) : QFontMetrics(font)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQFontMetrics();
}

KQFontMetrics::~KQFontMetrics()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QFontMetrics_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontMetrics *qp = RawPtr_to(KQFontMetrics *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFontMetrics]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontMetrics]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFontMetrics_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontMetrics *qp = RawPtr_to(KQFontMetrics *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFontMetrics]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontMetrics]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFontMetrics_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQFontMetrics *qp = (KQFontMetrics *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QFontMetrics*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QFontMetrics_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQFontMetrics *qp = (KQFontMetrics *)p->rawptr;
		KQFontMetrics *qp = static_cast<KQFontMetrics*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFontMetrics_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QFontMetrics*>(p1->rawptr) == *static_cast<QFontMetrics*>(p2->rawptr) ? 0 : 1);
}

void KQFontMetrics::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQFontMetrics(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontMetrics";
	cdef->free = QFontMetrics_free;
	cdef->reftrace = QFontMetrics_reftrace;
	cdef->compareTo = QFontMetrics_compareTo;
}


