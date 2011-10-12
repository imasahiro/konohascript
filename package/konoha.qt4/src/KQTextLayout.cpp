//QTextLayout QTextLayout.new();
KMETHOD QTextLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLayout *ret_v = new KQTextLayout();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextLayout QTextLayout.new(String text);
KMETHOD QTextLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	KQTextLayout *ret_v = new KQTextLayout(text);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextLayout QTextLayout.new(String text, QFont font, QPaintDevice paintdevice);
KMETHOD QTextLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	const QFont  font = *RawPtr_to(const QFont *, sfp[2]);
	QPaintDevice*  paintdevice = RawPtr_to(QPaintDevice*, sfp[3]);
	KQTextLayout *ret_v = new KQTextLayout(text, font, paintdevice);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//Array<int> QTextLayout.getAdditionalFormats();
KMETHOD QTextLayout_getAdditionalFormats(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QList<QTextLayout::FormatRange>ret_v = qp->additionalFormats();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTextLayout::FormatRange"));
		for (int n = 0; n < list_size; n++) {
			QTextLayout::FormatRange *ret_v_ = new QTextLayout::FormatRange(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QTextLayout.beginLayout();
KMETHOD QTextLayout_beginLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		qp->beginLayout();
	}
	RETURNvoid_();
}

//QRectF QTextLayout.boundingRect();
KMETHOD QTextLayout_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTextLayout.getCacheEnabled();
KMETHOD QTextLayout_getCacheEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->cacheEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextLayout.clearAdditionalFormats();
KMETHOD QTextLayout_clearAdditionalFormats(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		qp->clearAdditionalFormats();
	}
	RETURNvoid_();
}

//void QTextLayout.clearLayout();
KMETHOD QTextLayout_clearLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		qp->clearLayout();
	}
	RETURNvoid_();
}

//QTextLine QTextLayout.createLine();
KMETHOD QTextLayout_createLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QTextLine ret_v = qp->createLine();
		QTextLine *ret_v_ = new QTextLine(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextLayout.drawCursor(QPainter painter, QPointF position, int cursorPosition, int width);
KMETHOD QTextLayout_drawCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[2]);
		int cursorPosition = Int_to(int, sfp[3]);
		int width = Int_to(int, sfp[4]);
		qp->drawCursor(painter, position, cursorPosition, width);
	}
	RETURNvoid_();
}

/*
//void QTextLayout.drawCursor(QPainter painter, QPointF position, int cursorPosition);
KMETHOD QTextLayout_drawCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[2]);
		int cursorPosition = Int_to(int, sfp[3]);
		qp->drawCursor(painter, position, cursorPosition);
	}
	RETURNvoid_();
}
*/
//void QTextLayout.endLayout();
KMETHOD QTextLayout_endLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		qp->endLayout();
	}
	RETURNvoid_();
}

//QFont QTextLayout.getFont();
KMETHOD QTextLayout_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

////boolean QTextLayout.isValidCursorPosition(int pos);
KMETHOD QTextLayout_isValidCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		int pos = Int_to(int, sfp[1]);
		bool ret_v = qp->isValidCursorPosition(pos);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTextLine QTextLayout.lineAt(int i);
KMETHOD QTextLayout_lineAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextLine ret_v = qp->lineAt(i);
		QTextLine *ret_v_ = new QTextLine(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextLayout.lineCount();
KMETHOD QTextLayout_lineCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->lineCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextLine QTextLayout.lineForTextPosition(int pos);
KMETHOD QTextLayout_lineForTextPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		int pos = Int_to(int, sfp[1]);
		QTextLine ret_v = qp->lineForTextPosition(pos);
		QTextLine *ret_v_ = new QTextLine(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTextLayout.maximumWidth();
KMETHOD QTextLayout_maximumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->maximumWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextLayout.minimumWidth();
KMETHOD QTextLayout_minimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->minimumWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTextLayout.nextCursorPosition(int oldPos, int mode);
KMETHOD QTextLayout_nextCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		int oldPos = Int_to(int, sfp[1]);
		QTextLayout::CursorMode mode = Int_to(QTextLayout::CursorMode, sfp[2]);
		int ret_v = qp->nextCursorPosition(oldPos, mode);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPointF QTextLayout.getPosition();
KMETHOD QTextLayout_getPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->position();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextLayout.preeditAreaPosition();
KMETHOD QTextLayout_preeditAreaPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->preeditAreaPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTextLayout.preeditAreaText();
KMETHOD QTextLayout_preeditAreaText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->preeditAreaText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextLayout.previousCursorPosition(int oldPos, int mode);
KMETHOD QTextLayout_previousCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		int oldPos = Int_to(int, sfp[1]);
		QTextLayout::CursorMode mode = Int_to(QTextLayout::CursorMode, sfp[2]);
		int ret_v = qp->previousCursorPosition(oldPos, mode);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextLayout.setAdditionalFormats(Array<int> formatList);
KMETHOD QTextLayout_setAdditionalFormats(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QTextLayout::FormatRange> formatList;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			formatList.append(*(QTextLayout::FormatRange*)p->rawptr);
		}
		qp->setAdditionalFormats(formatList);
	}
	RETURNvoid_();
}

//void QTextLayout.setCacheEnabled(boolean enable);
KMETHOD QTextLayout_setCacheEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setCacheEnabled(enable);
	}
	RETURNvoid_();
}

//void QTextLayout.setFont(QFont font);
KMETHOD QTextLayout_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(font);
	}
	RETURNvoid_();
}

//void QTextLayout.setPosition(QPointF p);
KMETHOD QTextLayout_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		const QPointF  p = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setPosition(p);
	}
	RETURNvoid_();
}

//void QTextLayout.setPreeditArea(int position, String text);
KMETHOD QTextLayout_setPreeditArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		int position = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setPreeditArea(position, text);
	}
	RETURNvoid_();
}

//void QTextLayout.setText(String str);
KMETHOD QTextLayout_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		qp->setText(string);
	}
	RETURNvoid_();
}

//void QTextLayout.setTextOption(QTextOption option);
KMETHOD QTextLayout_setTextOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		const QTextOption  option = *RawPtr_to(const QTextOption *, sfp[1]);
		qp->setTextOption(option);
	}
	RETURNvoid_();
}

//String QTextLayout.getText();
KMETHOD QTextLayout_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextOption QTextLayout.getTextOption();
KMETHOD QTextLayout_getTextOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLayout *  qp = RawPtr_to(QTextLayout *, sfp[0]);
	if (qp != NULL) {
		QTextOption ret_v = qp->textOption();
		QTextOption *ret_v_ = new QTextOption(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQTextLayout::DummyQTextLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextLayout::self = ptr;
}

bool DummyQTextLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextLayout::event_map->bigin();
	if ((itr = DummyQTextLayout::event_map->find(str)) == DummyQTextLayout::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextLayout::slot_map->bigin();
	if ((itr = DummyQTextLayout::event_map->find(str)) == DummyQTextLayout::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextLayout::KQTextLayout() : QTextLayout()
{
	self = NULL;
}

KMETHOD QTextLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLayout *qp = RawPtr_to(KQTextLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextLayout::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLayout *qp = RawPtr_to(KQTextLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextLayout::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextLayout *qp = (KQTextLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextLayout *qp = (KQTextLayout *)p->rawptr;
		(void)qp;
	}
}

static int QTextLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTextLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextLayout";
	cdef->free = QTextLayout_free;
	cdef->reftrace = QTextLayout_reftrace;
	cdef->compareTo = QTextLayout_compareTo;
}

static knh_IntData_t QTextLayoutConstInt[] = {
	{"SkipCharacters", QTextLayout::SkipCharacters},
	{"SkipWords", QTextLayout::SkipWords},
	{NULL, 0}
};

DEFAPI(void) constQTextLayout(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextLayoutConstInt);
}

