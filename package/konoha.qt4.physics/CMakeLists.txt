cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})

if(USE_PHYSICS)

# it must be configured

project(physics)
find_package(Qt4 REQUIRED)
set(QT_USE_QTOPENGL TRUE)

set(PACKAGE_SOURCE_CODE
	lib/triangle/src/assert.cpp
	lib/triangle/src/del_impl.cpp
	lib/triangle/src/main.cpp
	physics.cpp
	src/QWorld.cpp
	src/KQGraphicsItem.cpp
	src/KQGraphicsItemGroup.cpp
	src/QGraphicsComplexItem.cpp
	src/QJoint.cpp
	src/DebugDraw.cpp
	moc_physics.cxx
	)

set(PACKAGE_SCRIPT_CODE physics.k)
set(PACKAGE_EXTRA_LIBRARY
	${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
	${QT_QTOPENGL_LIBRARY}
	)

set(PACKAGE_HEADERS physics.hpp)
qt4_wrap_cpp(PACKAGE_HEADERS_MOC ${PACKAGE_HEADERS})

include(${QT_USE_FILE})

add_definitions(-DREDUCED -DANSI_DECLARATORS -DTRILIBRARY -DCDT_ONLY)

find_path(HAVE_BOX2D Box2D/Box2D.h PATHS ${include_locations})
if(HAVE_BOX2D)
    add_definitions(-DGAM_USING_BOX2D=1)
    include_directories(${HAVE_BOX2D}/Box2D)
endif()

find_package(OpenGL REQUIRED)
if (NOT OPENGL_FOUND)
   message(ERROR "OpenGL not found!!")
endif(NOT OPENGL_FOUND)

set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  ${CMAKE_CURRENT_BINARY_DIR}
		${KONOHA_INCLUDE_DIRS} ${PACKAGE_INCLUDE_DIR})

set(INCLUDE_DIRS ${INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/lib/triangle/include/)
include_directories(${INCLUDE_DIRS})
add_definitions(-D_SETUP)
add_definitions(${QT_DEFINITIONS})

add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE} ${PACKAGE_HEADERS_MOC})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PACKAGE_NAME} konoha)
target_link_libraries(${PACKAGE_NAME} ${PACKAGE_EXTRA_LIBRARY} ${OPENGL_LIBRARIES} Box2D)

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(USE_PHYSICS)

