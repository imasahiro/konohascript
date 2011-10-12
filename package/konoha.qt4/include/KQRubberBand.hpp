#ifndef QRUBBERBAND
#define QRUBBERBAND
class DummyQRubberBand : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRubberBand();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQRubberBand : public QRubberBand, public DummyQRubberBand {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQRubberBand(QRubberBand::Shape s, QWidget* p);
	bool event(QEvent *event);
};

#endif //QRUBBERBAND


