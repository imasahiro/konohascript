#ifndef QFRAME
#define QFRAME
class DummyQFrame : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFrame();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQFrame : public QFrame, public DummyQFrame {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQFrame(QWidget* parent, Qt::WindowFlags f);
	bool event(QEvent *event);
};

#endif //QFRAME


