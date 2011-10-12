#ifndef QRESOURCE
#define QRESOURCE
class DummyQResource {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQResource();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQResource : public QResource, public DummyQResource {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQResource(const QString file, const QLocale locale);
};

#endif //QRESOURCE


