//QByteArray QByteArray.new();
KMETHOD QByteArray_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQByteArray *ret_v = new KQByteArray();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QByteArray QByteArray.new(String str);
KMETHOD QByteArray_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const char*  str = RawPtr_to(const char*, sfp[1]);
	KQByteArray *ret_v = new KQByteArray(str);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QByteArray QByteArray.new(String data, int size);
KMETHOD QByteArray_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const char*  data = RawPtr_to(const char*, sfp[1]);
	int size = Int_to(int, sfp[2]);
	KQByteArray *ret_v = new KQByteArray(data, size);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QByteArray QByteArray.new(int size, String ch);
KMETHOD QByteArray_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int size = Int_to(int, sfp[1]);
	char  ch = *RawPtr_to(char *, sfp[2]);
	KQByteArray *ret_v = new KQByteArray(size, ch);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QByteArray QByteArray.new(QByteArray other);
KMETHOD QByteArray_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QByteArray  other = *RawPtr_to(const QByteArray *, sfp[1]);
	KQByteArray *ret_v = new KQByteArray(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QByteArray QByteArray.append(QByteArray ba);
KMETHOD QByteArray_append(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = qp->append(ba);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QByteArray.append(String str);
KMETHOD QByteArray_append(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QString str = String_to(const QString, sfp[1]);
		QByteArray ret_v = qp->append(str);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.append(String str);
KMETHOD QByteArray_append(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		QByteArray ret_v = qp->append(str);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.append(String str, int len);
KMETHOD QByteArray_append(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		int len = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->append(str, len);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.append(String ch);
KMETHOD QByteArray_append(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		QByteArray ret_v = qp->append(ch);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//String QByteArray.at(int i);
KMETHOD QByteArray_at(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		char ret_v = qp->at(i);
		char *ret_v_ = new char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.capacity();
KMETHOD QByteArray_capacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int ret_v = qp->capacity();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QByteArray.chop(int n);
KMETHOD QByteArray_chop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int n = Int_to(int, sfp[1]);
		qp->chop(n);
	}
	RETURNvoid_();
}

//void QByteArray.clear();
KMETHOD QByteArray_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//String QByteArray.constData();
KMETHOD QByteArray_constData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->constData();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QByteArray.contains(QByteArray ba);
KMETHOD QByteArray_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->contains(ba);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QByteArray.contains(String str);
KMETHOD QByteArray_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		bool ret_v = qp->contains(str);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QByteArray.contains(String ch);
KMETHOD QByteArray_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		bool ret_v = qp->contains(ch);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//int QByteArray.count(QByteArray ba);
KMETHOD QByteArray_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		int ret_v = qp->count(ba);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QByteArray.count(String str);
KMETHOD QByteArray_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->count(str);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QByteArray.count(String ch);
KMETHOD QByteArray_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		int ret_v = qp->count(ch);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QByteArray.count();
KMETHOD QByteArray_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//String QByteArray.data();
KMETHOD QByteArray_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char* ret_v = qp->data();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QByteArray.data();
KMETHOD QByteArray_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->data();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QByteArray.endsWith(QByteArray ba);
KMETHOD QByteArray_endsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->endsWith(ba);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QByteArray.endsWith(String str);
KMETHOD QByteArray_endsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		bool ret_v = qp->endsWith(str);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QByteArray.endsWith(String ch);
KMETHOD QByteArray_endsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		bool ret_v = qp->endsWith(ch);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QByteArray QByteArray.fill(String ch, int size);
KMETHOD QByteArray_fill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		int size = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->fill(ch, size);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.indexOf(QByteArray ba, int from_);
KMETHOD QByteArray_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->indexOf(ba, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QByteArray.indexOf(String str, int from_);
KMETHOD QByteArray_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QString str = String_to(const QString, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->indexOf(str, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QByteArray.indexOf(String str, int from_);
KMETHOD QByteArray_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->indexOf(str, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QByteArray.indexOf(String ch, int from_);
KMETHOD QByteArray_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->indexOf(ch, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//QByteArray QByteArray.insert(int i, QByteArray ba);
KMETHOD QByteArray_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[2]);
		QByteArray ret_v = qp->insert(i, ba);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QByteArray.insert(int i, String str);
KMETHOD QByteArray_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		const QString str = String_to(const QString, sfp[2]);
		QByteArray ret_v = qp->insert(i, str);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.insert(int i, String str);
KMETHOD QByteArray_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		const char*  str = RawPtr_to(const char*, sfp[2]);
		QByteArray ret_v = qp->insert(i, str);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.insert(int i, String str, int len);
KMETHOD QByteArray_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		const char*  str = RawPtr_to(const char*, sfp[2]);
		int len = Int_to(int, sfp[3]);
		QByteArray ret_v = qp->insert(i, str, len);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.insert(int i, String ch);
KMETHOD QByteArray_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		char  ch = *RawPtr_to(char *, sfp[2]);
		QByteArray ret_v = qp->insert(i, ch);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QByteArray.isEmpty();
KMETHOD QByteArray_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QByteArray.lastIndexOf(QByteArray ba, int from_);
KMETHOD QByteArray_lastIndexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->lastIndexOf(ba, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QByteArray.lastIndexOf(String str, int from_);
KMETHOD QByteArray_lastIndexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QString str = String_to(const QString, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->lastIndexOf(str, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QByteArray.lastIndexOf(String str, int from_);
KMETHOD QByteArray_lastIndexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->lastIndexOf(str, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QByteArray.lastIndexOf(String ch, int from_);
KMETHOD QByteArray_lastIndexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		int from = Int_to(int, sfp[2]);
		int ret_v = qp->lastIndexOf(ch, from);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//QByteArray QByteArray.left(int len);
KMETHOD QByteArray_left(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int len = Int_to(int, sfp[1]);
		QByteArray ret_v = qp->left(len);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.leftJustified(int width, String fill, boolean truncate);
KMETHOD QByteArray_leftJustified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		char  fill = *RawPtr_to(char *, sfp[2]);
		bool truncate = Boolean_to(bool, sfp[3]);
		QByteArray ret_v = qp->leftJustified(width, fill, truncate);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.length();
KMETHOD QByteArray_length(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int ret_v = qp->length();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QByteArray QByteArray.mid(int pos, int len);
KMETHOD QByteArray_mid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int pos = Int_to(int, sfp[1]);
		int len = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->mid(pos, len);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.prepend(QByteArray ba);
KMETHOD QByteArray_prepend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = qp->prepend(ba);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QByteArray.prepend(String str);
KMETHOD QByteArray_prepend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		QByteArray ret_v = qp->prepend(str);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.prepend(String str, int len);
KMETHOD QByteArray_prepend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		int len = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->prepend(str, len);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.prepend(String ch);
KMETHOD QByteArray_prepend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		QByteArray ret_v = qp->prepend(ch);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QByteArray.push_back(QByteArray other);
KMETHOD QByteArray_push_back(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  other = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->push_back(other);
	}
	RETURNvoid_();
}

/*
//void QByteArray.push_back(String str);
KMETHOD QByteArray_push_back(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		qp->push_back(str);
	}
	RETURNvoid_();
}
*/
/*
//void QByteArray.push_back(String ch);
KMETHOD QByteArray_push_back(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		qp->push_back(ch);
	}
	RETURNvoid_();
}
*/
//void QByteArray.push_front(QByteArray other);
KMETHOD QByteArray_push_front(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  other = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->push_front(other);
	}
	RETURNvoid_();
}

/*
//void QByteArray.push_front(String str);
KMETHOD QByteArray_push_front(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		qp->push_front(str);
	}
	RETURNvoid_();
}
*/
/*
//void QByteArray.push_front(String ch);
KMETHOD QByteArray_push_front(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		qp->push_front(ch);
	}
	RETURNvoid_();
}
*/
//QByteArray QByteArray.remove(int pos, int len);
KMETHOD QByteArray_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int pos = Int_to(int, sfp[1]);
		int len = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->remove(pos, len);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.repeated(int times);
KMETHOD QByteArray_repeated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int times = Int_to(int, sfp[1]);
		QByteArray ret_v = qp->repeated(times);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.replace(int pos, int len, QByteArray after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int pos = Int_to(int, sfp[1]);
		int len = Int_to(int, sfp[2]);
		const QByteArray  after = *RawPtr_to(const QByteArray *, sfp[3]);
		QByteArray ret_v = qp->replace(pos, len, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QByteArray.replace(int pos, int len, String after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int pos = Int_to(int, sfp[1]);
		int len = Int_to(int, sfp[2]);
		const char*  after = RawPtr_to(const char*, sfp[3]);
		QByteArray ret_v = qp->replace(pos, len, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(int pos, int len, String after, int alen);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int pos = Int_to(int, sfp[1]);
		int len = Int_to(int, sfp[2]);
		const char*  after = RawPtr_to(const char*, sfp[3]);
		int alen = Int_to(int, sfp[4]);
		QByteArray ret_v = qp->replace(pos, len, after, alen);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(QByteArray before, QByteArray after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  before = *RawPtr_to(const QByteArray *, sfp[1]);
		const QByteArray  after = *RawPtr_to(const QByteArray *, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, QByteArray after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  before = RawPtr_to(const char*, sfp[1]);
		const QByteArray  after = *RawPtr_to(const QByteArray *, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, int bsize, String after, int asize);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  before = RawPtr_to(const char*, sfp[1]);
		int bsize = Int_to(int, sfp[2]);
		const char*  after = RawPtr_to(const char*, sfp[3]);
		int asize = Int_to(int, sfp[4]);
		QByteArray ret_v = qp->replace(before, bsize, after, asize);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(QByteArray before, String after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  before = *RawPtr_to(const QByteArray *, sfp[1]);
		const char*  after = RawPtr_to(const char*, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, QByteArray after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QString before = String_to(const QString, sfp[1]);
		const QByteArray  after = *RawPtr_to(const QByteArray *, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, String after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QString before = String_to(const QString, sfp[1]);
		const char*  after = RawPtr_to(const char*, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, String after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  before = RawPtr_to(const char*, sfp[1]);
		const char*  after = RawPtr_to(const char*, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, QByteArray after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  before = *RawPtr_to(char *, sfp[1]);
		const QByteArray  after = *RawPtr_to(const QByteArray *, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, String after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  before = *RawPtr_to(char *, sfp[1]);
		const QString after = String_to(const QString, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, String after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  before = *RawPtr_to(char *, sfp[1]);
		const char*  after = RawPtr_to(const char*, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.replace(String before, String after);
KMETHOD QByteArray_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  before = *RawPtr_to(char *, sfp[1]);
		char  after = *RawPtr_to(char *, sfp[2]);
		QByteArray ret_v = qp->replace(before, after);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QByteArray.reserve(int size);
KMETHOD QByteArray_reserve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->reserve(size);
	}
	RETURNvoid_();
}

//void QByteArray.resize(int size);
KMETHOD QByteArray_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->resize(size);
	}
	RETURNvoid_();
}

//QByteArray QByteArray.right(int len);
KMETHOD QByteArray_right(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int len = Int_to(int, sfp[1]);
		QByteArray ret_v = qp->right(len);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.rightJustified(int width, String fill, boolean truncate);
KMETHOD QByteArray_rightJustified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		char  fill = *RawPtr_to(char *, sfp[2]);
		bool truncate = Boolean_to(bool, sfp[3]);
		QByteArray ret_v = qp->rightJustified(width, fill, truncate);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.setNum(int n, int base);
KMETHOD QByteArray_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int n = Int_to(int, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->setNum(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QByteArray.setNum(int n, int base);
KMETHOD QByteArray_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		uint  n = *RawPtr_to(uint *, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->setNum(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.setNum(short n, int base);
KMETHOD QByteArray_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		short  n = *RawPtr_to(short *, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->setNum(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.setNum(int n, int base);
KMETHOD QByteArray_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		ushort  n = *RawPtr_to(ushort *, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->setNum(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.setNum(int n, int base);
KMETHOD QByteArray_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		qlonglong  n = *RawPtr_to(qlonglong *, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->setNum(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.setNum(int n, int base);
KMETHOD QByteArray_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		qulonglong  n = *RawPtr_to(qulonglong *, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->setNum(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.setNum(double n, String f, int prec);
KMETHOD QByteArray_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		double  n = *RawPtr_to(double *, sfp[1]);
		char  f = *RawPtr_to(char *, sfp[2]);
		int prec = Int_to(int, sfp[3]);
		QByteArray ret_v = qp->setNum(n, f, prec);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.setNum(float n, String f, int prec);
KMETHOD QByteArray_setNum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		float n = Float_to(float, sfp[1]);
		char  f = *RawPtr_to(char *, sfp[2]);
		int prec = Int_to(int, sfp[3]);
		QByteArray ret_v = qp->setNum(n, f, prec);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QByteArray QByteArray.setRawData(String data, int size);
KMETHOD QByteArray_setRawData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		uint  size = *RawPtr_to(uint *, sfp[2]);
		QByteArray ret_v = qp->setRawData(data, size);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.simplified();
KMETHOD QByteArray_simplified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->simplified();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.size();
KMETHOD QByteArray_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int ret_v = qp->size();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<QByteArray> QByteArray.split(String sep);
KMETHOD QByteArray_split(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  sep = *RawPtr_to(char *, sfp[1]);
		QList<QByteArray> ret_v = qp->split(sep);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QByteArray"));
		for (int n = 0; n < list_size; n++) {
			QByteArray *ret_v_ = new QByteArray(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QByteArray.squeeze();
KMETHOD QByteArray_squeeze(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		qp->squeeze();
	}
	RETURNvoid_();
}

//boolean QByteArray.startsWith(QByteArray ba);
KMETHOD QByteArray_startsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->startsWith(ba);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QByteArray.startsWith(String str);
KMETHOD QByteArray_startsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const char*  str = RawPtr_to(const char*, sfp[1]);
		bool ret_v = qp->startsWith(str);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QByteArray.startsWith(String ch);
KMETHOD QByteArray_startsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		char  ch = *RawPtr_to(char *, sfp[1]);
		bool ret_v = qp->startsWith(ch);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QByteArray QByteArray.toBase64();
KMETHOD QByteArray_toBase64(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->toBase64();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//double QByteArray.toDouble(boolean ok);
KMETHOD QByteArray_toDouble(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		double ret_v = qp->toDouble(ok);
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QByteArray.toFloat(boolean ok);
KMETHOD QByteArray_toFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		float ret_v = qp->toFloat(ok);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QByteArray QByteArray.toHex();
KMETHOD QByteArray_toHex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->toHex();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.toInt(boolean ok, int base);
KMETHOD QByteArray_toInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		int base = Int_to(int, sfp[2]);
		int ret_v = qp->toInt(ok, base);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//long QByteArray.toLong(boolean ok, int base);
KMETHOD QByteArray_toLong(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		int base = Int_to(int, sfp[2]);
		long ret_v = qp->toLong(ok, base);
		long *ret_v_ = new long(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.toLongLong(boolean ok, int base);
KMETHOD QByteArray_toLongLong(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		int base = Int_to(int, sfp[2]);
		qlonglong ret_v = qp->toLongLong(ok, base);
		qlonglong *ret_v_ = new qlonglong(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.toLower();
KMETHOD QByteArray_toLower(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->toLower();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.toPercentEncoding(QByteArray exclude, QByteArray inc, String percent);
KMETHOD QByteArray_toPercentEncoding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		const QByteArray  exclude = *RawPtr_to(const QByteArray *, sfp[1]);
		const QByteArray  include = *RawPtr_to(const QByteArray *, sfp[2]);
		char  percent = *RawPtr_to(char *, sfp[3]);
		QByteArray ret_v = qp->toPercentEncoding(exclude, include, percent);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//short QByteArray.toShort(boolean ok, int base);
KMETHOD QByteArray_toShort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		int base = Int_to(int, sfp[2]);
		short ret_v = qp->toShort(ok, base);
		short *ret_v_ = new short(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.toUInt(boolean ok, int base);
KMETHOD QByteArray_toUInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		int base = Int_to(int, sfp[2]);
		uint ret_v = qp->toUInt(ok, base);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.toULong(boolean ok, int base);
KMETHOD QByteArray_toULong(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		int base = Int_to(int, sfp[2]);
		ulong ret_v = qp->toULong(ok, base);
		ulong *ret_v_ = new ulong(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.toULongLong(boolean ok, int base);
KMETHOD QByteArray_toULongLong(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		int base = Int_to(int, sfp[2]);
		qulonglong ret_v = qp->toULongLong(ok, base);
		qulonglong *ret_v_ = new qulonglong(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QByteArray.toUShort(boolean ok, int base);
KMETHOD QByteArray_toUShort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		int base = Int_to(int, sfp[2]);
		ushort ret_v = qp->toUShort(ok, base);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.toUpper();
KMETHOD QByteArray_toUpper(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->toUpper();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.trimmed();
KMETHOD QByteArray_trimmed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->trimmed();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QByteArray.truncate(int pos);
KMETHOD QByteArray_truncate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *  qp = RawPtr_to(QByteArray *, sfp[0]);
	if (qp) {
		int pos = Int_to(int, sfp[1]);
		qp->truncate(pos);
	}
	RETURNvoid_();
}

//QByteArray QByteArray.fromBase64(QByteArray base64);
KMETHOD QByteArray_fromBase64(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  base64 = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = QByteArray::fromBase64(base64);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.fromHex(QByteArray hexEncoded);
KMETHOD QByteArray_fromHex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  hexEncoded = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = QByteArray::fromHex(hexEncoded);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.fromPercentEncoding(QByteArray input, String percent);
KMETHOD QByteArray_fromPercentEncoding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  input = *RawPtr_to(const QByteArray *, sfp[1]);
		char  percent = *RawPtr_to(char *, sfp[2]);
		QByteArray ret_v = QByteArray::fromPercentEncoding(input, percent);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.fromRawData(String data, int size);
KMETHOD QByteArray_fromRawData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		int size = Int_to(int, sfp[2]);
		QByteArray ret_v = QByteArray::fromRawData(data, size);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QByteArray.number(int n, int base);
KMETHOD QByteArray_number(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int n = Int_to(int, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = QByteArray::number(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QByteArray.number(int n, int base);
KMETHOD QByteArray_number(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		uint  n = *RawPtr_to(uint *, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = QByteArray::number(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.number(int n, int base);
KMETHOD QByteArray_number(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qlonglong  n = *RawPtr_to(qlonglong *, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = QByteArray::number(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.number(int n, int base);
KMETHOD QByteArray_number(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qulonglong  n = *RawPtr_to(qulonglong *, sfp[1]);
		int base = Int_to(int, sfp[2]);
		QByteArray ret_v = QByteArray::number(n, base);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QByteArray.number(double n, String f, int prec);
KMETHOD QByteArray_number(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		double  n = *RawPtr_to(double *, sfp[1]);
		char  f = *RawPtr_to(char *, sfp[2]);
		int prec = Int_to(int, sfp[3]);
		QByteArray ret_v = QByteArray::number(n, f, prec);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//Array<String> QByteArray.parents();
KMETHOD QByteArray_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QByteArray *qp = RawPtr_to(QByteArray*, sfp[0]);
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

DummyQByteArray::DummyQByteArray()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQByteArray::setSelf(knh_RawPtr_t *ptr)
{
	DummyQByteArray::self = ptr;
}

bool DummyQByteArray::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQByteArray::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQByteArray::event_map->bigin();
	if ((itr = DummyQByteArray::event_map->find(str)) == DummyQByteArray::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQByteArray::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQByteArray::slot_map->bigin();
	if ((itr = DummyQByteArray::slot_map->find(str)) == DummyQByteArray::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQByteArray::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQByteArray::connection(QObject *o)
{
	QByteArray *p = dynamic_cast<QByteArray*>(o);
	if (p != NULL) {
	}
}

KQByteArray::KQByteArray() : QByteArray()
{
	self = NULL;
	dummy = new DummyQByteArray();
}

KMETHOD QByteArray_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQByteArray *qp = RawPtr_to(KQByteArray *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QByteArray]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QByteArray]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QByteArray_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQByteArray *qp = RawPtr_to(KQByteArray *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QByteArray]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QByteArray]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QByteArray_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQByteArray *qp = (KQByteArray *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QByteArray_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQByteArray *qp = (KQByteArray *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QByteArray_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QByteArray*>(p1->rawptr) == *static_cast<QByteArray*>(p2->rawptr) ? 0 : 1);
}

void KQByteArray::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQByteArray(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QByteArray";
	cdef->free = QByteArray_free;
	cdef->reftrace = QByteArray_reftrace;
	cdef->compareTo = QByteArray_compareTo;
}


