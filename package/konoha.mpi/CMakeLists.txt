cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})

project(mpi)

# - set package variables
set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(PACKAGE_SCRIPT_CODE mpi.k)
set(PACKAGE_SOURCE_CODE
		mpi.c
		src/array.c
		src/sys.c
		src/coll.c
		src/data.c
		src/comm.c
		src/op.c
		src/pt2pt.c
)
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

# - check MPI library

set(MPI_TYPE_OMPI "on")
set(MPI_TYPE_MPICH "on")

if(MPI_TYPE)
   if("${MPI_TYPE}" STREQUAL "mpich")
     # -- disable ompi
     set(MPI_TYPE_OMPI)
   elseif("${MPI_TYPE}" STREQUAL "ompi")
     # -- disable mpich
     set(MPI_TYPE_MPICH)
   endif()
endif(MPI_TYPE)

if(NOT MPI_ROOT_DIR)
   # -- use default dirs
   set(MPI_ROOT_DIR /usr/local)
endif(NOT MPI_ROOT_DIR)

set(MPI_INCDIR ${MPI_ROOT_DIR}/include)
set(MPI_LIBDIR ${MPI_ROOT_DIR}/lib)

find_library(HAVE_LIBMPICH mpich ${MPI_LIBDIR})
find_library(HAVE_LIBMPI mpi ${MPI_LIBDIR})

if(MPI_TYPE_OMPI AND HAVE_LIBMPI)
   # -- OpenMPI
   set(MessageLibs ${MessageLibs} ompi PARENT_SCOPE)

   set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${KONOHA_INCLUDE_DIRS} ${MPI_INCDIR})
   include_directories(${INCLUDE_DIRS})

   # --- LIBMPI (already checked by HAVE_LIBMPI)
   set(MPI_LIBS ${HAVE_LIBMPI})

# endif MPI_TYPE_OMPI AND HAVE_LIBMPI
elseif(MPI_TYPE_MPICH AND HAVE_LIBMPICH)
   # -- MPICH
   set(MessageLibs ${MessageLibs} mpich PARENT_SCOPE)

   set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${KONOHA_INCLUDE_DIRS} ${MPI_INCDIR})
   include_directories(${INCLUDE_DIRS})

   # --- LIBMPICH (already checked by HAVE_LIBMPICH)
   set(MPI_LIBS ${HAVE_LIBMPICH})

   # --- LIBOPA
   find_library(LIB_OPENPA opa  ${MPI_LIBDIR})
   if (NOT EXISTS ${LIB_OPENPA})
      message(FATAL_ERROR "opa library not found.")
   endif(NOT EXISTS ${LIB_OPENPA})
   set(MPI_LIBS ${MPI_LIBS} ${LIB_OPENPA})

   # --- LIBMPL
   find_library(LIB_MPL mpl  ${MPI_LIBDIR})
   if (NOT EXISTS ${LIB_MPL})
      message(FATAL_ERROR "mpl library not found.")
   endif(NOT EXISTS ${LIB_MPL})
   set(MPI_LIBS ${MPI_LIBS} ${LIB_MPL})

   # --- LIBPMPICH (optional)
   find_library(LIB_PMPICH pmpich  ${MPI_LIBDIR})
   if (LIB_PMPICH)
      set(MPI_LIBS ${MPI_LIBS} ${LIB_PMPICH})
   endif(LIB_PMPICH)

# endif MPI_TYPE_MPICH AND HAVE_LIBMPICH
endif(MPI_TYPE_OMPI AND HAVE_LIBMPI)

if(MPI_LIBS)
   # -- install mpikonoha binary
   add_executable(mpikonoha src/mpikonoha.c)
   target_link_libraries(mpikonoha konoha ${MPI_LIBS})
   install(TARGETS mpikonoha RUNTIME DESTINATION bin)

   # -- install konoha.mpi package
   add_definitions(-D_SETUP)
   add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE})
   set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
   target_link_libraries(${PACKAGE_NAME} konoha ${MPI_LIBS})
   install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
   install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(MPI_LIBS)
