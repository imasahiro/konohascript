//QTextDocument QTextDocument.new(QObject parent);
KMETHOD QTextDocument_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQTextDocument *ret_v = new KQTextDocument(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextDocument QTextDocument.new(String text, QObject parent);
KMETHOD QTextDocument_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQTextDocument *ret_v = new KQTextDocument(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QTextDocument.addResource(int type, QUrl name, QVariant resource);
KMETHOD QTextDocument_addResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int type = Int_to(int, sfp[1]);
		const QUrl  name = *RawPtr_to(const QUrl *, sfp[2]);
		const QVariant  resource = *RawPtr_to(const QVariant *, sfp[3]);
		qp->addResource(type, name, resource);
	}
	RETURNvoid_();
}

//void QTextDocument.adjustSize();
KMETHOD QTextDocument_adjustSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qp->adjustSize();
	}
	RETURNvoid_();
}

//int QTextDocument.availableRedoSteps();
KMETHOD QTextDocument_availableRedoSteps(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->availableRedoSteps();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextDocument.availableUndoSteps();
KMETHOD QTextDocument_availableUndoSteps(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->availableUndoSteps();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextBlock QTextDocument.begin();
KMETHOD QTextDocument_begin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextBlock ret_v = qp->begin();
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextDocument.blockCount();
KMETHOD QTextDocument_blockCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->blockCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QChar QTextDocument.characterAt(int pos);
KMETHOD QTextDocument_characterAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int pos = Int_to(int, sfp[1]);
		QChar ret_v = qp->characterAt(pos);
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextDocument.characterCount();
KMETHOD QTextDocument_characterCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->characterCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QTextDocument.clear();
KMETHOD QTextDocument_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QTextDocument.clearUndoRedoStacks(int stacksToClear);
KMETHOD QTextDocument_clearUndoRedoStacks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextDocument::Stacks stacksToClear = Int_to(QTextDocument::Stacks, sfp[1]);
		qp->clearUndoRedoStacks(stacksToClear);
	}
	RETURNvoid_();
}

//QTextDocument QTextDocument.clone(QObject parent);
KMETHOD QTextDocument_clone(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QObject*  parent = RawPtr_to(QObject*, sfp[1]);
		QTextDocument* ret_v = qp->clone(parent);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QTextDocument.getDefaultFont();
KMETHOD QTextDocument_getDefaultFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QFont ret_v = qp->defaultFont();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextDocument.getDefaultStyleSheet();
KMETHOD QTextDocument_getDefaultStyleSheet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->defaultStyleSheet();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextOption QTextDocument.getDefaultTextOption();
KMETHOD QTextDocument_getDefaultTextOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextOption ret_v = qp->defaultTextOption();
		QTextOption *ret_v_ = new QTextOption(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractTextDocumentLayout QTextDocument.getDocumentLayout();
KMETHOD QTextDocument_getDocumentLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QAbstractTextDocumentLayout* ret_v = qp->documentLayout();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractTextDocumentLayout*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTextDocument.getDocumentMargin();
KMETHOD QTextDocument_getDocumentMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->documentMargin();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QTextDocument.drawContents(QPainter p, QRectF rect);
KMETHOD QTextDocument_drawContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QPainter*  p = RawPtr_to(QPainter*, sfp[1]);
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[2]);
		qp->drawContents(p, rect);
	}
	RETURNvoid_();
}

//QTextBlock QTextDocument.end();
KMETHOD QTextDocument_end(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextBlock ret_v = qp->end();
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QTextDocument.find(String subString, QTextCursor cursor, int options);
KMETHOD QTextDocument_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QString subString = String_to(const QString, sfp[1]);
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[2]);
		QTextDocument::FindFlags options = Int_to(QTextDocument::FindFlags, sfp[3]);
		QTextCursor ret_v = qp->find(subString, cursor, options);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextCursor QTextDocument.find(QRegExp expr, QTextCursor cursor, int options);
KMETHOD QTextDocument_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QRegExp  expr = *RawPtr_to(const QRegExp *, sfp[1]);
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[2]);
		QTextDocument::FindFlags options = Int_to(QTextDocument::FindFlags, sfp[3]);
		QTextCursor ret_v = qp->find(expr, cursor, options);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QTextCursor QTextDocument.find(String subString, int position, int options);
KMETHOD QTextDocument_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QString subString = String_to(const QString, sfp[1]);
		int position = Int_to(int, sfp[2]);
		QTextDocument::FindFlags options = Int_to(QTextDocument::FindFlags, sfp[3]);
		QTextCursor ret_v = qp->find(subString, position, options);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QTextCursor QTextDocument.find(QRegExp expr, int position, int options);
KMETHOD QTextDocument_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QRegExp  expr = *RawPtr_to(const QRegExp *, sfp[1]);
		int position = Int_to(int, sfp[2]);
		QTextDocument::FindFlags options = Int_to(QTextDocument::FindFlags, sfp[3]);
		QTextCursor ret_v = qp->find(expr, position, options);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTextBlock QTextDocument.findBlock(int pos);
KMETHOD QTextDocument_findBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int pos = Int_to(int, sfp[1]);
		QTextBlock ret_v = qp->findBlock(pos);
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBlock QTextDocument.findBlockByLineNumber(int lineNumber);
KMETHOD QTextDocument_findBlockByLineNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int lineNumber = Int_to(int, sfp[1]);
		QTextBlock ret_v = qp->findBlockByLineNumber(lineNumber);
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBlock QTextDocument.findBlockByNumber(int blockNumber);
KMETHOD QTextDocument_findBlockByNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int blockNumber = Int_to(int, sfp[1]);
		QTextBlock ret_v = qp->findBlockByNumber(blockNumber);
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextBlock QTextDocument.firstBlock();
KMETHOD QTextDocument_firstBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextBlock ret_v = qp->firstBlock();
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTextDocument.idealWidth();
KMETHOD QTextDocument_idealWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->idealWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTextDocument.getIndentWidth();
KMETHOD QTextDocument_getIndentWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->indentWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QTextDocument.isEmpty();
KMETHOD QTextDocument_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextDocument.isModified();
KMETHOD QTextDocument_isModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isModified();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextDocument.isRedoAvailable();
KMETHOD QTextDocument_isRedoAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isRedoAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextDocument.isUndoAvailable();
KMETHOD QTextDocument_isUndoAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isUndoAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextDocument.isUndoRedoEnabled();
KMETHOD QTextDocument_isUndoRedoEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isUndoRedoEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTextBlock QTextDocument.lastBlock();
KMETHOD QTextDocument_lastBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextBlock ret_v = qp->lastBlock();
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextDocument.lineCount();
KMETHOD QTextDocument_lineCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->lineCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextDocument.markContentsDirty(int position, int length);
KMETHOD QTextDocument_markContentsDirty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int position = Int_to(int, sfp[1]);
		int length = Int_to(int, sfp[2]);
		qp->markContentsDirty(position, length);
	}
	RETURNvoid_();
}

//int QTextDocument.getMaximumBlockCount();
KMETHOD QTextDocument_getMaximumBlockCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->maximumBlockCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTextDocument.getMetaInformation(int info);
KMETHOD QTextDocument_getMetaInformation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextDocument::MetaInformation info = Int_to(QTextDocument::MetaInformation, sfp[1]);
		QString ret_v = qp->metaInformation(info);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextObject QTextDocument.object(int objectIndex);
KMETHOD QTextDocument_object(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int objectIndex = Int_to(int, sfp[1]);
		QTextObject* ret_v = qp->object(objectIndex);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextObject QTextDocument.objectForFormat(QTextFormat f);
KMETHOD QTextDocument_objectForFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QTextFormat  f = *RawPtr_to(const QTextFormat *, sfp[1]);
		QTextObject* ret_v = qp->objectForFormat(f);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextDocument.pageCount();
KMETHOD QTextDocument_pageCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->pageCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSizeF QTextDocument.getPageSize();
KMETHOD QTextDocument_getPageSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QSizeF ret_v = qp->pageSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextDocument.print(QPrinter printer);
KMETHOD QTextDocument_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
		qp->print(printer);
	}
	RETURNvoid_();
}

//void QTextDocument.redo(QTextCursor cursor);
KMETHOD QTextDocument_redo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextCursor*  cursor = RawPtr_to(QTextCursor*, sfp[1]);
		qp->redo(cursor);
	}
	RETURNvoid_();
}

//QVariant QTextDocument.resource(int type, QUrl name);
KMETHOD QTextDocument_resource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int type = Int_to(int, sfp[1]);
		const QUrl  name = *RawPtr_to(const QUrl *, sfp[2]);
		QVariant ret_v = qp->resource(type, name);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextDocument.revision();
KMETHOD QTextDocument_revision(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->revision();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextFrame QTextDocument.rootFrame();
KMETHOD QTextDocument_rootFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextFrame* ret_v = qp->rootFrame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextDocument.setDefaultFont(QFont font);
KMETHOD QTextDocument_setDefaultFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setDefaultFont(font);
	}
	RETURNvoid_();
}

//void QTextDocument.setDefaultStyleSheet(String sheet);
KMETHOD QTextDocument_setDefaultStyleSheet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QString sheet = String_to(const QString, sfp[1]);
		qp->setDefaultStyleSheet(sheet);
	}
	RETURNvoid_();
}

//void QTextDocument.setDefaultTextOption(QTextOption option);
KMETHOD QTextDocument_setDefaultTextOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QTextOption  option = *RawPtr_to(const QTextOption *, sfp[1]);
		qp->setDefaultTextOption(option);
	}
	RETURNvoid_();
}

//void QTextDocument.setDocumentLayout(QAbstractTextDocumentLayout layout);
KMETHOD QTextDocument_setDocumentLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QAbstractTextDocumentLayout*  layout = RawPtr_to(QAbstractTextDocumentLayout*, sfp[1]);
		qp->setDocumentLayout(layout);
	}
	RETURNvoid_();
}

//void QTextDocument.setDocumentMargin(float margin);
KMETHOD QTextDocument_setDocumentMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qreal margin = Float_to(qreal, sfp[1]);
		qp->setDocumentMargin(margin);
	}
	RETURNvoid_();
}

//void QTextDocument.setHtml(String html);
KMETHOD QTextDocument_setHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QString html = String_to(const QString, sfp[1]);
		qp->setHtml(html);
	}
	RETURNvoid_();
}

//void QTextDocument.setIndentWidth(float width);
KMETHOD QTextDocument_setIndentWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setIndentWidth(width);
	}
	RETURNvoid_();
}

//void QTextDocument.setMaximumBlockCount(int maximum);
KMETHOD QTextDocument_setMaximumBlockCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		int maximum = Int_to(int, sfp[1]);
		qp->setMaximumBlockCount(maximum);
	}
	RETURNvoid_();
}

//void QTextDocument.setMetaInformation(int info, String str);
KMETHOD QTextDocument_setMetaInformation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextDocument::MetaInformation info = Int_to(QTextDocument::MetaInformation, sfp[1]);
		const QString string = String_to(const QString, sfp[2]);
		qp->setMetaInformation(info, string);
	}
	RETURNvoid_();
}

//void QTextDocument.setPageSize(QSizeF size);
KMETHOD QTextDocument_setPageSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[1]);
		qp->setPageSize(size);
	}
	RETURNvoid_();
}

//void QTextDocument.setPlainText(String text);
KMETHOD QTextDocument_setPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setPlainText(text);
	}
	RETURNvoid_();
}

//void QTextDocument.setTextWidth(float width);
KMETHOD QTextDocument_setTextWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setTextWidth(width);
	}
	RETURNvoid_();
}

//void QTextDocument.setUndoRedoEnabled(boolean enable);
KMETHOD QTextDocument_setUndoRedoEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setUndoRedoEnabled(enable);
	}
	RETURNvoid_();
}

//void QTextDocument.setUseDesignMetrics(boolean b);
KMETHOD QTextDocument_setUseDesignMetrics(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setUseDesignMetrics(b);
	}
	RETURNvoid_();
}

//QSizeF QTextDocument.size();
KMETHOD QTextDocument_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QSizeF ret_v = qp->size();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTextDocument.getTextWidth();
KMETHOD QTextDocument_getTextWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->textWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//String QTextDocument.toHtml(QByteArray encoding);
KMETHOD QTextDocument_toHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  encoding = *RawPtr_to(const QByteArray *, sfp[1]);
		QString ret_v = qp->toHtml(encoding);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextDocument.toPlainText();
KMETHOD QTextDocument_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->toPlainText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextDocument.undo(QTextCursor cursor);
KMETHOD QTextDocument_undo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		QTextCursor*  cursor = RawPtr_to(QTextCursor*, sfp[1]);
		qp->undo(cursor);
	}
	RETURNvoid_();
}

//boolean QTextDocument.getUseDesignMetrics();
KMETHOD QTextDocument_getUseDesignMetrics(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->useDesignMetrics();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//void QTextDocument.redo();
KMETHOD QTextDocument_redo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qp->redo();
	}
	RETURNvoid_();
}
*/
//void QTextDocument.setModified(boolean m);
KMETHOD QTextDocument_setModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		bool m = Boolean_to(bool, sfp[1]);
		qp->setModified(m);
	}
	RETURNvoid_();
}

/*
//void QTextDocument.undo();
KMETHOD QTextDocument_undo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp != NULL) {
		qp->undo();
	}
	RETURNvoid_();
}
*/

DummyQTextDocument::DummyQTextDocument()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextDocument::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextDocument::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQTextDocument::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextDocument::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDocument::event_map->bigin();
	if ((itr = DummyQTextDocument::event_map->find(str)) == DummyQTextDocument::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextDocument::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDocument::slot_map->bigin();
	if ((itr = DummyQTextDocument::event_map->find(str)) == DummyQTextDocument::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextDocument::KQTextDocument(QObject* parent) : QTextDocument(parent)
{
	self = NULL;
}

KMETHOD QTextDocument_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDocument *qp = RawPtr_to(KQTextDocument *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextDocument]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTextDocument::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDocument]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTextDocument_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDocument *qp = RawPtr_to(KQTextDocument *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextDocument]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTextDocument::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDocument]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextDocument_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextDocument *qp = (KQTextDocument *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextDocument_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextDocument *qp = (KQTextDocument *)p->rawptr;
		(void)qp;
	}
}

static int QTextDocument_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQTextDocument::event(QEvent *event)
{
	if (!DummyQTextDocument::eventDispatcher(event)) {
		QTextDocument::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTextDocument(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextDocument";
	cdef->free = QTextDocument_free;
	cdef->reftrace = QTextDocument_reftrace;
	cdef->compareTo = QTextDocument_compareTo;
}

static knh_IntData_t QTextDocumentConstInt[] = {
	{"FindBackward", QTextDocument::FindBackward},
	{"FindCaseSensitively", QTextDocument::FindCaseSensitively},
	{"FindWholeWords", QTextDocument::FindWholeWords},
	{"DocumentTitle", QTextDocument::DocumentTitle},
	{"DocumentUrl", QTextDocument::DocumentUrl},
	{"HtmlResource", QTextDocument::HtmlResource},
	{"ImageResource", QTextDocument::ImageResource},
	{"StyleSheetResource", QTextDocument::StyleSheetResource},
	{"UserResource", QTextDocument::UserResource},
	{"UndoStack", QTextDocument::UndoStack},
	{"RedoStack", QTextDocument::RedoStack},
	{"UndoAndRedoStacks", QTextDocument::UndoAndRedoStacks},
	{NULL, 0}
};

DEFAPI(void) constQTextDocument(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextDocumentConstInt);
}

