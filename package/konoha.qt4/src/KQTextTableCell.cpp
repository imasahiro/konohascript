//QTextTableCell QTextTableCell.new();
KMETHOD QTextTableCell_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableCell *ret_v = new KQTextTableCell();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextTableCell QTextTableCell.new(QTextTableCell other);
KMETHOD QTextTableCell_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextTableCell  other = *RawPtr_to(const QTextTableCell *, sfp[1]);
	KQTextTableCell *ret_v = new KQTextTableCell(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QTextTableCell.begin();
KMETHOD QTextTableCell_begin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		QTextFrame::iterator ret_v = qp->begin();
		QTextFrame::iterator *ret_v_ = new QTextFrame::iterator(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextTableCell.column();
KMETHOD QTextTableCell_column(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->column();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextTableCell.columnSpan();
KMETHOD QTextTableCell_columnSpan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->columnSpan();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextTableCell.end();
KMETHOD QTextTableCell_end(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		QTextFrame::iterator ret_v = qp->end();
		QTextFrame::iterator *ret_v_ = new QTextFrame::iterator(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QTextTableCell.firstCursorPosition();
KMETHOD QTextTableCell_firstCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		QTextCursor ret_v = qp->firstCursorPosition();
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCharFormat QTextTableCell.getFormat();
KMETHOD QTextTableCell_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		QTextCharFormat ret_v = qp->format();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

////boolean QTextTableCell.isValid();
KMETHOD QTextTableCell_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTextCursor QTextTableCell.lastCursorPosition();
KMETHOD QTextTableCell_lastCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		QTextCursor ret_v = qp->lastCursorPosition();
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextTableCell.row();
KMETHOD QTextTableCell_row(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->row();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextTableCell.rowSpan();
KMETHOD QTextTableCell_rowSpan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->rowSpan();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextTableCell.setFormat(QTextCharFormat fmt);
KMETHOD QTextTableCell_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//int QTextTableCell.tableCellFormatIndex();
KMETHOD QTextTableCell_tableCellFormatIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->tableCellFormatIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQTextTableCell::DummyQTextTableCell()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextTableCell::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextTableCell::self = ptr;
}

bool DummyQTextTableCell::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextTableCell::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTableCell::event_map->bigin();
	if ((itr = DummyQTextTableCell::event_map->find(str)) == DummyQTextTableCell::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextTableCell::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTableCell::slot_map->bigin();
	if ((itr = DummyQTextTableCell::event_map->find(str)) == DummyQTextTableCell::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextTableCell::KQTextTableCell() : QTextTableCell()
{
	self = NULL;
}

KMETHOD QTextTableCell_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableCell *qp = RawPtr_to(KQTextTableCell *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextTableCell]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextTableCell::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTableCell]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextTableCell_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableCell *qp = RawPtr_to(KQTextTableCell *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextTableCell]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextTableCell::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTableCell]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextTableCell_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextTableCell *qp = (KQTextTableCell *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextTableCell_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextTableCell *qp = (KQTextTableCell *)p->rawptr;
		(void)qp;
	}
}

static int QTextTableCell_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTextTableCell*>(p1->rawptr) == *static_cast<QTextTableCell*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQTextTableCell(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextTableCell";
	cdef->free = QTextTableCell_free;
	cdef->reftrace = QTextTableCell_reftrace;
	cdef->compareTo = QTextTableCell_compareTo;
}


