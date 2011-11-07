#ifndef QRUBBERBAND
#define QRUBBERBAND
class DummyQRubberBand : public DummyQWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRubberBand();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQRubberBand : public QRubberBand {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQRubberBand *dummy;
	KQRubberBand(QRubberBand::Shape s, QWidget* p);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QRUBBERBAND


