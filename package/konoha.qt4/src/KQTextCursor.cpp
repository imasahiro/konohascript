//QTextCursor QTextCursor.new();
KMETHOD QTextCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextCursor *ret_v = new KQTextCursor();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextCursor QTextCursor.new(QTextDocument document);
KMETHOD QTextCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument*  document = RawPtr_to(QTextDocument*, sfp[1]);
	KQTextCursor *ret_v = new KQTextCursor(document);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextCursor QTextCursor.new(QTextFrame frame);
KMETHOD QTextCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextFrame*  frame = RawPtr_to(QTextFrame*, sfp[1]);
	KQTextCursor *ret_v = new KQTextCursor(frame);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextCursor QTextCursor.new(QTextBlock block);
KMETHOD QTextCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextBlock  block = *RawPtr_to(const QTextBlock *, sfp[1]);
	KQTextCursor *ret_v = new KQTextCursor(block);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextCursor QTextCursor.new(QTextCursor cursor);
KMETHOD QTextCursor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[1]);
	KQTextCursor *ret_v = new KQTextCursor(cursor);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QTextCursor.anchor();
KMETHOD QTextCursor_anchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int ret_v = qp->anchor();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTextCursor.atBlockEnd();
KMETHOD QTextCursor_atBlockEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool ret_v = qp->atBlockEnd();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextCursor.atBlockStart();
KMETHOD QTextCursor_atBlockStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool ret_v = qp->atBlockStart();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextCursor.atEnd();
KMETHOD QTextCursor_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool ret_v = qp->atEnd();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextCursor.atStart();
KMETHOD QTextCursor_atStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool ret_v = qp->atStart();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextCursor.beginEditBlock();
KMETHOD QTextCursor_beginEditBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		qp->beginEditBlock();
	}
	RETURNvoid_();
}

//QTextBlock QTextCursor.block();
KMETHOD QTextCursor_block(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextBlock ret_v = qp->block();
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCharFormat QTextCursor.getBlockCharFormat();
KMETHOD QTextCursor_getBlockCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextCharFormat ret_v = qp->blockCharFormat();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBlockFormat QTextCursor.getBlockFormat();
KMETHOD QTextCursor_getBlockFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextBlockFormat ret_v = qp->blockFormat();
		QTextBlockFormat *ret_v_ = new QTextBlockFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextCursor.blockNumber();
KMETHOD QTextCursor_blockNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int ret_v = qp->blockNumber();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextCharFormat QTextCursor.getCharFormat();
KMETHOD QTextCursor_getCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextCharFormat ret_v = qp->charFormat();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextCursor.clearSelection();
KMETHOD QTextCursor_clearSelection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		qp->clearSelection();
	}
	RETURNvoid_();
}

//int QTextCursor.columnNumber();
KMETHOD QTextCursor_columnNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int ret_v = qp->columnNumber();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextList QTextCursor.createList(QTextListFormat fmt);
KMETHOD QTextCursor_createList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextListFormat  format = *RawPtr_to(const QTextListFormat *, sfp[1]);
		QTextList* ret_v = qp->createList(format);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextList*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextList QTextCursor.createList(int style);
KMETHOD QTextCursor_createList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextListFormat::Style style = Int_to(QTextListFormat::Style, sfp[1]);
		QTextList* ret_v = qp->createList(style);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextList*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTextFrame QTextCursor.currentFrame();
KMETHOD QTextCursor_currentFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextFrame* ret_v = qp->currentFrame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextList QTextCursor.currentList();
KMETHOD QTextCursor_currentList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextList* ret_v = qp->currentList();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextList*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextTable QTextCursor.currentTable();
KMETHOD QTextCursor_currentTable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextTable* ret_v = qp->currentTable();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextTable*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextCursor.deleteChar();
KMETHOD QTextCursor_deleteChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		qp->deleteChar();
	}
	RETURNvoid_();
}

//void QTextCursor.deletePreviousChar();
KMETHOD QTextCursor_deletePreviousChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		qp->deletePreviousChar();
	}
	RETURNvoid_();
}

//QTextDocument QTextCursor.document();
KMETHOD QTextCursor_document(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextDocument* ret_v = qp->document();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextCursor.endEditBlock();
KMETHOD QTextCursor_endEditBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		qp->endEditBlock();
	}
	RETURNvoid_();
}

//boolean QTextCursor.hasComplexSelection();
KMETHOD QTextCursor_hasComplexSelection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasComplexSelection();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextCursor.hasSelection();
KMETHOD QTextCursor_hasSelection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasSelection();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextCursor.insertBlock();
KMETHOD QTextCursor_insertBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		qp->insertBlock();
	}
	RETURNvoid_();
}

/*
//void QTextCursor.insertBlock(QTextBlockFormat fmt);
KMETHOD QTextCursor_insertBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextBlockFormat  format = *RawPtr_to(const QTextBlockFormat *, sfp[1]);
		qp->insertBlock(format);
	}
	RETURNvoid_();
}
*/
/*
//void QTextCursor.insertBlock(QTextBlockFormat fmt, QTextCharFormat charFormat);
KMETHOD QTextCursor_insertBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextBlockFormat  format = *RawPtr_to(const QTextBlockFormat *, sfp[1]);
		const QTextCharFormat  charFormat = *RawPtr_to(const QTextCharFormat *, sfp[2]);
		qp->insertBlock(format, charFormat);
	}
	RETURNvoid_();
}
*/
//void QTextCursor.insertFragment(QTextDocumentFragment fragment);
KMETHOD QTextCursor_insertFragment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextDocumentFragment  fragment = *RawPtr_to(const QTextDocumentFragment *, sfp[1]);
		qp->insertFragment(fragment);
	}
	RETURNvoid_();
}

//QTextFrame QTextCursor.insertFrame(QTextFrameFormat fmt);
KMETHOD QTextCursor_insertFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextFrameFormat  format = *RawPtr_to(const QTextFrameFormat *, sfp[1]);
		QTextFrame* ret_v = qp->insertFrame(format);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextCursor.insertHtml(String html);
KMETHOD QTextCursor_insertHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QString html = String_to(const QString, sfp[1]);
		qp->insertHtml(html);
	}
	RETURNvoid_();
}

//void QTextCursor.insertImage(QTextImageFormat fmt);
KMETHOD QTextCursor_insertImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextImageFormat  format = *RawPtr_to(const QTextImageFormat *, sfp[1]);
		qp->insertImage(format);
	}
	RETURNvoid_();
}

/*
//void QTextCursor.insertImage(QTextImageFormat fmt, int alignment);
KMETHOD QTextCursor_insertImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextImageFormat  format = *RawPtr_to(const QTextImageFormat *, sfp[1]);
		QTextFrameFormat::Position alignment = Int_to(QTextFrameFormat::Position, sfp[2]);
		qp->insertImage(format, alignment);
	}
	RETURNvoid_();
}
*/
/*
//void QTextCursor.insertImage(String name);
KMETHOD QTextCursor_insertImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->insertImage(name);
	}
	RETURNvoid_();
}
*/
/*
//void QTextCursor.insertImage(QImage image, String name);
KMETHOD QTextCursor_insertImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		const QString name = String_to(const QString, sfp[2]);
		qp->insertImage(image, name);
	}
	RETURNvoid_();
}
*/
//QTextList QTextCursor.insertList(QTextListFormat fmt);
KMETHOD QTextCursor_insertList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextListFormat  format = *RawPtr_to(const QTextListFormat *, sfp[1]);
		QTextList* ret_v = qp->insertList(format);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextList*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextList QTextCursor.insertList(int style);
KMETHOD QTextCursor_insertList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextListFormat::Style style = Int_to(QTextListFormat::Style, sfp[1]);
		QTextList* ret_v = qp->insertList(style);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextList*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTextTable QTextCursor.insertTable(int rows, int columns, QTextTableFormat fmt);
KMETHOD QTextCursor_insertTable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int rows = Int_to(int, sfp[1]);
		int columns = Int_to(int, sfp[2]);
		const QTextTableFormat  format = *RawPtr_to(const QTextTableFormat *, sfp[3]);
		QTextTable* ret_v = qp->insertTable(rows, columns, format);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextTable*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextTable QTextCursor.insertTable(int rows, int columns);
KMETHOD QTextCursor_insertTable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int rows = Int_to(int, sfp[1]);
		int columns = Int_to(int, sfp[2]);
		QTextTable* ret_v = qp->insertTable(rows, columns);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextTable*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QTextCursor.insertText(String text);
KMETHOD QTextCursor_insertText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->insertText(text);
	}
	RETURNvoid_();
}

/*
//void QTextCursor.insertText(String text, QTextCharFormat fmt);
KMETHOD QTextCursor_insertText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[2]);
		qp->insertText(text, format);
	}
	RETURNvoid_();
}
*/
//boolean QTextCursor.isCopyOf(QTextCursor other);
KMETHOD QTextCursor_isCopyOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextCursor  other = *RawPtr_to(const QTextCursor *, sfp[1]);
		bool ret_v = qp->isCopyOf(other);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextCursor.joinPreviousEditBlock();
KMETHOD QTextCursor_joinPreviousEditBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		qp->joinPreviousEditBlock();
	}
	RETURNvoid_();
}

//boolean QTextCursor.getKeepPositionOnInsert();
KMETHOD QTextCursor_getKeepPositionOnInsert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool ret_v = qp->keepPositionOnInsert();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextCursor.mergeBlockCharFormat(QTextCharFormat modifier);
KMETHOD QTextCursor_mergeBlockCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextCharFormat  modifier = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->mergeBlockCharFormat(modifier);
	}
	RETURNvoid_();
}

//void QTextCursor.mergeBlockFormat(QTextBlockFormat modifier);
KMETHOD QTextCursor_mergeBlockFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextBlockFormat  modifier = *RawPtr_to(const QTextBlockFormat *, sfp[1]);
		qp->mergeBlockFormat(modifier);
	}
	RETURNvoid_();
}

//void QTextCursor.mergeCharFormat(QTextCharFormat modifier);
KMETHOD QTextCursor_mergeCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextCharFormat  modifier = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->mergeCharFormat(modifier);
	}
	RETURNvoid_();
}

//boolean QTextCursor.movePosition(int operation, int mode, int n);
KMETHOD QTextCursor_movePosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextCursor::MoveOperation operation = Int_to(QTextCursor::MoveOperation, sfp[1]);
		QTextCursor::MoveMode mode = Int_to(QTextCursor::MoveMode, sfp[2]);
		int n = Int_to(int, sfp[3]);
		bool ret_v = qp->movePosition(operation, mode, n);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextCursor.getPosition();
KMETHOD QTextCursor_getPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int ret_v = qp->position();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextCursor.positionInBlock();
KMETHOD QTextCursor_positionInBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int ret_v = qp->positionInBlock();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextCursor.removeSelectedText();
KMETHOD QTextCursor_removeSelectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		qp->removeSelectedText();
	}
	RETURNvoid_();
}

//void QTextCursor.select(int selection);
KMETHOD QTextCursor_select(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextCursor::SelectionType selection = Int_to(QTextCursor::SelectionType, sfp[1]);
		qp->select(selection);
	}
	RETURNvoid_();
}

//void QTextCursor.selectedTableCells(int firstRow, int numRows, int firstColumn, int numColumns);
KMETHOD QTextCursor_selectedTableCells(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int* firstRow = Int_to(int*, sfp[1]);
		int* numRows = Int_to(int*, sfp[2]);
		int* firstColumn = Int_to(int*, sfp[3]);
		int* numColumns = Int_to(int*, sfp[4]);
		qp->selectedTableCells(firstRow, numRows, firstColumn, numColumns);
	}
	RETURNvoid_();
}

//String QTextCursor.selectedText();
KMETHOD QTextCursor_selectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QString ret_v = qp->selectedText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextDocumentFragment QTextCursor.selection();
KMETHOD QTextCursor_selection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		QTextDocumentFragment ret_v = qp->selection();
		QTextDocumentFragment *ret_v_ = new QTextDocumentFragment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextCursor.selectionEnd();
KMETHOD QTextCursor_selectionEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int ret_v = qp->selectionEnd();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextCursor.selectionStart();
KMETHOD QTextCursor_selectionStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int ret_v = qp->selectionStart();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextCursor.setBlockCharFormat(QTextCharFormat fmt);
KMETHOD QTextCursor_setBlockCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->setBlockCharFormat(format);
	}
	RETURNvoid_();
}

//void QTextCursor.setBlockFormat(QTextBlockFormat fmt);
KMETHOD QTextCursor_setBlockFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextBlockFormat  format = *RawPtr_to(const QTextBlockFormat *, sfp[1]);
		qp->setBlockFormat(format);
	}
	RETURNvoid_();
}

//void QTextCursor.setCharFormat(QTextCharFormat fmt);
KMETHOD QTextCursor_setCharFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->setCharFormat(format);
	}
	RETURNvoid_();
}

//void QTextCursor.setKeepPositionOnInsert(boolean b);
KMETHOD QTextCursor_setKeepPositionOnInsert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setKeepPositionOnInsert(b);
	}
	RETURNvoid_();
}

//void QTextCursor.setPosition(int pos, int m);
KMETHOD QTextCursor_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int pos = Int_to(int, sfp[1]);
		QTextCursor::MoveMode m = Int_to(QTextCursor::MoveMode, sfp[2]);
		qp->setPosition(pos, m);
	}
	RETURNvoid_();
}

//void QTextCursor.setVerticalMovementX(int x);
KMETHOD QTextCursor_setVerticalMovementX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		qp->setVerticalMovementX(x);
	}
	RETURNvoid_();
}

//void QTextCursor.setVisualNavigation(boolean b);
KMETHOD QTextCursor_setVisualNavigation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setVisualNavigation(b);
	}
	RETURNvoid_();
}

//int QTextCursor.getVerticalMovementX();
KMETHOD QTextCursor_getVerticalMovementX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		int ret_v = qp->verticalMovementX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTextCursor.getVisualNavigation();
KMETHOD QTextCursor_getVisualNavigation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *  qp = RawPtr_to(QTextCursor *, sfp[0]);
	if (qp) {
		bool ret_v = qp->visualNavigation();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<String> QTextCursor.parents();
KMETHOD QTextCursor_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCursor *qp = RawPtr_to(QTextCursor*, sfp[0]);
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

DummyQTextCursor::DummyQTextCursor()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextCursor::~DummyQTextCursor()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTextCursor::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextCursor::self = ptr;
}

bool DummyQTextCursor::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextCursor::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextCursor::event_map->bigin();
	if ((itr = DummyQTextCursor::event_map->find(str)) == DummyQTextCursor::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextCursor::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextCursor::slot_map->bigin();
	if ((itr = DummyQTextCursor::slot_map->find(str)) == DummyQTextCursor::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextCursor::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextCursor::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextCursor::connection(QObject *o)
{
	QTextCursor *p = dynamic_cast<QTextCursor*>(o);
	if (p != NULL) {
	}
}

KQTextCursor::KQTextCursor() : QTextCursor()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextCursor();
}

KQTextCursor::~KQTextCursor()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTextCursor_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextCursor *qp = RawPtr_to(KQTextCursor *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextCursor]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextCursor]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextCursor_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextCursor *qp = RawPtr_to(KQTextCursor *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextCursor]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextCursor]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextCursor_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextCursor *qp = (KQTextCursor *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextCursor*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextCursor_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextCursor *qp = (KQTextCursor *)p->rawptr;
		KQTextCursor *qp = static_cast<KQTextCursor*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextCursor_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTextCursor*>(p1->rawptr) == *static_cast<QTextCursor*>(p2->rawptr) ? 0 : 1);
}

void KQTextCursor::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextCursorConstInt[] = {
	{"MoveAnchor", QTextCursor::MoveAnchor},
	{"KeepAnchor", QTextCursor::KeepAnchor},
	{"NoMove", QTextCursor::NoMove},
	{"Start", QTextCursor::Start},
	{"StartOfLine", QTextCursor::StartOfLine},
	{"StartOfBlock", QTextCursor::StartOfBlock},
	{"StartOfWord", QTextCursor::StartOfWord},
	{"PreviousBlock", QTextCursor::PreviousBlock},
	{"PreviousCharacter", QTextCursor::PreviousCharacter},
	{"PreviousWord", QTextCursor::PreviousWord},
	{"Up", QTextCursor::Up},
	{"Left", QTextCursor::Left},
	{"WordLeft", QTextCursor::WordLeft},
	{"End", QTextCursor::End},
	{"EndOfLine", QTextCursor::EndOfLine},
	{"EndOfWord", QTextCursor::EndOfWord},
	{"EndOfBlock", QTextCursor::EndOfBlock},
	{"NextBlock", QTextCursor::NextBlock},
	{"NextCharacter", QTextCursor::NextCharacter},
	{"NextWord", QTextCursor::NextWord},
	{"Down", QTextCursor::Down},
	{"Right", QTextCursor::Right},
	{"WordRight", QTextCursor::WordRight},
	{"NextCell", QTextCursor::NextCell},
	{"PreviousCell", QTextCursor::PreviousCell},
	{"NextRow", QTextCursor::NextRow},
	{"PreviousRow", QTextCursor::PreviousRow},
	{"Document", QTextCursor::Document},
	{"BlockUnderCursor", QTextCursor::BlockUnderCursor},
	{"LineUnderCursor", QTextCursor::LineUnderCursor},
	{"WordUnderCursor", QTextCursor::WordUnderCursor},
	{NULL, 0}
};

DEFAPI(void) constQTextCursor(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextCursorConstInt);
}


DEFAPI(void) defQTextCursor(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextCursor";
	cdef->free = QTextCursor_free;
	cdef->reftrace = QTextCursor_reftrace;
	cdef->compareTo = QTextCursor_compareTo;
}


