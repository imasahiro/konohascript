# Makefile for macosx (i386)
#

CC = /usr/bin/arch -arch i386 /usr/bin/gcc
CFLAGS = -O2 -g -Wall -fPIC -I./include
#CFLAGS ?= -g3 -O0 -Wall -fPIC -I./include -DK_USING_DEBUG

ARCH = -arch i386 
include build/macosx.mk
