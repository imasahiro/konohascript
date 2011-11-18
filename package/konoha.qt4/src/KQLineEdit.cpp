//@Virtual @Override boolean QLineEdit.event(QEvent e);
KMETHOD QLineEdit_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QEvent*  e = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(e);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QVariant QLineEdit.inputMethodQuery(int property);
KMETHOD QLineEdit_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		Qt::InputMethodQuery property = Int_to(Qt::InputMethodQuery, sfp[1]);
		QVariant ret_v = qp->inputMethodQuery(property);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QLineEdit.minimumSizeHint();
KMETHOD QLineEdit_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QLineEdit.sizeHint();
KMETHOD QLineEdit_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QLineEdit QLineEdit.new(QWidget parent);
KMETHOD QLineEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQLineEdit *ret_v = new KQLineEdit(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLineEdit QLineEdit.new(String contents, QWidget parent);
KMETHOD QLineEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString contents = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQLineEdit *ret_v = new KQLineEdit(contents, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QtAlignment QLineEdit.getAlignment();
KMETHOD QLineEdit_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLineEdit.backspace();
KMETHOD QLineEdit_backspace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->backspace();
	}
	RETURNvoid_();
}

//QCompleter QLineEdit.getCompleter();
KMETHOD QLineEdit_getCompleter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QCompleter* ret_v = qp->completer();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QCompleter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMenu QLineEdit.createStandardContextMenu();
KMETHOD QLineEdit_createStandardContextMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QMenu* ret_v = qp->createStandardContextMenu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLineEdit.cursorBackward(boolean mark, int steps);
KMETHOD QLineEdit_cursorBackward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool mark = Boolean_to(bool, sfp[1]);
		int steps = Int_to(int, sfp[2]);
		qp->cursorBackward(mark, steps);
	}
	RETURNvoid_();
}

//void QLineEdit.cursorForward(boolean mark, int steps);
KMETHOD QLineEdit_cursorForward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool mark = Boolean_to(bool, sfp[1]);
		int steps = Int_to(int, sfp[2]);
		qp->cursorForward(mark, steps);
	}
	RETURNvoid_();
}

//int QLineEdit.getCursorPosition();
KMETHOD QLineEdit_getCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->cursorPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLineEdit.cursorPositionAt(QPoint pos);
KMETHOD QLineEdit_cursorPositionAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		int ret_v = qp->cursorPositionAt(pos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QLineEdit.cursorWordBackward(boolean mark);
KMETHOD QLineEdit_cursorWordBackward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool mark = Boolean_to(bool, sfp[1]);
		qp->cursorWordBackward(mark);
	}
	RETURNvoid_();
}

//void QLineEdit.cursorWordForward(boolean mark);
KMETHOD QLineEdit_cursorWordForward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool mark = Boolean_to(bool, sfp[1]);
		qp->cursorWordForward(mark);
	}
	RETURNvoid_();
}

//void QLineEdit.del();
KMETHOD QLineEdit_del(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->del();
	}
	RETURNvoid_();
}

//void QLineEdit.deselect();
KMETHOD QLineEdit_deselect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->deselect();
	}
	RETURNvoid_();
}

//String QLineEdit.displayText();
KMETHOD QLineEdit_displayText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->displayText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QLineEdit.getDragEnabled();
KMETHOD QLineEdit_getDragEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->dragEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QLineEdit.getEchoMode();
KMETHOD QLineEdit_getEchoMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QLineEdit::EchoMode ret_v = qp->echoMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QLineEdit.end(boolean mark);
KMETHOD QLineEdit_end(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool mark = Boolean_to(bool, sfp[1]);
		qp->end(mark);
	}
	RETURNvoid_();
}

//void QLineEdit.getTextMargins(int left, int top, int right, int bottom);
KMETHOD QLineEdit_getTextMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		int* left = Int_to(int*, sfp[1]);
		int* top = Int_to(int*, sfp[2]);
		int* right = Int_to(int*, sfp[3]);
		int* bottom = Int_to(int*, sfp[4]);
		qp->getTextMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//boolean QLineEdit.hasAcceptableInput();
KMETHOD QLineEdit_hasAcceptableInput(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasAcceptableInput();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLineEdit.hasFrame();
KMETHOD QLineEdit_hasFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasFrame();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLineEdit.hasSelectedText();
KMETHOD QLineEdit_hasSelectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasSelectedText();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QLineEdit.home(boolean mark);
KMETHOD QLineEdit_home(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool mark = Boolean_to(bool, sfp[1]);
		qp->home(mark);
	}
	RETURNvoid_();
}

//String QLineEdit.getInputMask();
KMETHOD QLineEdit_getInputMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->inputMask();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLineEdit.insert(String new_Text);
KMETHOD QLineEdit_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		const QString new_Text = String_to(const QString, sfp[1]);
		qp->insert(new_Text);
	}
	RETURNvoid_();
}

//boolean QLineEdit.isModified();
KMETHOD QLineEdit_isModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isModified();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLineEdit.isReadOnly();
KMETHOD QLineEdit_isReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isReadOnly();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLineEdit.isRedoAvailable();
KMETHOD QLineEdit_isRedoAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isRedoAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLineEdit.isUndoAvailable();
KMETHOD QLineEdit_isUndoAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isUndoAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QLineEdit.getMaxLength();
KMETHOD QLineEdit_getMaxLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxLength();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QLineEdit.getPlaceholderText();
KMETHOD QLineEdit_getPlaceholderText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->placeholderText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLineEdit.selectedText();
KMETHOD QLineEdit_selectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->selectedText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLineEdit.selectionStart();
KMETHOD QLineEdit_selectionStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->selectionStart();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QLineEdit.setAlignment(QtAlignment flag);
KMETHOD QLineEdit_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		initFlag(flag, Qt::Alignment, sfp[1]);
		qp->setAlignment(flag);
	}
	RETURNvoid_();
}

//void QLineEdit.setCompleter(QCompleter c);
KMETHOD QLineEdit_setCompleter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QCompleter*  c = RawPtr_to(QCompleter*, sfp[1]);
		qp->setCompleter(c);
	}
	RETURNvoid_();
}

//void QLineEdit.setCursorPosition(int arg0);
KMETHOD QLineEdit_setCursorPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setCursorPosition(arg0);
	}
	RETURNvoid_();
}

//void QLineEdit.setDragEnabled(boolean b);
KMETHOD QLineEdit_setDragEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setDragEnabled(b);
	}
	RETURNvoid_();
}

//void QLineEdit.setEchoMode(int arg0);
KMETHOD QLineEdit_setEchoMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QLineEdit::EchoMode arg0 = Int_to(QLineEdit::EchoMode, sfp[1]);
		qp->setEchoMode(arg0);
	}
	RETURNvoid_();
}

//void QLineEdit.setFrame(boolean arg0);
KMETHOD QLineEdit_setFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setFrame(arg0);
	}
	RETURNvoid_();
}

//void QLineEdit.setInputMask(String inputMask);
KMETHOD QLineEdit_setInputMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		const QString inputMask = String_to(const QString, sfp[1]);
		qp->setInputMask(inputMask);
	}
	RETURNvoid_();
}

//void QLineEdit.setMaxLength(int arg0);
KMETHOD QLineEdit_setMaxLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setMaxLength(arg0);
	}
	RETURNvoid_();
}

//void QLineEdit.setModified(boolean arg0);
KMETHOD QLineEdit_setModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setModified(arg0);
	}
	RETURNvoid_();
}

//void QLineEdit.setPlaceholderText(String arg0);
KMETHOD QLineEdit_setPlaceholderText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setPlaceholderText(arg0);
	}
	RETURNvoid_();
}

//void QLineEdit.setReadOnly(boolean arg0);
KMETHOD QLineEdit_setReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setReadOnly(arg0);
	}
	RETURNvoid_();
}

//void QLineEdit.setSelection(int start, int length);
KMETHOD QLineEdit_setSelection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		int start = Int_to(int, sfp[1]);
		int length = Int_to(int, sfp[2]);
		qp->setSelection(start, length);
	}
	RETURNvoid_();
}

//void QLineEdit.setTextMargins(int left, int top, int right, int bottom);
KMETHOD QLineEdit_setTextMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		int left = Int_to(int, sfp[1]);
		int top = Int_to(int, sfp[2]);
		int right = Int_to(int, sfp[3]);
		int bottom = Int_to(int, sfp[4]);
		qp->setTextMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

/*
//void QLineEdit.setTextMargins(QMargins margins);
KMETHOD QLineEdit_setTextMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		const QMargins  margins = *RawPtr_to(const QMargins *, sfp[1]);
		qp->setTextMargins(margins);
	}
	RETURNvoid_();
}
*/
//void QLineEdit.setValidator(QValidator v);
KMETHOD QLineEdit_setValidator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		const QValidator*  v = RawPtr_to(const QValidator*, sfp[1]);
		qp->setValidator(v);
	}
	RETURNvoid_();
}

//String QLineEdit.getText();
KMETHOD QLineEdit_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMargins QLineEdit.textMargins();
KMETHOD QLineEdit_textMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		QMargins ret_v = qp->textMargins();
		QMargins *ret_v_ = new QMargins(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QValidator QLineEdit.getValidator();
KMETHOD QLineEdit_getValidator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		const QValidator* ret_v = qp->validator();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QValidator*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLineEdit.clear();
KMETHOD QLineEdit_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QLineEdit.copy();
KMETHOD QLineEdit_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->copy();
	}
	RETURNvoid_();
}

//void QLineEdit.cut();
KMETHOD QLineEdit_cut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->cut();
	}
	RETURNvoid_();
}

//void QLineEdit.paste();
KMETHOD QLineEdit_paste(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->paste();
	}
	RETURNvoid_();
}

//void QLineEdit.redo();
KMETHOD QLineEdit_redo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->redo();
	}
	RETURNvoid_();
}

//void QLineEdit.selectAll();
KMETHOD QLineEdit_selectAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->selectAll();
	}
	RETURNvoid_();
}

//void QLineEdit.setText(String arg0);
KMETHOD QLineEdit_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setText(arg0);
	}
	RETURNvoid_();
}

//void QLineEdit.undo();
KMETHOD QLineEdit_undo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineEdit *  qp = RawPtr_to(QLineEdit *, sfp[0]);
	if (qp) {
		qp->undo();
	}
	RETURNvoid_();
}


DummyQLineEdit::DummyQLineEdit()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	cursor_position_changed_func = NULL;
	editing_finished_func = NULL;
	return_pressed_func = NULL;
	selection_changed_func = NULL;
	text_changed_func = NULL;
	text_edited_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("cursor-position-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("editing-finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("return-pressed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("selection-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("text-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("text-edited", NULL));
}
DummyQLineEdit::~DummyQLineEdit()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQLineEdit::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLineEdit::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQLineEdit::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLineEdit::cursorPositionChangedSlot(int old, int new_)
{
	if (cursor_position_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = old;
		lsfp[K_CALLDELTA+3].ivalue = new_;
		knh_Func_invoke(lctx, cursor_position_changed_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQLineEdit::editingFinishedSlot()
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

bool DummyQLineEdit::returnPressedSlot()
{
	if (return_pressed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, return_pressed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQLineEdit::selectionChangedSlot()
{
	if (selection_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, selection_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQLineEdit::textChangedSlot(const QString text)
{
	if (text_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, text);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, text_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQLineEdit::textEditedSlot(const QString text)
{
	if (text_edited_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, text);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, text_edited_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQLineEdit::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLineEdit::event_map->bigin();
	if ((itr = DummyQLineEdit::event_map->find(str)) == DummyQLineEdit::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLineEdit::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLineEdit::slot_map->bigin();
	if ((itr = DummyQLineEdit::slot_map->find(str)) == DummyQLineEdit::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		cursor_position_changed_func = (*slot_map)["cursor-position-changed"];
		editing_finished_func = (*slot_map)["editing-finished"];
		return_pressed_func = (*slot_map)["return-pressed"];
		selection_changed_func = (*slot_map)["selection-changed"];
		text_changed_func = (*slot_map)["text-changed"];
		text_edited_func = (*slot_map)["text-edited"];
		return true;
	}
}

knh_Object_t** DummyQLineEdit::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQLineEdit::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 7;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, cursor_position_changed_func);
	KNH_ADDNNREF(ctx, editing_finished_func);
	KNH_ADDNNREF(ctx, return_pressed_func);
	KNH_ADDNNREF(ctx, selection_changed_func);
	KNH_ADDNNREF(ctx, text_changed_func);
	KNH_ADDNNREF(ctx, text_edited_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQLineEdit::connection(QObject *o)
{
	QLineEdit *p = dynamic_cast<QLineEdit*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(cursorPositionChangedSlot(int, int)));
		connect(p, SIGNAL(editingFinished()), this, SLOT(editingFinishedSlot()));
		connect(p, SIGNAL(returnPressed()), this, SLOT(returnPressedSlot()));
		connect(p, SIGNAL(selectionChanged()), this, SLOT(selectionChangedSlot()));
		connect(p, SIGNAL(textChanged(const QString)), this, SLOT(textChangedSlot(const QString)));
		connect(p, SIGNAL(textEdited(const QString)), this, SLOT(textEditedSlot(const QString)));
	}
	DummyQWidget::connection(o);
}

KQLineEdit::KQLineEdit(QWidget* parent) : QLineEdit(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQLineEdit();
	dummy->connection((QObject*)this);
}

KQLineEdit::~KQLineEdit()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QLineEdit_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLineEdit *qp = RawPtr_to(KQLineEdit *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLineEdit]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLineEdit]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLineEdit_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLineEdit *qp = RawPtr_to(KQLineEdit *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLineEdit]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLineEdit]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLineEdit_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQLineEdit *qp = (KQLineEdit *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QLineEdit*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QLineEdit_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQLineEdit *qp = (KQLineEdit *)p->rawptr;
		KQLineEdit *qp = static_cast<KQLineEdit*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QLineEdit_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQLineEdit::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQLineEdit::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QLineEdit::event(event);
		return false;
	}
//	QLineEdit::event(event);
	return true;
}

static knh_IntData_t QLineEditConstInt[] = {
	{"Normal", QLineEdit::Normal},
	{"NoEcho", QLineEdit::NoEcho},
	{"Password", QLineEdit::Password},
	{"PasswordEchoOnEdit", QLineEdit::PasswordEchoOnEdit},
	{NULL, 0}
};

DEFAPI(void) constQLineEdit(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QLineEditConstInt);
}


DEFAPI(void) defQLineEdit(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLineEdit";
	cdef->free = QLineEdit_free;
	cdef->reftrace = QLineEdit_reftrace;
	cdef->compareTo = QLineEdit_compareTo;
}


