#ifndef QTEXTBROWSER
#define QTEXTBROWSER
class DummyQTextBrowser : public DummyQTextEdit {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *anchor_clicked_func;
	knh_Func_t *backward_available_func;
	knh_Func_t *forward_available_func;
	knh_Func_t *history_changed_func;
	knh_Func_t *source_changed_func;
	DummyQTextBrowser();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool anchorClickedSlot(const QUrl link);
	bool backwardAvailableSlot(bool available);
	bool forwardAvailableSlot(bool available);
	bool historyChangedSlot();
	bool sourceChangedSlot(const QUrl src);
};

class KQTextBrowser : public QTextBrowser {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTextBrowser *dummy;
	KQTextBrowser(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTEXTBROWSER


