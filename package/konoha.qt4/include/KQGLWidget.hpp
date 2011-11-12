#ifndef QGLWIDGET
#define QGLWIDGET
class DummyQGLWidget : public DummyQWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGLWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQGLWidget : public QGLWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGLWidget *dummy;
	KQGLWidget(QWidget* parent, const QGLWidget* shareWidget, Qt::WindowFlags f);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGLWIDGET


