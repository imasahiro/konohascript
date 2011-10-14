#ifndef QFRAME
#define QFRAME
class DummyQFrame : public DummyQWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFrame();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQFrame : public QFrame {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQFrame *dummy;
	KQFrame(QWidget* parent, Qt::WindowFlags f);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QFRAME


