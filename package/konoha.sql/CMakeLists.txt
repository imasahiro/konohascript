cmake_minimum_required(VERSION 2.6)
# -DCMAKE_BUILD_TYPE=Debug
# -DCMAKE_INSTALL_PREFIX=$HOME
# -DCMAKE_VERBOSE_MAKEFILE=1


set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")
set(KONOHA_VERSION  ${VERSION_MAJOR}.${VERSION_MINOR})

set(CMAKE_C_FLAGS_RELEASE "-Wall -O2 -g")
set(CMAKE_C_FLAGS_DEBUG   "-Wall -O0 -g3")
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

if(MINGW)
	message(STATUS "Konoha MinGW is not supprot konoha.sql package")
else()

project(sql)

macro(CHECK_HEADER _HEADER _PATH _RESULT)
	if(${_PATH})
		find_path(${_RESULT} ${_HEADER} PATHS ${${_PATH}})
	else()
		find_path(${_RESULT} ${_HEADER})
	endif()
endmacro(CHECK_HEADER)

check_header(mysql.h SQL_INCLUDE_DIR SQL_INCLUDE_PATH)

if(SQL_INCLUDE_PATH)
	set(SQL_HEADER mysql.h)
	set(HAVE_SQL_H 1)
	check_header(mysql.h SQL_INCLUDE_DIR SQL_INCLUDE_PATH_CHECK)
	if(NOT SQL_INCLUDE_PATH_CHECK)
		unset(SQL_HEADER)
		unset(HAVE_FFI_H)
	endif()
endif()

if(NOT SQL_INCLUDE_PATH_CHECK)
	check_header(mysql/mysql.h SQL_INCLUDE_DIR SQL_INCLUDE_PATH)
	if(SQL_INCLUDE_PATH)
		set(SQL_HEADER mysql/mysql.h)
		set(HAVE_SQL_SQL_H 1)
	endif()
endif()

if(SQL_INCLUDE_DIR)
	include_directories(${SQL_INCLUDE_DIR})
endif(SQL_INCLUDE_DIR)

if(NOT SQL_HEADER)
	message(FATAL_ERROR "mysql.h is not found. You may run cmake with -DSQL_INCLUDE_DIR=/path/to/mysql/include")
endif()

find_library(HAVE_LIBMYSQL NAMES mysqlclient)

if (HAVE_LIBMYSQL)
message("find library")

set(PACKAGE_SOURCE_CODE
	src/dbapi.c
	src/query.c
	src/sql.c
)
set(PACKAGE_SCRIPT_CODE sql.k)

set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  ${CMAKE_CURRENT_BINARY_DIR}
		${KONOHA_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})

add_definitions(-D_SETUP)

add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PACKAGE_NAME} konoha)
target_link_libraries(${PACKAGE_NAME} ${HAVE_LIBMYSQL})

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

else()
message("cannot find library")
endif(HAVE_LIBMYSQL)
endif(MINGW)
