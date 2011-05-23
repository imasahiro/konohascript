# Makefile for mingw
#

CC = gcc
CFLAGS ?= -g0 -O2 -Wall -I./include -I/mingw/include
#CFLAGS = -g3 -O0 -Wall -I./include -I/mingw/include
LDLIBS ?= -lpcre -liconv -lsqlite3 -lpthread -lws2_32 -L/mingw/lib

konoha = konoha
version = 1.0
PREFIX = /mingw
dir    = build

packages = \
	$(dir)/lib$(konoha)1.dll \
	$(dir)/i.dll \
	$(dir)/math.dll \
#	$(dir)/socket.dll \

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
	$(dir)/ffi.o \
	$(dir)/stack.o\
	$(dir)/stream.o \
	$(dir)/string.o \
	$(dir)/struct.o \
	$(dir)/system.o \
	$(dir)/thread.o\
	$(dir)/mt19937ar.o \

svnversion_exists := $(shell which svnversion)
define compile_with_revision
	$(CC) -DK_REVISION=$(shell svn info 2>&1 | python -c 'import sys;print sys.stdin.readlines()[4].split(":")[1].strip();')
endef

define compile
	$(CC) -DK_REVISION=$(shell $(svnversion_exists) -n ./)
endef

MYCC = $(if $(svnversion_exists), $(compile_with_revision), $(compile))

.PHONY: all
all: $(dir)/$(konoha) $(packages)

#$(dir)/$(konoha) : src/konoha.c $(dir)/lib$(konoha)1.dll
#	$(MYCC) $(CFLAGS) -o $@ src/konoha.c -L./$(dir) -l$(konoha)1
$(dir)/$(konoha) : src/konoha.c $(dir)/lib$(konoha)1.dll $(dir)/konoha.res
	$(MYCC) $(CFLAGS) -o $@ src/konoha.c -L./$(dir) -l$(konoha)1 $(dir)/konoha.res

$(dir)/lib$(konoha)1.dll: $(objs)
	$(MYCC) $(CFLAGS) -L./$(dir) -shared -o $@ $^ $(LDLIBS)

$(dir)/konoha.res: $(dir)/konoha.rc
	windres $(dir)/konoha.rc -O coff -o $(dir)/konoha.res

## object files

$(dir)/asm.o : src/lang/asm.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/term.o : src/lang/term.c
	$(MYCC) $(CFLAGS) -c $^ -o $@	

$(dir)/typing.o : src/lang/typing.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/script.o : src/lang/script.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/vmcodelibs.o : src/lang/vmcodelibs.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/message.o : src/lang/message.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/array.o : src/main/array.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/bytes.o : src/main/bytes.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/class.o : src/main/class.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/closure.o : src/main/closure.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/context.o: src/main/context.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/evidence.o : src/main/evidence.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/exports.o : src/main/exports.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/map.o : src/main/map.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/memory.o: src/main/memory.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/number.o : src/main/number.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/os.o: src/main/os.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/query.o : src/main/query.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/runtime.o : src/main/runtime.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/security.o : src/main/security.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/semantics.o: src/main/semantics.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/ffi.o : src/main/ffi.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/stack.o: src/main/stack.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/stream.o : src/main/stream.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/string.o : src/main/string.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/struct.o : src/main/struct.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/system.o : src/main/system.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/thread.o: src/main/thread.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

$(dir)/mt19937ar.o : src/ext/mt19937ar.c
	$(MYCC) $(CFLAGS) -c $^ -o $@

## konoha.i interactive mode

LDLIBS_libi = 
objs_i = $(dir)/i.o\

$(dir)/i.dll: $(objs_i)
	$(MYCC) $(CFLAGS) -shared -o $@ $^ $(LDLIBS_libi)

$(dir)/i.o : package/konoha.i/i.c
	$(MYCC) $(CFLAGS) -D_SETUP -c $^ -o $@

## math
LDLIBS_libmath = -lm
obj_math = $(dir)/math.o\

$(dir)/math.dll: $(obj_math)
	$(MYCC) $(CFLAGS) -shared -o $@ $^ $(LDLIBS_libmath)

$(dir)/math.o : package/konoha.math/math.c
	$(MYCC) $(CFLAGS) -D_SETUP -c $^ -o $@

## socket
LDLIBS_libsocket = 
objs_posix = $(dir)/socket.o\

$(dir)/socket.dll: $(objs_posix)
	$(MYCC) $(CFLAGS) -shared -o $@ $^ $(LDLIBS_libsocket)

$(dir)/socket.o : package/konoha.socket/socket.c
	$(MYCC) $(CFLAGS) -D_SETUP -c $^ -o $@

## install
.PHONY: install
install:
	bash $(dir)/uninstall.sh $(konoha) $(PREFIX)
	bash $(dir)/install.sh $(konoha) $(PREFIX)
	bash $(dir)/pkginstall.sh i $(PREFIX)/package/$(version) konoha.i
	bash $(dir)/pkginstall.sh math $(PREFIX)/package/$(version) konoha.math
	bash $(dir)/pkginstall.sh socket $(PREFIX)/package/$(version) konoha.socket

## uninstall
.PHONY: uninstall
uninstall:
	bash $(dir)/uninstall.sh $(konoha) $(PREFIX)

## clean
.PHONY: clean
clean:
	$(RM) -rf $(dir)/*.dll $(dir)/*.o $(dir)/$(konoha).exe $(dir)/*.res 
#	$(RM) -rf $(dir)/*.dll $(dir)/*.o $(dir)/$(konoha).exe
