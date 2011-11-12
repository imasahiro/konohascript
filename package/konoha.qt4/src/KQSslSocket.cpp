//@Virtual @Override boolean QSslSocket.atEnd();
KMETHOD QSslSocket_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->atEnd();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QSslSocket.bytesAvailable();
KMETHOD QSslSocket_bytesAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesAvailable();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QSslSocket.bytesToWrite();
KMETHOD QSslSocket_bytesToWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesToWrite();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QSslSocket.canReadLine();
KMETHOD QSslSocket_canReadLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canReadLine();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override void QSslSocket.close();
KMETHOD QSslSocket_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QSslSocket.waitForBytesWritten(int msecs);
KMETHOD QSslSocket_waitForBytesWritten(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForBytesWritten(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QSslSocket.waitForReadyRead(int msecs);
KMETHOD QSslSocket_waitForReadyRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForReadyRead(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QSslSocket QSslSocket.new(QObject parent);
KMETHOD QSslSocket_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQSslSocket *ret_v = new KQSslSocket(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QSslSocket.abort();
KMETHOD QSslSocket_abort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qp->abort();
	}
	RETURNvoid_();
}

//void QSslSocket.addCaCertificate(QSslCertificate certificate);
KMETHOD QSslSocket_addCaCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QSslCertificate  certificate = *RawPtr_to(const QSslCertificate *, sfp[1]);
		qp->addCaCertificate(certificate);
	}
	RETURNvoid_();
}

//boolean QSslSocket.addCaCertificates(String path, int fmt, int syntax);
KMETHOD QSslSocket_addCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		QSsl::EncodingFormat format = Int_to(QSsl::EncodingFormat, sfp[2]);
		QRegExp::PatternSyntax syntax = Int_to(QRegExp::PatternSyntax, sfp[3]);
		bool ret_v = qp->addCaCertificates(path, format, syntax);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//void QSslSocket.addCaCertificates(Array<QSslCertificate> certificates);
KMETHOD QSslSocket_addCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslCertificate> certificates;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			certificates.append(*(QSslCertificate*)p->rawptr);
		}
		qp->addCaCertificates(certificates);
	}
	RETURNvoid_();
}
*/
//Array<QSslCertificate> QSslSocket.getCaCertificates();
KMETHOD QSslSocket_getCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QList<QSslCertificate> ret_v = qp->caCertificates();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCertificate"));
		for (int n = 0; n < list_size; n++) {
			QSslCertificate *ret_v_ = new QSslCertificate(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QSslCipher> QSslSocket.getCiphers();
KMETHOD QSslSocket_getCiphers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QList<QSslCipher> ret_v = qp->ciphers();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCipher"));
		for (int n = 0; n < list_size; n++) {
			QSslCipher *ret_v_ = new QSslCipher(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QSslSocket.connectToHostEncrypted(String hostName, int port, QIODeviceOpenMode mode);
KMETHOD QSslSocket_connectToHostEncrypted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QString hostName = String_to(const QString, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		initFlag(mode, QIODevice::OpenMode, sfp[3]);
		qp->connectToHostEncrypted(hostName, port, mode);
	}
	RETURNvoid_();
}

/*
//void QSslSocket.connectToHostEncrypted(String hostName, int port, String sslPeerName, QIODeviceOpenMode mode);
KMETHOD QSslSocket_connectToHostEncrypted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QString hostName = String_to(const QString, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		const QString sslPeerName = String_to(const QString, sfp[3]);
		initFlag(mode, QIODevice::OpenMode, sfp[4]);
		qp->connectToHostEncrypted(hostName, port, sslPeerName, mode);
	}
	RETURNvoid_();
}
*/
//int QSslSocket.encryptedBytesAvailable();
KMETHOD QSslSocket_encryptedBytesAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->encryptedBytesAvailable();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSslSocket.encryptedBytesToWrite();
KMETHOD QSslSocket_encryptedBytesToWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->encryptedBytesToWrite();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSslSocket.flush();
KMETHOD QSslSocket_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->flush();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSslSocket.ignoreSslErrors(Array<QSslError> errors);
KMETHOD QSslSocket_ignoreSslErrors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
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

//boolean QSslSocket.isEncrypted();
KMETHOD QSslSocket_isEncrypted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEncrypted();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QSslCertificate QSslSocket.getLocalCertificate();
KMETHOD QSslSocket_getLocalCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSslCertificate ret_v = qp->localCertificate();
		QSslCertificate *ret_v_ = new QSslCertificate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSslSocket.mode();
KMETHOD QSslSocket_mode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSslSocket::SslMode ret_v = qp->mode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSslCertificate QSslSocket.peerCertificate();
KMETHOD QSslSocket_peerCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSslCertificate ret_v = qp->peerCertificate();
		QSslCertificate *ret_v_ = new QSslCertificate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QSslCertificate> QSslSocket.peerCertificateChain();
KMETHOD QSslSocket_peerCertificateChain(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QList<QSslCertificate> ret_v = qp->peerCertificateChain();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCertificate"));
		for (int n = 0; n < list_size; n++) {
			QSslCertificate *ret_v_ = new QSslCertificate(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QSslSocket.getPeerVerifyDepth();
KMETHOD QSslSocket_getPeerVerifyDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		int ret_v = qp->peerVerifyDepth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSslSocket.getPeerVerifyMode();
KMETHOD QSslSocket_getPeerVerifyMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSslSocket::PeerVerifyMode ret_v = qp->peerVerifyMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSslKey QSslSocket.getPrivateKey();
KMETHOD QSslSocket_getPrivateKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSslKey ret_v = qp->privateKey();
		QSslKey *ret_v_ = new QSslKey(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSslSocket.getProtocol();
KMETHOD QSslSocket_getProtocol(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSsl::SslProtocol ret_v = qp->protocol();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSslCipher QSslSocket.sessionCipher();
KMETHOD QSslSocket_sessionCipher(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSslCipher ret_v = qp->sessionCipher();
		QSslCipher *ret_v_ = new QSslCipher(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QSslSocket.setCaCertificates(Array<QSslCertificate> certificates);
KMETHOD QSslSocket_setCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslCertificate> certificates;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			certificates.append(*(QSslCertificate*)p->rawptr);
		}
		qp->setCaCertificates(certificates);
	}
	RETURNvoid_();
}

//void QSslSocket.setCiphers(Array<QSslCipher> ciphers);
KMETHOD QSslSocket_setCiphers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslCipher> ciphers;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			ciphers.append(*(QSslCipher*)p->rawptr);
		}
		qp->setCiphers(ciphers);
	}
	RETURNvoid_();
}

/*
//void QSslSocket.setCiphers(String ciphers);
KMETHOD QSslSocket_setCiphers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QString ciphers = String_to(const QString, sfp[1]);
		qp->setCiphers(ciphers);
	}
	RETURNvoid_();
}
*/
//void QSslSocket.setLocalCertificate(QSslCertificate certificate);
KMETHOD QSslSocket_setLocalCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QSslCertificate  certificate = *RawPtr_to(const QSslCertificate *, sfp[1]);
		qp->setLocalCertificate(certificate);
	}
	RETURNvoid_();
}

/*
//void QSslSocket.setLocalCertificate(String path, int fmt);
KMETHOD QSslSocket_setLocalCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		QSsl::EncodingFormat format = Int_to(QSsl::EncodingFormat, sfp[2]);
		qp->setLocalCertificate(path, format);
	}
	RETURNvoid_();
}
*/
//void QSslSocket.setPeerVerifyDepth(int depth);
KMETHOD QSslSocket_setPeerVerifyDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		int depth = Int_to(int, sfp[1]);
		qp->setPeerVerifyDepth(depth);
	}
	RETURNvoid_();
}

//void QSslSocket.setPeerVerifyMode(int mode);
KMETHOD QSslSocket_setPeerVerifyMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSslSocket::PeerVerifyMode mode = Int_to(QSslSocket::PeerVerifyMode, sfp[1]);
		qp->setPeerVerifyMode(mode);
	}
	RETURNvoid_();
}

//void QSslSocket.setPrivateKey(QSslKey key);
KMETHOD QSslSocket_setPrivateKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QSslKey  key = *RawPtr_to(const QSslKey *, sfp[1]);
		qp->setPrivateKey(key);
	}
	RETURNvoid_();
}

/*
//void QSslSocket.setPrivateKey(String fileName, int algorithm, int fmt, QByteArray passPhrase);
KMETHOD QSslSocket_setPrivateKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		QSsl::KeyAlgorithm algorithm = Int_to(QSsl::KeyAlgorithm, sfp[2]);
		QSsl::EncodingFormat format = Int_to(QSsl::EncodingFormat, sfp[3]);
		const QByteArray  passPhrase = *RawPtr_to(const QByteArray *, sfp[4]);
		qp->setPrivateKey(fileName, algorithm, format, passPhrase);
	}
	RETURNvoid_();
}
*/
//void QSslSocket.setProtocol(int protocol);
KMETHOD QSslSocket_setProtocol(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSsl::SslProtocol protocol = Int_to(QSsl::SslProtocol, sfp[1]);
		qp->setProtocol(protocol);
	}
	RETURNvoid_();
}

//void QSslSocket.setReadBufferSize(int size);
KMETHOD QSslSocket_setReadBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qint64 size = Int_to(qint64, sfp[1]);
		qp->setReadBufferSize(size);
	}
	RETURNvoid_();
}

//boolean QSslSocket.setSocketDescriptor(int socketDescriptor, int state, QIODeviceOpenMode openMode);
KMETHOD QSslSocket_setSocketDescriptor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		int socketDescriptor = Int_to(int, sfp[1]);
		QSslSocket::SocketState state = Int_to(QSslSocket::SocketState, sfp[2]);
		initFlag(openMode, QIODevice::OpenMode, sfp[3]);
		bool ret_v = qp->setSocketDescriptor(socketDescriptor, state, openMode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSslSocket.setSocketOption(int option, QVariant value);
KMETHOD QSslSocket_setSocketOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketOption option = Int_to(QAbstractSocket::SocketOption, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setSocketOption(option, value);
	}
	RETURNvoid_();
}

//void QSslSocket.setSslConfiguration(QSslConfiguration configuration);
KMETHOD QSslSocket_setSslConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		const QSslConfiguration  configuration = *RawPtr_to(const QSslConfiguration *, sfp[1]);
		qp->setSslConfiguration(configuration);
	}
	RETURNvoid_();
}

//QVariant QSslSocket.getSocketOption(int option);
KMETHOD QSslSocket_getSocketOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketOption option = Int_to(QAbstractSocket::SocketOption, sfp[1]);
		QVariant ret_v = qp->socketOption(option);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSslConfiguration QSslSocket.getSslConfiguration();
KMETHOD QSslSocket_getSslConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QSslConfiguration ret_v = qp->sslConfiguration();
		QSslConfiguration *ret_v_ = new QSslConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QSslError> QSslSocket.sslErrors();
KMETHOD QSslSocket_sslErrors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		QList<QSslError> ret_v = qp->sslErrors();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslError"));
		for (int n = 0; n < list_size; n++) {
			QSslError *ret_v_ = new QSslError(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QSslSocket.waitForConnected(int msecs);
KMETHOD QSslSocket_waitForConnected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForConnected(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QSslSocket.waitForDisconnected(int msecs);
KMETHOD QSslSocket_waitForDisconnected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForDisconnected(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QSslSocket.waitForEncrypted(int msecs);
KMETHOD QSslSocket_waitForEncrypted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForEncrypted(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSslSocket.addDefaultCaCertificate(QSslCertificate certificate);
KMETHOD QSslSocket_addDefaultCaCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QSslCertificate  certificate = *RawPtr_to(const QSslCertificate *, sfp[1]);
		QSslSocket::addDefaultCaCertificate(certificate);
	}
	RETURNvoid_();
}

//boolean QSslSocket.addDefaultCaCertificates(String path, int encoding, int syntax);
KMETHOD QSslSocket_addDefaultCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QSsl::EncodingFormat encoding = Int_to(QSsl::EncodingFormat, sfp[2]);
		QRegExp::PatternSyntax syntax = Int_to(QRegExp::PatternSyntax, sfp[3]);
		bool ret_v = QSslSocket::addDefaultCaCertificates(path, encoding, syntax);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//void QSslSocket.addDefaultCaCertificates(Array<QSslCertificate> certificates);
KMETHOD QSslSocket_addDefaultCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslCertificate> certificates;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			certificates.append(*(QSslCertificate*)p->rawptr);
		}
		QSslSocket::addDefaultCaCertificates(certificates);
	}
	RETURNvoid_();
}
*/
//Array<QSslCertificate> QSslSocket.getDefaultCaCertificates();
KMETHOD QSslSocket_getDefaultCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QSslCertificate> ret_v = QSslSocket::defaultCaCertificates();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCertificate"));
		for (int n = 0; n < list_size; n++) {
			QSslCertificate *ret_v_ = new QSslCertificate(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QSslCipher> QSslSocket.getDefaultCiphers();
KMETHOD QSslSocket_getDefaultCiphers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QSslCipher> ret_v = QSslSocket::defaultCiphers();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCipher"));
		for (int n = 0; n < list_size; n++) {
			QSslCipher *ret_v_ = new QSslCipher(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QSslSocket.setDefaultCaCertificates(Array<QSslCertificate> certificates);
KMETHOD QSslSocket_setDefaultCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslCertificate> certificates;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			certificates.append(*(QSslCertificate*)p->rawptr);
		}
		QSslSocket::setDefaultCaCertificates(certificates);
	}
	RETURNvoid_();
}

//void QSslSocket.setDefaultCiphers(Array<QSslCipher> ciphers);
KMETHOD QSslSocket_setDefaultCiphers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslCipher> ciphers;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			ciphers.append(*(QSslCipher*)p->rawptr);
		}
		QSslSocket::setDefaultCiphers(ciphers);
	}
	RETURNvoid_();
}

//Array<QSslCipher> QSslSocket.supportedCiphers();
KMETHOD QSslSocket_supportedCiphers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QSslCipher> ret_v = QSslSocket::supportedCiphers();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCipher"));
		for (int n = 0; n < list_size; n++) {
			QSslCipher *ret_v_ = new QSslCipher(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QSslSocket.supportsSsl();
KMETHOD QSslSocket_supportsSsl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QSslSocket::supportsSsl();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<QSslCertificate> QSslSocket.systemCaCertificates();
KMETHOD QSslSocket_systemCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QSslCertificate> ret_v = QSslSocket::systemCaCertificates();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCertificate"));
		for (int n = 0; n < list_size; n++) {
			QSslCertificate *ret_v_ = new QSslCertificate(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

/*
//void QSslSocket.ignoreSslErrors();
KMETHOD QSslSocket_ignoreSslErrors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qp->ignoreSslErrors();
	}
	RETURNvoid_();
}
*/
//void QSslSocket.startClientEncryption();
KMETHOD QSslSocket_startClientEncryption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qp->startClientEncryption();
	}
	RETURNvoid_();
}

//void QSslSocket.startServerEncryption();
KMETHOD QSslSocket_startServerEncryption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslSocket *  qp = RawPtr_to(QSslSocket *, sfp[0]);
	if (qp) {
		qp->startServerEncryption();
	}
	RETURNvoid_();
}


DummyQSslSocket::DummyQSslSocket()
{
	self = NULL;
	encrypted_func = NULL;
	encrypted_bytes_written_func = NULL;
	mode_changed_func = NULL;
	peer_verify_error_func = NULL;
	ssl_errors_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("encrypted", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("encrypted-bytes-written", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("mode-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("peer-verify-error", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ssl-errors", NULL));
}

void DummyQSslSocket::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSslSocket::self = ptr;
	DummyQTcpSocket::setSelf(ptr);
}

bool DummyQSslSocket::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTcpSocket::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSslSocket::encryptedSlot()
{
	if (encrypted_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, encrypted_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQSslSocket::encryptedBytesWrittenSlot(qint64 written)
{
	if (encrypted_bytes_written_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, qint64, written);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, encrypted_bytes_written_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQSslSocket::modeChangedSlot(QSslSocket::SslMode mode)
{
	if (mode_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = mode;
		knh_Func_invoke(lctx, mode_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQSslSocket::peerVerifyErrorSlot(const QSslError error)
{
	if (peer_verify_error_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QSslError, error);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, peer_verify_error_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQSslSocket::sslErrorsSlot(const QList<QSslError> errors)
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

bool DummyQSslSocket::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslSocket::event_map->bigin();
	if ((itr = DummyQSslSocket::event_map->find(str)) == DummyQSslSocket::event_map->end()) {
		bool ret = false;
		ret = DummyQTcpSocket::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSslSocket::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslSocket::slot_map->bigin();
	if ((itr = DummyQSslSocket::slot_map->find(str)) == DummyQSslSocket::slot_map->end()) {
		bool ret = false;
		ret = DummyQTcpSocket::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		encrypted_func = (*slot_map)["encrypted"];
		encrypted_bytes_written_func = (*slot_map)["encrypted-bytes-written"];
		mode_changed_func = (*slot_map)["mode-changed"];
		peer_verify_error_func = (*slot_map)["peer-verify-error"];
		ssl_errors_func = (*slot_map)["ssl-errors"];
		return true;
	}
}

knh_Object_t** DummyQSslSocket::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSslSocket::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 5;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, encrypted_func);
	KNH_ADDNNREF(ctx, encrypted_bytes_written_func);
	KNH_ADDNNREF(ctx, mode_changed_func);
	KNH_ADDNNREF(ctx, peer_verify_error_func);
	KNH_ADDNNREF(ctx, ssl_errors_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQTcpSocket::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQSslSocket::connection(QObject *o)
{
	QSslSocket *p = dynamic_cast<QSslSocket*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(encrypted()), this, SLOT(encryptedSlot()));
		connect(p, SIGNAL(encryptedBytesWritten(qint64)), this, SLOT(encryptedBytesWrittenSlot(qint64)));
		connect(p, SIGNAL(modeChanged(QSslSocket::SslMode)), this, SLOT(modeChangedSlot(QSslSocket::SslMode)));
		connect(p, SIGNAL(peerVerifyError(const QSslError)), this, SLOT(peerVerifyErrorSlot(const QSslError)));
		connect(p, SIGNAL(sslErrors(const QList<QSslError>)), this, SLOT(sslErrorsSlot(const QList<QSslError>)));
	}
	DummyQTcpSocket::connection(o);
}

KQSslSocket::KQSslSocket(QObject* parent) : QSslSocket(parent)
{
	self = NULL;
	dummy = new DummyQSslSocket();
	dummy->connection((QObject*)this);
}

KMETHOD QSslSocket_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslSocket *qp = RawPtr_to(KQSslSocket *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSslSocket]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslSocket]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSslSocket_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslSocket *qp = RawPtr_to(KQSslSocket *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSslSocket]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslSocket]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSslSocket_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSslSocket *qp = (KQSslSocket *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSslSocket_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSslSocket *qp = (KQSslSocket *)p->rawptr;
//		KQSslSocket *qp = static_cast<KQSslSocket*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSslSocket_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSslSocket::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSslSocket::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSslSocket::event(event);
		return false;
	}
//	QSslSocket::event(event);
	return true;
}

static knh_IntData_t QSslSocketConstInt[] = {
	{"VerifyNone", QSslSocket::VerifyNone},
	{"QueryPeer", QSslSocket::QueryPeer},
	{"VerifyPeer", QSslSocket::VerifyPeer},
	{"AutoVerifyPeer", QSslSocket::AutoVerifyPeer},
	{"UnencryptedMode", QSslSocket::UnencryptedMode},
	{"SslClientMode", QSslSocket::SslClientMode},
	{"SslServerMode", QSslSocket::SslServerMode},
	{NULL, 0}
};

DEFAPI(void) constQSslSocket(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSslSocketConstInt);
}


DEFAPI(void) defQSslSocket(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSslSocket";
	cdef->free = QSslSocket_free;
	cdef->reftrace = QSslSocket_reftrace;
	cdef->compareTo = QSslSocket_compareTo;
}


