OBSOLATE_CLASS = [
	"QPictureIO", "QMatrix", "QMimeSource", "QHttpHeader", "QHttpRequestHeader", "QHttpResponseHeader"
	];

ABSTRACT_CLASSES = [ // if add items, re-make interface files
	"QGraphicsLayout", "QGraphicsLayoutItem", "QGraphicsEffect", "QAccessibleObject",
	"QGraphicsItem", "QIODevice", "QValidator", "QRunnable", "QGraphicsObject",
	"QLayout", "QLayoutItem", "QStyle", "QGraphicsTransform", "QInputContext", "QPaintEngine",
	"QWebHistoryInterface", "QHttpHeader", "QNetworkProxyFactory", "QNetworkProxyFactory"
	];

UNUSED_CLASSES = [
	"Animation",
	"ExtraSelection",
	"FT_Face",
	"hasEditFocus", "HFONT",
	"Iterator",
	"mac", "Mac",
	"Plugin", 
	"setupUi", "S60", "Stream",	"symbian", "Symbian",
	"WId",
	"X11", "XEvent",
	"QAtomicPointer", "QAbstractFontEngine"/*for embedded linux*/,
//	"QAccessibleObject",
	"QItemSelection",
	"QClipboard" /*must init by QApplication::clipboard() , not constructor*/,
	"QConstString"/*part of the Qt3 support library*/, "QCustomEvent"/*part of the Qt3 support library*/,
	"QCache", "QColorGroup", "QContiguousCache","QCopChannel", "QCustomRasterPaintDevice",
	"QCleanlooksStyle",
	"QDirectPainter",
	"QDecoration",
	"QExplicitlySharedDataPointer",
	"QFuture", "QFile",	"QFSFileEngine", "QFlag",	"QFontEngineInfo",
	"QGestureRecognizer", /* "QGraphicsObject",*/ "QGenericMatrix",
	/*"QGraphicsTransform",*/ /*"QGraphicsAnchor",*/
	"QGtkStyle" /*cannot compile on MacOSX*/,
	"QHash",
	"QImageIOHandler", "QItemEditorCreator",
	"QKbdDriverFactory"/*for embedded linux*/,
	"QList" /*use konoha types : QList => Array*/, "QUndoView",
	"QListWidget", "QListWidgetItem",/*"QLayout",*/ "QLinkedList",
	"QMouseDriverFactory"/*for embedded linux*/, "QMenuItem"/*part of the Qt3 support library*/,
	"QMultiHash", "QMutableLinkedListIterator", "QMap", "QMultiMap", "QMultiMap", "QMetaType",
	"QPair", "QPointer", "QProxyScreen", /*"QPolygon", "QPolygonF",*/ "QPlastiqueStyle",
	"QQueue",
	"QString"/*use konoha types : QString => String*/, "QSet",
	"QStack", "QStringList", "QSharedPointer", "QSharedPointer", "QScreenCursor",
	"QSharedDataPointer", "QScopedPointer",	"QScopedArrayPointer",	"QScreeCursor",
	"QSyntaxHighlighter",  "QScreen",  "QStandardItemEditorCreator",
	"QSessionManager",
	"QThreadStorage", "QTextOStream", "QTableWidget", "QTemporaryFile",
	"QVector", "QVectorIterator", "QVariant", "QVarLengthArray",
	"qwsSetCustomColors", "QWS", "QWeakPointer","QWSClient", "QWindows"
//	"QWebFrame" /*have private destructor*/
	];

UNUSED_METHOD = [ //these methods are final
	"isNull", "isValid", "insertColumn", "insertRow",
	"addAction", /*"depth", "height", "width",*/ "accept",
	"ignore", "isAccepted", "setAccepted",// "setWindowModality",
	"transformed", "from_Image"
	];

UNUSED_WORDS = [
	"EasingFunction", "EventFilter",/*typdef Function Ptr*/
	"qws", "Symbian", "symbian", "x11", "QGtkStyle", "windows", "S60", "WId",/*Dependency Environment*/
	"FT_Face", "HFONT", /*Specify Paramater for Font*/
	"HBitmapFormat", "HBITMAP", "HICON", "CGImageRef", "CFbsBitmap", "RsgImage",/*Specify Paramater for Pixmap*/
	"QPair", "QSet", "QStringList",/*convert Konoha Original API*/
	"defaultAction", "setDefaultAction", /*QMenuBar*/
	"findChild", "findChildren", /*Template Method by QObject*/
	"setWinPageSize", "supportedPaperSources", "winPageSize",/*Windows API by QPrinter*/
	"nativeArguments", "setNativeArguments", /*not supported API by QProcess*/
	"Handle handle () const", /*QRegion*/
	"WId", "hasEditFocus", "setEditFocus", "setupUi", "HANDLE", "HDC", "macEvent", "winEvent",/*QWidget*/
	"macFontID", /*function for mac*/
	"QGenericMatrix", "QVector", "QHash", "QMap",/*templete class*/
	"hPal", /*function for Windows*/
	"navigationMode", "setNavigationMode", /*function for Embedded Linux, Symbian, and Windows CE*/
	"QDataStream", "QFile",/*cannot copy*/
	"keypadNavigationEnabled", /*deprecated function in QApplication*/
	"autoMaximizeThreshold", "AutoMaximizeThreshold", /*only availabel for Windows CE (in QApplication)*/
	"QSessionManager", /*cannot init by copy constructor*/
	"RootObjectHandler", /*[QAccessbile] : function ptr*/
	"allowX11ColorNames", "setAllowX11ColorNames", /*[QColor API] : cannot compile on MacOSX*/
//	"qint64 readData", "qint64 readLineData", "qint64 writeData", /*pure virtual method in QIODevice*/
//	"virtual bool viewportEvent ( QEvent * event )", /*QAbstractScrollArea*/
	"windowSurface", "WindowSurface", /*This function is under development and is subjet to change*/
	"operator", /*"virtual",*/ /*"~",*/ "...","const[]",
	"QTextOption::Tab", /*"Attribute",*/ "QPainterPath::Element", "iterator", "ConverterState", /*class defined in class*/
	"PixmapFragment", "ExtensionOption", "PaintContext",/*class defined in class*/
//	"blurHintsChanged", /*cannnot define corresponding slot, in order to use BlurHints*/
	"QMultiMap" /*template class*/
	];

GLOBAL_FLAG_LIST = [
	("Qt", "Alignment"), ("Qt", "DockWidgetAreas"),
	("Qt", "DropActions"), ("Qt", "GestureFlags"), ("Qt", "ImageConversionFlags"),
	("Qt", "InputMethodHints"), ("Qt", "ItemFlags"), ("Qt", "KeyboardModifiers"),
	("Qt", "MatchFlags"), ("Qt", "MouseButtons"), ("Qt", "Orientations"),
	("Qt", "TextInteractionFlags"), ("Qt", "ToolBarAreas"), ("Qt", "TouchPointStates"),
	("Qt", "WindowFlags"), ("Qt", "WindowStates")
	];

UNUSED_ENUM_NAME = [
	"MacVersion", "S60Version", "SymbianVersion", "WinVersion"//in QSysinfo
	];

UNUSED_ENUM_KEY = [
	"State_HasEditFocus", "SH_GUIStyle", "SH_ScrollBar_BackgroundMode",
	"ChildInserted", "EnterEditFocus", "LeaveEditFocus", //in QEvent
	"QColorGroup", //in QMetaType
	"NoAlpha", "PremultipliedAlpha", "Alpha", "ImplicitlyShared", "ExplicitlyShared",//QPixmap
//			"DecorationRole", "UserRole" //QDirModel
	];

UNUSED_ARG_NAMES = [
//first array element is unused type name. 
//in function convertUnusedTypeName in class FunctionElement, convert first into second
	["new", "new_"]
	];

// NOT_INHERITS_QOBJECT = [
// 	"QTextCodec", "QAccessibleWidget", "QPrinter", "QStandardItem",
// 	"QGraphicsLayoutItem", "QResource", "QTreeWidgetItem", "QDate",
// 	"QGraphicsLayout", "QPaintDevice", "QGraphicsItem", "QReadLocker"
// 	];

ADD_VIRTUAL_FUNCTION_LIST = [
	["QPaintDevice", "depth"],
	["QPaintDevice", "height"],
	["QPaintDevice", "width"],
	["QAbstractPrintDialog", "printer"],
	["QLayout", "setSpacing"],
	["QLayout", "getSpacing"],
	["QWidget", "setWindowModality"],
	["QWidget", "setWindowTitle"]
	];

RENAME_FUNCTION_LIST = [
//	["QPainter", "begin"],
	["QPixmap", "fromImage"],
	["QStylePainter", "begin"],
//	["QAbstractItemView", "closePersistentEditor"],
	["QTreeWidget", "closePersistentEditor"],
//	["QAbstractItemView", "openPersistentEditor"],
	["QTreeWidget", "openPersistentEditor"],
//	["QLayoutItem", "setAlignment"],
	["QLayout", "setAlignment"],
	["QLayout", "addWidget"],
//	["QObject", "setParent"],
	["QWidget", "update"],
	["QWidget", "setParent"],
//	["QWidget", "repaint"],
	["QSplashScreen", "repaint"],
//	["QDialog", "open"],
	["QFontDialog", "open"],
//	["QWidget, getFont"],
	["QFontDialog", "getFont"],
	["QProgressDialog", "open"]
	];

// NOT_HAVE_CONSTRUCTOR = [
// 	"QGraphicsSceneEvent", "QInputEvent", "QSessionManager",
// 	"QTextList", "QTextTable", "QWindowStateChangeEvent",
// 	"QLibraryInfo", "QToolTip", "QWhatsThis"
// 	];

HAVE_PRIVATE_DESTRUCTOR_LIST = [
	"QWebFrame"
]

NOT_HAVE_EVENT_METHOD = [ // these class do not have method "bool event()"
	"QAbstractFileEngine", "QAbstractFileEngineHandler",
	"QAbstractGraphicsShapeItem", "QAccessible",
	"QAccessibleBridge", "QAccessibleEvent", "QAccessibleInterface",
	"QAccessibleObject", "QAccessibleWidget", "QActionEvent",
	"QAtomicInt", "QBasicTimer", "QBitArray", "QBitmap",
	"QBrush", "QByteArray", "QByteArrayMatcher", "QChar",
	"QChildEvent", "QCloseEvent", "QColor", "QColormap",
	"QConicalGradient", "QContextMenuEvent", "QCryptographicHash",
	"QCursor", "QDate", "QDateTime", "QDebug", "QDesktopServices",
	"QDir", "QDragEnterEvent", "QDragLeaveEvent", "QDragMoveEvent",
	"QDropEvent", "QDynamicPropertyChangeEvent", "QEasingCurve",
	"QElapsedTimer", "QEvent", "QFocusEvent", "QFont",
	"QFontDatabase", "QFontInfo", "QFontMetrics", "QFontMetricsF",
	"QGenericArgument", "QGenericReturnArgument", "QGestureEvent",
	"QGradient", "QGraphicsAnchorLayout", "QGraphicsEllipseItem",
	"QGraphicsGridLayout", "QGraphicsItem", "QGraphicsItemGroup",
	"QGraphicsLayout", "QGraphicsLayoutItem", "QGraphicsLineItem",
	"QGraphicsLinearLayout", "QGraphicsPathItem", "QGraphicsPixmapItem",
	"QGraphicsPolygonItem", "QGraphicsRectItem",
	"QGraphicsSceneContextMenuEvent", "QGraphicsSceneDragDropEvent",
	"QGraphicsSceneEvent", "QGraphicsSceneHelpEvent",
	"QGraphicsSceneHoverEvent", "QGraphicsSceneMouseEvent",
	"QGraphicsSceneMoveEvent", "QGraphicsSceneResizeEvent",
	"QGraphicsSceneWheelEvent", "QGraphicsSimpleTextItem",
	"QHelpEvent", "QHideEvent", "QHoverEvent", "QIcon",
	"QIconDragEvent", "QIconEngine", "QIconEngineV2", "QImage",
	"QImageReader", "QImageWriter", "QInputContextFactory", "QInputEvent",
	"QInputMethodEvent", "QItemEditorFactory", "QKeyEvent", "QKeySequence",
	"QLatin1Char", "QLatin1String", "QLayoutItem", "QLibraryInfo",
	"QLine", "QLineF", "QLinearGradient", "QLocale", "QMargins",
	"QMatrix4x4", "QMetaClassInfo", "QMetaEnum", "QMetaMethod",
	"QMetaObject", "QMetaProperty","QModelIndex", "QMouseEvent",
	"QMoveEvent", "QMutex", "QMutexLocker", "QPaintEngine", "QPaintEngineState",
	"QPaintEvent", "QPainter", "QPainterPath", "QPainterPathStroker",
	"QPalette", "QPen", "QPersistentModelIndex", "QPicture", "QPixmap",
	"QPixmapCache", "QPoint", "QPointF", "QPrintEngine", "QPrinterInfo",
	"QProcessEnvironment", "QQuaternion", "QRadialGradient", "QReadLocker",
	"QReadWriteLock", "QRect", "QRectF", "QRegExp", "QRegion", "QResizeEvent",
	"QRunnable", "QSemaphore", "QSharedData", "QShortcutEvent","QShowEvent",
	"QSize", "QSizeF", "QSizePolicy", "QSpacerItem", "QStaticText",
	"QStatusTipEvent", "QStyleFactory", "QStyleHintReturn", "QStyleHintReturnMask",
	"QStyleHintReturnVariant", "QStyleOption", "QStyleOptionButton", "QStyleOptionComboBox",
	"QStyleOptionComplex", "QStyleOptionDockWidget", "QStyleOptionFocusRect",
	"QStyleOptionFrame", "QStyleOptionFrameV2", "QStyleOptionFrameV3",
	"QStyleOptionGraphicsItem", "QStyleOptionGroupBox", "QStyleOptionHeader",
	"QStyleOptionMenuItem", "QStyleOptionProgressBar", "QStyleOptionProgressBarV2",
	"QStyleOptionRubberBand", "QStyleOptionSizeGrip", "QStyleOptionSlider",
	"QStyleOptionSpinBox", "QStyleOptionTab", "QStyleOptionTabBarBase",
	"QStyleOptionTabBarBaseV2", "QStyleOptionTabV2", "QStyleOptionTabV3",
	"QStyleOptionTabWidgetFrame", "QStyleOptionTabWidgetFrameV2", "QStyleOptionTitleBar",
	"QStyleOptionToolBar", "QStyleOptionToolBox", "QStyleOptionToolBoxV2",
	"QStyleOptionToolButton", "QStyleOptionViewItem", "QStyleOptionViewItemV2",
	"QStyleOptionViewItemV3", "QStyleOptionViewItemV4", "QStylePainter",
	"QSysInfo", "QSystemLocale", "QSystemSemaphore", "QTabletEvent",
	"QTextBlock", "QTextBlockFormat", "QTextBlockUserData", "QTextBoundaryFinder",
	"QTextCharFormat", "QTextCursor", "QTextDecoder", "QTextDocumentFragment",
	"QTextDocumentWriter", "QTextEncoder", "QTextFormat", "QTextFragment",
	"QTextFrameFormat", "QTextImageFormat", "QTextInlineObject", "QTextItem",
	"QTextLayout", "QTextLength", "QTextLine", "QTextListFormat",
	"QTextObjectInterface", "QTextOption", "QTextTableCell", "QTextTableCellFormat",
	"QTextTableFormat", "QTileRules", "QTime", "QTimerEvent",
	"QToolTip", "QTouchEvent","QTransform", "QUndoCommand", "QUrl",
	"QUuid", "QWaitCondition", "QWhatsThis", "QWhatsThisClickedEvent",
	"QWheelEvent", "QWidgetItem", "QWindowStateChangeEvent", "QWriteLocker",
	"QWebDatabase", "QWebElement", "QWebElementCollection", "QWebHistory",
	"QWebHistoryItem", "QWebHitTestResult", "QWebSecurityOrigin", "QWebSettings",
	"QPaintDevice", "QPrinter", "QPolygon", "QPolygonF",
	"QResource", "QStandardItem", "QTextCodec",
	"QTreeWidgetItem",
	"QAuthenticator", "QHostAddress", "QHostInfo", "QHttpHeader", "QHttpRequestHeader",
	"QHttpResponseHeader", "QNetworkAddressEntry", "QNetworkCacheMetaData",
	"QNetworkConfiguration", "QNetworkCookie", "QNetworkInterface", "QNetworkProxy",
	"QNetworkProxyFactory",	"QNetworkProxyQuery", "QNetworkRequest", "QSslCertificate",
	"QSslCipher", "QSslConfiguration", "QSslError",	"QSslKey", "QUrlInfo"
	];
