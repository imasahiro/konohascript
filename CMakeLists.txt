include(CheckTypeSize)
include(CheckIncludeFiles)
include(CheckSymbolExists)
include(CheckLibraryExists)
include(CheckCSourceCompiles)

cmake_minimum_required(VERSION 2.8)
# -DCMAKE_BUILD_TYPE=Debug
# -DCMAKE_INSTALL_PREFIX=$HOME
# -DCMAKE_VERBOSE_MAKEFILE=1
project(konoha)
set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")

set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_VERSION  ${VERSION_MAJOR}.${VERSION_MINOR})

set(K_CONFIG_ARCH ${CMAKE_SYSTEM})
set(K_CONFIG_OS   ${CMAKE_SYSTEM_NAME})
set(K_CONFIG_CPU  ${CMAKE_SYSTEM_PROCESSOR})

set(SO_VERSION   ${VERSION_MAJOR}.${VERSION_MINOR})
set(ARCHIVE_NAME ${PACKAGE_STRING})

set(KONOHA_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${KONOHA_INCLUDE_DIRS}  ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${INCLUDE_DIRS})

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release" )
endif()
set(KONOHA_BUILD_TYPE ${CMAKE_BUILD_TYPE})

SET(CMAKE_C_FLAGS         "-Wall")
SET(CMAKE_C_FLAGS_RELEASE "-O2 -g")
SET(CMAKE_C_FLAGS_DEBUG   "-O0 -g3")
SET(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2 -g")
SET(CMAKE_CXX_FLAGS_DEBUG   "-Wall -O0 -g3")
# -Wold-style-cast 
#if("${CMAKE_C_COMPILER}" STREQUAL "/usr/bin/gcc")
#	set(CMAKE_OSX_ARCHITECTURES "i386;x86_64")
#endif()
#if(${CMAKE_C_COMPILER} MATCHES "clang")
#	SET(CMAKE_C_FLAGS "--analyze ${CMAKE_C_FLAGS}")
#endif()

set(KONOHA_CFLAGS)
macro(konoha_add_definitions)
	foreach(arg ${ARGN})
		set(KONOHA_CFLAGS "${KONOHA_CFLAGS} ${arg}")
	endforeach(arg ${ARGN})
	add_definitions(${ARGN})
endmacro(konoha_add_definitions)

macro(POP _STR _DELIM _RESULT)
    string(REPLACE ${_DELIM} ";" _tmp ${_STR})
    list(REVERSE _tmp)
    list(GET _tmp 0 ${_RESULT})
endmacro()

macro(PKGNAME _STR _RESULT)
    set(_tmp)
    POP(${_STR} "/" _tmp)
    POP(${_tmp} "." ${_RESULT})
endmacro()

konoha_add_definitions(-DHAVE_CONFIG_H)

set(KONOHA_SRC
	src/lang/typing.c
	src/lang/term.c
	src/lang/asm.c
	src/lang/script.c
	src/lang/vmcodelibs.c
	src/lang/message.c
	src/main/array.c
	src/gc/gc.c
	src/main/bytes.c
	src/main/class.c
	src/main/closure.c
	src/main/context.c
	src/main/evidence.c
	src/main/exports.c
	src/main/map.c
	src/main/number.c
	src/main/os.c
	src/main/link.c
	src/main/query.c
	src/main/runtime.c
	src/main/security.c
	src/main/semantics.c
	src/lang/ffi.c
	src/main/stack.c
	src/main/stream.c
	src/main/string.c
	src/main/struct.c
	src/main/system.c
	src/main/thread.c
	src/ext/mt19937ar.c
	src/sugar/sugar.c
)
set(KONOHA_BIN src/konoha.c)

check_include_files(malloc.h HAVE_MALLOC_H)
check_include_files(inttypes.h HAVE_INTTYPES_H)
check_include_files(string.h HAVE_STRING_H)
check_include_files(float.h HAVE_FLOAT_H)
check_include_files(langinfo.h HAVE_LANGINFO_H)
check_include_files(localcharset.h HAVE_LOCALCHARSET_H)
check_include_files(limits.h HAVE_LIMITS_H)
check_include_files(locale.h HAVE_LOCALE_H)
check_include_files(stdlib.h HAVE_STDLIB_H)
check_include_files("sys/time.h" HAVE_SYS_TIME_H)
check_include_files("sys/param.h" HAVE_SYS_PARAM_H)
check_include_files("sys/stat.h" HAVE_SYS_STAT_H)
check_include_files("sys/sysctl.h" HAVE_SYS_SYSCTL_H)
check_include_files("sys/types.h" HAVE_SYS_SYSCTL_H)

find_path(HAVE_PCRE_H  pcre.h  PATHS ${include_locations})
find_path(HAVE_ONIG_H  oniguruma.h  PATHS ${include_locations})
find_path(HAVE_SYS_MMAM_H mman.h PATHS ${include_locations} PATH_SUFFIXES sys)
find_path(HAVE_SYS_STAT_H stat.h PATHS ${include_locations} PATH_SUFFIXES sys)
find_path(HAVE_UNISTD_H unistd.h ${include_locations})

find_library(HAVE_LIBDL        NAMES dl)
find_library(HAVE_LIBM         NAMES m)
find_library(HAVE_PTHREAD      NAMES pthread)
find_library(HAVE_LIBSQLITE3   NAMES sqlite3)
find_library(HAVE_LIBCURL      NAMES curl)
find_library(HAVE_LIBMEMCACHED NAMES memcached)

check_type_size("void *" SIZEOF_VOIDP)
check_type_size(long     SIZEOF_LONG)
check_type_size(int      SIZEOF_INT)
check_type_size(float    SIZEOF_FLOAT)
check_type_size(double   SIZEOF_DOUBLE)

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

if(MINGW)
	set(CMAKE_RC_COMPILER_INIT windres)
	ENABLE_LANGUAGE(RC)
	SET(CMAKE_RC_COMPILE_OBJECT
		"<CMAKE_RC_COMPILER> <FLAGS> -O coff <DEFINES> -i <SOURCE> -o <OBJECT>")
	set(KONOHA_BIN ${KONOHA_BIN} ${CMAKE_CURRENT_SOURCE_DIR}/resources/konoha.rc)
endif(MINGW)

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

macro(CHECK_PROTOTYPE _SYMBOL _HEADER _RESULT)
	set(_INCLUDE_FILE)
	foreach(it ${_HEADER})
		set(_INCLUDE_FILE "${_INCLUDE_FILE}#include <${it}>\n")
	endforeach(it)
	SET(_CHECK_SOURCE_CODE "
${_INCLUDE_FILE}
void cmakeRequireSymbol(int dummy,...){(void)dummy;}
int main()
{
#ifndef ${_SYMBOL}
#ifndef _MSC_VER
  cmakeRequireSymbol(0,&${_SYMBOL});
#else
  char i = sizeof(&${_SYMBOL});
#endif
#endif
	return 0;
}
")
	check_c_source_compiles("${_CHECK_SOURCE_CODE}" ${_RESULT})
endmacro(CHECK_PROTOTYPE)

macro(CHECK_BUILTINS _FUNC _RESULT)
	SET(_CHECK_SOURCE_CODE "
${_INCLUDE_FILE}
int main() {
	${_FUNC};
	return 0;
}
")
	check_c_source_compiles("${_CHECK_SOURCE_CODE}" ${_RESULT})
endmacro(CHECK_BUILTINS)

check_builtins("__builtin_ctzll(0)" HAVE_BUILTIN_CTZLL)

set(ExtraLibs)
set(MessageLibs)

set(_HEADERS_SAVE ${_HEADERS})

if(HAVE_LIBSQLITE3)
	set(ExtraLibs ${ExtraLibs} ${HAVE_LIBSQLITE3})
	set(MessageLibs ${MessageLibs} sqlite3)
endif(HAVE_LIBSQLITE3)

if(HAVE_LIBCURL)
	set(ExtraLibs ${ExtraLibs} ${HAVE_LIBCURL})
	set(MessageLibs ${MessageLibs} curl)
endif(HAVE_LIBCURL)

if(HAVE_LIBDL)
	set(ExtraLibs ${ExtraLibs} ${HAVE_LIBDL})
	set(MessageLibs ${MessageLibs} dl)
endif()

if(HAVE_PTHREAD)
	set(ExtraLibs ${ExtraLibs} ${HAVE_PTHREAD})
	set(MessageLibs ${MessageLibs} pthread)
	set(K_USING_THREAD 1)
endif(HAVE_PTHREAD)

if(HAVE_LIBMEMCACHED)
	set(ExtraLibs ${ExtraLibs} ${HAVE_LIBMEMCACHED})
	set(MessageLibs ${MessageLibs} memcached)
endif(HAVE_LIBMEMCACHED)

#set(FFI_INCLUDE_DIR "")
#set(FFI_LIBRARY_DIR "")

macro(CHECK_HEADER _HEADER _PATH _RESULT)
	if(${_PATH})
		find_path(${_RESULT} ${_HEADER} PATHS ${${_PATH}})
	else()
		find_path(${_RESULT} ${_HEADER})
	endif()
endmacro(CHECK_HEADER)

#check_header(ffi.h FFI_INCLUDE_DIR FFI_INCLUDE_PATH)
#
#if(FFI_INCLUDE_PATH)
#	set(FFI_HEADER ffi.h)
#	set(HAVE_FFI_H 1)
#	check_header(ffi.h FFI_INCLUDE_DIR FFI_INCLUDE_PATH_CHECK)
#	if(NOT FFI_INCLUDE_PATH_CHECK)
#		unset(FFI_HEADER)
#		unset(HAVE_FFI_H)
#	endif()
#endif()
#
#if(NOT FFI_INCLUDE_PATH_CHECK)
#	check_header(ffi/ffi.h FFI_INCLUDE_DIR FFI_INCLUDE_PATH)
#	if(FFI_INCLUDE_PATH)
#		set(FFI_HEADER ffi/ffi.h)
#		set(HAVE_FFI_FFI_H 1)
#	endif()
#endif()
#
#if(FFI_INCLUDE_DIR)
#	include_directories(${FFI_INCLUDE_DIR})
#endif(FFI_INCLUDE_DIR)
#
#if(NOT FFI_HEADER)
#	message(FATAL_ERROR "ffi.h is not found. You may run cmake with -DFFI_INCLUDE_DIR=/path/to/ffi/include")
#endif()

#macro(CHECK_LIBFFI _RESULT)
#	if(FFI_LIBRARY_DIR)
#		find_library(${_RESULT} ffi PATHS ${FFI_LIBRARY_DIR})
#	else()
#		find_library(${_RESULT} ffi)
#	endif(FFI_LIBRARY_DIR)
#endmacro(CHECK_LIBFFI)
#
#check_libffi(HAVE_LIBFFI)
#if(NOT HAVE_LIBFFI)
#	message(FATAL_ERROR "libffi not found. You may run cmake again with -DFFI_LIBRARY_DIR=/path/to/lib/libffi or install libffi-dev")
#endif()
#set(ExtraLibs ${ExtraLibs} ${v} ${HAVE_LIBFFI})
#set(MessageLibs ${MessageLibs} ffi)

#if("${HAVE_PCRE_H}" STREQUAL "")
#	message(FATAL_ERROR "pcre.h not found. please install libpcre-dev")
#else()
#	if(HAVE_PCRE_H)
#		set(ExtraLibs ${ExtraLibs} ${HAVE_LIBPCRE})
#		set(MessageLibs ${MessageLibs} pcre)
#	endif(HAVE_PCRE_H)
#endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(K_USING_DEBUG 1)
endif()

FIND_FILE(HAS_DOTSVN .svn PATHS "${CMAKE_CURRENT_SOURCE_DIR}/include")
if("${HAS_DOTSVN}" MATCHES ".svn")
	find_package(Subversion)
	if(Subversion_FOUND)
		Subversion_WC_INFO(${CMAKE_CURRENT_SOURCE_DIR}/include ER)
		set(SUBVERSION_REVISION ${ER_WC_REVISION})
		konoha_add_definitions(-DK_REVISION=${SUBVERSION_REVISION})
	endif(Subversion_FOUND)
endif()

option(USE_LLVM "Use llvm" OFF)
if(USE_LLVM)
	konoha_add_definitions(-DK_USING_LLVM)
	find_program(LLVM_CONFIG NAMES llvm-config DOC "llvm-config")
	execute_process(
			COMMAND ${LLVM_CONFIG} --cppflags
			OUTPUT_VARIABLE LLVM_CFLAGS
			OUTPUT_STRIP_TRAILING_WHITESPACE
			)
	execute_process(
			COMMAND ${LLVM_CONFIG} --cxxflags
			OUTPUT_VARIABLE LLVM_CXXFLAGS
			OUTPUT_STRIP_TRAILING_WHITESPACE
			)
	execute_process(
			COMMAND ${LLVM_CONFIG} --ldflags
			OUTPUT_VARIABLE LLVM_LDFLAGS
			OUTPUT_STRIP_TRAILING_WHITESPACE
			)
	execute_process(
		COMMAND ${LLVM_CONFIG} --libs core jit native linker ipo engine interpreter
		OUTPUT_VARIABLE LLVM_JIT_LIBS
		OUTPUT_STRIP_TRAILING_WHITESPACE
		)
	execute_process(
			COMMAND ${LLVM_CONFIG} --libdir
			OUTPUT_VARIABLE LLVM_LIBDIR
			OUTPUT_STRIP_TRAILING_WHITESPACE
			)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${LLVM_CFLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CXXFLAGS}")
	set(KONOHA_SRC ${KONOHA_SRC} src/lang/llvm.cpp)
	string(REPLACE " " ";" v ${LLVM_JIT_LIBS})
	link_directories(${LINK_DIRECTORIES} ${LLVM_LIBDIR})
	set(ExtraLibs ${ExtraLibs} ${v})
endif()

option(USE_ACTOR "Compiling Actor package" OFF)

option(USE_GWT "Using gwt package" OFF)

option(USE_QT "Using qt package" OFF)

option(USE_QT4 "Using qt4 package" OFF)

option(USE_GENGC "Using GENGC" OFF)
if(USE_GENGC)
	konoha_add_definitions(-DK_USING_GENGC=1)
endif(USE_GENGC)

if(MINGW)
	find_library(HAVE_LIBCURLDLL NAMES curldll)
	if(HAVE_LIBCURLDLL)
		set(ExtraLibs ${ExtraLibs} ${HAVE_LIBCURLDLL})
	endif(HAVE_LIBCURLDLL)
	find_library(HAVE_LIBWS2_32 NAMES ws2_32)
	if(HAVE_LIBWS2_32)
		set(ExtraLibs ${ExtraLibs} ${HAVE_LIBWS2_32})
	endif(HAVE_LIBWS2_32)
endif(MINGW)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake 
		${CMAKE_CURRENT_BINARY_DIR}/config.h)

add_library(konoha SHARED ${KONOHA_SRC})
target_link_libraries(konoha ${ExtraLibs})
set_target_properties(konoha PROPERTIES VERSION ${PACKAGE_VERSION} SOVERSION ${SO_VERSION})

add_executable(konoha1 ${KONOHA_BIN})
target_link_libraries(konoha1 konoha)
set_target_properties(konoha1 PROPERTIES OUTPUT_NAME konoha)

find_program(CLANG_BIN NAMES clang DOC "clang")
if(CLANG_BIN)
       set(COMPILED_LIB_BC libkonoha.dylib.bc)
       SET (COMPILED_BC)
       string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
       set(_cflag "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_${BUILD_TYPE}}")
       set(_tmp "${_cflag} ${KONOHA_CFLAGS} -I${CMAKE_CURRENT_BINARY_DIR} -g0")
       string(REPLACE " " ";" LLVM_C_FLAGS ${_tmp})
       foreach(it ${KONOHA_SRC})
               string(REPLACE "/" ";" _source ${it})
               list(REVERSE _source)
               list(GET _source 0 _file)
               set(_output ${CMAKE_CURRENT_BINARY_DIR}/${_file}.bc)
               add_custom_command(
                               OUTPUT  ${_output}
                               DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${_it}
                               COMMAND clang ${PROJECT_SOURCE_DIR}/${it}
                               ${LLVM_C_FLAGS} -emit-llvm -c -o
                               ${_output})
               list(APPEND COMPILED_BC ${_output})
       endforeach()
       add_custom_command(
                       OUTPUT  ${COMPILED_LIB_BC}
                       DEPENDS ${COMPILED_BC}
                       COMMAND llvm-ld -link-as-library -o ${COMPILED_LIB_BC} ${COMPILED_BC})
       add_custom_target(CREATE_BC_LIB DEPENDS ${COMPILED_LIB_BC})
      #add_dependencies(konoha CREATE_BC_LIB)
      #install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${COMPILED_LIB_BC} DESTINATION konoha/lib/)
endif(CLANG_BIN)

if(USE_CTEST)
	include(CTest)
	message(STATUS "*** Enable CTest Option ***")
	konoha_add_definitions(-fprofile-arcs -ftest-coverage)
	target_link_libraries(konoha -fprofile-arcs)
endif(USE_CTEST)

macro(create_package_project PKGNAME)
project(${PKGNAME})
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})
set(_PACKAGE_NAME    ${PROJECT_NAME})
set(_PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(_PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${_PACKAGE_VERSION})
set(_KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})
set(_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  ${CMAKE_CURRENT_BINARY_DIR}
		${KONOHA_INCLUDE_DIRS}
		${_PACKAGE_INCLUDE_DIR})
include_directories(${_INCLUDE_DIRS})
add_definitions(-D_SETUP)
add_library(${_PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE})
set_target_properties(${_PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${_PACKAGE_NAME} konoha ${PACKAGE_EXTRA_LIBRARY})
install(TARGETS ${_PACKAGE_NAME} DESTINATION ${_KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${_KONOHA_PACKAGE_DIR})
endmacro(create_package_project)

macro(add_konoha_package PKGNAME)
	set(__BUILD true)
	foreach(arg ${ARGN})
		if (NOT ${arg})
			set(__BUILD false)
		endif (NOT ${arg})
	endforeach(arg ${ARGN})

	if (__BUILD)
		create_package_project(${PKGNAME})
	endif (__BUILD)
endmacro(add_konoha_package)

file(GLOB dirs "${CMAKE_CURRENT_SOURCE_DIR}/package/konoha.*")
foreach(dir ${dirs})
	add_subdirectory(${dir})
endforeach()
add_subdirectory(dist/script)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/Doxyfile.in
		${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
	add_custom_target(doc
		${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation with Doxygen" VERBATIM
		)
endif(DOXYGEN_FOUND)

install(TARGETS konoha1 konoha 
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		)

install(DIRECTORY include/ DESTINATION include 
		FILES_MATCHING
		PATTERN "*.h"
		PATTERN ".svn" EXCLUDE
		)


# test
enable_testing()
set(ktest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/konoha)
set(ac_dir ${CMAKE_CURRENT_SOURCE_DIR}/ac)
file(GLOB_RECURSE files "${CMAKE_CURRENT_SOURCE_DIR}/ac/*")
foreach(f ${files})
	if(NOT "${f}" MATCHES ".svn")
		if("${f}" MATCHES ".k$")
			string(REGEX REPLACE ".*/ac/([^ ]+).k" "\\1" res "${f}" )
			add_test(NAME ${res} COMMAND ${ktest} "${f}")
		endif()
	endif()
endforeach()

set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME ${ARCHIVE_NAME})
set(CPACK_PACKAGE_NAME ${PACKAGE_NAME})
set(CPACK_PACKAGE_VENDOR ${PACKAGE_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Statically-typed scripting language")
set(CPACK_PACKAGE_VERSION       ${PACKAGE_VERSION})
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})

# cpack package generator settings
set(CPACK_ARCH "")
if(CPACK_GENERATOR STREQUAL "PackageMaker") # macosx (dmg)
	set(CPACK_ARCH "_macosx")
	file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/COPYING ${CMAKE_CURRENT_SOURCE_DIR}/README
		DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
	file(RENAME ${CMAKE_CURRENT_BINARY_DIR}/COPYING
		${CMAKE_CURRENT_BINARY_DIR}/COPYING.txt)
	file(RENAME ${CMAKE_CURRENT_BINARY_DIR}/README
		${CMAKE_CURRENT_BINARY_DIR}/README.txt)
	set(CPACK_PACKAGING_INSTALL_PREFIX /usr/local)
	set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_BINARY_DIR}/COPYING.txt)
	set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_BINARY_DIR}/README.txt)
elseif(CPACK_GENERATOR STREQUAL "DEB") # linux (deb)
	if(CMAKE_SIZEOF_VOID_P MATCHES "8")
		set(CPACK_ARCH "_amd64")
	else(CMAKE_SIZEOF_VOID_P MATCHES "8")
		set(CPACK_ARCH "_i386")
	endif(CMAKE_SIZEOF_VOID_P MATCHES "8")
	set(CPACK_DEBIAN_PACKAGE_DEPENDS
		"libc6 (>= 2.11), libsqlite3-dev, libffi-dev, libcurl-dev")
	set(CPACK_DEBIAN_PACKAGE_MAINTAINER
		"Konoha Developers <konoha-users@lists.sourceforge.jp>")
elseif(CPACK_GENERATOR STREQUAL "RPM") # linux (rpm)
	set(CPACK_RPM_PACKAGE_LICENSE "GNU GPL v3")
	set(CPACK_RPM_PACKAGE_GROUP "Development/Languages")
	set(CPACK_RPM_PACKAGE_URL "http://konohascript.org")
	if(CMAKE_SIZEOF_VOID_P MATCHES "8")
		set(CPACK_ARCH "_x86_64")
	else(CMAKE_SIZEOF_VOID_P MATCHES "8")
		set(CPACK_ARCH "_i386")
	endif(CMAKE_SIZEOF_VOID_P MATCHES "8")
endif(CPACK_GENERATOR STREQUAL "PackageMaker")
if(SUBVERSION_REVISION)
	set(CPACK_PACKAGE_FILE_NAME ${PACKAGE_STRING}-${SUBVERSION_REVISION}${CPACK_ARCH})
else(SUBVERSION_REVISION)
	set(CPACK_PACKAGE_FILE_NAME ${PACKAGE_STRING}${CPACK_ARCH})
endif(SUBVERSION_REVISION)

include(CPack)

MESSAGE(STATUS)
MESSAGE(STATUS "---------------------------------------------------------------------------" )
MESSAGE(STATUS "CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}")
MESSAGE(STATUS "CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}")
MESSAGE(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "Change a value with: cmake -D<Variable>=<Value>" )
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	#if(NOT HAVE_PCRE_H)
	#		MESSAGE(STATUS "pcre.h is not found")
	#endif(NOT HAVE_PCRE_H)
endif()

MESSAGE(STATUS)
foreach(lib ${MessageLibs})
	MESSAGE(STATUS "using ${lib}")
endforeach()
MESSAGE(STATUS "---------------------------------------------------------------------------" )
MESSAGE(STATUS)

