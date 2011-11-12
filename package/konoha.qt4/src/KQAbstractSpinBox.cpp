//@Virtual @Override boolean QAbstractSpinBox.event(QEvent event);
KMETHOD QAbstractSpinBox_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QEvent*  event = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QVariant QAbstractSpinBox.inputMethodQuery(int query);
KMETHOD QAbstractSpinBox_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		Qt::InputMethodQuery query = Int_to(Qt::InputMethodQuery, sfp[1]);
		QVariant ret_v = qp->inputMethodQuery(query);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QAbstractSpinBox.minimumSizeHint();
KMETHOD QAbstractSpinBox_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QAbstractSpinBox.sizeHint();
KMETHOD QAbstractSpinBox_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//
//QtAlignment QAbstractSpinBox.getAlignment();
KMETHOD QAbstractSpinBox_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractSpinBox.getButtonSymbols();
KMETHOD QAbstractSpinBox_getButtonSymbols(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QAbstractSpinBox::ButtonSymbols ret_v = qp->buttonSymbols();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractSpinBox.getCorrectionMode();
KMETHOD QAbstractSpinBox_getCorrectionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QAbstractSpinBox::CorrectionMode ret_v = qp->correctionMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QAbstractSpinBox.fixup(String input);
KMETHOD QAbstractSpinBox_fixup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QString input = String_to(QString, sfp[1]);
		qp->fixup(input);
	}
	RETURNvoid_();
}

//boolean QAbstractSpinBox.hasAcceptableInput();
KMETHOD QAbstractSpinBox_hasAcceptableInput(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasAcceptableInput();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractSpinBox.hasFrame();
KMETHOD QAbstractSpinBox_hasFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasFrame();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QAbstractSpinBox.interpretText();
KMETHOD QAbstractSpinBox_interpretText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		qp->interpretText();
	}
	RETURNvoid_();
}

//boolean QAbstractSpinBox.isAccelerated();
KMETHOD QAbstractSpinBox_isAccelerated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isAccelerated();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractSpinBox.isReadOnly();
KMETHOD QAbstractSpinBox_isReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isReadOnly();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractSpinBox.getKeyboardTracking();
KMETHOD QAbstractSpinBox_getKeyboardTracking(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->keyboardTracking();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QAbstractSpinBox.setAccelerated(boolean on);
KMETHOD QAbstractSpinBox_setAccelerated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setAccelerated(on);
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.setAlignment(QtAlignment flag);
KMETHOD QAbstractSpinBox_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		initFlag(flag, Qt::Alignment, sfp[1]);
		qp->setAlignment(flag);
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.setButtonSymbols(int bs);
KMETHOD QAbstractSpinBox_setButtonSymbols(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QAbstractSpinBox::ButtonSymbols bs = Int_to(QAbstractSpinBox::ButtonSymbols, sfp[1]);
		qp->setButtonSymbols(bs);
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.setCorrectionMode(int cm);
KMETHOD QAbstractSpinBox_setCorrectionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QAbstractSpinBox::CorrectionMode cm = Int_to(QAbstractSpinBox::CorrectionMode, sfp[1]);
		qp->setCorrectionMode(cm);
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.setFrame(boolean arg0);
KMETHOD QAbstractSpinBox_setFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setFrame(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.setKeyboardTracking(boolean kt);
KMETHOD QAbstractSpinBox_setKeyboardTracking(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool kt = Boolean_to(bool, sfp[1]);
		qp->setKeyboardTracking(kt);
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.setReadOnly(boolean r);
KMETHOD QAbstractSpinBox_setReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool r = Boolean_to(bool, sfp[1]);
		qp->setReadOnly(r);
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.setSpecialValueText(String txt);
KMETHOD QAbstractSpinBox_setSpecialValueText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		const QString txt = String_to(const QString, sfp[1]);
		qp->setSpecialValueText(txt);
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.setWrapping(boolean w);
KMETHOD QAbstractSpinBox_setWrapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool w = Boolean_to(bool, sfp[1]);
		qp->setWrapping(w);
	}
	RETURNvoid_();
}

//String QAbstractSpinBox.getSpecialValueText();
KMETHOD QAbstractSpinBox_getSpecialValueText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QString ret_v = qp->specialValueText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QAbstractSpinBox.stepBy(int steps);
KMETHOD QAbstractSpinBox_stepBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		int steps = Int_to(int, sfp[1]);
		qp->stepBy(steps);
	}
	RETURNvoid_();
}

//String QAbstractSpinBox.text();
KMETHOD QAbstractSpinBox_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAbstractSpinBox.validate(String input, int pos);
KMETHOD QAbstractSpinBox_validate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		QString input = String_to(QString, sfp[1]);
		int pos = Int_to(int, sfp[2]);
		QValidator::State ret_v = qp->validate(input, pos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QAbstractSpinBox.getWrapping();
KMETHOD QAbstractSpinBox_getWrapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->wrapping();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QAbstractSpinBox.clear();
KMETHOD QAbstractSpinBox_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.selectAll();
KMETHOD QAbstractSpinBox_selectAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		qp->selectAll();
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.stepDown();
KMETHOD QAbstractSpinBox_stepDown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		qp->stepDown();
	}
	RETURNvoid_();
}

//void QAbstractSpinBox.stepUp();
KMETHOD QAbstractSpinBox_stepUp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox *  qp = RawPtr_to(QAbstractSpinBox *, sfp[0]);
	if (qp) {
		qp->stepUp();
	}
	RETURNvoid_();
}


DummyQAbstractSpinBox::DummyQAbstractSpinBox()
{
	self = NULL;
	editing_finished_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("editing-finished", NULL));
}

void DummyQAbstractSpinBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractSpinBox::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQAbstractSpinBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractSpinBox::editingFinishedSlot()
{
	if (editing_finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, editing_finished_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractSpinBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractSpinBox::event_map->bigin();
	if ((itr = DummyQAbstractSpinBox::event_map->find(str)) == DummyQAbstractSpinBox::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractSpinBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractSpinBox::slot_map->bigin();
	if ((itr = DummyQAbstractSpinBox::slot_map->find(str)) == DummyQAbstractSpinBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		editing_finished_func = (*slot_map)["editing-finished"];
		return true;
	}
}

knh_Object_t** DummyQAbstractSpinBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractSpinBox::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, editing_finished_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractSpinBox::connection(QObject *o)
{
	QAbstractSpinBox *p = dynamic_cast<QAbstractSpinBox*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(editingFinished()), this, SLOT(editingFinishedSlot()));
	}
	DummyQWidget::connection(o);
}

KQAbstractSpinBox::KQAbstractSpinBox(QWidget* parent) : QAbstractSpinBox(parent)
{
	self = NULL;
	dummy = new DummyQAbstractSpinBox();
	dummy->connection((QObject*)this);
}

KMETHOD QAbstractSpinBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractSpinBox *qp = RawPtr_to(KQAbstractSpinBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractSpinBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractSpinBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractSpinBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractSpinBox *qp = RawPtr_to(KQAbstractSpinBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractSpinBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractSpinBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractSpinBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractSpinBox *qp = (KQAbstractSpinBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractSpinBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAbstractSpinBox *qp = (KQAbstractSpinBox *)p->rawptr;
//		KQAbstractSpinBox *qp = static_cast<KQAbstractSpinBox*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractSpinBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractSpinBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractSpinBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractSpinBox::event(event);
		return false;
	}
//	QAbstractSpinBox::event(event);
	return true;
}

static knh_IntData_t QAbstractSpinBoxConstInt[] = {
	{"UpDownArrows", QAbstractSpinBox::UpDownArrows},
	{"PlusMinus", QAbstractSpinBox::PlusMinus},
	{"NoButtons", QAbstractSpinBox::NoButtons},
	{"CorrectToPreviousValue", QAbstractSpinBox::CorrectToPreviousValue},
	{"CorrectToNearestValue", QAbstractSpinBox::CorrectToNearestValue},
	{"StepNone", QAbstractSpinBox::StepNone},
	{"StepUpEnabled", QAbstractSpinBox::StepUpEnabled},
	{"StepDownEnabled", QAbstractSpinBox::StepDownEnabled},
	{NULL, 0}
};

DEFAPI(void) constQAbstractSpinBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QAbstractSpinBoxConstInt);
}


DEFAPI(void) defQAbstractSpinBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractSpinBox";
	cdef->free = QAbstractSpinBox_free;
	cdef->reftrace = QAbstractSpinBox_reftrace;
	cdef->compareTo = QAbstractSpinBox_compareTo;
}

//## QAbstractSpinBoxStepEnabled QAbstractSpinBoxStepEnabled.new(int value);
KMETHOD QAbstractSpinBoxStepEnabled_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractSpinBox::StepEnabledFlag i = Int_to(QAbstractSpinBox::StepEnabledFlag, sfp[1]);
	QAbstractSpinBox::StepEnabled *ret_v = new QAbstractSpinBox::StepEnabled(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QAbstractSpinBoxStepEnabled QAbstractSpinBoxStepEnabled.and(int mask);
KMETHOD QAbstractSpinBoxStepEnabled_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractSpinBox::StepEnabled *qp = RawPtr_to(QAbstractSpinBox::StepEnabled*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QAbstractSpinBox::StepEnabled ret = ((*qp) & i);
		QAbstractSpinBox::StepEnabled *ret_ = new QAbstractSpinBox::StepEnabled(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractSpinBoxStepEnabled QAbstractSpinBoxStepEnabled.iand(QAbstractSpinBox::QAbstractSpinBoxStepEnabled other);
KMETHOD QAbstractSpinBoxStepEnabled_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractSpinBox::StepEnabled *qp = RawPtr_to(QAbstractSpinBox::StepEnabled*, sfp[0]);
	if (qp != NULL) {
		QAbstractSpinBox::StepEnabled *other = RawPtr_to(QAbstractSpinBox::StepEnabled *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractSpinBoxStepEnabled QAbstractSpinBoxStepEnabled.or(QAbstractSpinBoxStepEnabled f);
KMETHOD QAbstractSpinBoxStepEnabled_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox::StepEnabled *qp = RawPtr_to(QAbstractSpinBox::StepEnabled*, sfp[0]);
	if (qp != NULL) {
		QAbstractSpinBox::StepEnabled *f = RawPtr_to(QAbstractSpinBox::StepEnabled*, sfp[1]);
		QAbstractSpinBox::StepEnabled ret = ((*qp) | (*f));
		QAbstractSpinBox::StepEnabled *ret_ = new QAbstractSpinBox::StepEnabled(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractSpinBoxStepEnabled QAbstractSpinBoxStepEnabled.ior(QAbstractSpinBox::QAbstractSpinBoxStepEnabled other);
KMETHOD QAbstractSpinBoxStepEnabled_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractSpinBox::StepEnabled *qp = RawPtr_to(QAbstractSpinBox::StepEnabled*, sfp[0]);
	if (qp != NULL) {
		QAbstractSpinBox::StepEnabled *other = RawPtr_to(QAbstractSpinBox::StepEnabled *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractSpinBoxStepEnabled QAbstractSpinBoxStepEnabled.xor(QAbstractSpinBoxStepEnabled f);
KMETHOD QAbstractSpinBoxStepEnabled_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSpinBox::StepEnabled *qp = RawPtr_to(QAbstractSpinBox::StepEnabled*, sfp[0]);
	if (qp != NULL) {
		QAbstractSpinBox::StepEnabled *f = RawPtr_to(QAbstractSpinBox::StepEnabled*, sfp[1]);
		QAbstractSpinBox::StepEnabled ret = ((*qp) ^ (*f));
		QAbstractSpinBox::StepEnabled *ret_ = new QAbstractSpinBox::StepEnabled(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractSpinBoxStepEnabled QAbstractSpinBoxStepEnabled.ixor(QAbstractSpinBox::QAbstractSpinBoxStepEnabled other);
KMETHOD QAbstractSpinBoxStepEnabled_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractSpinBox::StepEnabled *qp = RawPtr_to(QAbstractSpinBox::StepEnabled*, sfp[0]);
	if (qp != NULL) {
		QAbstractSpinBox::StepEnabled *other = RawPtr_to(QAbstractSpinBox::StepEnabled *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QAbstractSpinBoxStepEnabled.testFlag(int flag);
KMETHOD QAbstractSpinBoxStepEnabled_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractSpinBox::StepEnabled *qp = RawPtr_to(QAbstractSpinBox::StepEnabled *, sfp[0]);
	if (qp != NULL) {
		QAbstractSpinBox::StepEnabledFlag flag = Int_to(QAbstractSpinBox::StepEnabledFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QAbstractSpinBoxStepEnabled.value();
KMETHOD QAbstractSpinBoxStepEnabled_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractSpinBox::StepEnabled *qp = RawPtr_to(QAbstractSpinBox::StepEnabled *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QAbstractSpinBoxStepEnabled_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QAbstractSpinBox::StepEnabled *qp = (QAbstractSpinBox::StepEnabled *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QAbstractSpinBoxStepEnabled_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QAbstractSpinBox::StepEnabled *qp = (QAbstractSpinBox::StepEnabled *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractSpinBoxStepEnabled_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QAbstractSpinBox::StepEnabled*)p1->rawptr);
//		int v2 = int(*(QAbstractSpinBox::StepEnabled*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QAbstractSpinBox::StepEnabled v1 = *(QAbstractSpinBox::StepEnabled*)p1->rawptr;
		QAbstractSpinBox::StepEnabled v2 = *(QAbstractSpinBox::StepEnabled*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQAbstractSpinBoxStepEnabled(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractSpinBoxStepEnabled";
	cdef->free = QAbstractSpinBoxStepEnabled_free;
	cdef->reftrace = QAbstractSpinBoxStepEnabled_reftrace;
	cdef->compareTo = QAbstractSpinBoxStepEnabled_compareTo;
}

