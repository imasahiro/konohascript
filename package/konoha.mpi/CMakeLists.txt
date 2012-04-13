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
    src/coll.c
    src/data.c
    src/comm.c
    src/op.c
    src/pt2pt.c
    src/general.c
)
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

# - check MPI library
# --> require MPI module
# ---> check if MPI_LIBRARIES already defined (it means module is loaded before)
# ----> use -DMPI_BASE_DIR=/path/to/mpibase for specifying target lib.
if(NOT MPI_LIBRARIES)
    find_package(MPI)
endif(NOT MPI_LIBRARIES)

if(MPI_LIBRARIES)
    set(MessageLibs ${MessageLibs} mpi PARENT_SCOPE)
    set(CMAKE_COMPILE_FLAGS ${CMAKE_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
    set(CMAKE_LINK_FLAGS    ${CMAKE_LINK_FLAGS}    ${MPI_LINK_FLAGS})
    include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${KONOHA_INCLUDE_DIRS} ${MPI_INCLUDE_PATH})

    # -- install mpikonoha binary
    add_executable(mpikonoha src/mpikonoha.c)
    target_link_libraries(mpikonoha konoha ${MPI_LIBRARIES})
    install(TARGETS mpikonoha RUNTIME DESTINATION bin)

    # -- install konoha.mpi package
    add_definitions(-D_SETUP)
    #add_definitions(-DKNH_MPI_PROFILE)
    add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE})
    set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
    target_link_libraries(${PACKAGE_NAME} konoha ${MPI_LIBRARIES})
    install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(MPI_LIBRARIES)
