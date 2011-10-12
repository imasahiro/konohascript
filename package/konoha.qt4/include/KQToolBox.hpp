#ifndef QTOOLBOX
#define QTOOLBOX
class DummyQToolBox : public DummyQFrame {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQToolBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQToolBox : public QToolBox, public DummyQToolBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQToolBox(QWidget* parent, Qt::WindowFlags f);
	bool event(QEvent *event);
};

#endif //QTOOLBOX


