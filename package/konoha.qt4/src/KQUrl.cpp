//QUrl QUrl.new();
KMETHOD QUrl_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUrl *ret_v = new KQUrl();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QUrl QUrl.new(String url);
KMETHOD QUrl_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString url = String_to(const QString, sfp[1]);
	KQUrl *ret_v = new KQUrl(url);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QUrl QUrl.new(QUrl other);
KMETHOD QUrl_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QUrl  other = *RawPtr_to(const QUrl *, sfp[1]);
	KQUrl *ret_v = new KQUrl(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QUrl QUrl.new(String url, int parsingMode);
KMETHOD QUrl_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString url = String_to(const QString, sfp[1]);
	QUrl::ParsingMode parsingMode = Int_to(QUrl::ParsingMode, sfp[2]);
	KQUrl *ret_v = new KQUrl(url, parsingMode);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QUrl.addEncodedQueryItem(QByteArray key, QByteArray value);
KMETHOD QUrl_addEncodedQueryItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  key = *RawPtr_to(const QByteArray *, sfp[1]);
		const QByteArray  value = *RawPtr_to(const QByteArray *, sfp[2]);
		qp->addEncodedQueryItem(key, value);
	}
	RETURNvoid_();
}

//void QUrl.addQueryItem(String key, String value);
KMETHOD QUrl_addQueryItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		const QString value = String_to(const QString, sfp[2]);
		qp->addQueryItem(key, value);
	}
	RETURNvoid_();
}

//Array<QByteArray> QUrl.allEncodedQueryItemValues(QByteArray key);
KMETHOD QUrl_allEncodedQueryItemValues(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  key = *RawPtr_to(const QByteArray *, sfp[1]);
		QList<QByteArray> ret_v = qp->allEncodedQueryItemValues(key);
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
	

//String QUrl.getAuthority();
KMETHOD QUrl_getAuthority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->authority();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QUrl.clear();
KMETHOD QUrl_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//QByteArray QUrl.getEncodedFragment();
KMETHOD QUrl_getEncodedFragment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->encodedFragment();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QUrl.getEncodedHost();
KMETHOD QUrl_getEncodedHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->encodedHost();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QUrl.getEncodedPassword();
KMETHOD QUrl_getEncodedPassword(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->encodedPassword();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QUrl.getEncodedPath();
KMETHOD QUrl_getEncodedPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->encodedPath();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QUrl.getEncodedQuery();
KMETHOD QUrl_getEncodedQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->encodedQuery();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QUrl.encodedQueryItemValue(QByteArray key);
KMETHOD QUrl_encodedQueryItemValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  key = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = qp->encodedQueryItemValue(key);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QUrl.getEncodedUserName();
KMETHOD QUrl_getEncodedUserName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->encodedUserName();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.errorString();
KMETHOD QUrl_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.getFragment();
KMETHOD QUrl_getFragment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fragment();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QUrl.hasEncodedQueryItem(QByteArray key);
KMETHOD QUrl_hasEncodedQueryItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  key = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->hasEncodedQueryItem(key);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrl.hasFragment();
KMETHOD QUrl_hasFragment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasFragment();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrl.hasQuery();
KMETHOD QUrl_hasQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasQuery();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrl.hasQueryItem(String key);
KMETHOD QUrl_hasQueryItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		bool ret_v = qp->hasQueryItem(key);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QUrl.getHost();
KMETHOD QUrl_getHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->host();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QUrl.isEmpty();
KMETHOD QUrl_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrl.isParentOf(QUrl childUrl);
KMETHOD QUrl_isParentOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QUrl  childUrl = *RawPtr_to(const QUrl *, sfp[1]);
		bool ret_v = qp->isParentOf(childUrl);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrl.isRelative();
KMETHOD QUrl_isRelative(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isRelative();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QUrl.getPassword();
KMETHOD QUrl_getPassword(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->password();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.getPath();
KMETHOD QUrl_getPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->path();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QUrl.getPort();
KMETHOD QUrl_getPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		int ret_v = qp->port();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QUrl.getPort(int defaultPort);
KMETHOD QUrl_getPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		int defaultPort = Int_to(int, sfp[1]);
		int ret_v = qp->port(defaultPort);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//String QUrl.queryItemValue(String key);
KMETHOD QUrl_queryItemValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		QString ret_v = qp->queryItemValue(key);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.queryPairDelimiter();
KMETHOD QUrl_queryPairDelimiter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		char ret_v = qp->queryPairDelimiter();
		char *ret_v_ = new char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.queryValueDelimiter();
KMETHOD QUrl_queryValueDelimiter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		char ret_v = qp->queryValueDelimiter();
		char *ret_v_ = new char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QUrl.removeAllEncodedQueryItems(QByteArray key);
KMETHOD QUrl_removeAllEncodedQueryItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  key = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->removeAllEncodedQueryItems(key);
	}
	RETURNvoid_();
}

//void QUrl.removeAllQueryItems(String key);
KMETHOD QUrl_removeAllQueryItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		qp->removeAllQueryItems(key);
	}
	RETURNvoid_();
}

//void QUrl.removeEncodedQueryItem(QByteArray key);
KMETHOD QUrl_removeEncodedQueryItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  key = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->removeEncodedQueryItem(key);
	}
	RETURNvoid_();
}

//void QUrl.removeQueryItem(String key);
KMETHOD QUrl_removeQueryItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		qp->removeQueryItem(key);
	}
	RETURNvoid_();
}

//QUrl QUrl.resolved(QUrl relative);
KMETHOD QUrl_resolved(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QUrl  relative = *RawPtr_to(const QUrl *, sfp[1]);
		QUrl ret_v = qp->resolved(relative);
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.getScheme();
KMETHOD QUrl_getScheme(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->scheme();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QUrl.setAuthority(String authority);
KMETHOD QUrl_setAuthority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString authority = String_to(const QString, sfp[1]);
		qp->setAuthority(authority);
	}
	RETURNvoid_();
}

//void QUrl.setEncodedFragment(QByteArray fragment);
KMETHOD QUrl_setEncodedFragment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  fragment = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setEncodedFragment(fragment);
	}
	RETURNvoid_();
}

//void QUrl.setEncodedHost(QByteArray host);
KMETHOD QUrl_setEncodedHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  host = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setEncodedHost(host);
	}
	RETURNvoid_();
}

//void QUrl.setEncodedPassword(QByteArray password);
KMETHOD QUrl_setEncodedPassword(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  password = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setEncodedPassword(password);
	}
	RETURNvoid_();
}

//void QUrl.setEncodedPath(QByteArray path);
KMETHOD QUrl_setEncodedPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  path = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setEncodedPath(path);
	}
	RETURNvoid_();
}

//void QUrl.setEncodedQuery(QByteArray query);
KMETHOD QUrl_setEncodedQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  query = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setEncodedQuery(query);
	}
	RETURNvoid_();
}

//void QUrl.setEncodedUrl(QByteArray encodedUrl);
KMETHOD QUrl_setEncodedUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  encodedUrl = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setEncodedUrl(encodedUrl);
	}
	RETURNvoid_();
}

/*
//void QUrl.setEncodedUrl(QByteArray encodedUrl, int parsingMode);
KMETHOD QUrl_setEncodedUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  encodedUrl = *RawPtr_to(const QByteArray *, sfp[1]);
		QUrl::ParsingMode parsingMode = Int_to(QUrl::ParsingMode, sfp[2]);
		qp->setEncodedUrl(encodedUrl, parsingMode);
	}
	RETURNvoid_();
}
*/
//void QUrl.setEncodedUserName(QByteArray userName);
KMETHOD QUrl_setEncodedUserName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QByteArray  userName = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setEncodedUserName(userName);
	}
	RETURNvoid_();
}

//void QUrl.setFragment(String fragment);
KMETHOD QUrl_setFragment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString fragment = String_to(const QString, sfp[1]);
		qp->setFragment(fragment);
	}
	RETURNvoid_();
}

//void QUrl.setHost(String host);
KMETHOD QUrl_setHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString host = String_to(const QString, sfp[1]);
		qp->setHost(host);
	}
	RETURNvoid_();
}

//void QUrl.setPassword(String password);
KMETHOD QUrl_setPassword(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString password = String_to(const QString, sfp[1]);
		qp->setPassword(password);
	}
	RETURNvoid_();
}

//void QUrl.setPath(String path);
KMETHOD QUrl_setPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		qp->setPath(path);
	}
	RETURNvoid_();
}

//void QUrl.setPort(int port);
KMETHOD QUrl_setPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		int port = Int_to(int, sfp[1]);
		qp->setPort(port);
	}
	RETURNvoid_();
}

//void QUrl.setQueryDelimiters(String valueDelimiter, String pairDelimiter);
KMETHOD QUrl_setQueryDelimiters(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		char  valueDelimiter = *RawPtr_to(char *, sfp[1]);
		char  pairDelimiter = *RawPtr_to(char *, sfp[2]);
		qp->setQueryDelimiters(valueDelimiter, pairDelimiter);
	}
	RETURNvoid_();
}

//void QUrl.setScheme(String scheme);
KMETHOD QUrl_setScheme(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString scheme = String_to(const QString, sfp[1]);
		qp->setScheme(scheme);
	}
	RETURNvoid_();
}

//void QUrl.setUrl(String url);
KMETHOD QUrl_setUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString url = String_to(const QString, sfp[1]);
		qp->setUrl(url);
	}
	RETURNvoid_();
}

/*
//void QUrl.setUrl(String url, int parsingMode);
KMETHOD QUrl_setUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString url = String_to(const QString, sfp[1]);
		QUrl::ParsingMode parsingMode = Int_to(QUrl::ParsingMode, sfp[2]);
		qp->setUrl(url, parsingMode);
	}
	RETURNvoid_();
}
*/
//void QUrl.setUserInfo(String userInfo);
KMETHOD QUrl_setUserInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString userInfo = String_to(const QString, sfp[1]);
		qp->setUserInfo(userInfo);
	}
	RETURNvoid_();
}

//void QUrl.setUserName(String userName);
KMETHOD QUrl_setUserName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		const QString userName = String_to(const QString, sfp[1]);
		qp->setUserName(userName);
	}
	RETURNvoid_();
}

//QByteArray QUrl.toEncoded(QUrlFormattingOptions options);
KMETHOD QUrl_toEncoded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		initFlag(options, QUrl::FormattingOptions, sfp[1]);
		QByteArray ret_v = qp->toEncoded(options);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.toLocalFile();
KMETHOD QUrl_toLocalFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toLocalFile();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.toString(QUrlFormattingOptions options);
KMETHOD QUrl_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		initFlag(options, QUrl::FormattingOptions, sfp[1]);
		QString ret_v = qp->toString(options);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.getUserInfo();
KMETHOD QUrl_getUserInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->userInfo();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.getUserName();
KMETHOD QUrl_getUserName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *  qp = RawPtr_to(QUrl *, sfp[0]);
	if (qp) {
		QString ret_v = qp->userName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.fromAce(QByteArray domain);
KMETHOD QUrl_fromAce(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  domain = *RawPtr_to(const QByteArray *, sfp[1]);
		QString ret_v = QUrl::fromAce(domain);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QUrl.fromEncoded(QByteArray input);
KMETHOD QUrl_fromEncoded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  input = *RawPtr_to(const QByteArray *, sfp[1]);
		QUrl ret_v = QUrl::fromEncoded(input);
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QUrl QUrl.fromEncoded(QByteArray input, int parsingMode);
KMETHOD QUrl_fromEncoded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  input = *RawPtr_to(const QByteArray *, sfp[1]);
		QUrl::ParsingMode parsingMode = Int_to(QUrl::ParsingMode, sfp[2]);
		QUrl ret_v = QUrl::fromEncoded(input, parsingMode);
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QUrl QUrl.fromLocalFile(String localFile);
KMETHOD QUrl_fromLocalFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString localFile = String_to(const QString, sfp[1]);
		QUrl ret_v = QUrl::fromLocalFile(localFile);
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrl.fromPercentEncoding(QByteArray input);
KMETHOD QUrl_fromPercentEncoding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  input = *RawPtr_to(const QByteArray *, sfp[1]);
		QString ret_v = QUrl::fromPercentEncoding(input);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QUrl.fromUserInput(String userInput);
KMETHOD QUrl_fromUserInput(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString userInput = String_to(const QString, sfp[1]);
		QUrl ret_v = QUrl::fromUserInput(userInput);
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QUrl.toAce(String domain);
KMETHOD QUrl_toAce(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString domain = String_to(const QString, sfp[1]);
		QByteArray ret_v = QUrl::toAce(domain);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QUrl.toPercentEncoding(String input, QByteArray exclude, QByteArray inc);
KMETHOD QUrl_toPercentEncoding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString input = String_to(const QString, sfp[1]);
		const QByteArray  exclude = *RawPtr_to(const QByteArray *, sfp[2]);
		const QByteArray  include = *RawPtr_to(const QByteArray *, sfp[3]);
		QByteArray ret_v = QUrl::toPercentEncoding(input, exclude, include);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QUrl.parents();
KMETHOD QUrl_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl *qp = RawPtr_to(QUrl*, sfp[0]);
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

DummyQUrl::DummyQUrl()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQUrl::~DummyQUrl()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQUrl::setSelf(knh_RawPtr_t *ptr)
{
	DummyQUrl::self = ptr;
}

bool DummyQUrl::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQUrl::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUrl::event_map->bigin();
	if ((itr = DummyQUrl::event_map->find(str)) == DummyQUrl::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQUrl::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUrl::slot_map->bigin();
	if ((itr = DummyQUrl::slot_map->find(str)) == DummyQUrl::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQUrl::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQUrl::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQUrl::connection(QObject *o)
{
	QUrl *p = dynamic_cast<QUrl*>(o);
	if (p != NULL) {
	}
}

KQUrl::KQUrl() : QUrl()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQUrl();
}

KQUrl::~KQUrl()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QUrl_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUrl *qp = RawPtr_to(KQUrl *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QUrl]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUrl]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QUrl_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUrl *qp = RawPtr_to(KQUrl *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QUrl]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUrl]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QUrl_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQUrl *qp = (KQUrl *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QUrl*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QUrl_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQUrl *qp = (KQUrl *)p->rawptr;
		KQUrl *qp = static_cast<KQUrl*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QUrl_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QUrl*>(p1->rawptr) == *static_cast<QUrl*>(p2->rawptr) ? 0 : 1);
}

void KQUrl::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QUrlConstInt[] = {
	{"None", QUrl::None},
	{"RemoveScheme", QUrl::RemoveScheme},
	{"RemovePassword", QUrl::RemovePassword},
	{"RemoveUserInfo", QUrl::RemoveUserInfo},
	{"RemovePort", QUrl::RemovePort},
	{"RemoveAuthority", QUrl::RemoveAuthority},
	{"RemovePath", QUrl::RemovePath},
	{"RemoveQuery", QUrl::RemoveQuery},
	{"RemoveFragment", QUrl::RemoveFragment},
	{"StripTrailingSlash", QUrl::StripTrailingSlash},
	{"TolerantMode", QUrl::TolerantMode},
	{"StrictMode", QUrl::StrictMode},
	{NULL, 0}
};

DEFAPI(void) constQUrl(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QUrlConstInt);
}


DEFAPI(void) defQUrl(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUrl";
	cdef->free = QUrl_free;
	cdef->reftrace = QUrl_reftrace;
	cdef->compareTo = QUrl_compareTo;
}

//## QUrlFormattingOptions QUrlFormattingOptions.new(int value);
KMETHOD QUrlFormattingOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUrl::FormattingOption i = Int_to(QUrl::FormattingOption, sfp[1]);
	QUrl::FormattingOptions *ret_v = new QUrl::FormattingOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QUrlFormattingOptions QUrlFormattingOptions.and(int mask);
KMETHOD QUrlFormattingOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUrl::FormattingOptions *qp = RawPtr_to(QUrl::FormattingOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QUrl::FormattingOptions ret = ((*qp) & i);
		QUrl::FormattingOptions *ret_ = new QUrl::FormattingOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUrlFormattingOptions QUrlFormattingOptions.iand(QUrl::QUrlFormattingOptions other);
KMETHOD QUrlFormattingOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUrl::FormattingOptions *qp = RawPtr_to(QUrl::FormattingOptions*, sfp[0]);
	if (qp != NULL) {
		QUrl::FormattingOptions *other = RawPtr_to(QUrl::FormattingOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUrlFormattingOptions QUrlFormattingOptions.or(QUrlFormattingOptions f);
KMETHOD QUrlFormattingOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl::FormattingOptions *qp = RawPtr_to(QUrl::FormattingOptions*, sfp[0]);
	if (qp != NULL) {
		QUrl::FormattingOptions *f = RawPtr_to(QUrl::FormattingOptions*, sfp[1]);
		QUrl::FormattingOptions ret = ((*qp) | (*f));
		QUrl::FormattingOptions *ret_ = new QUrl::FormattingOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUrlFormattingOptions QUrlFormattingOptions.ior(QUrl::QUrlFormattingOptions other);
KMETHOD QUrlFormattingOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUrl::FormattingOptions *qp = RawPtr_to(QUrl::FormattingOptions*, sfp[0]);
	if (qp != NULL) {
		QUrl::FormattingOptions *other = RawPtr_to(QUrl::FormattingOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUrlFormattingOptions QUrlFormattingOptions.xor(QUrlFormattingOptions f);
KMETHOD QUrlFormattingOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrl::FormattingOptions *qp = RawPtr_to(QUrl::FormattingOptions*, sfp[0]);
	if (qp != NULL) {
		QUrl::FormattingOptions *f = RawPtr_to(QUrl::FormattingOptions*, sfp[1]);
		QUrl::FormattingOptions ret = ((*qp) ^ (*f));
		QUrl::FormattingOptions *ret_ = new QUrl::FormattingOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUrlFormattingOptions QUrlFormattingOptions.ixor(QUrl::QUrlFormattingOptions other);
KMETHOD QUrlFormattingOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUrl::FormattingOptions *qp = RawPtr_to(QUrl::FormattingOptions*, sfp[0]);
	if (qp != NULL) {
		QUrl::FormattingOptions *other = RawPtr_to(QUrl::FormattingOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QUrlFormattingOptions.testFlag(int flag);
KMETHOD QUrlFormattingOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUrl::FormattingOptions *qp = RawPtr_to(QUrl::FormattingOptions *, sfp[0]);
	if (qp != NULL) {
		QUrl::FormattingOption flag = Int_to(QUrl::FormattingOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QUrlFormattingOptions.value();
KMETHOD QUrlFormattingOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUrl::FormattingOptions *qp = RawPtr_to(QUrl::FormattingOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QUrlFormattingOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QUrl::FormattingOptions *qp = (QUrl::FormattingOptions *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QUrlFormattingOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QUrl::FormattingOptions *qp = (QUrl::FormattingOptions *)p->rawptr;
		(void)qp;
	}
}

static int QUrlFormattingOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QUrl::FormattingOptions*)p1->rawptr);
//		int v2 = int(*(QUrl::FormattingOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QUrl::FormattingOptions v1 = *(QUrl::FormattingOptions*)p1->rawptr;
		QUrl::FormattingOptions v2 = *(QUrl::FormattingOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQUrlFormattingOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUrlFormattingOptions";
	cdef->free = QUrlFormattingOptions_free;
	cdef->reftrace = QUrlFormattingOptions_reftrace;
	cdef->compareTo = QUrlFormattingOptions_compareTo;
}

