# cairo package
project(cairo)
find_library(HAVE_LIB_CAIRO NAMES cairo)
check_include_files("cairo/cairo.h" HAVE_CAIRO_CAIRO_H)
set(PACKAGE_SOURCE_CODE cairo.c)
set(PACKAGE_SCRIPT_CODE cairo.k)
set(PACKAGE_EXTRA_LIBRARY ${HAVE_LIB_CAIRO})
add_konoha_package(cairo HAVE_CAIRO_CAIRO_H HAVE_LIB_CAIRO)
