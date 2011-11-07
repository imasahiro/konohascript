//QWizardPage QWizardPage.new(QWidget parent);
KMETHOD QWizardPage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQWizardPage *ret_v = new KQWizardPage(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QWizardPage.getButtonText(int which);
KMETHOD QWizardPage_getButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		QWizard::WizardButton which = Int_to(QWizard::WizardButton, sfp[1]);
		QString ret_v = qp->buttonText(which);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QWizardPage.cleanupPage();
KMETHOD QWizardPage_cleanupPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		qp->cleanupPage();
	}
	RETURNvoid_();
}

//@Virtual void QWizardPage.initializePage();
KMETHOD QWizardPage_initializePage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		qp->initializePage();
	}
	RETURNvoid_();
}

//boolean QWizardPage.isCommitPage();
KMETHOD QWizardPage_isCommitPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCommitPage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QWizardPage.isComplete();
KMETHOD QWizardPage_isComplete(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isComplete();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWizardPage.isFinalPage();
KMETHOD QWizardPage_isFinalPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFinalPage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QWizardPage.nextId();
KMETHOD QWizardPage_nextId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		int ret_v = qp->nextId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPixmap QWizardPage.getPixmap(int which);
KMETHOD QWizardPage_getPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		QWizard::WizardPixmap which = Int_to(QWizard::WizardPixmap, sfp[1]);
		QPixmap ret_v = qp->pixmap(which);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWizardPage.setButtonText(int which, String text);
KMETHOD QWizardPage_setButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		QWizard::WizardButton which = Int_to(QWizard::WizardButton, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setButtonText(which, text);
	}
	RETURNvoid_();
}

//void QWizardPage.setCommitPage(boolean commitPage);
KMETHOD QWizardPage_setCommitPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		bool commitPage = Boolean_to(bool, sfp[1]);
		qp->setCommitPage(commitPage);
	}
	RETURNvoid_();
}

//void QWizardPage.setFinalPage(boolean finalPage);
KMETHOD QWizardPage_setFinalPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		bool finalPage = Boolean_to(bool, sfp[1]);
		qp->setFinalPage(finalPage);
	}
	RETURNvoid_();
}

//void QWizardPage.setPixmap(int which, QPixmap pixmap);
KMETHOD QWizardPage_setPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		QWizard::WizardPixmap which = Int_to(QWizard::WizardPixmap, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		qp->setPixmap(which, pixmap);
	}
	RETURNvoid_();
}

//void QWizardPage.setSubTitle(String subTitle);
KMETHOD QWizardPage_setSubTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		const QString subTitle = String_to(const QString, sfp[1]);
		qp->setSubTitle(subTitle);
	}
	RETURNvoid_();
}

//void QWizardPage.setTitle(String title);
KMETHOD QWizardPage_setTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		const QString title = String_to(const QString, sfp[1]);
		qp->setTitle(title);
	}
	RETURNvoid_();
}

//String QWizardPage.getSubTitle();
KMETHOD QWizardPage_getSubTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		QString ret_v = qp->subTitle();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWizardPage.getTitle();
KMETHOD QWizardPage_getTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		QString ret_v = qp->title();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QWizardPage.validatePage();
KMETHOD QWizardPage_validatePage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWizardPage *  qp = RawPtr_to(QWizardPage *, sfp[0]);
	if (qp) {
		bool ret_v = qp->validatePage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQWizardPage::DummyQWizardPage()
{
	self = NULL;
	complete_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("complete-changed", NULL));
}

void DummyQWizardPage::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWizardPage::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQWizardPage::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWizardPage::completeChangedSlot()
{
	if (complete_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, complete_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWizardPage::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWizardPage::event_map->bigin();
	if ((itr = DummyQWizardPage::event_map->find(str)) == DummyQWizardPage::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWizardPage::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWizardPage::slot_map->bigin();
	if ((itr = DummyQWizardPage::slot_map->find(str)) == DummyQWizardPage::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		complete_changed_func = (*slot_map)["complete-changed"];
		return true;
	}
}

void DummyQWizardPage::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, complete_changed_func);

	KNH_SIZEREF(ctx);

	DummyQWidget::reftrace(ctx, p, tail_);
}

void DummyQWizardPage::connection(QObject *o)
{
	QWizardPage *p = dynamic_cast<QWizardPage*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(completeChanged()), this, SLOT(completeChangedSlot()));
	}
	DummyQWidget::connection(o);
}

KQWizardPage::KQWizardPage(QWidget* parent) : QWizardPage(parent)
{
	self = NULL;
	dummy = new DummyQWizardPage();
	dummy->connection((QObject*)this);
}

KMETHOD QWizardPage_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWizardPage *qp = RawPtr_to(KQWizardPage *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWizardPage]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWizardPage]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWizardPage_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWizardPage *qp = RawPtr_to(KQWizardPage *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWizardPage]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWizardPage]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWizardPage_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWizardPage *qp = (KQWizardPage *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWizardPage_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWizardPage *qp = (KQWizardPage *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWizardPage_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWizardPage::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWizardPage::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWizardPage::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQWizardPage(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWizardPage";
	cdef->free = QWizardPage_free;
	cdef->reftrace = QWizardPage_reftrace;
	cdef->compareTo = QWizardPage_compareTo;
}


