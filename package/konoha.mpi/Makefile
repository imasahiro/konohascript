CC=gcc
CFLAGS=-O2 -g -Wall -fmessage-length=0 -fPIC
LDFLAGS=-Wl,-flat_namespace
LDLIBS=-lkonoha1 -lpmpich -lmpich -lopa -lmpl -lpthread
PKG=mpi
RM=rm
LINK=
LIB=

#ifeq ($(OS),Windows_NT)
#	# for Windows
#else
UNAME = ${shell uname}
ifeq ($(UNAME),Linux)
	# for Linux
	LINK=$(CC) -shared -o
	LIB=$(PKG).so
endif
ifeq ($(UNAME),Darwin)
	# for MacOSX
	LINK=$(CC) -dynamiclib -o
	LIB=$(PKG).dylib
endif
#endif

OBJS=$(PKG).o src/const.o src/ctx.o src/req.o src/pt2pt.o src/coll.o

.PHONY: all
all: $(LIB)

$(LIB): $(OBJS)
	$(LINK) $@ $^ $(LDFLAGS) $(LDLIBS)

$(PKG).o: $(PKG).c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

src/const.o: src/const.c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

src/ctx.o: src/ctx.c
	$(CC) $(CFLAGS) -o $@ -c $^

src/req.o: src/req.c
	$(CC) $(CFLAGS) -o $@ -c $^

src/pt2pt.o: src/pt2pt.c
	$(CC) $(CFLAGS) -o $@ -c $^

src/coll.o: src/coll.c
	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
	$(RM) -rf $(OBJS) $(LIB)
