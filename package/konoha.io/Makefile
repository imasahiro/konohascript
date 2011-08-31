CC = gcc
CXX = g++

CFLAGS = -O2 -g -Wall -fmessage-length=0 -fPIC -Ithird-party/msgpack-0.5.6/
#LDLIBS = -lmsgpack
version = 1.0
LIBVER = -current_version 1.0.0 -compatibility_version $(version)
pkgname = io
library = "$(pkgname).dylib"

.PHONY: all
all: $(library)

objs = \
	build/io.o\
	build/msgpack.o\
	build/base64.o\
	build/object.o\
	build/objectc.o\
	build/unpack.o\
	build/version.o\
	build/vrefbuffer.o\
	build/zone.o\

build/io.o: src/io.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

build/msgpack.o: src/msgpack.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

build/base64.o: src/base64.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

build/object.o: third-party/msgpack-0.5.6/object.cpp
	$(CXX) $(CFLAGS) -D_SETUP -o $@ -c $^

build/objectc.o: third-party/msgpack-0.5.6/objectc.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

build/unpack.o: third-party/msgpack-0.5.6/unpack.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

build/version.o: third-party/msgpack-0.5.6/version.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

build/vrefbuffer.o: third-party/msgpack-0.5.6/vrefbuffer.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

build/zone.o: third-party/msgpack-0.5.6/zone.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

$(library): $(objs)
	$(CXX) -dynamiclib $(LIBVER) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -rf $(objs) $(library)
