# Makefile for linux
#

CC = gcc
CFLAGS = -g -O2 -Wall -fPIC -I./include
LDLIBS = -lpthread -lsqlite3 -ldl 
STRIP = strip

konoha = konoha1
version = 1.0
PREFIX = ${DESTDIR}/usr/local
dir    = build

packages = \
	$(dir)/math.so \

objs = \
	$(dir)/asm.o \
	$(dir)/term.o \
	$(dir)/typing.o\
	$(dir)/script.o\
	$(dir)/vmcodelibs.o\
	$(dir)/message.o\
	$(dir)/array.o \
	$(dir)/bytes.o \
	$(dir)/class.o\
	$(dir)/closure.o \
	$(dir)/context.o\
	$(dir)/evidence.o \
	$(dir)/exports.o \
	$(dir)/map.o \
	$(dir)/memory.o\
	$(dir)/number.o \
	$(dir)/os.o\
	$(dir)/query.o \
	$(dir)/runtime.o \
	$(dir)/security.o \
	$(dir)/semantics.o\
	$(dir)/stack.o\
	$(dir)/stream.o \
	$(dir)/string.o \
	$(dir)/struct.o \
	$(dir)/system.o \
	$(dir)/ffi.o \
	$(dir)/thread.o\
	$(dir)/mt19937ar.o \

.PHONY: all
all: $(dir)/$(konoha) $(dir)/lib$(konoha).so $(packages)

$(dir)/$(konoha) : $(dir)/konoha.o $(objs)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)
	$(STRIP) $@

$(dir)/lib$(konoha).so: $(objs)
	$(CC) $(CFLAGS) -shared -o $@ $^ $(LDLIBS)

## object files

$(dir)/asm.o : src/lang/asm.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/term.o : src/lang/term.c
	$(CC) $(CFLAGS) -c $^ -o $@	

$(dir)/typing.o : src/lang/typing.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/script.o : src/lang/script.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/vmcodelibs.o : src/lang/vmcodelibs.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/message.o : src/lang/message.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/array.o : src/main/array.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/bytes.o : src/main/bytes.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/class.o : src/main/class.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/closure.o : src/main/closure.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/context.o: src/main/context.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/evidence.o : src/main/evidence.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/exports.o : src/main/exports.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/map.o : src/main/map.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/memory.o: src/main/memory.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/number.o : src/main/number.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/os.o: src/main/os.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/query.o : src/main/query.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/ffi.o : src/main/ffi.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/runtime.o : src/main/runtime.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/security.o : src/main/security.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/semantics.o: src/main/semantics.c
	$(CC) $(CFLAGS) -c $^ -o $@

#$(dir)/setjmp.o : src/main/setjmp.c
#	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/stack.o: src/main/stack.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/stream.o : src/main/stream.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/string.o : src/main/string.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/struct.o : src/main/struct.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/system.o : src/main/system.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/thread.o: src/main/thread.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/mt19937ar.o : src/ext/mt19937ar.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/konoha.o : src/konoha.c
	$(CC) $(CFLAGS) -c $^ -o $@


## math
LDLIBS_libmath = -lm

libmath = \
	$(dir)/math.o\

$(dir)/math.so: $(libmath)
	$(CC) $(CFLAGS) -shared -o $@ $^ $(LDLIBS_libmath)

$(dir)/math.o : package/konoha.math/math.c
	$(CC) $(CFLAGS) -c $^ -o $@

## install
.PHONY: install
install:
	bash $(dir)/uninstall.sh $(konoha) $(PREFIX)
	bash $(dir)/install.sh $(konoha) $(PREFIX)
	bash $(dir)/pkginstall.sh math $(PREFIX)/konoha/package/$(version) konoha.math

## uninstall
.PHONY: uninstall
uninstall:
	bash $(dir)/uninstall.sh $(konoha) $(PREFIX)

## clean
.PHONY: clean
clean:
	$(RM) -rf $(dir)/*.so $(dir)/*.o $(dir)/$(konoha)
