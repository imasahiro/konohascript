//QTextTableCell QTextTableCell.new();
KMETHOD QTextTableCell_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextTableCell *ret_v = new KQTextTableCell();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QTextTableCell.column();
KMETHOD QTextTableCell_column(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp) {
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
	if (qp) {
		int ret_v = qp->columnSpan();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextCursor QTextTableCell.firstCursorPosition();
KMETHOD QTextTableCell_firstCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp) {
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
	if (qp) {
		QTextCharFormat ret_v = qp->format();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QTextTableCell.lastCursorPosition();
KMETHOD QTextTableCell_lastCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *  qp = RawPtr_to(QTextTableCell *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		int ret_v = qp->tableCellFormatIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QTextTableCell.parents();
KMETHOD QTextTableCell_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextTableCell *qp = RawPtr_to(QTextTableCell*, sfp[0]);
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

DummyQTextTableCell::DummyQTextTableCell()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextTableCell::~DummyQTextTableCell()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextTableCell::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextTableCell::slot_map->bigin();
	if ((itr = DummyQTextTableCell::slot_map->find(str)) == DummyQTextTableCell::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextTableCell::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextTableCell::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextTableCell::connection(QObject *o)
{
	QTextTableCell *p = dynamic_cast<QTextTableCell*>(o);
	if (p != NULL) {
	}
}

KQTextTableCell::KQTextTableCell() : QTextTableCell()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextTableCell();
}

KQTextTableCell::~KQTextTableCell()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextTableCell]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextTableCell_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextTableCell *qp = (KQTextTableCell *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextTableCell*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextTableCell_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextTableCell *qp = (KQTextTableCell *)p->rawptr;
		KQTextTableCell *qp = static_cast<KQTextTableCell*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextTableCell_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTextTableCell*>(p1->rawptr) == *static_cast<QTextTableCell*>(p2->rawptr) ? 0 : 1);
}

void KQTextTableCell::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextTableCell(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextTableCell";
	cdef->free = QTextTableCell_free;
	cdef->reftrace = QTextTableCell_reftrace;
	cdef->compareTo = QTextTableCell_compareTo;
}


