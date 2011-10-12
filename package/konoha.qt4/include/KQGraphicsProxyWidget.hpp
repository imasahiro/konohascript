#ifndef QGRAPHICSPROXYWIDGET
#define QGRAPHICSPROXYWIDGET
class DummyQGraphicsProxyWidget : public DummyQGraphicsWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsProxyWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsProxyWidget : public QGraphicsProxyWidget, public DummyQGraphicsProxyWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsProxyWidget(QGraphicsItem* parent, Qt::WindowFlags wFlags);
	bool event(QEvent *event);
};

#endif //QGRAPHICSPROXYWIDGET


