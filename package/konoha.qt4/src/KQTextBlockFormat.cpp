//QTextBlockFormat QTextBlockFormat.new();
KMETHOD QTextBlockFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockFormat *ret_v = new KQTextBlockFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTextBlockFormat.getAlignment();
KMETHOD QTextBlockFormat_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment ret_v = qp->alignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextBlockFormat.getBottomMargin();
KMETHOD QTextBlockFormat_getBottomMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->bottomMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTextBlockFormat.getIndent();
KMETHOD QTextBlockFormat_getIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->indent();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

////boolean QTextBlockFormat.isValid();
KMETHOD QTextBlockFormat_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QTextBlockFormat.getLeftMargin();
KMETHOD QTextBlockFormat_getLeftMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->leftMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QTextBlockFormat.getNonBreakableLines();
KMETHOD QTextBlockFormat_getNonBreakableLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->nonBreakableLines();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextBlockFormat.getPageBreakPolicy();
KMETHOD QTextBlockFormat_getPageBreakPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		QTextBlockFormat::PageBreakFlags ret_v = qp->pageBreakPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextBlockFormat.getRightMargin();
KMETHOD QTextBlockFormat_getRightMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->rightMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QTextBlockFormat.setAlignment(int alignment);
KMETHOD QTextBlockFormat_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.setBottomMargin(float margin);
KMETHOD QTextBlockFormat_setBottomMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setBottomMargin(margin);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.setIndent(int indentation);
KMETHOD QTextBlockFormat_setIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		int indentation = Int_to(int, sfp[1]);
		qp->setIndent(indentation);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.setLeftMargin(float margin);
KMETHOD QTextBlockFormat_setLeftMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setLeftMargin(margin);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.setNonBreakableLines(boolean b);
KMETHOD QTextBlockFormat_setNonBreakableLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setNonBreakableLines(b);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.setPageBreakPolicy(int policy);
KMETHOD QTextBlockFormat_setPageBreakPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		QTextBlockFormat::PageBreakFlags policy = Int_to(QTextBlockFormat::PageBreakFlags, sfp[1]);
		qp->setPageBreakPolicy(policy);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.setRightMargin(float margin);
KMETHOD QTextBlockFormat_setRightMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setRightMargin(margin);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.setTabPositions(Array<int> tabs);
KMETHOD QTextBlockFormat_setTabPositions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QTextOption::Tab> tabs;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			tabs.append(*(QTextOption::Tab*)p->rawptr);
		}
		qp->setTabPositions(tabs);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.setTextIndent(float indent);
KMETHOD QTextBlockFormat_setTextIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal indent = Float_to(qreal, sfp[1]);
		qp->setTextIndent(indent);
	}
	RETURNvoid_();
}

//void QTextBlockFormat.settopMargin(float margin);
KMETHOD QTextBlockFormat_setTopMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setTopMargin(margin);
	}
	RETURNvoid_();
}

//Array<int> QTextBlockFormat.getTabPositions();
KMETHOD QTextBlockFormat_getTabPositions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		QList<QTextOption::Tab>ret_v = qp->tabPositions();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTextOption::Tab"));
		for (int n = 0; n < list_size; n++) {
			QTextOption::Tab *ret_v_ = new QTextOption::Tab(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//float QTextBlockFormat.getTextIndent();
KMETHOD QTextBlockFormat_getTextIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->textIndent();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextBlockFormat.gettopMargin();
KMETHOD QTextBlockFormat_getTopMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockFormat *  qp = RawPtr_to(QTextBlockFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->topMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQTextBlockFormat::DummyQTextBlockFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextBlockFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextBlockFormat::self = ptr;
	DummyQTextFormat::setSelf(ptr);
}

bool DummyQTextBlockFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextFormat::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextBlockFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlockFormat::event_map->bigin();
	if ((itr = DummyQTextBlockFormat::event_map->find(str)) == DummyQTextBlockFormat::event_map->end()) {
		bool ret;
		ret = DummyQTextFormat::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextBlockFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlockFormat::slot_map->bigin();
	if ((itr = DummyQTextBlockFormat::event_map->find(str)) == DummyQTextBlockFormat::slot_map->end()) {
		bool ret;
		ret = DummyQTextFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextBlockFormat::KQTextBlockFormat() : QTextBlockFormat()
{
	self = NULL;
}

KMETHOD QTextBlockFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockFormat *qp = RawPtr_to(KQTextBlockFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlockFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextBlockFormat::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlockFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextBlockFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockFormat *qp = RawPtr_to(KQTextBlockFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlockFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextBlockFormat::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlockFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextBlockFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextBlockFormat *qp = (KQTextBlockFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextBlockFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextBlockFormat *qp = (KQTextBlockFormat *)p->rawptr;
		(void)qp;
	}
}

static int QTextBlockFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTextBlockFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBlockFormat";
	cdef->free = QTextBlockFormat_free;
	cdef->reftrace = QTextBlockFormat_reftrace;
	cdef->compareTo = QTextBlockFormat_compareTo;
}


