//QPlainTextEdit QPlainTextEdit.new(QWidget parent);
KMETHOD QPlainTextEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQPlainTextEdit *ret_v = new KQPlainTextEdit(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPlainTextEdit QPlainTextEdit.new(String text, QWidget parent);
KMETHOD QPlainTextEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQPlainTextEdit *ret_v = new KQPlainTextEdit(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QPlainTextEdit.anchorAt(QPoint pos);
KMETHOD QPlainTextEdit_anchorAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QString ret_v = qp->anchorAt(pos);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPlainTextEdit.getBackgroundVisible();
KMETHOD QPlainTextEdit_getBackgroundVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->backgroundVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPlainTextEdit.blockCount();
KMETHOD QPlainTextEdit_blockCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->blockCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QPlainTextEdit.canPaste();
KMETHOD QPlainTextEdit_canPaste(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canPaste();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPlainTextEdit.getCenterOnScroll();
KMETHOD QPlainTextEdit_getCenterOnScroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->centerOnScroll();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QMenu QPlainTextEdit.createStandardContextMenu();
KMETHOD QPlainTextEdit_createStandardContextMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QMenu* ret_v = qp->createStandardContextMenu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCharFormat QPlainTextEdit.getCurrentCharFormat();
KMETHOD QPlainTextEdit_getCurrentCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QTextCharFormat ret_v = qp->currentCharFormat();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QPlainTextEdit.cursorForPosition(QPoint pos);
KMETHOD QPlainTextEdit_cursorForPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QTextCursor ret_v = qp->cursorForPosition(pos);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QPlainTextEdit.cursorRect(QTextCursor cursor);
KMETHOD QPlainTextEdit_cursorRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		QRect ret_v = qp->cursorRect(cursor);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRect QPlainTextEdit.cursorRect();
KMETHOD QPlainTextEdit_cursorRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->cursorRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QPlainTextEdit.getCursorWidth();
KMETHOD QPlainTextEdit_getCursorWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->cursorWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextDocument QPlainTextEdit.getDocument();
KMETHOD QPlainTextEdit_getDocument(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QTextDocument* ret_v = qp->document();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QPlainTextEdit.getDocumentTitle();
KMETHOD QPlainTextEdit_getDocumentTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->documentTitle();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPlainTextEdit.ensureCursorVisible();
KMETHOD QPlainTextEdit_ensureCursorVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->ensureCursorVisible();
	}
	RETURNvoid_();
}

//Array<int> QPlainTextEdit.getExtraSelections();
KMETHOD QPlainTextEdit_getExtraSelections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QList<QTextEdit::ExtraSelection> ret_v = qp->extraSelections();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTextEdit::ExtraSelection"));
		for (int n = 0; n < list_size; n++) {
			QTextEdit::ExtraSelection *ret_v_ = new QTextEdit::ExtraSelection(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QPlainTextEdit.find(String exp, int options);
KMETHOD QPlainTextEdit_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QString exp = String_to(const QString, sfp[1]);
		QTextDocument::FindFlags options = Int_to(QTextDocument::FindFlags, sfp[2]);
		bool ret_v = qp->find(exp, options);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPlainTextEdit.isReadOnly();
KMETHOD QPlainTextEdit_isReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isReadOnly();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPlainTextEdit.isUndoRedoEnabled();
KMETHOD QPlainTextEdit_isUndoRedoEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isUndoRedoEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPlainTextEdit.getLineWrapMode();
KMETHOD QPlainTextEdit_getLineWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QPlainTextEdit::LineWrapMode ret_v = qp->lineWrapMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QVariant QPlainTextEdit.loadResource(int type, QUrl name);
KMETHOD QPlainTextEdit_loadResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		int type = Int_to(int, sfp[1]);
		const QUrl  name = *RawPtr_to(const QUrl *, sfp[2]);
		QVariant ret_v = qp->loadResource(type, name);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPlainTextEdit.getMaximumBlockCount();
KMETHOD QPlainTextEdit_getMaximumBlockCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->maximumBlockCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPlainTextEdit.mergeCurrentCharFormat(QTextCharFormat modifier);
KMETHOD QPlainTextEdit_mergeCurrentCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QTextCharFormat  modifier = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->mergeCurrentCharFormat(modifier);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.moveCursor(int operation, int mode);
KMETHOD QPlainTextEdit_moveCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QTextCursor::MoveOperation operation = Int_to(QTextCursor::MoveOperation, sfp[1]);
		QTextCursor::MoveMode mode = Int_to(QTextCursor::MoveMode, sfp[2]);
		qp->moveCursor(operation, mode);
	}
	RETURNvoid_();
}

//boolean QPlainTextEdit.getOverwriteMode();
KMETHOD QPlainTextEdit_getOverwriteMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->overwriteMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QPlainTextEdit.print(QPrinter printer);
KMETHOD QPlainTextEdit_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
		qp->print(printer);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setBackgroundVisible(boolean visible);
KMETHOD QPlainTextEdit_setBackgroundVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setBackgroundVisible(visible);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setCenterOnScroll(boolean enabled);
KMETHOD QPlainTextEdit_setCenterOnScroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setCenterOnScroll(enabled);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setCurrentCharFormat(QTextCharFormat fmt);
KMETHOD QPlainTextEdit_setCurrentCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->setCurrentCharFormat(format);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setCursorWidth(int width);
KMETHOD QPlainTextEdit_setCursorWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		qp->setCursorWidth(width);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setDocument(QTextDocument document);
KMETHOD QPlainTextEdit_setDocument(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QTextDocument*  document = RawPtr_to(QTextDocument*, sfp[1]);
		qp->setDocument(document);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setDocumentTitle(String title);
KMETHOD QPlainTextEdit_setDocumentTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QString title = String_to(const QString, sfp[1]);
		qp->setDocumentTitle(title);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setExtraSelections(Array<int> selections);
KMETHOD QPlainTextEdit_setExtraSelections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QTextEdit::ExtraSelection> selections;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			selections.append(*(QTextEdit::ExtraSelection*)p->rawptr);
		}
		qp->setExtraSelections(selections);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setLineWrapMode(int mode);
KMETHOD QPlainTextEdit_setLineWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QPlainTextEdit::LineWrapMode mode = Int_to(QPlainTextEdit::LineWrapMode, sfp[1]);
		qp->setLineWrapMode(mode);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setMaximumBlockCount(int maximum);
KMETHOD QPlainTextEdit_setMaximumBlockCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		int maximum = Int_to(int, sfp[1]);
		qp->setMaximumBlockCount(maximum);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setOverwriteMode(boolean overwrite);
KMETHOD QPlainTextEdit_setOverwriteMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool overwrite = Boolean_to(bool, sfp[1]);
		qp->setOverwriteMode(overwrite);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setReadOnly(boolean ro);
KMETHOD QPlainTextEdit_setReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool ro = Boolean_to(bool, sfp[1]);
		qp->setReadOnly(ro);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setTabChangesFocus(boolean b);
KMETHOD QPlainTextEdit_setTabChangesFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setTabChangesFocus(b);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setTabStopWidth(int width);
KMETHOD QPlainTextEdit_setTabStopWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		qp->setTabStopWidth(width);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setTextCursor(QTextCursor cursor);
KMETHOD QPlainTextEdit_setTextCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
		qp->setTextCursor(cursor);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setTextInteractionFlags(QtTextInteractionFlags flags);
KMETHOD QPlainTextEdit_setTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		initFlag(flags, Qt::TextInteractionFlags, sfp[1]);
		qp->setTextInteractionFlags(flags);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setUndoRedoEnabled(boolean enable);
KMETHOD QPlainTextEdit_setUndoRedoEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setUndoRedoEnabled(enable);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setWordWrapMode(int policy);
KMETHOD QPlainTextEdit_setWordWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QTextOption::WrapMode policy = Int_to(QTextOption::WrapMode, sfp[1]);
		qp->setWordWrapMode(policy);
	}
	RETURNvoid_();
}

//boolean QPlainTextEdit.getTabChangesFocus();
KMETHOD QPlainTextEdit_getTabChangesFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		bool ret_v = qp->tabChangesFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPlainTextEdit.getTabStopWidth();
KMETHOD QPlainTextEdit_getTabStopWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		int ret_v = qp->tabStopWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextCursor QPlainTextEdit.getTextCursor();
KMETHOD QPlainTextEdit_getTextCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QTextCursor ret_v = qp->textCursor();
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtTextInteractionFlags QPlainTextEdit.getTextInteractionFlags();
KMETHOD QPlainTextEdit_getTextInteractionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		Qt::TextInteractionFlags ret_v = qp->textInteractionFlags();
		Qt::TextInteractionFlags *ret_v_ = new Qt::TextInteractionFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QPlainTextEdit.toPlainText();
KMETHOD QPlainTextEdit_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toPlainText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPlainTextEdit.getWordWrapMode();
KMETHOD QPlainTextEdit_getWordWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		QTextOption::WrapMode ret_v = qp->wordWrapMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPlainTextEdit.appendHtml(String html);
KMETHOD QPlainTextEdit_appendHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QString html = String_to(const QString, sfp[1]);
		qp->appendHtml(html);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.appendPlainText(String text);
KMETHOD QPlainTextEdit_appendPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->appendPlainText(text);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.centerCursor();
KMETHOD QPlainTextEdit_centerCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->centerCursor();
	}
	RETURNvoid_();
}

//void QPlainTextEdit.clear();
KMETHOD QPlainTextEdit_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QPlainTextEdit.copy();
KMETHOD QPlainTextEdit_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->copy();
	}
	RETURNvoid_();
}

//void QPlainTextEdit.cut();
KMETHOD QPlainTextEdit_cut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->cut();
	}
	RETURNvoid_();
}

//void QPlainTextEdit.insertPlainText(String text);
KMETHOD QPlainTextEdit_insertPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->insertPlainText(text);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.paste();
KMETHOD QPlainTextEdit_paste(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->paste();
	}
	RETURNvoid_();
}

//void QPlainTextEdit.redo();
KMETHOD QPlainTextEdit_redo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->redo();
	}
	RETURNvoid_();
}

//void QPlainTextEdit.selectAll();
KMETHOD QPlainTextEdit_selectAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->selectAll();
	}
	RETURNvoid_();
}

//void QPlainTextEdit.setPlainText(String text);
KMETHOD QPlainTextEdit_setPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setPlainText(text);
	}
	RETURNvoid_();
}

//void QPlainTextEdit.undo();
KMETHOD QPlainTextEdit_undo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPlainTextEdit *  qp = RawPtr_to(QPlainTextEdit *, sfp[0]);
	if (qp) {
		qp->undo();
	}
	RETURNvoid_();
}


DummyQPlainTextEdit::DummyQPlainTextEdit()
{
	self = NULL;
	block_count_changed_func = NULL;
	copy_available_func = NULL;
	cursor_position_changed_func = NULL;
	modification_changed_func = NULL;
	redo_available_func = NULL;
	selection_changed_func = NULL;
	text_changed_func = NULL;
	undo_available_func = NULL;
	update_request_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("block-count-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("copy-available", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("cursor-position-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("modification-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("redo-available", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("selection-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("text-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("undo-available", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("update-request", NULL));
}

void DummyQPlainTextEdit::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPlainTextEdit::self = ptr;
	DummyQAbstractScrollArea::setSelf(ptr);
}

bool DummyQPlainTextEdit::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractScrollArea::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPlainTextEdit::blockCountChangedSlot(int new_BlockCount)
{
	if (block_count_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = new_BlockCount;
		knh_Func_invoke(lctx, block_count_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQPlainTextEdit::copyAvailableSlot(bool yes)
{
	if (copy_available_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = yes;
		knh_Func_invoke(lctx, copy_available_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQPlainTextEdit::cursorPositionChangedSlot()
{
	if (cursor_position_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, cursor_position_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQPlainTextEdit::modificationChangedSlot(bool changed)
{
	if (modification_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = changed;
		knh_Func_invoke(lctx, modification_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQPlainTextEdit::redoAvailableSlot(bool available)
{
	if (redo_available_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = available;
		knh_Func_invoke(lctx, redo_available_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQPlainTextEdit::selectionChangedSlot()
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

bool DummyQPlainTextEdit::textChangedSlot()
{
	if (text_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, text_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQPlainTextEdit::undoAvailableSlot(bool available)
{
	if (undo_available_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = available;
		knh_Func_invoke(lctx, undo_available_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQPlainTextEdit::updateRequestSlot(const QRect rect, int dy)
{
	if (update_request_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QRect, rect);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = dy;
		knh_Func_invoke(lctx, update_request_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQPlainTextEdit::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPlainTextEdit::event_map->bigin();
	if ((itr = DummyQPlainTextEdit::event_map->find(str)) == DummyQPlainTextEdit::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractScrollArea::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPlainTextEdit::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPlainTextEdit::slot_map->bigin();
	if ((itr = DummyQPlainTextEdit::slot_map->find(str)) == DummyQPlainTextEdit::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractScrollArea::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		block_count_changed_func = (*slot_map)["block-count-changed"];
		copy_available_func = (*slot_map)["copy-available"];
		cursor_position_changed_func = (*slot_map)["cursor-position-changed"];
		modification_changed_func = (*slot_map)["modification-changed"];
		redo_available_func = (*slot_map)["redo-available"];
		selection_changed_func = (*slot_map)["selection-changed"];
		text_changed_func = (*slot_map)["text-changed"];
		undo_available_func = (*slot_map)["undo-available"];
		update_request_func = (*slot_map)["update-request"];
		return true;
	}
}

knh_Object_t** DummyQPlainTextEdit::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPlainTextEdit::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 9;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, block_count_changed_func);
	KNH_ADDNNREF(ctx, copy_available_func);
	KNH_ADDNNREF(ctx, cursor_position_changed_func);
	KNH_ADDNNREF(ctx, modification_changed_func);
	KNH_ADDNNREF(ctx, redo_available_func);
	KNH_ADDNNREF(ctx, selection_changed_func);
	KNH_ADDNNREF(ctx, text_changed_func);
	KNH_ADDNNREF(ctx, undo_available_func);
	KNH_ADDNNREF(ctx, update_request_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQAbstractScrollArea::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQPlainTextEdit::connection(QObject *o)
{
	QPlainTextEdit *p = dynamic_cast<QPlainTextEdit*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(blockCountChanged(int)), this, SLOT(blockCountChangedSlot(int)));
		connect(p, SIGNAL(copyAvailable(bool)), this, SLOT(copyAvailableSlot(bool)));
		connect(p, SIGNAL(cursorPositionChanged()), this, SLOT(cursorPositionChangedSlot()));
		connect(p, SIGNAL(modificationChanged(bool)), this, SLOT(modificationChangedSlot(bool)));
		connect(p, SIGNAL(redoAvailable(bool)), this, SLOT(redoAvailableSlot(bool)));
		connect(p, SIGNAL(selectionChanged()), this, SLOT(selectionChangedSlot()));
		connect(p, SIGNAL(textChanged()), this, SLOT(textChangedSlot()));
		connect(p, SIGNAL(undoAvailable(bool)), this, SLOT(undoAvailableSlot(bool)));
		connect(p, SIGNAL(updateRequest(const QRect, int)), this, SLOT(updateRequestSlot(const QRect, int)));
	}
	DummyQAbstractScrollArea::connection(o);
}

KQPlainTextEdit::KQPlainTextEdit(QWidget* parent) : QPlainTextEdit(parent)
{
	self = NULL;
	dummy = new DummyQPlainTextEdit();
	dummy->connection((QObject*)this);
}

KMETHOD QPlainTextEdit_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPlainTextEdit *qp = RawPtr_to(KQPlainTextEdit *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPlainTextEdit]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPlainTextEdit]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPlainTextEdit_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPlainTextEdit *qp = RawPtr_to(KQPlainTextEdit *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPlainTextEdit]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPlainTextEdit]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPlainTextEdit_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPlainTextEdit *qp = (KQPlainTextEdit *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPlainTextEdit_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPlainTextEdit *qp = (KQPlainTextEdit *)p->rawptr;
//		KQPlainTextEdit *qp = static_cast<KQPlainTextEdit*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPlainTextEdit_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPlainTextEdit::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQPlainTextEdit::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QPlainTextEdit::event(event);
		return false;
	}
//	QPlainTextEdit::event(event);
	return true;
}

static knh_IntData_t QPlainTextEditConstInt[] = {
	{"NoWrap", QPlainTextEdit::NoWrap},
	{"WidgetWidth", QPlainTextEdit::WidgetWidth},
	{NULL, 0}
};

DEFAPI(void) constQPlainTextEdit(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPlainTextEditConstInt);
}


DEFAPI(void) defQPlainTextEdit(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPlainTextEdit";
	cdef->free = QPlainTextEdit_free;
	cdef->reftrace = QPlainTextEdit_reftrace;
	cdef->compareTo = QPlainTextEdit_compareTo;
}


