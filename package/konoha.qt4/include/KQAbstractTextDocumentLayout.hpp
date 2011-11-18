#ifndef QABSTRACTTEXTDOCUMENTLAYOUT
#define QABSTRACTTEXTDOCUMENTLAYOUT
class DummyQAbstractTextDocumentLayout : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *document_size_changed_func;
	knh_Func_t *page_count_changed_func;
	knh_Func_t *update_func;
	knh_Func_t *update_block_func;
	DummyQAbstractTextDocumentLayout();
	virtual ~DummyQAbstractTextDocumentLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool documentSizeChangedSlot(const QSizeF new_Size);
	bool pageCountChangedSlot(int new_Pages);
	bool updateSlot(const QRectF rect);
	bool updateBlockSlot(const QTextBlock block);
};

class KQAbstractTextDocumentLayout : public QAbstractTextDocumentLayout {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQAbstractTextDocumentLayout *dummy;
	KQAbstractTextDocumentLayout(QTextDocument* document);
	~KQAbstractTextDocumentLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTTEXTDOCUMENTLAYOUT


