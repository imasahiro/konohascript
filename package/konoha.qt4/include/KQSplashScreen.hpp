#ifndef QSPLASHSCREEN
#define QSPLASHSCREEN
class DummyQSplashScreen : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *message_changed_func;
	DummyQSplashScreen();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool messageChangedSlot(const QString message);
};

class KQSplashScreen : public QSplashScreen {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQSplashScreen *dummy;
	KQSplashScreen(const QPixmap pixmap, Qt::WindowFlags f);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSPLASHSCREEN

