include(CheckTypeSize)
include(CheckIncludeFiles)
include(CheckSymbolExists)

cmake_minimum_required(VERSION 2.8)
# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$HOME

set(CMAKE_C_FLAGS_RELEASE "-O2 -Wall")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g3 -Wall")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_OSX_ARCHITECTURES "i386;x86_64")

project(konoha)
set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")

set(PACKAGE_NAME ${PROJECT_NAME})
set(PACKAGE_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
set(PACKAGE_STRING ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})

set(K_CONFIG_ARCH "${CMAKE_SYSTEM}")
set(K_CONFIG_OS   "${CMAKE_SYSTEM_NAME}")
set(K_CONFIG_CPU  "${CMAKE_SYSTEM_PROCESSOR}")

set(SO_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")
set(ARCHIVE_NAME ${PACKAGE_STRING})

include_directories("${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}")

set(KONOHA_SRC
	src/lang/typing.c
	src/lang/term.c
	src/lang/asm.c
	src/lang/script.c
	src/lang/vmcodelibs.c
	src/lang/message.c
	src/main/array.c
	src/main/bytes.c
	src/main/class.c
	src/main/closure.c
	src/main/context.c
	src/main/evidence.c
	src/main/exports.c
	src/main/map.c
	src/main/memory.c
	src/main/number.c
	src/main/os.c
	src/main/query.c
	src/main/runtime.c
	src/main/security.c
	src/main/semantics.c
	src/main/ffi.c
	src/main/stack.c
	src/main/stream.c
	src/main/string.c
	src/main/struct.c
	src/main/system.c
	src/main/thread.c
	src/ext/mt19937ar.c
)

check_include_file(malloc.h HAVE_MALLOC_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)
check_include_file(string.h HAVE_STRING_H)
check_include_file(float.h HAVE_FLOAT_H)
check_include_file(langinfo.h HAVE_LANGINFO_H)
check_include_file(localcharset.h HAVE_LOCALCHARSET_H)
check_include_file(limits.h HAVE_LIMITS_H)
check_include_file(locale.h HAVE_LOCALE_H)
check_include_file(stdlib.h HAVE_STDLIB_H)
check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("sys/param.h" HAVE_SYS_PARAM_H)
check_include_file("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file("sys/sysctl.h" HAVE_SYS_SYSCTL_H)
check_include_file("sys/types.h" HAVE_SYS_SYSCTL_H)
check_include_file(pcre.h HAVE_PRCE_H)

find_path(HAVE_SYS_MMAM_H  mman.h PATHS ${include_locations} PATH_SUFFIXES sys)
find_path(HAVE_SYS_STAT_H stat.h PATHS ${include_locations} PATH_SUFFIXES sys)
find_path(HAVE_UNISTD_H unistd.h ${include_locations})


find_library(HAVE_LIBDL dl)
find_library(HAVE_LIBM  m)
find_library(HAVE_LIBICONV iconv)
find_library(HAVE_PTHREAD pthread)
find_library(HAVE_LIBSQLITE3 sqlite3)
find_library(HAVE_LIBPCRE pcre)

check_type_size("void *" SIZEOF_VOIDP)
check_type_size(long SIZEOF_LONG)
check_type_size(int  SIZEOF_INT)
check_type_size(float  SIZEOF_FLOAT)
check_type_size(double  SIZEOF_DOUBLE)

set(_HEADERS stdio.h stdlib.h string.h ctype.h)
if(UNIX)
	set(_HEADERS ${_HEADERS} sys/mman.h unistd.h)
endif(UNIX)

if(APPLE)
	set(_HEADERS ${_HEADERS} mach-o/dyld.h)
endif(APPLE)

if(CYGWIN)
endif(CYGWIN)

if(MSVC)
endif(MSVC)

check_symbol_exists(malloc         "${_HEADERS}" HAVE_MALLOC)
check_symbol_exists(isascii        "${_HEADERS}" HAVE_ISASCII)
check_symbol_exists(memset         "${_HEADERS}" HAVE_MEMSET)
check_symbol_exists(realpath       "${_HEADERS}" HAVE_REALPATH)
check_symbol_exists(qsort_r        "${_HEADERS}" HAVE_QSORT_R)
check_symbol_exists(posix_memalign "${_HEADERS}" HAVE_POSIX_MEMALIGN)
check_symbol_exists(mmap           "${_HEADERS}" HAVE_MMAP)
check_symbol_exists(sysctlbyname   "${_HEADERS}" HAVE_SYSCTLBYNAME)
check_symbol_exists(mlock          "${_HEADERS}" HAVE_MLOCK)
check_symbol_exists(snprintf       "${_HEADERS}" HAVE_SNPRINTF)

set(CMAKE_REQUIRED_LIBRARIES HAVE_LIBDL ${HAVE_LIBDL})

set(ExtraLibs)
if(HAVE_LIBSQLITE3)
	set(ExtraLibs ${ExtraLibs} ${HAVE_LIBSQLITE3})
endif(HAVE_LIBSQLITE3)

if(HAVE_LIBICONV)
	set(ExtraLibs ${ExtraLibs} ${HAVE_LIBICONV})
endif(HAVE_LIBICONV)

if(HAVE_PTHREAD)
	set(ExtraLibs ${ExtraLibs} ${HAVE_PTHREAD})
endif(HAVE_PTHREAD)

if(HAVE_LIBPCRE)
	set(ExtraLibs ${ExtraLibs} ${HAVE_LIBPCRE})
endif(HAVE_LIBPCRE)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
	set(K_USING_DEBUG 1)
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

add_library(konoha SHARED ${KONOHA_SRC})
target_link_libraries(konoha ${ExtraLibs})
set_target_properties(konoha PROPERTIES VERSION ${PACKAGE_VERSION} SOVERSION ${SO_VERSION})

add_executable(konoha1 src/konoha.c)
target_link_libraries(konoha1 konoha)
set_target_properties(konoha1 PROPERTIES OUTPUT_NAME konoha)

install(TARGETS konoha1 konoha 
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		)

install(DIRECTORY include/ DESTINATION include 
		FILES_MATCHING
		PATTERN "*.h"
		PATTERN ".svn" EXCLUDE
		)

#set(CPACK_SOURCE_GENERATOR "TGZ;DEB")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "uh")
set(CPACK_SOURCE_PACKAGE_FILE_NAME ${ARCHIVE_NAME})
set(CPACK_PACKAGE_NAME "Konoha")
#set(CPACK_PACKAGE_VENDOR "konoha.org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Konoha - Statically-typed scripting language")
set(CPACK_PACKAGE_VERSION       ${PACKAGE_VERSION})
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
include(CPack)

