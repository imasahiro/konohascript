//void QTextTable.appendColumns(int count);
KMETHOD QTextTable_appendColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int count = Int_to(int, sfp[1]);
		qp->appendColumns(count);
	}
	RETURNvoid_();
}

//void QTextTable.appendRows(int count);
KMETHOD QTextTable_appendRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int count = Int_to(int, sfp[1]);
		qp->appendRows(count);
	}
	RETURNvoid_();
}

//QTextTableCell QTextTable.cellAt(int row, int column);
KMETHOD QTextTable_cellAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QTextTableCell ret_v = qp->cellAt(row, column);
		QTextTableCell *ret_v_ = new QTextTableCell(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextTableCell QTextTable.cellAt(int position);
KMETHOD QTextTable_cellAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int position = Int_to(int, sfp[1]);
		QTextTableCell ret_v = qp->cellAt(position);
		QTextTableCell *ret_v_ = new QTextTableCell(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QTextTableCell QTextTable.cellAt(QTextCursor cursor);
KMETHOD QTextTable_cellAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		QTextTableCell ret_v = qp->cellAt(cursor);
		QTextTableCell *ret_v_ = new QTextTableCell(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QTextTable.columns();
KMETHOD QTextTable_columns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->columns();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextTableFormat QTextTable.getFormat();
KMETHOD QTextTable_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		QTextTableFormat ret_v = qp->format();
		QTextTableFormat *ret_v_ = new QTextTableFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

////void QTextTable.insertColumns(int index, int columns);
KMETHOD QTextTable_insertColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		int columns = Int_to(int, sfp[2]);
		qp->insertColumns(index, columns);
	}
	RETURNvoid_();
}

////void QTextTable.insertRows(int index, int rows);
KMETHOD QTextTable_insertRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		int rows = Int_to(int, sfp[2]);
		qp->insertRows(index, rows);
	}
	RETURNvoid_();
}

//void QTextTable.mergeCells(int row, int column, int numRows, int numCols);
KMETHOD QTextTable_mergeCells(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		int numRows = Int_to(int, sfp[3]);
		int numCols = Int_to(int, sfp[4]);
		qp->mergeCells(row, column, numRows, numCols);
	}
	RETURNvoid_();
}

/*
//void QTextTable.mergeCells(QTextCursor cursor);
KMETHOD QTextTable_mergeCells(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		qp->mergeCells(cursor);
	}
	RETURNvoid_();
}
*/
//void QTextTable.removeColumns(int index, int columns);
KMETHOD QTextTable_removeColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		int columns = Int_to(int, sfp[2]);
		qp->removeColumns(index, columns);
	}
	RETURNvoid_();
}

//void QTextTable.removeRows(int index, int rows);
KMETHOD QTextTable_removeRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		int rows = Int_to(int, sfp[2]);
		qp->removeRows(index, rows);
	}
	RETURNvoid_();
}

//void QTextTable.resize(int rows, int columns);
KMETHOD QTextTable_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int rows = Int_to(int, sfp[1]);
		int columns = Int_to(int, sfp[2]);
		qp->resize(rows, columns);
	}
	RETURNvoid_();
}

//QTextCursor QTextTable.rowEnd(QTextCursor cursor);
KMETHOD QTextTable_rowEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		QTextCursor ret_v = qp->rowEnd(cursor);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QTextTable.rowStart(QTextCursor cursor);
KMETHOD QTextTable_rowStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		QTextCursor ret_v = qp->rowStart(cursor);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextTable.rows();
KMETHOD QTextTable_rows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->rows();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextTable.setFormat(QTextTableFormat fmt);
KMETHOD QTextTable_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		const QTextTableFormat  format = *RawPtr_to(const QTextTableFormat *, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//void QTextTable.splitCell(int row, int column, int numRows, int numCols);
KMETHOD QTextTable_splitCell(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTable *  qp = RawPtr_to(QTextTable *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		int numRows = Int_to(int, sfp[3]);
		int numCols = Int_to(int, sfp[4]);
		qp->splitCell(row, column, numRows, numCols);
	}
	RETURNvoid_();
}


DummyQTextTable::DummyQTextTable()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextTable::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextTable::self = ptr;
	DummyQTextFrame::setSelf(ptr);
}

bool DummyQTextTable::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextTable::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTable::event_map->bigin();
	if ((itr = DummyQTextTable::event_map->find(str)) == DummyQTextTable::event_map->end()) {
		bool ret;
		ret = DummyQTextFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextTable::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTable::slot_map->bigin();
	if ((itr = DummyQTextTable::event_map->find(str)) == DummyQTextTable::slot_map->end()) {
		bool ret;
		ret = DummyQTextFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KMETHOD QTextTable_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTable *qp = RawPtr_to(KQTextTable *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextTable]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextTable::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTable]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextTable_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTable *qp = RawPtr_to(KQTextTable *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextTable]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextTable::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTable]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextTable_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextTable *qp = (KQTextTable *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextTable_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextTable *qp = (KQTextTable *)p->rawptr;
		(void)qp;
	}
}

static int QTextTable_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQTextTable::event(QEvent *event)
{
	if (!DummyQTextTable::eventDispatcher(event)) {
		QTextTable::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTextTable(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextTable";
	cdef->free = QTextTable_free;
	cdef->reftrace = QTextTable_reftrace;
	cdef->compareTo = QTextTable_compareTo;
}


