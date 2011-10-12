//QTextBlock QTextBlock.new(QTextBlock other);
KMETHOD QTextBlock_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextBlock  other = *RawPtr_to(const QTextBlock *, sfp[1]);
	KQTextBlock *ret_v = new KQTextBlock(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTextBlock.begin();
KMETHOD QTextBlock_begin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextBlock::iterator ret_v = qp->begin();
		QTextBlock::iterator *ret_v_ = new QTextBlock::iterator(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBlockFormat QTextBlock.blockFormat();
KMETHOD QTextBlock_blockFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextBlockFormat ret_v = qp->blockFormat();
		QTextBlockFormat *ret_v_ = new QTextBlockFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.blockFormatIndex();
KMETHOD QTextBlock_blockFormatIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->blockFormatIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextBlock.blockNumber();
KMETHOD QTextBlock_blockNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->blockNumber();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextCharFormat QTextBlock.charFormat();
KMETHOD QTextBlock_charFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextCharFormat ret_v = qp->charFormat();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.charFormatIndex();
KMETHOD QTextBlock_charFormatIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->charFormatIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextBlock.clearLayout();
KMETHOD QTextBlock_clearLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		qp->clearLayout();
	}
	RETURNvoid_();
}

//boolean QTextBlock.contains(int position);
KMETHOD QTextBlock_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int position = Int_to(int, sfp[1]);
		bool ret_v = qp->contains(position);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTextDocument QTextBlock.document();
KMETHOD QTextBlock_document(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		const QTextDocument* ret_v = qp->document();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.end();
KMETHOD QTextBlock_end(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextBlock::iterator ret_v = qp->end();
		QTextBlock::iterator *ret_v_ = new QTextBlock::iterator(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.firstLineNumber();
KMETHOD QTextBlock_firstLineNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->firstLineNumber();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

////boolean QTextBlock.isValid();
KMETHOD QTextBlock_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextBlock.isVisible();
KMETHOD QTextBlock_isVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTextLayout QTextBlock.layout();
KMETHOD QTextBlock_layout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextLayout* ret_v = qp->layout();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextLayout*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.length();
KMETHOD QTextBlock_length(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->length();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextBlock.getLineCount();
KMETHOD QTextBlock_getLineCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->lineCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextBlock QTextBlock.next();
KMETHOD QTextBlock_next(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextBlock ret_v = qp->next();
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.position();
KMETHOD QTextBlock_position(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->position();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextBlock QTextBlock.previous();
KMETHOD QTextBlock_previous(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextBlock ret_v = qp->previous();
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.getRevision();
KMETHOD QTextBlock_getRevision(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->revision();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextBlock.setLineCount(int count);
KMETHOD QTextBlock_setLineCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int count = Int_to(int, sfp[1]);
		qp->setLineCount(count);
	}
	RETURNvoid_();
}

//void QTextBlock.setRevision(int rev);
KMETHOD QTextBlock_setRevision(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int rev = Int_to(int, sfp[1]);
		qp->setRevision(rev);
	}
	RETURNvoid_();
}

//void QTextBlock.setUserData(QTextBlockUserData data);
KMETHOD QTextBlock_setUserData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextBlockUserData*  data = RawPtr_to(QTextBlockUserData*, sfp[1]);
		qp->setUserData(data);
	}
	RETURNvoid_();
}

//void QTextBlock.setUserState(int state);
KMETHOD QTextBlock_setUserState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int state = Int_to(int, sfp[1]);
		qp->setUserState(state);
	}
	RETURNvoid_();
}

//void QTextBlock.setVisible(boolean visible);
KMETHOD QTextBlock_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//String QTextBlock.text();
KMETHOD QTextBlock_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.textDirection();
KMETHOD QTextBlock_textDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		Qt::LayoutDirection ret_v = qp->textDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextList QTextBlock.textList();
KMETHOD QTextBlock_textList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextList* ret_v = qp->textList();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextList*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBlockUserData QTextBlock.getUserData();
KMETHOD QTextBlock_getUserData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		QTextBlockUserData* ret_v = qp->userData();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextBlockUserData*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextBlock.getUserState();
KMETHOD QTextBlock_getUserState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->userState();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQTextBlock::DummyQTextBlock()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextBlock::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextBlock::self = ptr;
}

bool DummyQTextBlock::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextBlock::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlock::event_map->bigin();
	if ((itr = DummyQTextBlock::event_map->find(str)) == DummyQTextBlock::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextBlock::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlock::slot_map->bigin();
	if ((itr = DummyQTextBlock::event_map->find(str)) == DummyQTextBlock::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextBlock::KQTextBlock(const QTextBlock other) : QTextBlock(other)
{
	self = NULL;
}

KMETHOD QTextBlock_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlock *qp = RawPtr_to(KQTextBlock *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlock]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextBlock::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlock]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextBlock_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlock *qp = RawPtr_to(KQTextBlock *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlock]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextBlock::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlock]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextBlock_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextBlock *qp = (KQTextBlock *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextBlock_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextBlock *qp = (KQTextBlock *)p->rawptr;
		(void)qp;
	}
}

static int QTextBlock_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTextBlock*>(p1->rawptr) == *static_cast<QTextBlock*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQTextBlock(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBlock";
	cdef->free = QTextBlock_free;
	cdef->reftrace = QTextBlock_reftrace;
	cdef->compareTo = QTextBlock_compareTo;
}


