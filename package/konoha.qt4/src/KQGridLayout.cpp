//@Virtual @Override int QGridLayout.count();
KMETHOD QGridLayout_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QtOrientations QGridLayout.expandingDirections();
KMETHOD QGridLayout_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		Qt::Orientations ret_v = qp->expandingDirections();
		Qt::Orientations *ret_v_ = new Qt::Orientations(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QGridLayout.hasHeightForWidth();
KMETHOD QGridLayout_hasHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasHeightForWidth();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QGridLayout.heightForWidth(int w);
KMETHOD QGridLayout_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override void QGridLayout.invalidate();
KMETHOD QGridLayout_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//@Virtual @Override QLayoutItem QGridLayout.itemAt(int index);
KMETHOD QGridLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QLayoutItem* ret_v = qp->itemAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QGridLayout.maximumSize();
KMETHOD QGridLayout_maximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->maximumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QGridLayout.minimumHeightForWidth(int w);
KMETHOD QGridLayout_minimumHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->minimumHeightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QSize QGridLayout.minimumSize();
KMETHOD QGridLayout_minimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGridLayout.setGeometry(QRect rect);
KMETHOD QGridLayout_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QGridLayout.sizeHint();
KMETHOD QGridLayout_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QLayoutItem QGridLayout.takeAt(int index);
KMETHOD QGridLayout_takeAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QLayoutItem* ret_v = qp->takeAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGridLayout QGridLayout.new(QWidget parent);
KMETHOD QGridLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQGridLayout *ret_v = new KQGridLayout(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGridLayout QGridLayout.new();
KMETHOD QGridLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGridLayout *ret_v = new KQGridLayout();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QGridLayout.addItem(QLayoutItem item, int row, int column, int rowSpan, int columnSpan, QtAlignment alignment);
KMETHOD QGridLayout_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		QLayoutItem*  item = RawPtr_to(QLayoutItem*, sfp[1]);
		int row = Int_to(int, sfp[2]);
		int column = Int_to(int, sfp[3]);
		int rowSpan = Int_to(int, sfp[4]);
		int columnSpan = Int_to(int, sfp[5]);
		initFlag(alignment, Qt::Alignment, sfp[6]);
		qp->addItem(item, row, column, rowSpan, columnSpan, alignment);
	}
	RETURNvoid_();
}

//void QGridLayout.addLayout(QLayout layout, int row, int column, QtAlignment alignment);
KMETHOD QGridLayout_addLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		QLayout*  layout = RawPtr_to(QLayout*, sfp[1]);
		int row = Int_to(int, sfp[2]);
		int column = Int_to(int, sfp[3]);
		initFlag(alignment, Qt::Alignment, sfp[4]);
		qp->addLayout(layout, row, column, alignment);
	}
	RETURNvoid_();
}

/*
//void QGridLayout.addLayout(QLayout layout, int row, int column, int rowSpan, int columnSpan, QtAlignment alignment);
KMETHOD QGridLayout_addLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		QLayout*  layout = RawPtr_to(QLayout*, sfp[1]);
		int row = Int_to(int, sfp[2]);
		int column = Int_to(int, sfp[3]);
		int rowSpan = Int_to(int, sfp[4]);
		int columnSpan = Int_to(int, sfp[5]);
		initFlag(alignment, Qt::Alignment, sfp[6]);
		qp->addLayout(layout, row, column, rowSpan, columnSpan, alignment);
	}
	RETURNvoid_();
}
*/
//void QGridLayout.addWidget(QWidget widget, int row, int column, QtAlignment alignment);
KMETHOD QGridLayout_addWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int row = Int_to(int, sfp[2]);
		int column = Int_to(int, sfp[3]);
		initFlag(alignment, Qt::Alignment, sfp[4]);
		qp->addWidget(widget, row, column, alignment);
	}
	RETURNvoid_();
}

/*
//void QGridLayout.addWidget(QWidget widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, QtAlignment alignment);
KMETHOD QGridLayout_addWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int fromRow = Int_to(int, sfp[2]);
		int fromColumn = Int_to(int, sfp[3]);
		int rowSpan = Int_to(int, sfp[4]);
		int columnSpan = Int_to(int, sfp[5]);
		initFlag(alignment, Qt::Alignment, sfp[6]);
		qp->addWidget(widget, fromRow, fromColumn, rowSpan, columnSpan, alignment);
	}
	RETURNvoid_();
}
*/
//QRect QGridLayout.cellRect(int row, int column);
KMETHOD QGridLayout_cellRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QRect ret_v = qp->cellRect(row, column);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGridLayout.columnCount();
KMETHOD QGridLayout_columnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->columnCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGridLayout.getColumnMinimumWidth(int column);
KMETHOD QGridLayout_getColumnMinimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->columnMinimumWidth(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGridLayout.getColumnStretch(int column);
KMETHOD QGridLayout_getColumnStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->columnStretch(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGridLayout.getItemPosition(int index, int row, int column, int rowSpan, int columnSpan);
KMETHOD QGridLayout_getItemPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int* row = Int_to(int*, sfp[2]);
		int* column = Int_to(int*, sfp[3]);
		int* rowSpan = Int_to(int*, sfp[4]);
		int* columnSpan = Int_to(int*, sfp[5]);
		qp->getItemPosition(index, row, column, rowSpan, columnSpan);
	}
	RETURNvoid_();
}

//int QGridLayout.getHorizontalSpacing();
KMETHOD QGridLayout_getHorizontalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->horizontalSpacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QLayoutItem QGridLayout.itemAtPosition(int row, int column);
KMETHOD QGridLayout_itemAtPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QLayoutItem* ret_v = qp->itemAtPosition(row, column);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGridLayout.getOriginCorner();
KMETHOD QGridLayout_getOriginCorner(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		Qt::Corner ret_v = qp->originCorner();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGridLayout.rowCount();
KMETHOD QGridLayout_rowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->rowCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGridLayout.getRowMinimumHeight(int row);
KMETHOD QGridLayout_getRowMinimumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int ret_v = qp->rowMinimumHeight(row);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGridLayout.getRowStretch(int row);
KMETHOD QGridLayout_getRowStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int ret_v = qp->rowStretch(row);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGridLayout.setColumnMinimumWidth(int column, int minSize);
KMETHOD QGridLayout_setColumnMinimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int minSize = Int_to(int, sfp[2]);
		qp->setColumnMinimumWidth(column, minSize);
	}
	RETURNvoid_();
}

//void QGridLayout.setColumnStretch(int column, int stretch);
KMETHOD QGridLayout_setColumnStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->setColumnStretch(column, stretch);
	}
	RETURNvoid_();
}

//void QGridLayout.setHorizontalSpacing(int spacing);
KMETHOD QGridLayout_setHorizontalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int spacing = Int_to(int, sfp[1]);
		qp->setHorizontalSpacing(spacing);
	}
	RETURNvoid_();
}

//void QGridLayout.setOriginCorner(int corner);
KMETHOD QGridLayout_setOriginCorner(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		Qt::Corner corner = Int_to(Qt::Corner, sfp[1]);
		qp->setOriginCorner(corner);
	}
	RETURNvoid_();
}

//void QGridLayout.setRowMinimumHeight(int row, int minSize);
KMETHOD QGridLayout_setRowMinimumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int minSize = Int_to(int, sfp[2]);
		qp->setRowMinimumHeight(row, minSize);
	}
	RETURNvoid_();
}

//void QGridLayout.setRowStretch(int row, int stretch);
KMETHOD QGridLayout_setRowStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->setRowStretch(row, stretch);
	}
	RETURNvoid_();
}

//void QGridLayout.setSpacing(int spacing);
KMETHOD QGridLayout_setSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int spacing = Int_to(int, sfp[1]);
		qp->setSpacing(spacing);
	}
	RETURNvoid_();
}

//void QGridLayout.setVerticalSpacing(int spacing);
KMETHOD QGridLayout_setVerticalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int spacing = Int_to(int, sfp[1]);
		qp->setVerticalSpacing(spacing);
	}
	RETURNvoid_();
}

//int QGridLayout.getSpacing();
KMETHOD QGridLayout_getSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->spacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGridLayout.getVerticalSpacing();
KMETHOD QGridLayout_getVerticalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGridLayout *  qp = RawPtr_to(QGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->verticalSpacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQGridLayout::DummyQGridLayout()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGridLayout::~DummyQGridLayout()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGridLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGridLayout::self = ptr;
	DummyQLayout::setSelf(ptr);
}

bool DummyQGridLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGridLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGridLayout::event_map->bigin();
	if ((itr = DummyQGridLayout::event_map->find(str)) == DummyQGridLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGridLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGridLayout::slot_map->bigin();
	if ((itr = DummyQGridLayout::slot_map->find(str)) == DummyQGridLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGridLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGridLayout::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQLayout::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGridLayout::connection(QObject *o)
{
	QGridLayout *p = dynamic_cast<QGridLayout*>(o);
	if (p != NULL) {
	}
	DummyQLayout::connection(o);
}

KQGridLayout::KQGridLayout(QWidget* parent) : QGridLayout(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGridLayout();
	dummy->connection((QObject*)this);
}

KQGridLayout::~KQGridLayout()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGridLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGridLayout *qp = RawPtr_to(KQGridLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGridLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGridLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGridLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGridLayout *qp = RawPtr_to(KQGridLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGridLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGridLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGridLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGridLayout *qp = (KQGridLayout *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGridLayout*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGridLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGridLayout *qp = (KQGridLayout *)p->rawptr;
		KQGridLayout *qp = static_cast<KQGridLayout*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGridLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGridLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGridLayout::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGridLayout::event(event);
		return false;
	}
//	QGridLayout::event(event);
	return true;
}



DEFAPI(void) defQGridLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGridLayout";
	cdef->free = QGridLayout_free;
	cdef->reftrace = QGridLayout_reftrace;
	cdef->compareTo = QGridLayout_compareTo;
}


