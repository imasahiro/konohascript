//@Virtual @Override QSize QFontComboBox.sizeHint();
KMETHOD QFontComboBox_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFontComboBox QFontComboBox.new(QWidget parent);
KMETHOD QFontComboBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQFontComboBox *ret_v = new KQFontComboBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QFont QFontComboBox.getCurrentFont();
KMETHOD QFontComboBox_getCurrentFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp != NULL) {
		QFont ret_v = qp->currentFont();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFontComboBox.getFontFilters();
KMETHOD QFontComboBox_getFontFilters(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp != NULL) {
		QFontComboBox::FontFilters ret_v = qp->fontFilters();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QFontComboBox.setFontFilters(int filters);
KMETHOD QFontComboBox_setFontFilters(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp != NULL) {
		QFontComboBox::FontFilters filters = Int_to(QFontComboBox::FontFilters, sfp[1]);
		qp->setFontFilters(filters);
	}
	RETURNvoid_();
}

//void QFontComboBox.setWritingSystem(int script);
KMETHOD QFontComboBox_setWritingSystem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp != NULL) {
		QFontDatabase::WritingSystem script = Int_to(QFontDatabase::WritingSystem, sfp[1]);
		qp->setWritingSystem(script);
	}
	RETURNvoid_();
}

//int QFontComboBox.getWritingSystem();
KMETHOD QFontComboBox_getWritingSystem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp != NULL) {
		QFontDatabase::WritingSystem ret_v = qp->writingSystem();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QFontComboBox.setCurrentFont(QFont font);
KMETHOD QFontComboBox_setCurrentFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontComboBox *  qp = RawPtr_to(QFontComboBox *, sfp[0]);
	if (qp != NULL) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setCurrentFont(font);
	}
	RETURNvoid_();
}


DummyQFontComboBox::DummyQFontComboBox()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQFontComboBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFontComboBox::self = ptr;
	DummyQComboBox::setSelf(ptr);
}

bool DummyQFontComboBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQComboBox::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFontComboBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontComboBox::event_map->bigin();
	if ((itr = DummyQFontComboBox::event_map->find(str)) == DummyQFontComboBox::event_map->end()) {
		bool ret;
		ret = DummyQComboBox::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFontComboBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontComboBox::slot_map->bigin();
	if ((itr = DummyQFontComboBox::event_map->find(str)) == DummyQFontComboBox::slot_map->end()) {
		bool ret;
		ret = DummyQComboBox::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQFontComboBox::KQFontComboBox(QWidget* parent) : QFontComboBox(parent)
{
	self = NULL;
}

KMETHOD QFontComboBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontComboBox *qp = RawPtr_to(KQFontComboBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFontComboBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQFontComboBox::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontComboBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QFontComboBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontComboBox *qp = RawPtr_to(KQFontComboBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFontComboBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQFontComboBox::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontComboBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFontComboBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFontComboBox *qp = (KQFontComboBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFontComboBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQFontComboBox *qp = (KQFontComboBox *)p->rawptr;
		(void)qp;
	}
}

static int QFontComboBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQFontComboBox::event(QEvent *event)
{
	if (!DummyQFontComboBox::eventDispatcher(event)) {
		QFontComboBox::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQFontComboBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontComboBox";
	cdef->free = QFontComboBox_free;
	cdef->reftrace = QFontComboBox_reftrace;
	cdef->compareTo = QFontComboBox_compareTo;
}

static knh_IntData_t QFontComboBoxConstInt[] = {
	{"AllFonts", QFontComboBox::AllFonts},
	{"ScalableFonts", QFontComboBox::ScalableFonts},
	{"NonScalableFonts", QFontComboBox::NonScalableFonts},
	{"MonospacedFonts", QFontComboBox::MonospacedFonts},
	{"ProportionalFonts", QFontComboBox::ProportionalFonts},
	{NULL, 0}
};

DEFAPI(void) constQFontComboBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFontComboBoxConstInt);
}

