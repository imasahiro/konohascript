#ifndef QWEBPAGE
#define QWEBPAGE
class DummyQWebPage : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *contents_changed_func;
	knh_Func_t *database_quota_exceeded_func;
	knh_Func_t *download_requested_func;
	knh_Func_t *frame_created_func;
	knh_Func_t *geometry_change_requested_func;
	knh_Func_t *link_clicked_func;
	knh_Func_t *link_hovered_func;
	knh_Func_t *load_finished_func;
	knh_Func_t *load_progress_func;
	knh_Func_t *load_started_func;
	knh_Func_t *menu_bar_visibility_change_requested_func;
	knh_Func_t *micro_focus_changed_func;
	knh_Func_t *print_requested_func;
	knh_Func_t *repaint_requested_func;
	knh_Func_t *restore_frame_state_requested_func;
	knh_Func_t *save_frame_state_requested_func;
	knh_Func_t *scroll_requested_func;
	knh_Func_t *selection_changed_func;
	knh_Func_t *status_bar_message_func;
	knh_Func_t *status_bar_visibility_change_requested_func;
	knh_Func_t *tool_bar_visibility_change_requested_func;
	knh_Func_t *unsupported_content_func;
	knh_Func_t *window_close_requested_func;
	DummyQWebPage();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool contentsChangedSlot();
	bool databaseQuotaExceededSlot(QWebFrame* frame, QString databaseName);
	bool downloadRequestedSlot(const QNetworkRequest request);
	bool frameCreatedSlot(QWebFrame* frame);
	bool geometryChangeRequestedSlot(const QRect geom);
	bool linkClickedSlot(const QUrl url);
	bool linkHoveredSlot(const QString link, const QString title, const QString textContent);
	bool loadFinishedSlot(bool ok);
	bool loadProgressSlot(int progress);
	bool loadStartedSlot();
	bool menuBarVisibilityChangeRequestedSlot(bool visible);
	bool microFocusChangedSlot();
	bool printRequestedSlot(QWebFrame* frame);
	bool repaintRequestedSlot(const QRect dirtyRect);
	bool restoreFrameStateRequestedSlot(QWebFrame* frame);
	bool saveFrameStateRequestedSlot(QWebFrame* frame, QWebHistoryItem* item);
	bool scrollRequestedSlot(int dx, int dy, const QRect rectToScroll);
	bool selectionChangedSlot();
	bool statusBarMessageSlot(const QString text);
	bool statusBarVisibilityChangeRequestedSlot(bool visible);
	bool toolBarVisibilityChangeRequestedSlot(bool visible);
	bool unsupportedContentSlot(QNetworkReply* reply);
	bool windowCloseRequestedSlot();
};

class KQWebPage : public QWebPage {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWebPage *dummy;
	KQWebPage(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QWEBPAGE


