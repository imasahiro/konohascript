//QChar QChar.new();
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQChar *ret_v = new KQChar();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QChar QChar.new(String ch);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	char  ch = *RawPtr_to(char *, sfp[1]);
	KQChar *ret_v = new KQChar(ch);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QChar QChar.new(String ch);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	uchar  ch = *RawPtr_to(uchar *, sfp[1]);
	KQChar *ret_v = new KQChar(ch);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QChar QChar.new(QLatin1Char ch);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLatin1Char  ch = *RawPtr_to(QLatin1Char *, sfp[1]);
	KQChar *ret_v = new KQChar(ch);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QChar QChar.new(String cell, String row);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	uchar  cell = *RawPtr_to(uchar *, sfp[1]);
	uchar  row = *RawPtr_to(uchar *, sfp[2]);
	KQChar *ret_v = new KQChar(cell, row);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QChar QChar.new(int code);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	ushort  code = *RawPtr_to(ushort *, sfp[1]);
	KQChar *ret_v = new KQChar(code);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QChar QChar.new(short code);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	short  code = *RawPtr_to(short *, sfp[1]);
	KQChar *ret_v = new KQChar(code);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QChar QChar.new(int code);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	uint  code = *RawPtr_to(uint *, sfp[1]);
	KQChar *ret_v = new KQChar(code);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QChar QChar.new(int code);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int code = Int_to(int, sfp[1]);
	KQChar *ret_v = new KQChar(code);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QChar QChar.new(int ch);
KMETHOD QChar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar::SpecialCharacter ch = Int_to(QChar::SpecialCharacter, sfp[1]);
	KQChar *ret_v = new KQChar(ch);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QChar.category();
KMETHOD QChar_category(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar::Category ret_v = qp->category();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QChar.cell();
KMETHOD QChar_cell(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uchar ret_v = qp->cell();
		uchar *ret_v_ = new uchar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

// char QChar.combiningClass();
KMETHOD QChar_combiningClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		unsigned char ret_v = qp->combiningClass();
		unsigned char *ret_v_ = new unsigned char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QChar.decomposition();
KMETHOD QChar_decomposition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->decomposition();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QChar.decompositionTag();
KMETHOD QChar_decompositionTag(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar::Decomposition ret_v = qp->decompositionTag();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QChar.digitValue();
KMETHOD QChar_digitValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->digitValue();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QChar.direction();
KMETHOD QChar_direction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar::Direction ret_v = qp->direction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QChar.hasMirrored();
KMETHOD QChar_hasMirrored(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasMirrored();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isDigit();
KMETHOD QChar_isDigit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isDigit();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isHighSurrogate();
KMETHOD QChar_isHighSurrogate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isHighSurrogate();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isLetter();
KMETHOD QChar_isLetter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isLetter();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isLetterOrNumber();
KMETHOD QChar_isLetterOrNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isLetterOrNumber();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isLowSurrogate();
KMETHOD QChar_isLowSurrogate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isLowSurrogate();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isLower();
KMETHOD QChar_isLower(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isLower();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isMark();
KMETHOD QChar_isMark(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isMark();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QChar.isNull();
KMETHOD QChar_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isNumber();
KMETHOD QChar_isNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNumber();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isPrint();
KMETHOD QChar_isPrint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isPrint();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isPunct();
KMETHOD QChar_isPunct(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isPunct();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isSpace();
KMETHOD QChar_isSpace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isSpace();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isSymbol();
KMETHOD QChar_isSymbol(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isSymbol();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isTitleCase();
KMETHOD QChar_isTitleCase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isTitleCase();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChar.isUpper();
KMETHOD QChar_isUpper(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isUpper();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QChar.joining();
KMETHOD QChar_joining(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar::Joining ret_v = qp->joining();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QChar QChar.mirroredChar();
KMETHOD QChar_mirroredChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->mirroredChar();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QChar.row();
KMETHOD QChar_row(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uchar ret_v = qp->row();
		uchar *ret_v_ = new uchar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QChar.toAscii();
KMETHOD QChar_toAscii(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		char ret_v = qp->toAscii();
		char *ret_v_ = new char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QChar.toCaseFolded();
KMETHOD QChar_toCaseFolded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->toCaseFolded();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QChar.toLatin1();
KMETHOD QChar_toLatin1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		char ret_v = qp->toLatin1();
		char *ret_v_ = new char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QChar.toLower();
KMETHOD QChar_toLower(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->toLower();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QChar.toTitleCase();
KMETHOD QChar_toTitleCase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->toTitleCase();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QChar.toUpper();
KMETHOD QChar_toUpper(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->toUpper();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QChar.unicode();
KMETHOD QChar_unicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort ret_v = qp->unicode();
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//int QChar.unicode();
KMETHOD QChar_unicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort ret_v = qp->unicode();
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QChar.unicodeVersion();
KMETHOD QChar_unicodeVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar::UnicodeVersion ret_v = qp->unicodeVersion();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QChar.category(int ucs4);
KMETHOD QChar_category(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		QChar::Category ret_v = qp->category(ucs4);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QChar.category(int ucs2);
KMETHOD QChar_category(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		QChar::Category ret_v = qp->category(ucs2);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
// char QChar.combiningClass(int ucs4);
KMETHOD QChar_combiningClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		unsigned char ret_v = qp->combiningClass(ucs4);
		unsigned char *ret_v_ = new unsigned char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
// char QChar.combiningClass(int ucs2);
KMETHOD QChar_combiningClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		unsigned char ret_v = qp->combiningClass(ucs2);
		unsigned char *ret_v_ = new unsigned char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QChar.decomposition(int ucs4);
KMETHOD QChar_decomposition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		QString ret_v = qp->decomposition(ucs4);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.decompositionTag(int ucs4);
KMETHOD QChar_decompositionTag(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		QChar::Decomposition ret_v = qp->decompositionTag(ucs4);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QChar.digitValue(int ucs2);
KMETHOD QChar_digitValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		int ret_v = qp->digitValue(ucs2);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QChar.digitValue(int ucs4);
KMETHOD QChar_digitValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		int ret_v = qp->digitValue(ucs4);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QChar.direction(int ucs4);
KMETHOD QChar_direction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		QChar::Direction ret_v = qp->direction(ucs4);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QChar.direction(int ucs2);
KMETHOD QChar_direction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		QChar::Direction ret_v = qp->direction(ucs2);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//QChar QChar.fromAscii(String c);
KMETHOD QChar_fromAscii(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		char  c = *RawPtr_to(char *, sfp[1]);
		QChar ret_v = qp->fromAscii(c);
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QChar.fromLatin1(String c);
KMETHOD QChar_fromLatin1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		char  c = *RawPtr_to(char *, sfp[1]);
		QChar ret_v = qp->fromLatin1(c);
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QChar.highSurrogate(int ucs4);
KMETHOD QChar_highSurrogate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		ushort ret_v = qp->highSurrogate(ucs4);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//boolean QChar.isHighSurrogate(int ucs4);
KMETHOD QChar_isHighSurrogate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		bool ret_v = qp->isHighSurrogate(ucs4);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QChar.isLowSurrogate(int ucs4);
KMETHOD QChar_isLowSurrogate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		bool ret_v = qp->isLowSurrogate(ucs4);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//int QChar.joining(int ucs4);
KMETHOD QChar_joining(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		QChar::Joining ret_v = qp->joining(ucs4);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QChar.joining(int ucs2);
KMETHOD QChar_joining(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		QChar::Joining ret_v = qp->joining(ucs2);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QChar.lowSurrogate(int ucs4);
KMETHOD QChar_lowSurrogate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		ushort ret_v = qp->lowSurrogate(ucs4);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//int QChar.mirroredChar(int ucs4);
KMETHOD QChar_mirroredChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		uint ret_v = qp->mirroredChar(ucs4);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.mirroredChar(int ucs2);
KMETHOD QChar_mirroredChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		ushort ret_v = qp->mirroredChar(ucs2);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QChar.requiresSurrogates(int ucs4);
KMETHOD QChar_requiresSurrogates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		bool ret_v = qp->requiresSurrogates(ucs4);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QChar.surrogateToUcs4(int high, int low);
KMETHOD QChar_surrogateToUcs4(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  high = *RawPtr_to(ushort *, sfp[1]);
		ushort  low = *RawPtr_to(ushort *, sfp[2]);
		uint ret_v = qp->surrogateToUcs4(high, low);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//int QChar.surrogateToUcs4(QChar high, QChar low);
KMETHOD QChar_surrogateToUcs4(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		QChar  high = *RawPtr_to(QChar *, sfp[1]);
		QChar  low = *RawPtr_to(QChar *, sfp[2]);
		uint ret_v = qp->surrogateToUcs4(high, low);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.toCaseFolded(int ucs4);
KMETHOD QChar_toCaseFolded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		uint ret_v = qp->toCaseFolded(ucs4);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.toCaseFolded(int ucs2);
KMETHOD QChar_toCaseFolded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		ushort ret_v = qp->toCaseFolded(ucs2);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.toLower(int ucs4);
KMETHOD QChar_toLower(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		uint ret_v = qp->toLower(ucs4);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.toLower(int ucs2);
KMETHOD QChar_toLower(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		ushort ret_v = qp->toLower(ucs2);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.toTitleCase(int ucs4);
KMETHOD QChar_toTitleCase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		uint ret_v = qp->toTitleCase(ucs4);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.toTitleCase(int ucs2);
KMETHOD QChar_toTitleCase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		ushort ret_v = qp->toTitleCase(ucs2);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.toUpper(int ucs4);
KMETHOD QChar_toUpper(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		uint ret_v = qp->toUpper(ucs4);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.toUpper(int ucs2);
KMETHOD QChar_toUpper(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		ushort ret_v = qp->toUpper(ucs2);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QChar.unicodeVersion(int ucs4);
KMETHOD QChar_unicodeVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		uint  ucs4 = *RawPtr_to(uint *, sfp[1]);
		QChar::UnicodeVersion ret_v = qp->unicodeVersion(ucs4);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QChar.unicodeVersion(int ucs2);
KMETHOD QChar_unicodeVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChar *  qp = RawPtr_to(QChar *, sfp[0]);
	if (qp != NULL) {
		ushort  ucs2 = *RawPtr_to(ushort *, sfp[1]);
		QChar::UnicodeVersion ret_v = qp->unicodeVersion(ucs2);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/

DummyQChar::DummyQChar()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQChar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQChar::self = ptr;
}

bool DummyQChar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQChar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQChar::event_map->bigin();
	if ((itr = DummyQChar::event_map->find(str)) == DummyQChar::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQChar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQChar::slot_map->bigin();
	if ((itr = DummyQChar::slot_map->find(str)) == DummyQChar::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQChar::connection(QObject *o)
{
	return;
}

KQChar::KQChar() : QChar()
{
	self = NULL;
	dummy = new DummyQChar();
	dummy->connection((QObject*)this);
}

KMETHOD QChar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQChar *qp = RawPtr_to(KQChar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QChar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QChar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QChar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQChar *qp = RawPtr_to(KQChar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QChar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QChar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QChar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQChar *qp = (KQChar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QChar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQChar *qp = (KQChar *)p->rawptr;
		(void)qp;
	}
}

static int QChar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQChar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQChar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QChar";
	cdef->free = QChar_free;
	cdef->reftrace = QChar_reftrace;
	cdef->compareTo = QChar_compareTo;
}

static knh_IntData_t QCharConstInt[] = {
	{"Mark_NonSpacing", QChar::Mark_NonSpacing},
	{"Mark_SpacingCombining", QChar::Mark_SpacingCombining},
	{"Mark_Enclosing", QChar::Mark_Enclosing},
	{"Number_DecimalDigit", QChar::Number_DecimalDigit},
	{"Number_Letter", QChar::Number_Letter},
	{"Number_Other", QChar::Number_Other},
	{"Separator_Space", QChar::Separator_Space},
	{"Separator_Line", QChar::Separator_Line},
	{"Separator_Paragraph", QChar::Separator_Paragraph},
	{"Other_Control", QChar::Other_Control},
	{"Other_Format", QChar::Other_Format},
	{"Other_Surrogate", QChar::Other_Surrogate},
	{"Other_PrivateUse", QChar::Other_PrivateUse},
	{"Other_NotAssigned", QChar::Other_NotAssigned},
	{"Letter_Uppercase", QChar::Letter_Uppercase},
	{"Letter_Lowercase", QChar::Letter_Lowercase},
	{"Letter_Titlecase", QChar::Letter_Titlecase},
	{"Letter_Modifier", QChar::Letter_Modifier},
	{"Letter_Other", QChar::Letter_Other},
	{"Punctuation_Connector", QChar::Punctuation_Connector},
	{"Punctuation_Dash", QChar::Punctuation_Dash},
	{"Punctuation_Open", QChar::Punctuation_Open},
	{"Punctuation_Close", QChar::Punctuation_Close},
	{"Punctuation_InitialQuote", QChar::Punctuation_InitialQuote},
	{"Punctuation_FinalQuote", QChar::Punctuation_FinalQuote},
	{"Punctuation_Other", QChar::Punctuation_Other},
	{"Symbol_Math", QChar::Symbol_Math},
	{"Symbol_Currency", QChar::Symbol_Currency},
	{"Symbol_Modifier", QChar::Symbol_Modifier},
	{"Symbol_Other", QChar::Symbol_Other},
	{"NoCategory", QChar::NoCategory},
	{"NoDecomposition", QChar::NoDecomposition},
	{"Canonical", QChar::Canonical},
	{"Circle", QChar::Circle},
	{"Compat", QChar::Compat},
	{"Final", QChar::Final},
	{"Font", QChar::Font},
	{"Fraction", QChar::Fraction},
	{"Initial", QChar::Initial},
	{"Isolated", QChar::Isolated},
	{"Medial", QChar::Medial},
	{"Narrow", QChar::Narrow},
	{"NoBreak", QChar::NoBreak},
	{"Small", QChar::Small},
	{"Square", QChar::Square},
	{"Sub", QChar::Sub},
	{"Super", QChar::Super},
	{"Vertical", QChar::Vertical},
	{"Wide", QChar::Wide},
	{"DirAL", QChar::DirAL},
	{"DirAN", QChar::DirAN},
	{"DirB", QChar::DirB},
	{"DirBN", QChar::DirBN},
	{"DirCS", QChar::DirCS},
	{"DirEN", QChar::DirEN},
	{"DirES", QChar::DirES},
	{"DirET", QChar::DirET},
	{"DirL", QChar::DirL},
	{"DirLRE", QChar::DirLRE},
	{"DirLRO", QChar::DirLRO},
	{"DirNSM", QChar::DirNSM},
	{"DirON", QChar::DirON},
	{"DirPDF", QChar::DirPDF},
	{"DirR", QChar::DirR},
	{"DirRLE", QChar::DirRLE},
	{"DirRLO", QChar::DirRLO},
	{"DirS", QChar::DirS},
	{"DirWS", QChar::DirWS},
	{"Center", QChar::Center},
	{"Dual", QChar::Dual},
	{"OtherJoining", QChar::OtherJoining},
	{"Right", QChar::Right},
	{"Null", QChar::Null},
	{"Nbsp", QChar::Nbsp},
	{"ReplacementCharacter", QChar::ReplacementCharacter},
	{"ObjectReplacementCharacter", QChar::ObjectReplacementCharacter},
	{"ByteOrderMark", QChar::ByteOrderMark},
	{"ByteOrderSwapped", QChar::ByteOrderSwapped},
	{"ParagraphSeparator", QChar::ParagraphSeparator},
	{"LineSeparator", QChar::LineSeparator},
	{"Unicode_1_1", QChar::Unicode_1_1},
	{"Unicode_2_0", QChar::Unicode_2_0},
	{"Unicode_2_1_2", QChar::Unicode_2_1_2},
	{"Unicode_3_0", QChar::Unicode_3_0},
	{"Unicode_3_1", QChar::Unicode_3_1},
	{"Unicode_3_2", QChar::Unicode_3_2},
	{"Unicode_4_0", QChar::Unicode_4_0},
	{"Unicode_4_1", QChar::Unicode_4_1},
	{"Unicode_5_0", QChar::Unicode_5_0},
	{"Unicode_Unassigned", QChar::Unicode_Unassigned},
	{NULL, 0}
};

DEFAPI(void) constQChar(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QCharConstInt);
}

