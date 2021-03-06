//QTextBlock QTextBlock.new(QTextBlock other);
KMETHOD QTextBlock_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextBlock  other = *RawPtr_to(const QTextBlock *, sfp[1]);
	KQTextBlock *ret_v = new KQTextBlock(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QTextBlockFormat QTextBlock.blockFormat();
KMETHOD QTextBlock_blockFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->clearLayout();
	}
	RETURNvoid_();
}

//boolean QTextBlock.contains(int position);
KMETHOD QTextBlock_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp) {
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
	if (qp) {
		const QTextDocument* ret_v = qp->document();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
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
	if (qp) {
		int ret_v = qp->firstLineNumber();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTextBlock.isVisible();
KMETHOD QTextBlock_isVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *  qp = RawPtr_to(QTextBlock *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		int ret_v = qp->userState();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QTextBlock.parents();
KMETHOD QTextBlock_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlock *qp = RawPtr_to(QTextBlock*, sfp[0]);
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

DummyQTextBlock::DummyQTextBlock()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextBlock::~DummyQTextBlock()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextBlock::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlock::slot_map->bigin();
	if ((itr = DummyQTextBlock::slot_map->find(str)) == DummyQTextBlock::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextBlock::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextBlock::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextBlock::connection(QObject *o)
{
	QTextBlock *p = dynamic_cast<QTextBlock*>(o);
	if (p != NULL) {
	}
}

KQTextBlock::KQTextBlock(const QTextBlock other) : QTextBlock(other)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextBlock();
}

KQTextBlock::~KQTextBlock()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlock]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextBlock_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextBlock *qp = (KQTextBlock *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextBlock*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextBlock_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextBlock *qp = (KQTextBlock *)p->rawptr;
		KQTextBlock *qp = static_cast<KQTextBlock*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextBlock_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTextBlock*>(p1->rawptr) == *static_cast<QTextBlock*>(p2->rawptr) ? 0 : 1);
}

void KQTextBlock::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextBlock(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBlock";
	cdef->free = QTextBlock_free;
	cdef->reftrace = QTextBlock_reftrace;
	cdef->compareTo = QTextBlock_compareTo;
}


