#ifndef QGRAPHICSPROXYWIDGET
#define QGRAPHICSPROXYWIDGET
class DummyQGraphicsProxyWidget : public DummyQGraphicsWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *paint_func;
	DummyQGraphicsProxyWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQGraphicsProxyWidget : public QGraphicsProxyWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsProxyWidget *dummy;
	KQGraphicsProxyWidget(QGraphicsItem* parent, Qt::WindowFlags wFlags);
	void setSelf(knh_RawPtr_t *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif //QGRAPHICSPROXYWIDGET


