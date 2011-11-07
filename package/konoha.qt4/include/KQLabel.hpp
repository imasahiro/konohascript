#ifndef QLABEL
#define QLABEL
class DummyQLabel : public DummyQFrame {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *link_activated_func;
	knh_Func_t *link_hovered_func;
	DummyQLabel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool linkActivatedSlot(const QString link);
	bool linkHoveredSlot(const QString link);
};

class KQLabel : public QLabel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQLabel *dummy;
	KQLabel(QWidget* parent, Qt::WindowFlags f);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QLABEL


