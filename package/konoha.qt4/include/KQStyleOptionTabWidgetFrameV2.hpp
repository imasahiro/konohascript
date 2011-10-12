#ifndef QSTYLEOPTIONTABWIDGETFRAMEV2
#define QSTYLEOPTIONTABWIDGETFRAMEV2
class DummyQStyleOptionTabWidgetFrameV2 : public DummyQStyleOptionTabWidgetFrame {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionTabWidgetFrameV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionTabWidgetFrameV2 : public QStyleOptionTabWidgetFrameV2, public DummyQStyleOptionTabWidgetFrameV2 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionTabWidgetFrameV2();
};

#endif //QSTYLEOPTIONTABWIDGETFRAMEV2


