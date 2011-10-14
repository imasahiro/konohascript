#ifndef QPIXMAPCACHE
#define QPIXMAPCACHE
class DummyQPixmapCache {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPixmapCache();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQPixmapCache : public QPixmapCache {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPixmapCache *dummy;
	KQPixmapCache();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QPIXMAPCACHE


