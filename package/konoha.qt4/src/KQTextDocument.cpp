//QTextDocument QTextDocument.new(QObject parent);
KMETHOD QTextDocument_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQTextDocument *ret_v = new KQTextDocument(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QTextDocument.addResource(int type, QUrl name, QVariant resource);
KMETHOD QTextDocument_addResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp) {
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
	if (qp) {
		qp->adjustSize();
	}
	RETURNvoid_();
}

//int QTextDocument.availableRedoSteps();
KMETHOD QTextDocument_availableRedoSteps(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QTextDocument.clearUndoRedoStacks(int stacksToClear);
KMETHOD QTextDocument_clearUndoRedoStacks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QTextBlock ret_v = qp->end();
		QTextBlock *ret_v_ = new QTextBlock(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCursor QTextDocument.find(String subString, QTextCursor cursor, QTextDocumentFindFlags options);
KMETHOD QTextDocument_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp) {
		const QString subString = String_to(const QString, sfp[1]);
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[2]);
		initFlag(options, QTextDocument::FindFlags, sfp[3]);
		QTextCursor ret_v = qp->find(subString, cursor, options);
		QTextCursor *ret_v_ = new QTextCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextCursor QTextDocument.find(QRegExp expr, QTextCursor cursor, QTextDocumentFindFlags options);
KMETHOD QTextDocument_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp) {
		const QRegExp  expr = *RawPtr_to(const QRegExp *, sfp[1]);
		const QTextCursor  cursor = *RawPtr_to(const QTextCursor *, sfp[2]);
		initFlag(options, QTextDocument::FindFlags, sfp[3]);
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
//QTextCursor QTextDocument.find(String subString, int position, QTextDocumentFindFlags options);
KMETHOD QTextDocument_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp) {
		const QString subString = String_to(const QString, sfp[1]);
		int position = Int_to(int, sfp[2]);
		initFlag(options, QTextDocument::FindFlags, sfp[3]);
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
//QTextCursor QTextDocument.find(QRegExp expr, int position, QTextDocumentFindFlags options);
KMETHOD QTextDocument_find(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument *  qp = RawPtr_to(QTextDocument *, sfp[0]);
	if (qp) {
		const QRegExp  expr = *RawPtr_to(const QRegExp *, sfp[1]);
		int position = Int_to(int, sfp[2]);
		initFlag(options, QTextDocument::FindFlags, sfp[3]);
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->undo();
	}
	RETURNvoid_();
}
*/

DummyQTextDocument::DummyQTextDocument()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	block_count_changed_func = NULL;
	contents_change_func = NULL;
	contents_changed_func = NULL;
	cursor_position_changed_func = NULL;
	document_layout_changed_func = NULL;
	modification_changed_func = NULL;
	redo_available_func = NULL;
	undo_available_func = NULL;
	undo_command_added_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("block-count-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("contents-change", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("contents-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("cursor-position-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("document-layout-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("modification-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("redo-available", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("undo-available", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("undo-command-added", NULL));
}
DummyQTextDocument::~DummyQTextDocument()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

bool DummyQTextDocument::blockCountChangedSlot(int new_BlockCount)
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

bool DummyQTextDocument::contentsChangeSlot(int position, int charsRemoved, int charsAdded)
{
	if (contents_change_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = position;
		lsfp[K_CALLDELTA+3].ivalue = charsRemoved;
		lsfp[K_CALLDELTA+4].ivalue = charsAdded;
		knh_Func_invoke(lctx, contents_change_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQTextDocument::contentsChangedSlot()
{
	if (contents_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, contents_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQTextDocument::cursorPositionChangedSlot(const QTextCursor cursor)
{
	if (cursor_position_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QTextCursor, cursor);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, cursor_position_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTextDocument::documentLayoutChangedSlot()
{
	if (document_layout_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, document_layout_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQTextDocument::modificationChangedSlot(bool changed)
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

bool DummyQTextDocument::redoAvailableSlot(bool available)
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

bool DummyQTextDocument::undoAvailableSlot(bool available)
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

bool DummyQTextDocument::undoCommandAddedSlot()
{
	if (undo_command_added_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, undo_command_added_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQTextDocument::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDocument::event_map->bigin();
	if ((itr = DummyQTextDocument::event_map->find(str)) == DummyQTextDocument::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQTextDocument::slot_map->find(str)) == DummyQTextDocument::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		block_count_changed_func = (*slot_map)["block-count-changed"];
		contents_change_func = (*slot_map)["contents-change"];
		contents_changed_func = (*slot_map)["contents-changed"];
		cursor_position_changed_func = (*slot_map)["cursor-position-changed"];
		document_layout_changed_func = (*slot_map)["document-layout-changed"];
		modification_changed_func = (*slot_map)["modification-changed"];
		redo_available_func = (*slot_map)["redo-available"];
		undo_available_func = (*slot_map)["undo-available"];
		undo_command_added_func = (*slot_map)["undo-command-added"];
		return true;
	}
}

knh_Object_t** DummyQTextDocument::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextDocument::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 10;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, block_count_changed_func);
	KNH_ADDNNREF(ctx, contents_change_func);
	KNH_ADDNNREF(ctx, contents_changed_func);
	KNH_ADDNNREF(ctx, cursor_position_changed_func);
	KNH_ADDNNREF(ctx, document_layout_changed_func);
	KNH_ADDNNREF(ctx, modification_changed_func);
	KNH_ADDNNREF(ctx, redo_available_func);
	KNH_ADDNNREF(ctx, undo_available_func);
	KNH_ADDNNREF(ctx, undo_command_added_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTextDocument::connection(QObject *o)
{
	QTextDocument *p = dynamic_cast<QTextDocument*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(blockCountChanged(int)), this, SLOT(blockCountChangedSlot(int)));
		connect(p, SIGNAL(contentsChange(int, int, int)), this, SLOT(contentsChangeSlot(int, int, int)));
		connect(p, SIGNAL(contentsChanged()), this, SLOT(contentsChangedSlot()));
		connect(p, SIGNAL(cursorPositionChanged(const QTextCursor)), this, SLOT(cursorPositionChangedSlot(const QTextCursor)));
		connect(p, SIGNAL(documentLayoutChanged()), this, SLOT(documentLayoutChangedSlot()));
		connect(p, SIGNAL(modificationChanged(bool)), this, SLOT(modificationChangedSlot(bool)));
		connect(p, SIGNAL(redoAvailable(bool)), this, SLOT(redoAvailableSlot(bool)));
		connect(p, SIGNAL(undoAvailable(bool)), this, SLOT(undoAvailableSlot(bool)));
		connect(p, SIGNAL(undoCommandAdded()), this, SLOT(undoCommandAddedSlot()));
	}
	DummyQObject::connection(o);
}

KQTextDocument::KQTextDocument(QObject* parent) : QTextDocument(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextDocument();
	dummy->connection((QObject*)this);
}

KQTextDocument::~KQTextDocument()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDocument]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextDocument_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextDocument *qp = (KQTextDocument *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextDocument*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextDocument_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextDocument *qp = (KQTextDocument *)p->rawptr;
		KQTextDocument *qp = static_cast<KQTextDocument*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextDocument_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextDocument::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTextDocument::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTextDocument::event(event);
		return false;
	}
//	QTextDocument::event(event);
	return true;
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


DEFAPI(void) defQTextDocument(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextDocument";
	cdef->free = QTextDocument_free;
	cdef->reftrace = QTextDocument_reftrace;
	cdef->compareTo = QTextDocument_compareTo;
}

//## QTextDocumentFindFlags QTextDocumentFindFlags.new(int value);
KMETHOD QTextDocumentFindFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextDocument::FindFlag i = Int_to(QTextDocument::FindFlag, sfp[1]);
	QTextDocument::FindFlags *ret_v = new QTextDocument::FindFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QTextDocumentFindFlags QTextDocumentFindFlags.and(int mask);
KMETHOD QTextDocumentFindFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextDocument::FindFlags *qp = RawPtr_to(QTextDocument::FindFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextDocument::FindFlags ret = ((*qp) & i);
		QTextDocument::FindFlags *ret_ = new QTextDocument::FindFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextDocumentFindFlags QTextDocumentFindFlags.iand(QTextDocument::QTextDocumentFindFlags other);
KMETHOD QTextDocumentFindFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextDocument::FindFlags *qp = RawPtr_to(QTextDocument::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QTextDocument::FindFlags *other = RawPtr_to(QTextDocument::FindFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextDocumentFindFlags QTextDocumentFindFlags.or(QTextDocumentFindFlags f);
KMETHOD QTextDocumentFindFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument::FindFlags *qp = RawPtr_to(QTextDocument::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QTextDocument::FindFlags *f = RawPtr_to(QTextDocument::FindFlags*, sfp[1]);
		QTextDocument::FindFlags ret = ((*qp) | (*f));
		QTextDocument::FindFlags *ret_ = new QTextDocument::FindFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextDocumentFindFlags QTextDocumentFindFlags.ior(QTextDocument::QTextDocumentFindFlags other);
KMETHOD QTextDocumentFindFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextDocument::FindFlags *qp = RawPtr_to(QTextDocument::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QTextDocument::FindFlags *other = RawPtr_to(QTextDocument::FindFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextDocumentFindFlags QTextDocumentFindFlags.xor(QTextDocumentFindFlags f);
KMETHOD QTextDocumentFindFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDocument::FindFlags *qp = RawPtr_to(QTextDocument::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QTextDocument::FindFlags *f = RawPtr_to(QTextDocument::FindFlags*, sfp[1]);
		QTextDocument::FindFlags ret = ((*qp) ^ (*f));
		QTextDocument::FindFlags *ret_ = new QTextDocument::FindFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextDocumentFindFlags QTextDocumentFindFlags.ixor(QTextDocument::QTextDocumentFindFlags other);
KMETHOD QTextDocumentFindFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextDocument::FindFlags *qp = RawPtr_to(QTextDocument::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QTextDocument::FindFlags *other = RawPtr_to(QTextDocument::FindFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QTextDocumentFindFlags.testFlag(int flag);
KMETHOD QTextDocumentFindFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextDocument::FindFlags *qp = RawPtr_to(QTextDocument::FindFlags *, sfp[0]);
	if (qp != NULL) {
		QTextDocument::FindFlag flag = Int_to(QTextDocument::FindFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QTextDocumentFindFlags.value();
KMETHOD QTextDocumentFindFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextDocument::FindFlags *qp = RawPtr_to(QTextDocument::FindFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QTextDocumentFindFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QTextDocument::FindFlags *qp = (QTextDocument::FindFlags *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QTextDocumentFindFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QTextDocument::FindFlags *qp = (QTextDocument::FindFlags *)p->rawptr;
		(void)qp;
	}
}

static int QTextDocumentFindFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QTextDocument::FindFlags*)p1->rawptr);
//		int v2 = int(*(QTextDocument::FindFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QTextDocument::FindFlags v1 = *(QTextDocument::FindFlags*)p1->rawptr;
		QTextDocument::FindFlags v2 = *(QTextDocument::FindFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQTextDocumentFindFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextDocumentFindFlags";
	cdef->free = QTextDocumentFindFlags_free;
	cdef->reftrace = QTextDocumentFindFlags_reftrace;
	cdef->compareTo = QTextDocumentFindFlags_compareTo;
}

