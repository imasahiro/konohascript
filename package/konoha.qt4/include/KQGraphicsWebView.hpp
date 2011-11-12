#ifndef QGRAPHICSWEBVIEW
#define QGRAPHICSWEBVIEW
class DummyQGraphicsWebView : public DummyQGraphicsWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *icon_changed_func;
	knh_Func_t *link_clicked_func;
	knh_Func_t *load_finished_func;
	knh_Func_t *load_progress_func;
	knh_Func_t *load_started_func;
	knh_Func_t *status_bar_message_func;
	knh_Func_t *title_changed_func;
	knh_Func_t *url_changed_func;
	knh_Func_t *paint_func;
	DummyQGraphicsWebView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool iconChangedSlot();
	bool linkClickedSlot(const QUrl url);
	bool loadFinishedSlot(bool ok);
	bool loadProgressSlot(int progress);
	bool loadStartedSlot();
	bool statusBarMessageSlot(const QString text);
	bool titleChangedSlot(const QString title);
	bool urlChangedSlot(const QUrl url);
};

class KQGraphicsWebView : public QGraphicsWebView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsWebView *dummy;
	KQGraphicsWebView(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif //QGRAPHICSWEBVIEW


