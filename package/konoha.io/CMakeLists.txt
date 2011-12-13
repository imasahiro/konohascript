cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})

if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
	set(CMAKE_C_FLAGS "-fPIC")
endif()

project(io)
set(PACKAGE_SOURCE_CODE src/io.c src/base64.c ./src/digest.c ./src/msgpack.c)
set(PACKAGE_SCRIPT_CODE io.k)

add_library(msgpack
	third-party/msgpack-0.5.6/object.cpp
	third-party/msgpack-0.5.6/objectc.c
	third-party/msgpack-0.5.6/unpack.c
	third-party/msgpack-0.5.6/version.c
	third-party/msgpack-0.5.6/vrefbuffer.c
	third-party/msgpack-0.5.6/zone.c
)

add_library(md5
	third-party/ext/md5.c
)

set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  ${CMAKE_CURRENT_BINARY_DIR}
		${KONOHA_INCLUDE_DIRS}
		${CMAKE_CURRENT_SOURCE_DIR}/third-party/msgpack-0.5.6
		${CMAKE_CURRENT_SOURCE_DIR}/third-party/ext)
include_directories(${INCLUDE_DIRS})

add_definitions(-D_SETUP)
add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PACKAGE_NAME} konoha msgpack md5)

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

