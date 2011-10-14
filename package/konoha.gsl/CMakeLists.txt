cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_FLAGS_RELEASE "-Wall -O2 -g")
set(CMAKE_C_FLAGS_DEBUG   "-Wall -O0 -g3")
set(CMAKE_BUILD_TYPE Release)
project(gsl)
find_library(HAVE_LIB_GSL NAMES gsl)
set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")
set(KONOHA_VERSION  ${VERSION_MAJOR}.${VERSION_MINOR})
if(HAVE_LIB_GSL)

set(PACKAGE_SOURCE_CODE 
	src/gsl.c
	src/comb.c
	src/math.c
	src/multi.c
	src/perm.c
	src/poly.c
	src/stats.c
)
set(PACKAGE_SCRIPT_CODE gsl.k)
set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  ${CMAKE_CURRENT_BINARY_DIR}
		${KONOHA_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})
add_definitions(-D_SETUP)

find_library(LIB_GSLCBLAS gslcblas)
if(NOT EXISTS ${LIB_GSLCBLAS})
	message(FATAL_ERROR "libgslcblas not found.")
endif()

add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PACKAGE_NAME} konoha ${HAVE_LIB_GSL} ${LIB_GSLCUBLAS} m)
install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})
endif(HAVE_LIB_GSL)
