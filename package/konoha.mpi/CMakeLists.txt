cmake_minimum_required(VERSION 2.6)
# -DCMAKE_BUILD_TYPE=Debug
# -DCMAKE_INSTALL_PREFIX=$HOME
# -DCMAKE_VERBOSE_MAKEFILE=1

set(CMAKE_C_FLAGS_RELEASE "-Wall -O2 -g")
set(CMAKE_C_FLAGS_DEBUG   "-Wall -O0 -g3")
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)

project(mpi)

find_library(HAVE_LIBMPICH mpich)
if (HAVE_LIBMPICH)

# - set package variables
set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(PACKAGE_SCRIPT_CODE mpi.k)
set(PACKAGE_SOURCE_CODE
		mpi.c
		src/array.c
		src/coll.c
		src/comm.c
		src/op.c
		src/pt2pt.c
)
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${KONOHA_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRS})

# --- LIBMPICH (already checked by HAVE_LIBMPICH)
set(MPI_LIBS ${HAVE_LIBMPICH})

# --- LIBOPA
find_library(LIB_OPENPA opa)
if (NOT EXISTS ${LIB_OPENPA})
   message(FATAL_ERROR "opa library not found.")
endif(NOT EXISTS ${LIB_OPENPA})
set(MPI_LIBS ${MPI_LIBS} ${LIB_OPENPA})

# --- LIBMPL
find_library(LIB_MPL mpl)
if (NOT EXISTS ${LIB_MPL})
   message(FATAL_ERROR "mpl library not found.")
endif(NOT EXISTS ${LIB_MPL})
set(MPI_LIBS ${MPI_LIBS} ${LIB_MPL})

# --- LIBPMPICH (optional)
find_library(LIB_PMPICH pmpich)
if (LIB_PMPICH)
   set(MPI_LIBS ${MPI_LIBS} ${LIB_PMPICH})
endif(LIB_PMPICH)

# - install mpikonoha binary
add_executable(mpikonoha src/mpikonoha.c)
target_link_libraries(mpikonoha konoha ${MPI_LIBS})
install(TARGETS mpikonoha RUNTIME DESTINATION bin)

# - install konoha.mpi package
add_definitions(-D_SETUP)
add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PACKAGE_NAME} konoha ${MPI_LIBS})
install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(HAVE_LIBMPICH)
