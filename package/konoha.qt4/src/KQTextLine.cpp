//QTextLine QTextLine.new();
KMETHOD QTextLine_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLine *ret_v = new KQTextLine();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QTextLine.ascent();
KMETHOD QTextLine_ascent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->ascent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextLine.cursorToX(int cursorPos, int edge);
KMETHOD QTextLine_cursorToX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		int* cursorPos = Int_to(int*, sfp[1]);
		QTextLine::Edge edge = Int_to(QTextLine::Edge, sfp[2]);
		qreal ret_v = qp->cursorToX(cursorPos, edge);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

/*
//float QTextLine.cursorToX(int cursorPos, int edge);
KMETHOD QTextLine_cursorToX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		int cursorPos = Int_to(int, sfp[1]);
		QTextLine::Edge edge = Int_to(QTextLine::Edge, sfp[2]);
		qreal ret_v = qp->cursorToX(cursorPos, edge);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}
*/
//float QTextLine.descent();
KMETHOD QTextLine_descent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->descent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QTextLine.draw(QPainter painter, QPointF position, int selection);
KMETHOD QTextLine_draw(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[2]);
		const QTextLayout::FormatRange* selection = Int_to(const QTextLayout::FormatRange*, sfp[3]);
		qp->draw(painter, position, selection);
	}
	RETURNvoid_();
}

//float QTextLine.height();
KMETHOD QTextLine_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->height();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextLine.horizontalAdvance();
KMETHOD QTextLine_horizontalAdvance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->horizontalAdvance();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextLine.leading();
KMETHOD QTextLine_leading(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->leading();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QTextLine.getLeadingIncluded();
KMETHOD QTextLine_getLeadingIncluded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		bool ret_v = qp->leadingIncluded();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextLine.lineNumber();
KMETHOD QTextLine_lineNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		int ret_v = qp->lineNumber();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRectF QTextLine.naturalTextRect();
KMETHOD QTextLine_naturalTextRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->naturalTextRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTextLine.naturalTextWidth();
KMETHOD QTextLine_naturalTextWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->naturalTextWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QPointF QTextLine.getPosition();
KMETHOD QTextLine_getPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->position();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRectF QTextLine.rect();
KMETHOD QTextLine_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->rect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextLine.setLeadingIncluded(boolean incd);
KMETHOD QTextLine_setLeadingIncluded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		bool included = Boolean_to(bool, sfp[1]);
		qp->setLeadingIncluded(included);
	}
	RETURNvoid_();
}

//void QTextLine.setLineWidth(float width);
KMETHOD QTextLine_setLineWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setLineWidth(width);
	}
	RETURNvoid_();
}

//void QTextLine.setNumColumns(int numColumns);
KMETHOD QTextLine_setNumColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		int numColumns = Int_to(int, sfp[1]);
		qp->setNumColumns(numColumns);
	}
	RETURNvoid_();
}

/*
//void QTextLine.setNumColumns(int numColumns, float alignmentWidth);
KMETHOD QTextLine_setNumColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		int numColumns = Int_to(int, sfp[1]);
		qreal alignmentWidth = Float_to(qreal, sfp[2]);
		qp->setNumColumns(numColumns, alignmentWidth);
	}
	RETURNvoid_();
}
*/
//void QTextLine.setPosition(QPointF pos);
KMETHOD QTextLine_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		const QPointF  pos = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setPosition(pos);
	}
	RETURNvoid_();
}

//int QTextLine.textLength();
KMETHOD QTextLine_textLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		int ret_v = qp->textLength();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextLine.textStart();
KMETHOD QTextLine_textStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		int ret_v = qp->textStart();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextLine.width();
KMETHOD QTextLine_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextLine.x();
KMETHOD QTextLine_x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->x();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTextLine.xToCursor(float x, int cpos);
KMETHOD QTextLine_xToCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		QTextLine::CursorPosition cpos = Int_to(QTextLine::CursorPosition, sfp[2]);
		int ret_v = qp->xToCursor(x, cpos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextLine.y();
KMETHOD QTextLine_y(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *  qp = RawPtr_to(QTextLine *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->y();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QTextLine.parents();
KMETHOD QTextLine_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLine *qp = RawPtr_to(QTextLine*, sfp[0]);
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

DummyQTextLine::DummyQTextLine()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextLine::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextLine::self = ptr;
}

bool DummyQTextLine::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextLine::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextLine::event_map->bigin();
	if ((itr = DummyQTextLine::event_map->find(str)) == DummyQTextLine::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextLine::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextLine::slot_map->bigin();
	if ((itr = DummyQTextLine::slot_map->find(str)) == DummyQTextLine::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextLine::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQTextLine::connection(QObject *o)
{
	QTextLine *p = dynamic_cast<QTextLine*>(o);
	if (p != NULL) {
	}
}

KQTextLine::KQTextLine() : QTextLine()
{
	self = NULL;
	dummy = new DummyQTextLine();
}

KMETHOD QTextLine_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLine *qp = RawPtr_to(KQTextLine *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextLine]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextLine]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextLine_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLine *qp = RawPtr_to(KQTextLine *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextLine]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextLine]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextLine_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextLine *qp = (KQTextLine *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextLine_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextLine *qp = (KQTextLine *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextLine_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextLine::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextLineConstInt[] = {
	{"CursorBetweenCharacters", QTextLine::CursorBetweenCharacters},
	{"CursorOnCharacter", QTextLine::CursorOnCharacter},
	{"Leading", QTextLine::Leading},
	{"Trailing", QTextLine::Trailing},
	{NULL, 0}
};

DEFAPI(void) constQTextLine(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextLineConstInt);
}


DEFAPI(void) defQTextLine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextLine";
	cdef->free = QTextLine_free;
	cdef->reftrace = QTextLine_reftrace;
	cdef->compareTo = QTextLine_compareTo;
}


