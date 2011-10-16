CC=gcc
LINK=
PKG=mysql
CFLAGS = -O2 -g -Wall -fmessage-length=0 -fPIC `mysql_config --cflags`
LDLIBS = `mysql_config --libs` -lkonoha
RM=rm
LIB=

ifeq ($(OS),Windows_NT)
	# for Windows
else
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
endif

OBJS= $(PKG).o
.PHONY: all
all: $(LIB)

$(PKG).o: $(PKG).c
	$(CC) $(CFLAGS) -o $@ -c $^

$(LIB): $(OBJS)
	$(LINK) $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -rf $(OBJS) $(LIB)
