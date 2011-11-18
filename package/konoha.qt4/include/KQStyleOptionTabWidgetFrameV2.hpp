#ifndef QSTYLEOPTIONTABWIDGETFRAMEV2
#define QSTYLEOPTIONTABWIDGETFRAMEV2
class DummyQStyleOptionTabWidgetFrameV2 : public DummyQStyleOptionTabWidgetFrame {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionTabWidgetFrameV2();
	virtual ~DummyQStyleOptionTabWidgetFrameV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionTabWidgetFrameV2 : public QStyleOptionTabWidgetFrameV2 {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQStyleOptionTabWidgetFrameV2 *dummy;
	KQStyleOptionTabWidgetFrameV2();
	~KQStyleOptionTabWidgetFrameV2();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONTABWIDGETFRAMEV2


