#ifndef QWEBFRAME
#define QWEBFRAME
class DummyQWebFrame : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *contents_size_changed_func;
	knh_Func_t *icon_changed_func;
	knh_Func_t *initial_layout_completed_func;
	knh_Func_t *java_script_window_object_cleared_func;
	knh_Func_t *load_finished_func;
	knh_Func_t *load_started_func;
	knh_Func_t *page_changed_func;
	knh_Func_t *title_changed_func;
	knh_Func_t *url_changed_func;
	DummyQWebFrame();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool contentsSizeChangedSlot(const QSize size);
	bool iconChangedSlot();
	bool initialLayoutCompletedSlot();
	bool javaScriptWindowObjectClearedSlot();
	bool loadFinishedSlot(bool ok);
	bool loadStartedSlot();
	bool pageChangedSlot();
	bool titleChangedSlot(const QString title);
	bool urlChangedSlot(const QUrl url);
};

class KQWebFrame {
// Q_OBJECT;
public:
	QWebFrame *q_self;
	knh_RawPtr_t *self;
	DummyQWebFrame *dummy;

	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QWEBFRAME


