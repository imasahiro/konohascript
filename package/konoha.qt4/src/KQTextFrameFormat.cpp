//QTextFrameFormat QTextFrameFormat.new();
KMETHOD QTextFrameFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFrameFormat *ret_v = new KQTextFrameFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QTextFrameFormat.getBorder();
KMETHOD QTextFrameFormat_getBorder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->border();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QBrush QTextFrameFormat.getBorderBrush();
KMETHOD QTextFrameFormat_getBorderBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QBrush ret_v = qp->borderBrush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextFrameFormat.getBorderStyle();
KMETHOD QTextFrameFormat_getBorderStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QTextFrameFormat::BorderStyle ret_v = qp->borderStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextFrameFormat.getBottomMargin();
KMETHOD QTextFrameFormat_getBottomMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->bottomMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QTextLength QTextFrameFormat.getHeight();
KMETHOD QTextFrameFormat_getHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QTextLength ret_v = qp->height();
		QTextLength *ret_v_ = new QTextLength(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

////boolean QTextFrameFormat.isValid();
KMETHOD QTextFrameFormat_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QTextFrameFormat.getLeftMargin();
KMETHOD QTextFrameFormat_getLeftMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->leftMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextFrameFormat.getMargin();
KMETHOD QTextFrameFormat_getMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->margin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextFrameFormat.getPadding();
KMETHOD QTextFrameFormat_getPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->padding();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTextFrameFormat.getPageBreakPolicy();
KMETHOD QTextFrameFormat_getPageBreakPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QTextFrameFormat::PageBreakFlags ret_v = qp->pageBreakPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextFrameFormat.getPosition();
KMETHOD QTextFrameFormat_getPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QTextFrameFormat::Position ret_v = qp->position();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextFrameFormat.getRightMargin();
KMETHOD QTextFrameFormat_getRightMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->rightMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QTextFrameFormat.setBorder(float width);
KMETHOD QTextFrameFormat_setBorder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setBorder(width);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setBorderBrush(QBrush brush);
KMETHOD QTextFrameFormat_setBorderBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBorderBrush(brush);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setBorderStyle(int style);
KMETHOD QTextFrameFormat_setBorderStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QTextFrameFormat::BorderStyle style = Int_to(QTextFrameFormat::BorderStyle, sfp[1]);
		qp->setBorderStyle(style);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setBottomMargin(float margin);
KMETHOD QTextFrameFormat_setBottomMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setBottomMargin(margin);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setHeight(QTextLength height);
KMETHOD QTextFrameFormat_setHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		const QTextLength  height = *RawPtr_to(const QTextLength *, sfp[1]);
		qp->setHeight(height);
	}
	RETURNvoid_();
}

/*
//void QTextFrameFormat.setHeight(float height);
KMETHOD QTextFrameFormat_setHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal height = Float_to(qreal, sfp[1]);
		qp->setHeight(height);
	}
	RETURNvoid_();
}
*/
//void QTextFrameFormat.setLeftMargin(float margin);
KMETHOD QTextFrameFormat_setLeftMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setLeftMargin(margin);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setMargin(float margin);
KMETHOD QTextFrameFormat_setMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setMargin(margin);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setPadding(float width);
KMETHOD QTextFrameFormat_setPadding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setPadding(width);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setPageBreakPolicy(int policy);
KMETHOD QTextFrameFormat_setPageBreakPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QTextFrameFormat::PageBreakFlags policy = Int_to(QTextFrameFormat::PageBreakFlags, sfp[1]);
		qp->setPageBreakPolicy(policy);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setPosition(int policy);
KMETHOD QTextFrameFormat_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QTextFrameFormat::Position policy = Int_to(QTextFrameFormat::Position, sfp[1]);
		qp->setPosition(policy);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setRightMargin(float margin);
KMETHOD QTextFrameFormat_setRightMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setRightMargin(margin);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.settopMargin(float margin);
KMETHOD QTextFrameFormat_setTopMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setTopMargin(margin);
	}
	RETURNvoid_();
}

//void QTextFrameFormat.setWidth(QTextLength width);
KMETHOD QTextFrameFormat_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		const QTextLength  width = *RawPtr_to(const QTextLength *, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}

/*
//void QTextFrameFormat.setWidth(float width);
KMETHOD QTextFrameFormat_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}
*/
//float QTextFrameFormat.gettopMargin();
KMETHOD QTextFrameFormat_getTopMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->topMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QTextLength QTextFrameFormat.getWidth();
KMETHOD QTextFrameFormat_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrameFormat *  qp = RawPtr_to(QTextFrameFormat *, sfp[0]);
	if (qp != NULL) {
		QTextLength ret_v = qp->width();
		QTextLength *ret_v_ = new QTextLength(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQTextFrameFormat::DummyQTextFrameFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextFrameFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextFrameFormat::self = ptr;
	DummyQTextFormat::setSelf(ptr);
}

bool DummyQTextFrameFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextFormat::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextFrameFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextFrameFormat::event_map->bigin();
	if ((itr = DummyQTextFrameFormat::event_map->find(str)) == DummyQTextFrameFormat::event_map->end()) {
		bool ret = false;
		ret = DummyQTextFormat::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextFrameFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextFrameFormat::slot_map->bigin();
	if ((itr = DummyQTextFrameFormat::slot_map->find(str)) == DummyQTextFrameFormat::slot_map->end()) {
		bool ret = false;
		ret = DummyQTextFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQTextFrameFormat::connection(QObject *o)
{
	DummyQTextFormat::connection(o);
}

KQTextFrameFormat::KQTextFrameFormat() : QTextFrameFormat()
{
	self = NULL;
	dummy = new DummyQTextFrameFormat();
	dummy->connection((QObject*)this);
}

KMETHOD QTextFrameFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFrameFormat *qp = RawPtr_to(KQTextFrameFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextFrameFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextFrameFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextFrameFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextFrameFormat *qp = RawPtr_to(KQTextFrameFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextFrameFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextFrameFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextFrameFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextFrameFormat *qp = (KQTextFrameFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextFrameFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQTextFrameFormat *qp = (KQTextFrameFormat *)p->rawptr;
		(void)qp;
	}
}

static int QTextFrameFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextFrameFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQTextFrameFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextFrameFormat";
	cdef->free = QTextFrameFormat_free;
	cdef->reftrace = QTextFrameFormat_reftrace;
	cdef->compareTo = QTextFrameFormat_compareTo;
}

static knh_IntData_t QTextFrameFormatConstInt[] = {
	{"BorderStyle_None", QTextFrameFormat::BorderStyle_None},
	{"BorderStyle_Dotted", QTextFrameFormat::BorderStyle_Dotted},
	{"BorderStyle_Dashed", QTextFrameFormat::BorderStyle_Dashed},
	{"BorderStyle_Solid", QTextFrameFormat::BorderStyle_Solid},
	{"BorderStyle_Double", QTextFrameFormat::BorderStyle_Double},
	{"BorderStyle_DotDash", QTextFrameFormat::BorderStyle_DotDash},
	{"BorderStyle_DotDotDash", QTextFrameFormat::BorderStyle_DotDotDash},
	{"BorderStyle_Groove", QTextFrameFormat::BorderStyle_Groove},
	{"BorderStyle_Ridge", QTextFrameFormat::BorderStyle_Ridge},
	{"BorderStyle_Inset", QTextFrameFormat::BorderStyle_Inset},
	{"BorderStyle_Outset", QTextFrameFormat::BorderStyle_Outset},
	{"InFlow", QTextFrameFormat::InFlow},
	{"FloatLeft", QTextFrameFormat::FloatLeft},
	{"FloatRight", QTextFrameFormat::FloatRight},
	{NULL, 0}
};

DEFAPI(void) constQTextFrameFormat(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextFrameFormatConstInt);
}

