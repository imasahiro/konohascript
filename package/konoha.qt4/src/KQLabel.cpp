//@Virtual @Override int QLabel.heightForWidth(int w);
KMETHOD QLabel_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QSize QLabel.minimumSizeHint();
KMETHOD QLabel_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QLabel.sizeHint();
KMETHOD QLabel_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QLabel QLabel.new(QWidget parent, int f);
KMETHOD QLabel_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	Qt::WindowFlags f = Int_to(Qt::WindowFlags, sfp[2]);
	KQLabel *ret_v = new KQLabel(parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLabel QLabel.new(String text, QWidget parent, int f);
KMETHOD QLabel_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	Qt::WindowFlags f = Int_to(Qt::WindowFlags, sfp[3]);
	KQLabel *ret_v = new KQLabel(text, parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QLabel.getAlignment();
KMETHOD QLabel_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment ret_v = qp->alignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QLabel.getBuddy();
KMETHOD QLabel_getBuddy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->buddy();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QLabel.hasScaledContents();
KMETHOD QLabel_hasScaledContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasScaledContents();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLabel.hasSelectedText();
KMETHOD QLabel_hasSelectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasSelectedText();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QLabel.getIndent();
KMETHOD QLabel_getIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->indent();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLabel.getMargin();
KMETHOD QLabel_getMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->margin();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMovie QLabel.getMovie();
KMETHOD QLabel_getMovie(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		QMovie* ret_v = qp->movie();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMovie*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QLabel.getOpenExternalLinks();
KMETHOD QLabel_getOpenExternalLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->openExternalLinks();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPicture QLabel.getPicture();
KMETHOD QLabel_getPicture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		const QPicture* ret_v = qp->picture();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPicture*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QLabel.getPixmap();
KMETHOD QLabel_getPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		const QPixmap* ret_v = qp->pixmap();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPixmap*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLabel.selectedText();
KMETHOD QLabel_selectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->selectedText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLabel.selectionStart();
KMETHOD QLabel_selectionStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->selectionStart();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QLabel.setAlignment(int arg0);
KMETHOD QLabel_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment arg0 = Int_to(Qt::Alignment, sfp[1]);
		qp->setAlignment(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setBuddy(QWidget buddy);
KMETHOD QLabel_setBuddy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		QWidget*  buddy = RawPtr_to(QWidget*, sfp[1]);
		qp->setBuddy(buddy);
	}
	RETURNvoid_();
}

//void QLabel.setIndent(int arg0);
KMETHOD QLabel_setIndent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setIndent(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setMargin(int arg0);
KMETHOD QLabel_setMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setMargin(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setOpenExternalLinks(boolean open);
KMETHOD QLabel_setOpenExternalLinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		bool open = Boolean_to(bool, sfp[1]);
		qp->setOpenExternalLinks(open);
	}
	RETURNvoid_();
}

//void QLabel.setScaledContents(boolean arg0);
KMETHOD QLabel_setScaledContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setScaledContents(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setSelection(int start, int length);
KMETHOD QLabel_setSelection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		int start = Int_to(int, sfp[1]);
		int length = Int_to(int, sfp[2]);
		qp->setSelection(start, length);
	}
	RETURNvoid_();
}

//void QLabel.setTextFormat(int arg0);
KMETHOD QLabel_setTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		Qt::TextFormat arg0 = Int_to(Qt::TextFormat, sfp[1]);
		qp->setTextFormat(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setTextInteractionFlags(int flags);
KMETHOD QLabel_setTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		Qt::TextInteractionFlags flags = Int_to(Qt::TextInteractionFlags, sfp[1]);
		qp->setTextInteractionFlags(flags);
	}
	RETURNvoid_();
}

//void QLabel.setWordWrap(boolean on);
KMETHOD QLabel_setWordWrap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setWordWrap(on);
	}
	RETURNvoid_();
}

//String QLabel.getText();
KMETHOD QLabel_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLabel.getTextFormat();
KMETHOD QLabel_getTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		Qt::TextFormat ret_v = qp->textFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLabel.getTextInteractionFlags();
KMETHOD QLabel_getTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		Qt::TextInteractionFlags ret_v = qp->textInteractionFlags();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QLabel.getWordWrap();
KMETHOD QLabel_getWordWrap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->wordWrap();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QLabel.clear();
KMETHOD QLabel_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QLabel.setMovie(QMovie movie);
KMETHOD QLabel_setMovie(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		QMovie*  movie = RawPtr_to(QMovie*, sfp[1]);
		qp->setMovie(movie);
	}
	RETURNvoid_();
}

//void QLabel.setNum(int num);
KMETHOD QLabel_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		int num = Int_to(int, sfp[1]);
		qp->setNum(num);
	}
	RETURNvoid_();
}

/*
//void QLabel.setNum(double num);
KMETHOD QLabel_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		double  num = *RawPtr_to(double *, sfp[1]);
		qp->setNum(num);
	}
	RETURNvoid_();
}
*/
//void QLabel.setPicture(QPicture picture);
KMETHOD QLabel_setPicture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		const QPicture  picture = *RawPtr_to(const QPicture *, sfp[1]);
		qp->setPicture(picture);
	}
	RETURNvoid_();
}

//void QLabel.setPixmap(QPixmap arg0);
KMETHOD QLabel_setPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		const QPixmap  arg0 = *RawPtr_to(const QPixmap *, sfp[1]);
		qp->setPixmap(arg0);
	}
	RETURNvoid_();
}

//void QLabel.setText(String arg0);
KMETHOD QLabel_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLabel *  qp = RawPtr_to(QLabel *, sfp[0]);
	if (qp != NULL) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setText(arg0);
	}
	RETURNvoid_();
}


DummyQLabel::DummyQLabel()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLabel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLabel::self = ptr;
	DummyQFrame::setSelf(ptr);
}

bool DummyQLabel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLabel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLabel::event_map->bigin();
	if ((itr = DummyQLabel::event_map->find(str)) == DummyQLabel::event_map->end()) {
		bool ret;
		ret = DummyQFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLabel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLabel::slot_map->bigin();
	if ((itr = DummyQLabel::event_map->find(str)) == DummyQLabel::slot_map->end()) {
		bool ret;
		ret = DummyQFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQLabel::KQLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent, f)
{
	self = NULL;
}

KMETHOD QLabel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLabel *qp = RawPtr_to(KQLabel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLabel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQLabel::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLabel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QLabel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLabel *qp = RawPtr_to(KQLabel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLabel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQLabel::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLabel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLabel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLabel *qp = (KQLabel *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLabel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQLabel *qp = (KQLabel *)p->rawptr;
		(void)qp;
	}
}

static int QLabel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQLabel::event(QEvent *event)
{
	if (!DummyQLabel::eventDispatcher(event)) {
		QLabel::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQLabel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLabel";
	cdef->free = QLabel_free;
	cdef->reftrace = QLabel_reftrace;
	cdef->compareTo = QLabel_compareTo;
}


