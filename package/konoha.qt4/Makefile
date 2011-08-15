CC = g++
QTDIR ?= /usr/local/Trolltech/Qt-4.7.3
INCPATH       = -I/usr/local/Trolltech/Qt-4.7.3/mkspecs/macx-g++ -I. -I/usr/local/Trolltech/Qt-4.7.3/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Trolltech/Qt-4.7.3/include/QtCore -I/usr/local/Trolltech/Qt-4.7.3/lib/QtNetwork.framework/Versions/4/Headers -I/usr/local/Trolltech/Qt-4.7.3/include/QtNetwork -I/usr/local/Trolltech/Qt-4.7.3/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Trolltech/Qt-4.7.3/include/QtGui -I/usr/local/Trolltech/Qt-4.7.3/lib/QtXml.framework/Versions/4/Headers -I/usr/local/Trolltech/Qt-4.7.3/include/QtXml -I/usr/local/Trolltech/Qt-4.7.3/lib/QtWebKit.framework/Versions/4/Headers -I/usr/local/Trolltech/Qt-4.7.3/include/QtWebKit -I/usr/local/Trolltech/Qt-4.7.3/include -I. -F/usr/local/Trolltech/Qt-4.7.3/lib
LFLAGS        = -headerpad_max_install_names -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5
#OPENCV_LIBS = `pkg-config opencv --libs`
#OPENCV_LIBS = -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_ts -lopencv_video
#OPENCV_FLAGS = #`pkg-config opencv --cflags`
#LIBS = -F$(QTDIR)/lib -L$(QTDIR)/lib -framework QtGui -L$(QTDIR)/lib -F$(QTDIR)/lib -framework QtCore $(OPENCV_LIBS) -L./lib/triangle++/lib/
#LIBS = -F$(QTDIR)/lib -L$(QTDIR)/lib -framework QtGui -L$(QTDIR)/lib -F$(QTDIR)/lib -framework QtCore -L./lib/triangle++/lib/
LIBS          = $(SUBLIBS) -F/usr/local/Trolltech/Qt-4.7.3/lib -L/usr/local/Trolltech/Qt-4.7.3/lib -framework QtWebKit -framework QtXml -L/usr/local/Trolltech/Qt-4.7.3/lib -F/usr/local/Trolltech/Qt-4.7.3/lib -framework QtCore -framework QtGui -framework QtNetwork  -lkonoha1
DEFINES       = -DQT_NO_DEBUG -DQT_WEBKIT_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS = -O0 -g3 -pipe -g -gdwarf-2 -Wall -W -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 $(DEFINES) -I/usr/local/include/ -I./include/ -I$(QTDIR)/include -Wall -W -fPIC $(INCPATH) -DNDEBUG
LDLIBS = $(LFLAGS) $(LIBS)

pkgname = qt4
library = "$(pkgname).dylib"

# please add in an alphabetical order
objs = \
	build/QApplication.o\
	build/QBoxLayout.o\
	build/QHBoxLayout.o\
	build/QLabel.o\
	build/QLineEdit.o\
	build/QObject.o\
	build/QPushButton.o\
	build/QWebView.o\
	build/QWidget.o\
	build/QTextEdit.o\
	build/QTimer.o\
	build/QAbstractScrollArea.o\
	build/QPainter.o\
	build/QRect.o\
	build/QColor.o\
	build/qt4commons_moc.o\

.PHONY: all
all: $(library)

build/QApplication.o: src/QApplication.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QBoxLayout.o: src/QBoxLayout.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QHBoxLayout.o: src/QHBoxLayout.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QLabel.o: src/QLabel.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QLineEdit.o: src/QLineEdit.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QObject.o : src/QObject.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QPushButton.o : src/QPushButton.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QWebView.o: src/QWebView.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QWidget.o: src/QWidget.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QTextEdit.o: src/QTextEdit.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QTimer.o: src/QTimer.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QAbstractScrollArea.o: src/QAbstractScrollArea.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QPainter.o: src/QPainter.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QRect.o: src/QRect.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/QColor.o: src/QColor.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/qt4commons_moc.o: src/qt4commons_moc.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

src/qt4commons_moc.cpp: src/qt4commons.hpp
	$(QTDIR)/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ $^ -o $@

$(library): $(objs)
	$(CC) -dynamiclib -o $@ $^ $(LDLIBS)


.PHONY: clean
clean:
	$(RM) -rf $(objs) $(library) *~
