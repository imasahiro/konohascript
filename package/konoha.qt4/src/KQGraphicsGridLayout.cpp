//@Virtual @Override int QGraphicsGridLayout.count();
KMETHOD QGraphicsGridLayout_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override void QGraphicsGridLayout.invalidate();
KMETHOD QGraphicsGridLayout_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//@Virtual @Override QGraphicsLayoutItem QGraphicsGridLayout.itemAt(int index);
KMETHOD QGraphicsGridLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QGraphicsLayoutItem* ret_v = qp->itemAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsGridLayout.removeAt(int index);
KMETHOD QGraphicsGridLayout_removeAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->removeAt(index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QGraphicsGridLayout.setGeometry(QRectF rect);
KMETHOD QGraphicsGridLayout_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//@Virtual @Override QSizeF QGraphicsGridLayout.sizeHint(int which, QSizeF constraint);
KMETHOD QGraphicsGridLayout_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		Qt::SizeHint which = Int_to(Qt::SizeHint, sfp[1]);
		const QSizeF  constraint = *RawPtr_to(const QSizeF *, sfp[2]);
		QSizeF ret_v = qp->sizeHint(which, constraint);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsGridLayout QGraphicsGridLayout.new(QGraphicsLayoutItem parent);
KMETHOD QGraphicsGridLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem*  parent = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
	KQGraphicsGridLayout *ret_v = new KQGraphicsGridLayout(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QGraphicsGridLayout.addItem(QGraphicsLayoutItem item, int row, int column, int rowSpan, int columnSpan, QtAlignment alignment);
KMETHOD QGraphicsGridLayout_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		int row = Int_to(int, sfp[2]);
		int column = Int_to(int, sfp[3]);
		int rowSpan = Int_to(int, sfp[4]);
		int columnSpan = Int_to(int, sfp[5]);
		initFlag(alignment, Qt::Alignment, sfp[6]);
		qp->addItem(item, row, column, rowSpan, columnSpan, alignment);
	}
	RETURNvoid_();
}

/*
//void QGraphicsGridLayout.addItem(QGraphicsLayoutItem item, int row, int column, QtAlignment alignment);
KMETHOD QGraphicsGridLayout_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		int row = Int_to(int, sfp[2]);
		int column = Int_to(int, sfp[3]);
		initFlag(alignment, Qt::Alignment, sfp[4]);
		qp->addItem(item, row, column, alignment);
	}
	RETURNvoid_();
}
*/
//QtAlignment QGraphicsGridLayout.getAlignment(QGraphicsLayoutItem item);
KMETHOD QGraphicsGridLayout_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		Qt::Alignment ret_v = qp->alignment(item);
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtAlignment QGraphicsGridLayout.getColumnAlignment(int column);
KMETHOD QGraphicsGridLayout_getColumnAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::Alignment ret_v = qp->columnAlignment(column);
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsGridLayout.columnCount();
KMETHOD QGraphicsGridLayout_columnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->columnCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QGraphicsGridLayout.getColumnMaximumWidth(int column);
KMETHOD QGraphicsGridLayout_getColumnMaximumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal ret_v = qp->columnMaximumWidth(column);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsGridLayout.getColumnMinimumWidth(int column);
KMETHOD QGraphicsGridLayout_getColumnMinimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal ret_v = qp->columnMinimumWidth(column);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsGridLayout.getColumnPreferredWidth(int column);
KMETHOD QGraphicsGridLayout_getColumnPreferredWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal ret_v = qp->columnPreferredWidth(column);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsGridLayout.getColumnSpacing(int column);
KMETHOD QGraphicsGridLayout_getColumnSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal ret_v = qp->columnSpacing(column);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QGraphicsGridLayout.getColumnStretchFactor(int column);
KMETHOD QGraphicsGridLayout_getColumnStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->columnStretchFactor(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QGraphicsGridLayout.getHorizontalSpacing();
KMETHOD QGraphicsGridLayout_getHorizontalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->horizontalSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

/*
//QGraphicsLayoutItem QGraphicsGridLayout.itemAt(int row, int column);
KMETHOD QGraphicsGridLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QGraphicsLayoutItem* ret_v = qp->itemAt(row, column);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QtAlignment QGraphicsGridLayout.getRowAlignment(int row);
KMETHOD QGraphicsGridLayout_getRowAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		Qt::Alignment ret_v = qp->rowAlignment(row);
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsGridLayout.rowCount();
KMETHOD QGraphicsGridLayout_rowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->rowCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QGraphicsGridLayout.getRowMaximumHeight(int row);
KMETHOD QGraphicsGridLayout_getRowMaximumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal ret_v = qp->rowMaximumHeight(row);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsGridLayout.getRowMinimumHeight(int row);
KMETHOD QGraphicsGridLayout_getRowMinimumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal ret_v = qp->rowMinimumHeight(row);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsGridLayout.getRowPreferredHeight(int row);
KMETHOD QGraphicsGridLayout_getRowPreferredHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal ret_v = qp->rowPreferredHeight(row);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsGridLayout.getRowSpacing(int row);
KMETHOD QGraphicsGridLayout_getRowSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal ret_v = qp->rowSpacing(row);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QGraphicsGridLayout.getRowStretchFactor(int row);
KMETHOD QGraphicsGridLayout_getRowStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int ret_v = qp->rowStretchFactor(row);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsGridLayout.setAlignment(QGraphicsLayoutItem item, QtAlignment alignment);
KMETHOD QGraphicsGridLayout_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		initFlag(alignment, Qt::Alignment, sfp[2]);
		qp->setAlignment(item, alignment);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setColumnAlignment(int column, QtAlignment alignment);
KMETHOD QGraphicsGridLayout_setColumnAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		initFlag(alignment, Qt::Alignment, sfp[2]);
		qp->setColumnAlignment(column, alignment);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setColumnFixedWidth(int column, float width);
KMETHOD QGraphicsGridLayout_setColumnFixedWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal width = Float_to(qreal, sfp[2]);
		qp->setColumnFixedWidth(column, width);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setColumnMaximumWidth(int column, float width);
KMETHOD QGraphicsGridLayout_setColumnMaximumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal width = Float_to(qreal, sfp[2]);
		qp->setColumnMaximumWidth(column, width);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setColumnMinimumWidth(int column, float width);
KMETHOD QGraphicsGridLayout_setColumnMinimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal width = Float_to(qreal, sfp[2]);
		qp->setColumnMinimumWidth(column, width);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setColumnPreferredWidth(int column, float width);
KMETHOD QGraphicsGridLayout_setColumnPreferredWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal width = Float_to(qreal, sfp[2]);
		qp->setColumnPreferredWidth(column, width);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setColumnSpacing(int column, float spacing);
KMETHOD QGraphicsGridLayout_setColumnSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qreal spacing = Float_to(qreal, sfp[2]);
		qp->setColumnSpacing(column, spacing);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setColumnStretchFactor(int column, int stretch);
KMETHOD QGraphicsGridLayout_setColumnStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->setColumnStretchFactor(column, stretch);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setHorizontalSpacing(float spacing);
KMETHOD QGraphicsGridLayout_setHorizontalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setHorizontalSpacing(spacing);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setRowAlignment(int row, QtAlignment alignment);
KMETHOD QGraphicsGridLayout_setRowAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		initFlag(alignment, Qt::Alignment, sfp[2]);
		qp->setRowAlignment(row, alignment);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setRowFixedHeight(int row, float height);
KMETHOD QGraphicsGridLayout_setRowFixedHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal height = Float_to(qreal, sfp[2]);
		qp->setRowFixedHeight(row, height);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setRowMaximumHeight(int row, float height);
KMETHOD QGraphicsGridLayout_setRowMaximumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal height = Float_to(qreal, sfp[2]);
		qp->setRowMaximumHeight(row, height);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setRowMinimumHeight(int row, float height);
KMETHOD QGraphicsGridLayout_setRowMinimumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal height = Float_to(qreal, sfp[2]);
		qp->setRowMinimumHeight(row, height);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setRowPreferredHeight(int row, float height);
KMETHOD QGraphicsGridLayout_setRowPreferredHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal height = Float_to(qreal, sfp[2]);
		qp->setRowPreferredHeight(row, height);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setRowSpacing(int row, float spacing);
KMETHOD QGraphicsGridLayout_setRowSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qreal spacing = Float_to(qreal, sfp[2]);
		qp->setRowSpacing(row, spacing);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setRowStretchFactor(int row, int stretch);
KMETHOD QGraphicsGridLayout_setRowStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->setRowStretchFactor(row, stretch);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setSpacing(float spacing);
KMETHOD QGraphicsGridLayout_setSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setSpacing(spacing);
	}
	RETURNvoid_();
}

//void QGraphicsGridLayout.setVerticalSpacing(float spacing);
KMETHOD QGraphicsGridLayout_setVerticalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setVerticalSpacing(spacing);
	}
	RETURNvoid_();
}

//float QGraphicsGridLayout.getVerticalSpacing();
KMETHOD QGraphicsGridLayout_getVerticalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsGridLayout *  qp = RawPtr_to(QGraphicsGridLayout *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->verticalSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQGraphicsGridLayout::DummyQGraphicsGridLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsGridLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsGridLayout::self = ptr;
	DummyQGraphicsLayout::setSelf(ptr);
}

bool DummyQGraphicsGridLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsGridLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsGridLayout::event_map->bigin();
	if ((itr = DummyQGraphicsGridLayout::event_map->find(str)) == DummyQGraphicsGridLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsGridLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsGridLayout::slot_map->bigin();
	if ((itr = DummyQGraphicsGridLayout::slot_map->find(str)) == DummyQGraphicsGridLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGraphicsGridLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsGridLayout::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGraphicsLayout::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsGridLayout::connection(QObject *o)
{
	QGraphicsGridLayout *p = dynamic_cast<QGraphicsGridLayout*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsLayout::connection(o);
}

KQGraphicsGridLayout::KQGraphicsGridLayout(QGraphicsLayoutItem* parent) : QGraphicsGridLayout(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsGridLayout();
}

KMETHOD QGraphicsGridLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsGridLayout *qp = RawPtr_to(KQGraphicsGridLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsGridLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsGridLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsGridLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsGridLayout *qp = RawPtr_to(KQGraphicsGridLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsGridLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsGridLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsGridLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsGridLayout *qp = (KQGraphicsGridLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsGridLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsGridLayout *qp = (KQGraphicsGridLayout *)p->rawptr;
//		KQGraphicsGridLayout *qp = static_cast<KQGraphicsGridLayout*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsGridLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsGridLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsGridLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsGridLayout";
	cdef->free = QGraphicsGridLayout_free;
	cdef->reftrace = QGraphicsGridLayout_reftrace;
	cdef->compareTo = QGraphicsGridLayout_compareTo;
}


