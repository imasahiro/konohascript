#ifndef QLABEL
#define QLABEL
class DummyQLabel : public DummyQFrame {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLabel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQLabel : public QLabel, public DummyQLabel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQLabel(QWidget* parent, Qt::WindowFlags f);
	bool event(QEvent *event);
};

#endif //QLABEL


