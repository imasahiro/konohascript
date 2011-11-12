//QGLShaderProgram QGLShaderProgram.new(QObject parent);
KMETHOD QGLShaderProgram_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGLShaderProgram *ret_v = new KQGLShaderProgram(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLShaderProgram QGLShaderProgram.new(QGLContext context, QObject parent);
KMETHOD QGLShaderProgram_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QGLContext*  context = RawPtr_to(const QGLContext*, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQGLShaderProgram *ret_v = new KQGLShaderProgram(context, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QGLShaderProgram.addShader(QGLShader shader);
KMETHOD QGLShaderProgram_addShader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		QGLShader*  shader = RawPtr_to(QGLShader*, sfp[1]);
		bool ret_v = qp->addShader(shader);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGLShaderProgram.addShaderFromSourceCode(int type, String source);
KMETHOD QGLShaderProgram_addShaderFromSourceCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		QGLShader::ShaderType type = Int_to(QGLShader::ShaderType, sfp[1]);
		const char*  source = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->addShaderFromSourceCode(type, source);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QGLShaderProgram.addShaderFromSourceCode(int type, QByteArray source);
KMETHOD QGLShaderProgram_addShaderFromSourceCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		QGLShader::ShaderType type = Int_to(QGLShader::ShaderType, sfp[1]);
		const QByteArray  source = *RawPtr_to(const QByteArray *, sfp[2]);
		bool ret_v = qp->addShaderFromSourceCode(type, source);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QGLShaderProgram.addShaderFromSourceCode(int type, String source);
KMETHOD QGLShaderProgram_addShaderFromSourceCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		QGLShader::ShaderType type = Int_to(QGLShader::ShaderType, sfp[1]);
		const QString source = String_to(const QString, sfp[2]);
		bool ret_v = qp->addShaderFromSourceCode(type, source);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QGLShaderProgram.addShaderFromSourceFile(int type, String fileName);
KMETHOD QGLShaderProgram_addShaderFromSourceFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		QGLShader::ShaderType type = Int_to(QGLShader::ShaderType, sfp[1]);
		const QString fileName = String_to(const QString, sfp[2]);
		bool ret_v = qp->addShaderFromSourceFile(type, fileName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLShaderProgram.attributeLocation(String name);
KMETHOD QGLShaderProgram_attributeLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->attributeLocation(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QGLShaderProgram.attributeLocation(QByteArray name);
KMETHOD QGLShaderProgram_attributeLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const QByteArray  name = *RawPtr_to(const QByteArray *, sfp[1]);
		int ret_v = qp->attributeLocation(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QGLShaderProgram.attributeLocation(String name);
KMETHOD QGLShaderProgram_attributeLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		int ret_v = qp->attributeLocation(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//boolean QGLShaderProgram.bind();
KMETHOD QGLShaderProgram_bind(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		bool ret_v = qp->bind();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLShaderProgram.bindAttributeLocation(String name, int location);
KMETHOD QGLShaderProgram_bindAttributeLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		int location = Int_to(int, sfp[2]);
		qp->bindAttributeLocation(name, location);
	}
	RETURNvoid_();
}

/*
//void QGLShaderProgram.bindAttributeLocation(QByteArray name, int location);
KMETHOD QGLShaderProgram_bindAttributeLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const QByteArray  name = *RawPtr_to(const QByteArray *, sfp[1]);
		int location = Int_to(int, sfp[2]);
		qp->bindAttributeLocation(name, location);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.bindAttributeLocation(String name, int location);
KMETHOD QGLShaderProgram_bindAttributeLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		int location = Int_to(int, sfp[2]);
		qp->bindAttributeLocation(name, location);
	}
	RETURNvoid_();
}
*/
//void QGLShaderProgram.disableAttributeArray(int location);
KMETHOD QGLShaderProgram_disableAttributeArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		qp->disableAttributeArray(location);
	}
	RETURNvoid_();
}

/*
//void QGLShaderProgram.disableAttributeArray(String name);
KMETHOD QGLShaderProgram_disableAttributeArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		qp->disableAttributeArray(name);
	}
	RETURNvoid_();
}
*/
//void QGLShaderProgram.enableAttributeArray(int location);
KMETHOD QGLShaderProgram_enableAttributeArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		qp->enableAttributeArray(location);
	}
	RETURNvoid_();
}

/*
//void QGLShaderProgram.enableAttributeArray(String name);
KMETHOD QGLShaderProgram_enableAttributeArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		qp->enableAttributeArray(name);
	}
	RETURNvoid_();
}
*/
//GLenum QGLShaderProgram.getGeometryInputType();
KMETHOD QGLShaderProgram_getGeometryInputType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		GLenum ret_v = qp->geometryInputType();
		GLenum *ret_v_ = new GLenum(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//GLenum QGLShaderProgram.getGeometryOutputType();
KMETHOD QGLShaderProgram_getGeometryOutputType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		GLenum ret_v = qp->geometryOutputType();
		GLenum *ret_v_ = new GLenum(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGLShaderProgram.getGeometryOutputVertexCount();
KMETHOD QGLShaderProgram_getGeometryOutputVertexCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int ret_v = qp->geometryOutputVertexCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLShaderProgram.isLinked();
KMETHOD QGLShaderProgram_isLinked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isLinked();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QGLShaderProgram.link();
KMETHOD QGLShaderProgram_link(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		bool ret_v = qp->link();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QGLShaderProgram.log();
KMETHOD QGLShaderProgram_log(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		QString ret_v = qp->log();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGLShaderProgram.maxGeometryOutputVertices();
KMETHOD QGLShaderProgram_maxGeometryOutputVertices(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxGeometryOutputVertices();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//GLuint QGLShaderProgram.programId();
KMETHOD QGLShaderProgram_programId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		GLuint ret_v = qp->programId();
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLShaderProgram.release();
KMETHOD QGLShaderProgram_release(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		qp->release();
	}
	RETURNvoid_();
}

//void QGLShaderProgram.removeAllShaders();
KMETHOD QGLShaderProgram_removeAllShaders(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		qp->removeAllShaders();
	}
	RETURNvoid_();
}

//void QGLShaderProgram.removeShader(QGLShader shader);
KMETHOD QGLShaderProgram_removeShader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		QGLShader*  shader = RawPtr_to(QGLShader*, sfp[1]);
		qp->removeShader(shader);
	}
	RETURNvoid_();
}

//void QGLShaderProgram.setAttributeArray(int location, GLfloat values, int tupleSize, int stride);
KMETHOD QGLShaderProgram_setAttributeArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const GLfloat*  values = RawPtr_to(const GLfloat*, sfp[2]);
		int tupleSize = Int_to(int, sfp[3]);
		int stride = Int_to(int, sfp[4]);
		qp->setAttributeArray(location, values, tupleSize, stride);
	}
	RETURNvoid_();
}

/*
//void QGLShaderProgram.setAttributeArray(int location, GLenum type, void values, int tupleSize, int stride);
KMETHOD QGLShaderProgram_setAttributeArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLenum  type = *RawPtr_to(GLenum *, sfp[2]);
		const void*  values = RawPtr_to(const void*, sfp[3]);
		int tupleSize = Int_to(int, sfp[4]);
		int stride = Int_to(int, sfp[5]);
		qp->setAttributeArray(location, type, values, tupleSize, stride);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeArray(String name, GLfloat values, int tupleSize, int stride);
KMETHOD QGLShaderProgram_setAttributeArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const GLfloat*  values = RawPtr_to(const GLfloat*, sfp[2]);
		int tupleSize = Int_to(int, sfp[3]);
		int stride = Int_to(int, sfp[4]);
		qp->setAttributeArray(name, values, tupleSize, stride);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeArray(String name, GLenum type, void values, int tupleSize, int stride);
KMETHOD QGLShaderProgram_setAttributeArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLenum  type = *RawPtr_to(GLenum *, sfp[2]);
		const void*  values = RawPtr_to(const void*, sfp[3]);
		int tupleSize = Int_to(int, sfp[4]);
		int stride = Int_to(int, sfp[5]);
		qp->setAttributeArray(name, type, values, tupleSize, stride);
	}
	RETURNvoid_();
}
*/
//void QGLShaderProgram.setAttributeBuffer(int location, GLenum type, int offset, int tupleSize, int stride);
KMETHOD QGLShaderProgram_setAttributeBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLenum  type = *RawPtr_to(GLenum *, sfp[2]);
		int offset = Int_to(int, sfp[3]);
		int tupleSize = Int_to(int, sfp[4]);
		int stride = Int_to(int, sfp[5]);
		qp->setAttributeBuffer(location, type, offset, tupleSize, stride);
	}
	RETURNvoid_();
}

/*
//void QGLShaderProgram.setAttributeBuffer(String name, GLenum type, int offset, int tupleSize, int stride);
KMETHOD QGLShaderProgram_setAttributeBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLenum  type = *RawPtr_to(GLenum *, sfp[2]);
		int offset = Int_to(int, sfp[3]);
		int tupleSize = Int_to(int, sfp[4]);
		int stride = Int_to(int, sfp[5]);
		qp->setAttributeBuffer(name, type, offset, tupleSize, stride);
	}
	RETURNvoid_();
}
*/
//void QGLShaderProgram.setAttributeValue(int location, GLfloat value);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLfloat  value = *RawPtr_to(GLfloat *, sfp[2]);
		qp->setAttributeValue(location, value);
	}
	RETURNvoid_();
}

/*
//void QGLShaderProgram.setAttributeValue(int location, GLfloat x, GLfloat y);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		qp->setAttributeValue(location, x, y);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(int location, GLfloat x, GLfloat y, GLfloat z);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		GLfloat  z = *RawPtr_to(GLfloat *, sfp[4]);
		qp->setAttributeValue(location, x, y, z);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(int location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		GLfloat  z = *RawPtr_to(GLfloat *, sfp[4]);
		GLfloat  w = *RawPtr_to(GLfloat *, sfp[5]);
		qp->setAttributeValue(location, x, y, z, w);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(int location, QColor value);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QColor  value = *RawPtr_to(const QColor *, sfp[2]);
		qp->setAttributeValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(int location, GLfloat values, int columns, int rows);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const GLfloat*  values = RawPtr_to(const GLfloat*, sfp[2]);
		int columns = Int_to(int, sfp[3]);
		int rows = Int_to(int, sfp[4]);
		qp->setAttributeValue(location, values, columns, rows);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(String name, GLfloat value);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLfloat  value = *RawPtr_to(GLfloat *, sfp[2]);
		qp->setAttributeValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(String name, GLfloat x, GLfloat y);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		qp->setAttributeValue(name, x, y);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(String name, GLfloat x, GLfloat y, GLfloat z);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		GLfloat  z = *RawPtr_to(GLfloat *, sfp[4]);
		qp->setAttributeValue(name, x, y, z);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(String name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		GLfloat  z = *RawPtr_to(GLfloat *, sfp[4]);
		GLfloat  w = *RawPtr_to(GLfloat *, sfp[5]);
		qp->setAttributeValue(name, x, y, z, w);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(String name, QColor value);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QColor  value = *RawPtr_to(const QColor *, sfp[2]);
		qp->setAttributeValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setAttributeValue(String name, GLfloat values, int columns, int rows);
KMETHOD QGLShaderProgram_setAttributeValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const GLfloat*  values = RawPtr_to(const GLfloat*, sfp[2]);
		int columns = Int_to(int, sfp[3]);
		int rows = Int_to(int, sfp[4]);
		qp->setAttributeValue(name, values, columns, rows);
	}
	RETURNvoid_();
}
*/
//void QGLShaderProgram.setGeometryInputType(GLenum inputType);
KMETHOD QGLShaderProgram_setGeometryInputType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		GLenum  inputType = *RawPtr_to(GLenum *, sfp[1]);
		qp->setGeometryInputType(inputType);
	}
	RETURNvoid_();
}

//void QGLShaderProgram.setGeometryOutputType(GLenum outputType);
KMETHOD QGLShaderProgram_setGeometryOutputType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		GLenum  outputType = *RawPtr_to(GLenum *, sfp[1]);
		qp->setGeometryOutputType(outputType);
	}
	RETURNvoid_();
}

//void QGLShaderProgram.setGeometryOutputVertexCount(int count);
KMETHOD QGLShaderProgram_setGeometryOutputVertexCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int count = Int_to(int, sfp[1]);
		qp->setGeometryOutputVertexCount(count);
	}
	RETURNvoid_();
}

//void QGLShaderProgram.setUniformValue(int location, GLfloat value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLfloat  value = *RawPtr_to(GLfloat *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}

/*
//void QGLShaderProgram.setUniformValue(String name, QPointF point);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[2]);
		qp->setUniformValue(name, point);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QSize size);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QSize  size = *RawPtr_to(const QSize *, sfp[2]);
		qp->setUniformValue(name, size);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QSizeF size);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[2]);
		qp->setUniformValue(name, size);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix2x2 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix2x2  value = *RawPtr_to(const QMatrix2x2 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix2x3 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix2x3  value = *RawPtr_to(const QMatrix2x3 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix2x4 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix2x4  value = *RawPtr_to(const QMatrix2x4 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix3x2 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix3x2  value = *RawPtr_to(const QMatrix3x2 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix3x3 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix3x3  value = *RawPtr_to(const QMatrix3x3 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix3x4 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix3x4  value = *RawPtr_to(const QMatrix3x4 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix4x2 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix4x2  value = *RawPtr_to(const QMatrix4x2 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix4x3 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix4x3  value = *RawPtr_to(const QMatrix4x3 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QMatrix4x4 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix4x4  value = *RawPtr_to(const QMatrix4x4 *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, GLfloat[2][2] value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const GLfloat[2][2]  value = *RawPtr_to(const GLfloat[2][2] *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, GLfloat[3][3] value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const GLfloat[3][3]  value = *RawPtr_to(const GLfloat[3][3] *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, GLfloat[4][4] value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const GLfloat[4][4]  value = *RawPtr_to(const GLfloat[4][4] *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLfloat[2][2] value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const GLfloat[2][2]  value = *RawPtr_to(const GLfloat[2][2] *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLfloat[3][3] value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const GLfloat[3][3]  value = *RawPtr_to(const GLfloat[3][3] *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLfloat[4][4] value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const GLfloat[4][4]  value = *RawPtr_to(const GLfloat[4][4] *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QTransform value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QTransform  value = *RawPtr_to(const QTransform *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, GLint value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLint  value = *RawPtr_to(GLint *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, GLuint value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLuint  value = *RawPtr_to(GLuint *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, GLfloat x, GLfloat y);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		qp->setUniformValue(location, x, y);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, GLfloat x, GLfloat y, GLfloat z);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		GLfloat  z = *RawPtr_to(GLfloat *, sfp[4]);
		qp->setUniformValue(location, x, y, z);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		GLfloat  z = *RawPtr_to(GLfloat *, sfp[4]);
		GLfloat  w = *RawPtr_to(GLfloat *, sfp[5]);
		qp->setUniformValue(location, x, y, z, w);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QColor color);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[2]);
		qp->setUniformValue(location, color);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QPoint point);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[2]);
		qp->setUniformValue(location, point);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QPointF point);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[2]);
		qp->setUniformValue(location, point);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QSize size);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QSize  size = *RawPtr_to(const QSize *, sfp[2]);
		qp->setUniformValue(location, size);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QSizeF size);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[2]);
		qp->setUniformValue(location, size);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix2x2 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix2x2  value = *RawPtr_to(const QMatrix2x2 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix2x3 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix2x3  value = *RawPtr_to(const QMatrix2x3 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix2x4 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix2x4  value = *RawPtr_to(const QMatrix2x4 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix3x2 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix3x2  value = *RawPtr_to(const QMatrix3x2 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix3x3 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix3x3  value = *RawPtr_to(const QMatrix3x3 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix3x4 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix3x4  value = *RawPtr_to(const QMatrix3x4 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix4x2 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix4x2  value = *RawPtr_to(const QMatrix4x2 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix4x3 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix4x3  value = *RawPtr_to(const QMatrix4x3 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QMatrix4x4 value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix4x4  value = *RawPtr_to(const QMatrix4x4 *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(int location, QTransform value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QTransform  value = *RawPtr_to(const QTransform *, sfp[2]);
		qp->setUniformValue(location, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLfloat value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLfloat  value = *RawPtr_to(GLfloat *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLint value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLint  value = *RawPtr_to(GLint *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLuint value);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLuint  value = *RawPtr_to(GLuint *, sfp[2]);
		qp->setUniformValue(name, value);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLfloat x, GLfloat y);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		qp->setUniformValue(name, x, y);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLfloat x, GLfloat y, GLfloat z);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		GLfloat  z = *RawPtr_to(GLfloat *, sfp[4]);
		qp->setUniformValue(name, x, y, z);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		GLfloat  x = *RawPtr_to(GLfloat *, sfp[2]);
		GLfloat  y = *RawPtr_to(GLfloat *, sfp[3]);
		GLfloat  z = *RawPtr_to(GLfloat *, sfp[4]);
		GLfloat  w = *RawPtr_to(GLfloat *, sfp[5]);
		qp->setUniformValue(name, x, y, z, w);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QColor color);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[2]);
		qp->setUniformValue(name, color);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValue(String name, QPoint point);
KMETHOD QGLShaderProgram_setUniformValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[2]);
		qp->setUniformValue(name, point);
	}
	RETURNvoid_();
}
*/
//void QGLShaderProgram.setUniformValueArray(int location, GLfloat values, int count, int tupleSize);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const GLfloat*  values = RawPtr_to(const GLfloat*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		int tupleSize = Int_to(int, sfp[4]);
		qp->setUniformValueArray(location, values, count, tupleSize);
	}
	RETURNvoid_();
}

/*
//void QGLShaderProgram.setUniformValueArray(int location, GLint values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const GLint*  values = RawPtr_to(const GLint*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, GLuint values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const GLuint*  values = RawPtr_to(const GLuint*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix2x2 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix2x2*  values = RawPtr_to(const QMatrix2x2*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix2x3 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix2x3*  values = RawPtr_to(const QMatrix2x3*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix2x4 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix2x4*  values = RawPtr_to(const QMatrix2x4*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix3x2 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix3x2*  values = RawPtr_to(const QMatrix3x2*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix3x3 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix3x3*  values = RawPtr_to(const QMatrix3x3*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix3x4 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix3x4*  values = RawPtr_to(const QMatrix3x4*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix4x2 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix4x2*  values = RawPtr_to(const QMatrix4x2*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix4x3 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix4x3*  values = RawPtr_to(const QMatrix4x3*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(int location, QMatrix4x4 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		int location = Int_to(int, sfp[1]);
		const QMatrix4x4*  values = RawPtr_to(const QMatrix4x4*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(location, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, GLint values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const GLint*  values = RawPtr_to(const GLint*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, GLuint values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const GLuint*  values = RawPtr_to(const GLuint*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, GLfloat values, int count, int tupleSize);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const GLfloat*  values = RawPtr_to(const GLfloat*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		int tupleSize = Int_to(int, sfp[4]);
		qp->setUniformValueArray(name, values, count, tupleSize);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix2x2 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix2x2*  values = RawPtr_to(const QMatrix2x2*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix2x3 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix2x3*  values = RawPtr_to(const QMatrix2x3*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix2x4 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix2x4*  values = RawPtr_to(const QMatrix2x4*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix3x2 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix3x2*  values = RawPtr_to(const QMatrix3x2*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix3x3 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix3x3*  values = RawPtr_to(const QMatrix3x3*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix3x4 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix3x4*  values = RawPtr_to(const QMatrix3x4*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix4x2 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix4x2*  values = RawPtr_to(const QMatrix4x2*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix4x3 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix4x3*  values = RawPtr_to(const QMatrix4x3*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
/*
//void QGLShaderProgram.setUniformValueArray(String name, QMatrix4x4 values, int count);
KMETHOD QGLShaderProgram_setUniformValueArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		const QMatrix4x4*  values = RawPtr_to(const QMatrix4x4*, sfp[2]);
		int count = Int_to(int, sfp[3]);
		qp->setUniformValueArray(name, values, count);
	}
	RETURNvoid_();
}
*/
//Array<QGLShader> QGLShaderProgram.shaders();
KMETHOD QGLShaderProgram_shaders(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		QList<QGLShader*> ret_v = qp->shaders();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGLShader"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QGLShaderProgram.uniformLocation(String name);
KMETHOD QGLShaderProgram_uniformLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->uniformLocation(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QGLShaderProgram.uniformLocation(QByteArray name);
KMETHOD QGLShaderProgram_uniformLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const QByteArray  name = *RawPtr_to(const QByteArray *, sfp[1]);
		int ret_v = qp->uniformLocation(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QGLShaderProgram.uniformLocation(String name);
KMETHOD QGLShaderProgram_uniformLocation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLShaderProgram *  qp = RawPtr_to(QGLShaderProgram *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		int ret_v = qp->uniformLocation(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//boolean QGLShaderProgram.hasOpenGLShaderPrograms(QGLContext context);
KMETHOD QGLShaderProgram_hasOpenGLShaderPrograms(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QGLContext*  context = RawPtr_to(const QGLContext*, sfp[1]);
		bool ret_v = QGLShaderProgram::hasOpenGLShaderPrograms(context);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQGLShaderProgram::DummyQGLShaderProgram()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGLShaderProgram::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLShaderProgram::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQGLShaderProgram::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGLShaderProgram::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLShaderProgram::event_map->bigin();
	if ((itr = DummyQGLShaderProgram::event_map->find(str)) == DummyQGLShaderProgram::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLShaderProgram::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLShaderProgram::slot_map->bigin();
	if ((itr = DummyQGLShaderProgram::slot_map->find(str)) == DummyQGLShaderProgram::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLShaderProgram::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLShaderProgram::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGLShaderProgram::connection(QObject *o)
{
	QGLShaderProgram *p = dynamic_cast<QGLShaderProgram*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQGLShaderProgram::KQGLShaderProgram(QObject* parent) : QGLShaderProgram(parent)
{
	self = NULL;
	dummy = new DummyQGLShaderProgram();
	dummy->connection((QObject*)this);
}

KMETHOD QGLShaderProgram_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLShaderProgram *qp = RawPtr_to(KQGLShaderProgram *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLShaderProgram]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLShaderProgram]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLShaderProgram_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLShaderProgram *qp = RawPtr_to(KQGLShaderProgram *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLShaderProgram]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLShaderProgram]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLShaderProgram_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGLShaderProgram *qp = (KQGLShaderProgram *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGLShaderProgram_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGLShaderProgram *qp = (KQGLShaderProgram *)p->rawptr;
//		KQGLShaderProgram *qp = static_cast<KQGLShaderProgram*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLShaderProgram_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGLShaderProgram::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGLShaderProgram::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGLShaderProgram::event(event);
		return false;
	}
//	QGLShaderProgram::event(event);
	return true;
}



DEFAPI(void) defQGLShaderProgram(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLShaderProgram";
	cdef->free = QGLShaderProgram_free;
	cdef->reftrace = QGLShaderProgram_reftrace;
	cdef->compareTo = QGLShaderProgram_compareTo;
}


