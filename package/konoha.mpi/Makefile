CC=gcc
CFLAGS=-O2 -g -Wall -fPIC
#CFLAGS=-O0 -g3 -Wall -fPIC
LDFLAGS=-fmessage-length=0 -fPIC -Wl,-flat_namespace
LDLIBS=-lkonoha -lmpich -lopa -lmpl

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
	LDLIBS+=-lpmpich
	LINK=$(CC) -dynamiclib -o
	LIB=$(PKG).dylib
endif
#endif

PKGOBJS=$(PKG).o
MPIOBJS=src/comm.o src/op.o src/pt2pt.o src/coll.o

FLAGS=$(LDFLAGS)
LIBS=$(LDLIBS)
OBJS=$(PKGOBJS) $(MPIOBJS)

.PHONY: all
all: $(LIB)

#package
$(LIB): $(OBJS)
	$(LINK) $@ $^ $(FLAGS) $(LIBS)

$(PKG).o: $(PKG).c
	$(CC) $(CFLAGS) -D_SETUP -o $@ -c $^

#mpobjs
src/comm.o: src/comm.c
	$(CC) $(CFLAGS) -o $@ -c $^

src/op.o: src/op.c
	$(CC) $(CFLAGS) -o $@ -c $^

src/pt2pt.o: src/pt2pt.c
	$(CC) $(CFLAGS) -o $@ -c $^

src/coll.o: src/coll.c
	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY: clean
clean:
	$(RM) -rf $(OBJS) $(LIB) *.dSYM *.dSYM
