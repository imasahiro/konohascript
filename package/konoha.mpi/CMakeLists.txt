cmake_minimum_required(VERSION 2.6)
# -DCMAKE_BUILD_TYPE=Debug
# -DCMAKE_INSTALL_PREFIX=$HOME
# -DCMAKE_VERBOSE_MAKEFILE=1

set(CMAKE_C_FLAGS_RELEASE "-Wall -O2 -g")
set(CMAKE_C_FLAGS_DEBUG   "-Wall -O0 -g3")
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)

if(USE_MPI)
project(mpi)
set(PACKAGE_SOURCE_CODE 
		mpi.c
		src/coll.c
		src/comm.c
		src/op.c
		src/pt2pt.c
)

set(PACKAGE_SCRIPT_CODE mpi.k)

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

set(MPI_Libs)
set(MPI_Libs ${MPI_Libs} konoha mpich opa mpl)

find_library(MPI_LIB mpich)
if (NOT EXISTS ${MPI_LIB})
   message(FATAL_ERROR "libmpich not found.")
endif()

if (APPLE)
   set(MPI_Libs ${MPI_Libs} pmpich)
endif()

target_link_libraries(${PACKAGE_NAME} ${MPI_Libs})

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})
endif(USE_MPI)
