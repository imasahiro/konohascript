//@Virtual @Override void QNetworkReply.close();
KMETHOD QNetworkReply_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//@Virtual void QNetworkReply.abort();
KMETHOD QNetworkReply_abort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		qp->abort();
	}
	RETURNvoid_();
}

//QVariant QNetworkReply.attribute(int code);
KMETHOD QNetworkReply_attribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QNetworkRequest::Attribute code = Int_to(QNetworkRequest::Attribute, sfp[1]);
		QVariant ret_v = qp->attribute(code);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkReply.error();
KMETHOD QNetworkReply_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QNetworkReply::NetworkError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QNetworkReply.hasRawHeader(QByteArray headerName);
KMETHOD QNetworkReply_hasRawHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		const QByteArray  headerName = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->hasRawHeader(headerName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QVariant QNetworkReply.header(int header);
KMETHOD QNetworkReply_header(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QNetworkRequest::KnownHeaders header = Int_to(QNetworkRequest::KnownHeaders, sfp[1]);
		QVariant ret_v = qp->header(header);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QNetworkReply.ignoreSslErrors(Array<QSslError> errors);
KMETHOD QNetworkReply_ignoreSslErrors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslError> errors;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			errors.append(*(QSslError*)p->rawptr);
		}
		qp->ignoreSslErrors(errors);
	}
	RETURNvoid_();
}

//boolean QNetworkReply.isFinished();
KMETHOD QNetworkReply_isFinished(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFinished();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QNetworkReply.isRunning();
KMETHOD QNetworkReply_isRunning(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isRunning();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QNetworkAccessManager QNetworkReply.manager();
KMETHOD QNetworkReply_manager(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QNetworkAccessManager* ret_v = qp->manager();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkAccessManager*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkReply.operation();
KMETHOD QNetworkReply_operation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QNetworkAccessManager::Operation ret_v = qp->operation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QByteArray QNetworkReply.rawHeader(QByteArray headerName);
KMETHOD QNetworkReply_rawHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		const QByteArray  headerName = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = qp->rawHeader(headerName);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QByteArray> QNetworkReply.rawHeaderList();
KMETHOD QNetworkReply_rawHeaderList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QList<QByteArray> ret_v = qp->rawHeaderList();
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
	

//int QNetworkReply.getReadBufferSize();
KMETHOD QNetworkReply_getReadBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->readBufferSize();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkRequest QNetworkReply.request();
KMETHOD QNetworkReply_request(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QNetworkRequest ret_v = qp->request();
		QNetworkRequest *ret_v_ = new QNetworkRequest(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QNetworkReply.setReadBufferSize(int size);
KMETHOD QNetworkReply_setReadBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		qint64 size = Int_to(qint64, sfp[1]);
		qp->setReadBufferSize(size);
	}
	RETURNvoid_();
}

//void QNetworkReply.setSslConfiguration(QSslConfiguration config);
KMETHOD QNetworkReply_setSslConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		const QSslConfiguration  config = *RawPtr_to(const QSslConfiguration *, sfp[1]);
		qp->setSslConfiguration(config);
	}
	RETURNvoid_();
}

//QSslConfiguration QNetworkReply.getSslConfiguration();
KMETHOD QNetworkReply_getSslConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QSslConfiguration ret_v = qp->sslConfiguration();
		QSslConfiguration *ret_v_ = new QSslConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QNetworkReply.url();
KMETHOD QNetworkReply_url(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->url();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//@Virtual void QNetworkReply.ignoreSslErrors();
KMETHOD QNetworkReply_ignoreSslErrors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkReply *  qp = RawPtr_to(QNetworkReply *, sfp[0]);
	if (qp) {
		qp->ignoreSslErrors();
	}
	RETURNvoid_();
}
*/

DummyQNetworkReply::DummyQNetworkReply()
{
	self = NULL;
	download_progress_func = NULL;
	error_func = NULL;
	finished_func = NULL;
	meta_data_changed_func = NULL;
	ssl_errors_func = NULL;
	upload_progress_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("download-progress", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("error", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("meta-data-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ssl-errors", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("upload-progress", NULL));
}

void DummyQNetworkReply::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkReply::self = ptr;
	DummyQIODevice::setSelf(ptr);
}

bool DummyQNetworkReply::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQIODevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQNetworkReply::downloadProgressSlot(qint64 bytesReceived, qint64 bytesTotal)
{
	if (download_progress_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, qint64, bytesReceived);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, qint64, bytesTotal);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, download_progress_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQNetworkReply::errorSlot(QNetworkReply::NetworkError code)
{
	if (error_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = code;
		knh_Func_invoke(lctx, error_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkReply::finishedSlot()
{
	if (finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, finished_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQNetworkReply::metaDataChangedSlot()
{
	if (meta_data_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, meta_data_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQNetworkReply::sslErrorsSlot(const QList<QSslError> errors)
{
	if (ssl_errors_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		int size = errors.length();
		knh_Array_t *p1 = new_Array0(lctx, size);
		knh_class_t cid = knh_getcid(lctx, STEXT("QSslError"));
		for (int i = 0; i < size; i++) {
			QSslError *errors_ = new QSslError(errors[i]);
			knh_RawPtr_t *p = new_RawPtr(lctx, lctx->share->ClassTBL[cid], errors_);
			knh_Array_add(lctx, p1, UPCAST(p));
		}
		knh_Func_invoke(lctx, ssl_errors_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkReply::uploadProgressSlot(qint64 bytesSent, qint64 bytesTotal)
{
	if (upload_progress_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, qint64, bytesSent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, qint64, bytesTotal);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, upload_progress_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQNetworkReply::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkReply::event_map->bigin();
	if ((itr = DummyQNetworkReply::event_map->find(str)) == DummyQNetworkReply::event_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkReply::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkReply::slot_map->bigin();
	if ((itr = DummyQNetworkReply::slot_map->find(str)) == DummyQNetworkReply::slot_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		download_progress_func = (*slot_map)["download-progress"];
		error_func = (*slot_map)["error"];
		finished_func = (*slot_map)["finished"];
		meta_data_changed_func = (*slot_map)["meta-data-changed"];
		ssl_errors_func = (*slot_map)["ssl-errors"];
		upload_progress_func = (*slot_map)["upload-progress"];
		return true;
	}
}

void DummyQNetworkReply::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 6;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, download_progress_func);
	KNH_ADDNNREF(ctx, error_func);
	KNH_ADDNNREF(ctx, finished_func);
	KNH_ADDNNREF(ctx, meta_data_changed_func);
	KNH_ADDNNREF(ctx, ssl_errors_func);
	KNH_ADDNNREF(ctx, upload_progress_func);

	KNH_SIZEREF(ctx);

	DummyQIODevice::reftrace(ctx, p, tail_);
}

void DummyQNetworkReply::connection(QObject *o)
{
	QNetworkReply *p = dynamic_cast<QNetworkReply*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgressSlot(qint64, qint64)));
		connect(p, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(errorSlot(QNetworkReply::NetworkError)));
		connect(p, SIGNAL(finished()), this, SLOT(finishedSlot()));
		connect(p, SIGNAL(metaDataChanged()), this, SLOT(metaDataChangedSlot()));
		connect(p, SIGNAL(sslErrors(const QList<QSslError>)), this, SLOT(sslErrorsSlot(const QList<QSslError>)));
		connect(p, SIGNAL(uploadProgress(qint64, qint64)), this, SLOT(uploadProgressSlot(qint64, qint64)));
	}
	DummyQIODevice::connection(o);
}

KMETHOD QNetworkReply_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkReply *qp = RawPtr_to(KQNetworkReply *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkReply]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkReply]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkReply_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkReply *qp = RawPtr_to(KQNetworkReply *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkReply]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkReply]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkReply_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQNetworkReply *qp = (KQNetworkReply *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QNetworkReply_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQNetworkReply *qp = (KQNetworkReply *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkReply_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQNetworkReply::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQNetworkReply::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QNetworkReply::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QNetworkReplyConstInt[] = {
	{"NoError", QNetworkReply::NoError},
	{"ConnectionRefusedError", QNetworkReply::ConnectionRefusedError},
	{"RemoteHostClosedError", QNetworkReply::RemoteHostClosedError},
	{"HostNotFoundError", QNetworkReply::HostNotFoundError},
	{"TimeoutError", QNetworkReply::TimeoutError},
	{"OperationCanceledError", QNetworkReply::OperationCanceledError},
	{"SslHandshakeFailedError", QNetworkReply::SslHandshakeFailedError},
	{"TemporaryNetworkFailureError", QNetworkReply::TemporaryNetworkFailureError},
	{"ProxyConnectionRefusedError", QNetworkReply::ProxyConnectionRefusedError},
	{"ProxyConnectionClosedError", QNetworkReply::ProxyConnectionClosedError},
	{"ProxyNotFoundError", QNetworkReply::ProxyNotFoundError},
	{"ProxyTimeoutError", QNetworkReply::ProxyTimeoutError},
	{"ProxyAuthenticationRequiredError", QNetworkReply::ProxyAuthenticationRequiredError},
	{"ContentAccessDenied", QNetworkReply::ContentAccessDenied},
	{"ContentOperationNotPermittedError", QNetworkReply::ContentOperationNotPermittedError},
	{"ContentNotFoundError", QNetworkReply::ContentNotFoundError},
	{"AuthenticationRequiredError", QNetworkReply::AuthenticationRequiredError},
	{"ContentReSendError", QNetworkReply::ContentReSendError},
	{"ProtocolUnknownError", QNetworkReply::ProtocolUnknownError},
	{"ProtocolInvalidOperationError", QNetworkReply::ProtocolInvalidOperationError},
	{"UnknownNetworkError", QNetworkReply::UnknownNetworkError},
	{"UnknownProxyError", QNetworkReply::UnknownProxyError},
	{"UnknownContentError", QNetworkReply::UnknownContentError},
	{"ProtocolFailure", QNetworkReply::ProtocolFailure},
	{NULL, 0}
};

DEFAPI(void) constQNetworkReply(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkReplyConstInt);
}


DEFAPI(void) defQNetworkReply(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkReply";
	cdef->free = QNetworkReply_free;
	cdef->reftrace = QNetworkReply_reftrace;
	cdef->compareTo = QNetworkReply_compareTo;
}


