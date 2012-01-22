## json package
find_library(HAVE_LIB_JSON json)
check_include_files("json/json.h" HAVE_JSON_JSON_H)

set(PACKAGE_SOURCE_CODE json.c)
set(PACKAGE_SCRIPT_CODE json.k)
set(PACKAGE_INCLUDE_DIR)
set(PACKAGE_EXTRA_LIBRARY ${HAVE_LIB_JSON})
add_konoha_package(json HAVE_LIB_JSON HAVE_JSON_JSON_H)
