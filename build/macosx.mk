# Makefile for macosx
#

CC = gcc
CFLAGS = -g -O2 -Wall -fPIC -I./include
CFLAGS_32 = $(CFLAGS) -m32
CFLAGS_64 = $(CFLAGS) -m64
LDLIBS = -lpthread
LIPO = lipo
STRIP = strip

konoha = konoha1
version = 1.0
PREFIX = /usr/local
dir    = build

packages = \
	$(dir)/lib$(konoha).dylib \
	$(dir)/math.dylib \

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
	$(dir)/setjmp.o \
	$(dir)/stack.o\
	$(dir)/stream.o \
	$(dir)/string.o \
	$(dir)/struct.o \
	$(dir)/system.o \
	$(dir)/thread.o\
	$(dir)/mt19937ar.o \

objs_64 = \
	$(dir)/asm_64.o \
	$(dir)/term_64.o \
	$(dir)/typing_64.o\
	$(dir)/script_64.o\
	$(dir)/vmcodelibs_64.o\
	$(dir)/message_64.o\
	$(dir)/array_64.o \
	$(dir)/bytes_64.o \
	$(dir)/class_64.o\
	$(dir)/closure_64.o \
	$(dir)/context_64.o\
	$(dir)/evidence_64.o \
	$(dir)/exports_64.o \
	$(dir)/map_64.o \
	$(dir)/memory_64.o\
	$(dir)/number_64.o \
	$(dir)/os_64.o\
	$(dir)/query_64.o \
	$(dir)/runtime_64.o \
	$(dir)/security_64.o \
	$(dir)/semantics_64.o\
	$(dir)/setjmp_64.o \
	$(dir)/stack_64.o\
	$(dir)/stream_64.o \
	$(dir)/string_64.o \
	$(dir)/struct_64.o \
	$(dir)/system_64.o \
	$(dir)/thread_64.o\
	$(dir)/mt19937ar_64.o \

objs_32 = \
	$(dir)/asm_32.o \
	$(dir)/term_32.o \
	$(dir)/typing_32.o\
	$(dir)/script_32.o\
	$(dir)/vmcodelibs_32.o\
	$(dir)/message_32.o\
	$(dir)/array_32.o \
	$(dir)/bytes_32.o \
	$(dir)/class_32.o\
	$(dir)/closure_32.o \
	$(dir)/context_32.o\
	$(dir)/evidence_32.o \
	$(dir)/exports_32.o \
	$(dir)/map_32.o \
	$(dir)/memory_32.o\
	$(dir)/number_32.o \
	$(dir)/os_32.o\
	$(dir)/query_32.o \
	$(dir)/runtime_32.o \
	$(dir)/security_32.o \
	$(dir)/semantics_32.o\
	$(dir)/setjmp_32.o \
	$(dir)/stack_32.o\
	$(dir)/stream_32.o \
	$(dir)/string_32.o \
	$(dir)/struct_32.o \
	$(dir)/system_32.o \
	$(dir)/thread_32.o\
	$(dir)/mt19937ar_32.o \

.PHONY: all
all: $(dir)/$(konoha) $(packages)

$(dir)/$(konoha) : $(dir)/$(konoha)_32 $(dir)/$(konoha)_64 
	$(LIPO) -create -arch i386 $(dir)/$(konoha)_32 -arch x86_64 $(dir)/$(konoha)_64 -o $@
	$(STRIP) $@

$(dir)/$(konoha)_64 : $(objs_64) $(dir)/konoha_64.o
	$(CC) $(CFLAGS_64) -o $@ $^ $(LDLIBS)
	
$(dir)/$(konoha)_32 : $(objs_32) $(dir)/konoha_32.o
	$(CC) $(CFLAGS_32) -o $@ $^ $(LDLIBS)

$(dir)/lib$(konoha).dylib : $(dir)/lib$(konoha)_32.dylib $(dir)/lib$(konoha)_64.dylib
	$(LIPO) -create -arch i386 $(dir)/lib$(konoha)_32.dylib -arch x86_64 $(dir)/lib$(konoha)_64.dylib -o $@

$(dir)/lib$(konoha)_64.dylib: $(objs_64)
	$(CC) $(CFLAGS_64) -dynamiclib -o $@ $^ $(LDLIBS)

$(dir)/lib$(konoha)_32.dylib: $(objs_32)
	$(CC) $(CFLAGS_32) -dynamiclib -o $@ $^ $(LDLIBS)

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

$(dir)/runtime.o : src/main/runtime.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/security.o : src/main/security.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/semantics.o: src/main/semantics.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(dir)/setjmp.o : src/main/setjmp.c
	$(CC) $(CFLAGS) -c $^ -o $@

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


## -m32

$(dir)/asm_64.o : src/lang/asm.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/term_64.o : src/lang/term.c
	$(CC) $(CFLAGS_64) -c $^ -o $@	

$(dir)/typing_64.o : src/lang/typing.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/script_64.o : src/lang/script.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/vmcodelibs_64.o : src/lang/vmcodelibs.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/message_64.o : src/lang/message.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/array_64.o : src/main/array.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/bytes_64.o : src/main/bytes.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/class_64.o : src/main/class.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/closure_64.o : src/main/closure.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/context_64.o: src/main/context.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/evidence_64.o : src/main/evidence.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/exports_64.o : src/main/exports.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/map_64.o : src/main/map.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/memory_64.o: src/main/memory.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/number_64.o : src/main/number.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/os_64.o: src/main/os.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/query_64.o : src/main/query.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/runtime_64.o : src/main/runtime.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/security_64.o : src/main/security.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/semantics_64.o: src/main/semantics.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/setjmp_64.o : src/main/setjmp.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/stack_64.o: src/main/stack.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/stream_64.o : src/main/stream.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/string_64.o : src/main/string.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/struct_64.o : src/main/struct.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/system_64.o : src/main/system.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/thread_64.o: src/main/thread.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/mt19937ar_64.o : src/ext/mt19937ar.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

$(dir)/konoha_64.o : src/konoha.c
	$(CC) $(CFLAGS_64) -c $^ -o $@

## -m32

$(dir)/asm_32.o : src/lang/asm.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/term_32.o : src/lang/term.c
	$(CC) $(CFLAGS_32) -c $^ -o $@	

$(dir)/typing_32.o : src/lang/typing.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/script_32.o : src/lang/script.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/vmcodelibs_32.o : src/lang/vmcodelibs.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/message_32.o : src/lang/message.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/array_32.o : src/main/array.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/bytes_32.o : src/main/bytes.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/class_32.o : src/main/class.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/closure_32.o : src/main/closure.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/context_32.o: src/main/context.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/evidence_32.o : src/main/evidence.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/exports_32.o : src/main/exports.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/map_32.o : src/main/map.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/memory_32.o: src/main/memory.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/number_32.o : src/main/number.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/os_32.o: src/main/os.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/query_32.o : src/main/query.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/runtime_32.o : src/main/runtime.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/security_32.o : src/main/security.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/semantics_32.o: src/main/semantics.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/setjmp_32.o : src/main/setjmp.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/stack_32.o: src/main/stack.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/stream_32.o : src/main/stream.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/string_32.o : src/main/string.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/struct_32.o : src/main/struct.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/system_32.o : src/main/system.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/thread_32.o: src/main/thread.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/mt19937ar_32.o : src/ext/mt19937ar.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

$(dir)/konoha_32.o : src/konoha.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

## math
LDLIBS_libmath = -lm

libmath_64 = \
	$(dir)/math_64.o\

libmath_32 = \
	$(dir)/math_32.o\
	
$(dir)/math.dylib: $(dir)/math_64.dylib $(dir)/math_32.dylib
	$(LIPO) -create -arch i386 $(dir)/math_32.dylib -arch x86_64 $(dir)/math_64.dylib -o $@

$(dir)/math_64.dylib: $(libmath_64)
	$(CC) $(CFLAGS_64) -dynamiclib -o $@ $^ $(LDLIBS_libmath)
	
$(dir)/math_32.dylib: $(libmath_32)
	$(CC) $(CFLAGS_32) -dynamiclib -o $@ $^ $(LDLIBS_libmath)

$(dir)/math_64.o : package/konoha.math/math.c
	$(CC) $(CFLAGS_64) -c $^ -o $@
	
$(dir)/math_32.o : package/konoha.math/math.c
	$(CC) $(CFLAGS_32) -c $^ -o $@

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
	$(RM) -rf $(dir)/*.dylib $(dir)/*.o $(dir)/$(konoha)_32 $(dir)/$(konoha)_64 $(dir)/$(konoha)

