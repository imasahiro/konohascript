//@Virtual @Override void QFormLayout.addItem(QLayoutItem item);
KMETHOD QFormLayout_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QLayoutItem*  item = RawPtr_to(QLayoutItem*, sfp[1]);
		qp->addItem(item);
	}
	RETURNvoid_();
}

//@Virtual @Override int QFormLayout.count();
KMETHOD QFormLayout_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QtOrientations QFormLayout.expandingDirections();
KMETHOD QFormLayout_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		Qt::Orientations ret_v = qp->expandingDirections();
		Qt::Orientations *ret_v_ = new Qt::Orientations(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QFormLayout.hasHeightForWidth();
KMETHOD QFormLayout_hasHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasHeightForWidth();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QFormLayout.heightForWidth(int width);
KMETHOD QFormLayout_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(width);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override void QFormLayout.invalidate();
KMETHOD QFormLayout_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//@Virtual @Override QLayoutItem QFormLayout.itemAt(int index);
KMETHOD QFormLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QLayoutItem* ret_v = qp->itemAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QFormLayout.minimumSize();
KMETHOD QFormLayout_minimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QFormLayout.setGeometry(QRect rect);
KMETHOD QFormLayout_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QFormLayout.sizeHint();
KMETHOD QFormLayout_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QLayoutItem QFormLayout.takeAt(int index);
KMETHOD QFormLayout_takeAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QLayoutItem* ret_v = qp->takeAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFormLayout QFormLayout.new(QWidget parent);
KMETHOD QFormLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQFormLayout *ret_v = new KQFormLayout(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QFormLayout.addRow(QWidget label, QWidget field);
KMETHOD QFormLayout_addRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QWidget*  label = RawPtr_to(QWidget*, sfp[1]);
		QWidget*  field = RawPtr_to(QWidget*, sfp[2]);
		qp->addRow(label, field);
	}
	RETURNvoid_();
}

/*
//void QFormLayout.addRow(QWidget label, QLayout field);
KMETHOD QFormLayout_addRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QWidget*  label = RawPtr_to(QWidget*, sfp[1]);
		QLayout*  field = RawPtr_to(QLayout*, sfp[2]);
		qp->addRow(label, field);
	}
	RETURNvoid_();
}
*/
/*
//void QFormLayout.addRow(String labelText, QWidget field);
KMETHOD QFormLayout_addRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		const QString labelText = String_to(const QString, sfp[1]);
		QWidget*  field = RawPtr_to(QWidget*, sfp[2]);
		qp->addRow(labelText, field);
	}
	RETURNvoid_();
}
*/
/*
//void QFormLayout.addRow(String labelText, QLayout field);
KMETHOD QFormLayout_addRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		const QString labelText = String_to(const QString, sfp[1]);
		QLayout*  field = RawPtr_to(QLayout*, sfp[2]);
		qp->addRow(labelText, field);
	}
	RETURNvoid_();
}
*/
/*
//void QFormLayout.addRow(QWidget widget);
KMETHOD QFormLayout_addRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->addRow(widget);
	}
	RETURNvoid_();
}
*/
/*
//void QFormLayout.addRow(QLayout layout);
KMETHOD QFormLayout_addRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QLayout*  layout = RawPtr_to(QLayout*, sfp[1]);
		qp->addRow(layout);
	}
	RETURNvoid_();
}
*/
//int QFormLayout.getFieldGrowthPolicy();
KMETHOD QFormLayout_getFieldGrowthPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QFormLayout::FieldGrowthPolicy ret_v = qp->fieldGrowthPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtAlignment QFormLayout.getFormAlignment();
KMETHOD QFormLayout_getFormAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->formAlignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QFormLayout.getItemPosition(int index, int rowPtr, int rolePtr);
KMETHOD QFormLayout_getItemPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int* rowPtr = Int_to(int*, sfp[2]);
		QFormLayout::ItemRole* rolePtr = Int_to(QFormLayout::ItemRole*, sfp[3]);
		qp->getItemPosition(index, rowPtr, rolePtr);
	}
	RETURNvoid_();
}

//void QFormLayout.getLayoutPosition(QLayout layout, int rowPtr, int rolePtr);
KMETHOD QFormLayout_getLayoutPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QLayout*  layout = RawPtr_to(QLayout*, sfp[1]);
		int* rowPtr = Int_to(int*, sfp[2]);
		QFormLayout::ItemRole* rolePtr = Int_to(QFormLayout::ItemRole*, sfp[3]);
		qp->getLayoutPosition(layout, rowPtr, rolePtr);
	}
	RETURNvoid_();
}

//void QFormLayout.getWidgetPosition(QWidget widget, int rowPtr, int rolePtr);
KMETHOD QFormLayout_getWidgetPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int* rowPtr = Int_to(int*, sfp[2]);
		QFormLayout::ItemRole* rolePtr = Int_to(QFormLayout::ItemRole*, sfp[3]);
		qp->getWidgetPosition(widget, rowPtr, rolePtr);
	}
	RETURNvoid_();
}

//int QFormLayout.getHorizontalSpacing();
KMETHOD QFormLayout_getHorizontalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->horizontalSpacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//QLayoutItem QFormLayout.itemAt(int row, int role);
KMETHOD QFormLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		QFormLayout::ItemRole role = Int_to(QFormLayout::ItemRole, sfp[2]);
		QLayoutItem* ret_v = qp->itemAt(row, role);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QtAlignment QFormLayout.getLabelAlignment();
KMETHOD QFormLayout_getLabelAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->labelAlignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QFormLayout.labelForField(QWidget field);
KMETHOD QFormLayout_labelForField(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QWidget*  field = RawPtr_to(QWidget*, sfp[1]);
		QWidget* ret_v = qp->labelForField(field);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QWidget QFormLayout.labelForField(QLayout field);
KMETHOD QFormLayout_labelForField(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QLayout*  field = RawPtr_to(QLayout*, sfp[1]);
		QWidget* ret_v = qp->labelForField(field);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QFormLayout.rowCount();
KMETHOD QFormLayout_rowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->rowCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFormLayout.getRowWrapPolicy();
KMETHOD QFormLayout_getRowWrapPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QFormLayout::RowWrapPolicy ret_v = qp->rowWrapPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QFormLayout.setFieldGrowthPolicy(int policy);
KMETHOD QFormLayout_setFieldGrowthPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QFormLayout::FieldGrowthPolicy policy = Int_to(QFormLayout::FieldGrowthPolicy, sfp[1]);
		qp->setFieldGrowthPolicy(policy);
	}
	RETURNvoid_();
}

//void QFormLayout.setFormAlignment(QtAlignment alignment);
KMETHOD QFormLayout_setFormAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		initFlag(alignment, Qt::Alignment, sfp[1]);
		qp->setFormAlignment(alignment);
	}
	RETURNvoid_();
}

//void QFormLayout.setHorizontalSpacing(int spacing);
KMETHOD QFormLayout_setHorizontalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int spacing = Int_to(int, sfp[1]);
		qp->setHorizontalSpacing(spacing);
	}
	RETURNvoid_();
}

//void QFormLayout.setItem(int row, int role, QLayoutItem item);
KMETHOD QFormLayout_setItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		QFormLayout::ItemRole role = Int_to(QFormLayout::ItemRole, sfp[2]);
		QLayoutItem*  item = RawPtr_to(QLayoutItem*, sfp[3]);
		qp->setItem(row, role, item);
	}
	RETURNvoid_();
}

//void QFormLayout.setLabelAlignment(QtAlignment alignment);
KMETHOD QFormLayout_setLabelAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		initFlag(alignment, Qt::Alignment, sfp[1]);
		qp->setLabelAlignment(alignment);
	}
	RETURNvoid_();
}

//void QFormLayout.setLayout(int row, int role, QLayout layout);
KMETHOD QFormLayout_setLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		QFormLayout::ItemRole role = Int_to(QFormLayout::ItemRole, sfp[2]);
		QLayout*  layout = RawPtr_to(QLayout*, sfp[3]);
		qp->setLayout(row, role, layout);
	}
	RETURNvoid_();
}

//void QFormLayout.setRowWrapPolicy(int policy);
KMETHOD QFormLayout_setRowWrapPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		QFormLayout::RowWrapPolicy policy = Int_to(QFormLayout::RowWrapPolicy, sfp[1]);
		qp->setRowWrapPolicy(policy);
	}
	RETURNvoid_();
}

//void QFormLayout.setSpacing(int spacing);
KMETHOD QFormLayout_setSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int spacing = Int_to(int, sfp[1]);
		qp->setSpacing(spacing);
	}
	RETURNvoid_();
}

//void QFormLayout.setVerticalSpacing(int spacing);
KMETHOD QFormLayout_setVerticalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int spacing = Int_to(int, sfp[1]);
		qp->setVerticalSpacing(spacing);
	}
	RETURNvoid_();
}

//void QFormLayout.setWidget(int row, int role, QWidget widget);
KMETHOD QFormLayout_setWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		QFormLayout::ItemRole role = Int_to(QFormLayout::ItemRole, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->setWidget(row, role, widget);
	}
	RETURNvoid_();
}

//int QFormLayout.getSpacing();
KMETHOD QFormLayout_getSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->spacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFormLayout.getVerticalSpacing();
KMETHOD QFormLayout_getVerticalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFormLayout *  qp = RawPtr_to(QFormLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->verticalSpacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQFormLayout::DummyQFormLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQFormLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFormLayout::self = ptr;
	DummyQLayout::setSelf(ptr);
}

bool DummyQFormLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFormLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFormLayout::event_map->bigin();
	if ((itr = DummyQFormLayout::event_map->find(str)) == DummyQFormLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFormLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFormLayout::slot_map->bigin();
	if ((itr = DummyQFormLayout::slot_map->find(str)) == DummyQFormLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQFormLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQLayout::reftrace(ctx, p, tail_);
}

void DummyQFormLayout::connection(QObject *o)
{
	QFormLayout *p = dynamic_cast<QFormLayout*>(o);
	if (p != NULL) {
	}
	DummyQLayout::connection(o);
}

KQFormLayout::KQFormLayout(QWidget* parent) : QFormLayout(parent)
{
	self = NULL;
	dummy = new DummyQFormLayout();
	dummy->connection((QObject*)this);
}

KMETHOD QFormLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFormLayout *qp = RawPtr_to(KQFormLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFormLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFormLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFormLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFormLayout *qp = RawPtr_to(KQFormLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFormLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFormLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFormLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFormLayout *qp = (KQFormLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFormLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQFormLayout *qp = (KQFormLayout *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFormLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQFormLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQFormLayout::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QFormLayout::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QFormLayoutConstInt[] = {
	{"FieldsStayAtSizeHint", QFormLayout::FieldsStayAtSizeHint},
	{"ExpandingFieldsGrow", QFormLayout::ExpandingFieldsGrow},
	{"AllNonFixedFieldsGrow", QFormLayout::AllNonFixedFieldsGrow},
	{"LabelRole", QFormLayout::LabelRole},
	{"FieldRole", QFormLayout::FieldRole},
	{"SpanningRole", QFormLayout::SpanningRole},
	{"DontWrapRows", QFormLayout::DontWrapRows},
	{"WrapLongRows", QFormLayout::WrapLongRows},
	{"WrapAllRows", QFormLayout::WrapAllRows},
	{NULL, 0}
};

DEFAPI(void) constQFormLayout(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFormLayoutConstInt);
}


DEFAPI(void) defQFormLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFormLayout";
	cdef->free = QFormLayout_free;
	cdef->reftrace = QFormLayout_reftrace;
	cdef->compareTo = QFormLayout_compareTo;
}


