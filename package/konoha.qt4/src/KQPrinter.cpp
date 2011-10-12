//@Virtual @Override QPaintEngine QPrinter.paintEngine();
KMETHOD QPrinter_paintEngine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPaintEngine* ret_v = qp->paintEngine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPrinter QPrinter.new(int mode);
KMETHOD QPrinter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter::PrinterMode mode = Int_to(QPrinter::PrinterMode, sfp[1]);
	KQPrinter *ret_v = new KQPrinter(mode);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPrinter QPrinter.new(QPrinterInfo printer, int mode);
KMETHOD QPrinter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPrinterInfo  printer = *RawPtr_to(const QPrinterInfo *, sfp[1]);
	QPrinter::PrinterMode mode = Int_to(QPrinter::PrinterMode, sfp[2]);
	KQPrinter *ret_v = new KQPrinter(printer, mode);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QPrinter.abort();
KMETHOD QPrinter_abort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->abort();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPrinter.getCollateCopies();
KMETHOD QPrinter_getCollateCopies(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->collateCopies();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPrinter.getColorMode();
KMETHOD QPrinter_getColorMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::ColorMode ret_v = qp->colorMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPrinter.getCopyCount();
KMETHOD QPrinter_getCopyCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->copyCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QPrinter.getCreator();
KMETHOD QPrinter_getCreator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->creator();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QPrinter.getDocName();
KMETHOD QPrinter_getDocName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->docName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPrinter.getDoubleSidedPrinting();
KMETHOD QPrinter_getDoubleSidedPrinting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->doubleSidedPrinting();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPrinter.getDuplex();
KMETHOD QPrinter_getDuplex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::DuplexMode ret_v = qp->duplex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QPrinter.getFontEmbeddingEnabled();
KMETHOD QPrinter_getFontEmbeddingEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fontEmbeddingEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPrinter.fromPage();
KMETHOD QPrinter_fromPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->fromPage();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QPrinter.getFullPage();
KMETHOD QPrinter_getFullPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fullPage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QPrinter.getPageMargins(float left, float top, float right, float bottom, int unit);
KMETHOD QPrinter_getPageMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		qreal*  left = RawPtr_to(qreal*, sfp[1]);
		qreal*  top = RawPtr_to(qreal*, sfp[2]);
		qreal*  right = RawPtr_to(qreal*, sfp[3]);
		qreal*  bottom = RawPtr_to(qreal*, sfp[4]);
		QPrinter::Unit unit = Int_to(QPrinter::Unit, sfp[5]);
		qp->getPageMargins(left, top, right, bottom, unit);
	}
	RETURNvoid_();
}

////boolean QPrinter.isValid();
KMETHOD QPrinter_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPrinter.newPage();
KMETHOD QPrinter_newPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->newPage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPrinter.getOrientation();
KMETHOD QPrinter_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QPrinter.getOutputFileName();
KMETHOD QPrinter_getOutputFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->outputFileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPrinter.getOutputFormat();
KMETHOD QPrinter_getOutputFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::OutputFormat ret_v = qp->outputFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPrinter.getPageOrder();
KMETHOD QPrinter_getPageOrder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PageOrder ret_v = qp->pageOrder();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QPrinter.pageRect();
KMETHOD QPrinter_pageRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->pageRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QPrinter.pageRect(int unit);
KMETHOD QPrinter_pageRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::Unit unit = Int_to(QPrinter::Unit, sfp[1]);
		QRectF ret_v = qp->pageRect(unit);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRect QPrinter.paperRect();
KMETHOD QPrinter_paperRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->paperRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QPrinter.paperRect(int unit);
KMETHOD QPrinter_paperRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::Unit unit = Int_to(QPrinter::Unit, sfp[1]);
		QRectF ret_v = qp->paperRect(unit);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QPrinter.getPaperSize();
KMETHOD QPrinter_getPaperSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PaperSize ret_v = qp->paperSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//QSizeF QPrinter.getPaperSize(int unit);
KMETHOD QPrinter_getPaperSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::Unit unit = Int_to(QPrinter::Unit, sfp[1]);
		QSizeF ret_v = qp->paperSize(unit);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QPrinter.getPaperSource();
KMETHOD QPrinter_getPaperSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PaperSource ret_v = qp->paperSource();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPrintEngine QPrinter.printEngine();
KMETHOD QPrinter_printEngine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrintEngine* ret_v = qp->printEngine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPrintEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QPrinter.getPrintProgram();
KMETHOD QPrinter_getPrintProgram(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->printProgram();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPrinter.getPrintRange();
KMETHOD QPrinter_getPrintRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PrintRange ret_v = qp->printRange();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QPrinter.getPrinterName();
KMETHOD QPrinter_getPrinterName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->printerName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QPrinter.getPrinterSelectionOption();
KMETHOD QPrinter_getPrinterSelectionOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->printerSelectionOption();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPrinter.printerState();
KMETHOD QPrinter_printerState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PrinterState ret_v = qp->printerState();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPrinter.getResolution();
KMETHOD QPrinter_getResolution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->resolution();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPrinter.setCollateCopies(boolean collate);
KMETHOD QPrinter_setCollateCopies(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool collate = Boolean_to(bool, sfp[1]);
		qp->setCollateCopies(collate);
	}
	RETURNvoid_();
}

//void QPrinter.setColorMode(int new_ColorMode);
KMETHOD QPrinter_setColorMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::ColorMode new_ColorMode = Int_to(QPrinter::ColorMode, sfp[1]);
		qp->setColorMode(new_ColorMode);
	}
	RETURNvoid_();
}

//void QPrinter.setCopyCount(int count);
KMETHOD QPrinter_setCopyCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		int count = Int_to(int, sfp[1]);
		qp->setCopyCount(count);
	}
	RETURNvoid_();
}

//void QPrinter.setCreator(String creator);
KMETHOD QPrinter_setCreator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		const QString creator = String_to(const QString, sfp[1]);
		qp->setCreator(creator);
	}
	RETURNvoid_();
}

//void QPrinter.setDocName(String name);
KMETHOD QPrinter_setDocName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		const QString name = String_to(const QString, sfp[1]);
		qp->setDocName(name);
	}
	RETURNvoid_();
}

//void QPrinter.setDoubleSidedPrinting(boolean doubleSided);
KMETHOD QPrinter_setDoubleSidedPrinting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool doubleSided = Boolean_to(bool, sfp[1]);
		qp->setDoubleSidedPrinting(doubleSided);
	}
	RETURNvoid_();
}

//void QPrinter.setDuplex(int duplex);
KMETHOD QPrinter_setDuplex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::DuplexMode duplex = Int_to(QPrinter::DuplexMode, sfp[1]);
		qp->setDuplex(duplex);
	}
	RETURNvoid_();
}

//void QPrinter.setFontEmbeddingEnabled(boolean enable);
KMETHOD QPrinter_setFontEmbeddingEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setFontEmbeddingEnabled(enable);
	}
	RETURNvoid_();
}

//void QPrinter.setFromTo(int from_, int to_);
KMETHOD QPrinter_setFromTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		int from = Int_to(int, sfp[1]);
		int to = Int_to(int, sfp[2]);
		qp->setFromTo(from, to);
	}
	RETURNvoid_();
}

//void QPrinter.setFullPage(boolean fp);
KMETHOD QPrinter_setFullPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool fp = Boolean_to(bool, sfp[1]);
		qp->setFullPage(fp);
	}
	RETURNvoid_();
}

//void QPrinter.setOrientation(int orientation);
KMETHOD QPrinter_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::Orientation orientation = Int_to(QPrinter::Orientation, sfp[1]);
		qp->setOrientation(orientation);
	}
	RETURNvoid_();
}

//void QPrinter.setOutputFileName(String fileName);
KMETHOD QPrinter_setOutputFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		qp->setOutputFileName(fileName);
	}
	RETURNvoid_();
}

//void QPrinter.setOutputFormat(int fmt);
KMETHOD QPrinter_setOutputFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::OutputFormat format = Int_to(QPrinter::OutputFormat, sfp[1]);
		qp->setOutputFormat(format);
	}
	RETURNvoid_();
}

//void QPrinter.setPageMargins(float left, float top, float right, float bottom, int unit);
KMETHOD QPrinter_setPageMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		qreal left = Float_to(qreal, sfp[1]);
		qreal top = Float_to(qreal, sfp[2]);
		qreal right = Float_to(qreal, sfp[3]);
		qreal bottom = Float_to(qreal, sfp[4]);
		QPrinter::Unit unit = Int_to(QPrinter::Unit, sfp[5]);
		qp->setPageMargins(left, top, right, bottom, unit);
	}
	RETURNvoid_();
}

//void QPrinter.setPageOrder(int pageOrder);
KMETHOD QPrinter_setPageOrder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PageOrder pageOrder = Int_to(QPrinter::PageOrder, sfp[1]);
		qp->setPageOrder(pageOrder);
	}
	RETURNvoid_();
}

//void QPrinter.setPaperSize(int new_PaperSize);
KMETHOD QPrinter_setPaperSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PaperSize new_PaperSize = Int_to(QPrinter::PaperSize, sfp[1]);
		qp->setPaperSize(new_PaperSize);
	}
	RETURNvoid_();
}

/*
//void QPrinter.setPaperSize(QSizeF paperSize, int unit);
KMETHOD QPrinter_setPaperSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		const QSizeF  paperSize = *RawPtr_to(const QSizeF *, sfp[1]);
		QPrinter::Unit unit = Int_to(QPrinter::Unit, sfp[2]);
		qp->setPaperSize(paperSize, unit);
	}
	RETURNvoid_();
}
*/
//void QPrinter.setPaperSource(int source);
KMETHOD QPrinter_setPaperSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PaperSource source = Int_to(QPrinter::PaperSource, sfp[1]);
		qp->setPaperSource(source);
	}
	RETURNvoid_();
}

//void QPrinter.setPrintProgram(String printProg);
KMETHOD QPrinter_setPrintProgram(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		const QString printProg = String_to(const QString, sfp[1]);
		qp->setPrintProgram(printProg);
	}
	RETURNvoid_();
}

//void QPrinter.setPrintRange(int range);
KMETHOD QPrinter_setPrintRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QPrinter::PrintRange range = Int_to(QPrinter::PrintRange, sfp[1]);
		qp->setPrintRange(range);
	}
	RETURNvoid_();
}

//void QPrinter.setPrinterName(String name);
KMETHOD QPrinter_setPrinterName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		const QString name = String_to(const QString, sfp[1]);
		qp->setPrinterName(name);
	}
	RETURNvoid_();
}

//void QPrinter.setPrinterSelectionOption(String option);
KMETHOD QPrinter_setPrinterSelectionOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		const QString option = String_to(const QString, sfp[1]);
		qp->setPrinterSelectionOption(option);
	}
	RETURNvoid_();
}

//void QPrinter.setResolution(int dpi);
KMETHOD QPrinter_setResolution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		int dpi = Int_to(int, sfp[1]);
		qp->setResolution(dpi);
	}
	RETURNvoid_();
}

//Array<int> QPrinter.supportedResolutions();
KMETHOD QPrinter_supportedResolutions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		QList<int>ret_v = qp->supportedResolutions();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("int"));
		for (int n = 0; n < list_size; n++) {
			int *ret_v_ = new int(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QPrinter.supportsMultipleCopies();
KMETHOD QPrinter_supportsMultipleCopies(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->supportsMultipleCopies();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPrinter.toPage();
KMETHOD QPrinter_toPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter *  qp = RawPtr_to(QPrinter *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->toPage();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQPrinter::DummyQPrinter()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPrinter::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPrinter::self = ptr;
	DummyQPaintDevice::setSelf(ptr);
}

bool DummyQPrinter::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPaintDevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPrinter::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrinter::event_map->bigin();
	if ((itr = DummyQPrinter::event_map->find(str)) == DummyQPrinter::event_map->end()) {
		bool ret;
		ret = DummyQPaintDevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPrinter::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrinter::slot_map->bigin();
	if ((itr = DummyQPrinter::event_map->find(str)) == DummyQPrinter::slot_map->end()) {
		bool ret;
		ret = DummyQPaintDevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPrinter::KQPrinter(QPrinter::PrinterMode mode) : QPrinter(mode)
{
	self = NULL;
}

KMETHOD QPrinter_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrinter *qp = RawPtr_to(KQPrinter *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPrinter]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPrinter::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrinter]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPrinter_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrinter *qp = RawPtr_to(KQPrinter *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPrinter]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPrinter::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrinter]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPrinter_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPrinter *qp = (KQPrinter *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPrinter_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPrinter *qp = (KQPrinter *)p->rawptr;
		(void)qp;
	}
}

static int QPrinter_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQPrinter(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPrinter";
	cdef->free = QPrinter_free;
	cdef->reftrace = QPrinter_reftrace;
	cdef->compareTo = QPrinter_compareTo;
}

static knh_IntData_t QPrinterConstInt[] = {
	{"Color", QPrinter::Color},
	{"GrayScale", QPrinter::GrayScale},
	{"DuplexNone", QPrinter::DuplexNone},
	{"DuplexAuto", QPrinter::DuplexAuto},
	{"DuplexLongSide", QPrinter::DuplexLongSide},
	{"DuplexShortSide", QPrinter::DuplexShortSide},
	{"Portrait", QPrinter::Portrait},
	{"Landscape", QPrinter::Landscape},
	{"NativeFormat", QPrinter::NativeFormat},
	{"PdfFormat", QPrinter::PdfFormat},
	{"PostScriptFormat", QPrinter::PostScriptFormat},
	{"FirstPageFirst", QPrinter::FirstPageFirst},
	{"LastPageFirst", QPrinter::LastPageFirst},
	{"A0", QPrinter::A0},
	{"A1", QPrinter::A1},
	{"A2", QPrinter::A2},
	{"A3", QPrinter::A3},
	{"A4", QPrinter::A4},
	{"A5", QPrinter::A5},
	{"A6", QPrinter::A6},
	{"A7", QPrinter::A7},
	{"A8", QPrinter::A8},
	{"A9", QPrinter::A9},
	{"B0", QPrinter::B0},
	{"B1", QPrinter::B1},
	{"B2", QPrinter::B2},
	{"B3", QPrinter::B3},
	{"B4", QPrinter::B4},
	{"B5", QPrinter::B5},
	{"B6", QPrinter::B6},
	{"B7", QPrinter::B7},
	{"B8", QPrinter::B8},
	{"B9", QPrinter::B9},
	{"B10", QPrinter::B10},
	{"C5E", QPrinter::C5E},
	{"Comm10E", QPrinter::Comm10E},
	{"DLE", QPrinter::DLE},
	{"Executive", QPrinter::Executive},
	{"Folio", QPrinter::Folio},
	{"Ledger", QPrinter::Ledger},
	{"Legal", QPrinter::Legal},
	{"Letter", QPrinter::Letter},
	{"Tabloid", QPrinter::Tabloid},
	{"Custom", QPrinter::Custom},
	{"Auto", QPrinter::Auto},
	{"Cassette", QPrinter::Cassette},
	{"Envelope", QPrinter::Envelope},
	{"EnvelopeManual", QPrinter::EnvelopeManual},
	{"FormSource", QPrinter::FormSource},
	{"LargeCapacity", QPrinter::LargeCapacity},
	{"LargeFormat", QPrinter::LargeFormat},
	{"Lower", QPrinter::Lower},
	{"MaxPageSource", QPrinter::MaxPageSource},
	{"Middle", QPrinter::Middle},
	{"Manual", QPrinter::Manual},
	{"OnlyOne", QPrinter::OnlyOne},
	{"Tractor", QPrinter::Tractor},
	{"SmallFormat", QPrinter::SmallFormat},
	{"AllPages", QPrinter::AllPages},
	{"Selection", QPrinter::Selection},
	{"PageRange", QPrinter::PageRange},
	{"CurrentPage", QPrinter::CurrentPage},
	{"ScreenResolution", QPrinter::ScreenResolution},
	{"PrinterResolution", QPrinter::PrinterResolution},
	{"HighResolution", QPrinter::HighResolution},
	{"Idle", QPrinter::Idle},
	{"Active", QPrinter::Active},
	{"Aborted", QPrinter::Aborted},
	{"Error", QPrinter::Error},
	{"Millimeter", QPrinter::Millimeter},
	{"Point", QPrinter::Point},
	{"Inch", QPrinter::Inch},
	{"Pica", QPrinter::Pica},
	{"Didot", QPrinter::Didot},
	{"Cicero", QPrinter::Cicero},
	{"DevicePixel", QPrinter::DevicePixel},
	{NULL, 0}
};

DEFAPI(void) constQPrinter(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPrinterConstInt);
}

