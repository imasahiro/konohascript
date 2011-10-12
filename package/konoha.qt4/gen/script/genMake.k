using konoha.posix.*;

void genMake(BindInfo[] binded_class) {
	print "genMake";
	Dir build_dir = System.openDir("build");
	if (build_dir == null) {
		System.exec("mkdir build");
	}

	String moc = "";
	String str = """
CC = g++
QTDIR ?= /home/onoda/QtSDK/Desktop/Qt/473/gcc
#QTDIR ?= /usr/local/Trolltech/Qt-4.7.3
MOC = $(QTDIR)/bin/moc
INCPATH = -I$(QTDIR)/include/Qt -I$(QTDIR)/include -I$(QTDIR)/include/QtGui -I$(QTDIR)/include/QtCore -I./include
LFLAGS = -m64 -Wl,-O1 -Wl,-rpath,/home/onoda/QtSDK/Desktop/Qt/473/gcc/lib
#OPENCV_LIBS = `pkg-config opencv --libs`
#OPENCV_LIBS = -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_ts -lopencv_video
#OPENCV_FLAGS = #`pkg-config opencv --cflags`
#LIBS = -F$(QTDIR)/lib -L$(QTDIR)/lib -framework QtGui -L$(QTDIR)/lib -F$(QTDIR)/lib -framework QtCore $(OPENCV_LIBS) -L./lib/triangle++/lib/
#LIBS = -F$(QTDIR)/lib -L$(QTDIR)/lib -framework QtGui -L$(QTDIR)/lib -F$(QTDIR)/lib -framework QtCore -L./lib/triangle++/lib/
LIBS = $(SUBLIBS)  -L/home/onoda/QtSDK/Desktop/Qt/473/gcc/lib -lQtGui -lQtCore -lQtWebKit -lpthread -lkonoha
DEFINES = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB
#CFLAGS = -fpermissive -fPIC -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CFLAGS = -fPIC -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)

LDLIBS = $(LFLAGS) $(LIBS)

pkgname = qt4
library = "$(pkgname).so"

VPATH = src:moc:include

.PHONY: all
all: $(library)

""";

	if (GEN_CONCATENATE_FILE) {
		String file = CONCATENATE_CPP_FILE - ".cpp";
		str += """
.PHONY: clean
clean:
	$(RM) -rf build/*.o $(library) *~ 

$(library): build/<FILE>.o
	$(CC) -shared -o $@ $^ $(LDLIBS)

build/<FILE>.o: <FILE>.cpp
	$(CC) $(CFLAGS) $(INCPATH) -o $@ -c $^
""";
		str = str.replace("<FILE>", file);
	} else {
		str += """
.PHONY: clean
clean:
	$(RM) -rf build/*.o $(library) *~ moc/moc_*

"""
		str +="objs = \\\n";
		foreach (bc in binded_class) {
			if (bc.checkUnusedClass()) continue;
			String objs1 = "\tbuild/<CLASS>.o\\\n";
			String objs2 = "\tbuild/moc_<CLASS>.o\\\n";
			if (OUTPUT_EVENT_BIND) {
				if (bc.make_rapper_class_flag) {
					objs1 += objs2;
					String tmp_moc = """
moc/moc_<CLASS>.cpp: K<CLASS>.hpp
	$(MOC) $(INCPATH) -D__APPLE__ -D__GNUC__ $^ -o $@
""";
					tmp_moc = tmp_moc.replace("<CLASS>", bc.class_name);
					moc += tmp_moc;
				}
			}
			objs1 = objs1.replace("<CLASS>", bc.class_name);
			str+= objs1;
		}
		str += "\tbuild/QtInitFunction.o\\\n";
		str += """

build/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCPATH) -o $@ -c $^

$(library): $(objs)
	$(CC) -shared -o $@ $^ $(LDLIBS)

""";
		str += moc;
	}
	ous = new OutputStream("AllMake.mk");
	ous.println(str);
	ous.flush();
	ous.close();
}
