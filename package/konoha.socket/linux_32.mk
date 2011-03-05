CC = gcc
CFLAGS = -O2 -Wall -fmessage-length=0 -fPIC -g

LDLIBS = -lkonoha

pkgname = socket

library = "$(pkgname).so"

.PHONY: all
all: $(library)

objs = "$(pkgname).o"

"$(pkgname).o": $(pkgname).c
	$(CC) $(CFLAGS) -o $@ -c $^

$(library): $(objs)
	$(CC) -shared -Wl -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -rf $(objs) $(library)

