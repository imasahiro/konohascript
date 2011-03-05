# Last modified by Masahiro Ide imasahiro@users.sourceforge.jp

CC = gcc
CFLAGS = -O0 -g3 -Wall -fmessage-length=0 -fPIC
LDLIBS = -lkonoha

pkgname = socket

library = "$(pkgname).dylib"

.PHONY: all
all: $(library)

objs = "$(pkgname).o"

"$(pkgname).o": $(pkgname).c
	$(CC) $(CFLAGS) -o $@ -c $^

$(library): $(objs)
	$(CC) -dynamiclib -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -rf $(objs) $(library)

