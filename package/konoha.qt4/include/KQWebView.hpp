#ifndef QWEBVIEW
#define QWEBVIEW
class DummyQWebView : public DummyQWidget {
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
	knh_Func_t *selection_changed_func;
	knh_Func_t *status_bar_message_func;
	knh_Func_t *title_changed_func;
	knh_Func_t *url_changed_func;
	DummyQWebView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool iconChangedSlot();
	bool linkClickedSlot(const QUrl url);
	bool loadFinishedSlot(bool ok);
	bool loadProgressSlot(int progress);
	bool loadStartedSlot();
	bool selectionChangedSlot();
	bool statusBarMessageSlot(const QString text);
	bool titleChangedSlot(const QString title);
	bool urlChangedSlot(const QUrl url);
};

class KQWebView : public QWebView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWebView *dummy;
	KQWebView(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QWEBVIEW


