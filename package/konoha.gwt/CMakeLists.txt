cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})
if(USE_GWT)

project(gwt)
set(DESIRED_QT_VERSION 4)
find_package(Qt4 REQUIRED)

set(PACKAGE_SOURCE_CODE
	src/Application.cpp
	src/Brush.cpp
	src/Camera.cpp
	src/Color.cpp
	src/ComplexItem.cpp
	src/Contact.cpp
	src/Ellipse.cpp
	src/Font.cpp
	src/Group.cpp
	src/Item.cpp
	src/Line.cpp
	src/MouseEvent.cpp
	src/Painter.cpp
	src/Pen.cpp
	src/Point.cpp
	src/Rect.cpp
	src/Scene.cpp
	src/Shadow.cpp
	src/Text.cpp
	src/Texture.cpp
	src/TimeLine.cpp
	src/Timer.cpp
	src/Transform.cpp
	src/Video.cpp
	src/View.cpp
	src/World.cpp
	src/moc_gwt.cpp
	src/gwt.cpp)

set(PACKAGE_HEADERS include/gwt.hpp)
qt4_wrap_cpp(PACKAGE_HEADERS_MOC ${PACKAGE_HEADERS})
include(${QT_USE_FILE})

set(PACKAGE_EXTRA_LIBRARY
	${QT_QTCORE_LIBRARY}
	${QT_QTWEBKIT_LIBRARY}
	${QT_QTGUI_LIBRARY}
	)

set(PACKAGE_SCRIPT_CODE ./gwt.k)

set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

add_definitions(-DREDUCED -DANSI_DECLARATORS -DTRILIBRARY -DCDT_ONLY)
add_definitions(-DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED)
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  ${CMAKE_CURRENT_BINARY_DIR}
		${KONOHA_INCLUDE_DIRS})

find_path(HAVE_QTGUI QtGui  PATHS ${include_locations})
if(HAVE_QTGUI)
	set(INCLUDE_DIRS ${INCLUDE_DIRS} ${HAVE_QTGUI})
endif()
include_directories(${INCLUDE_DIRS})

find_path(HAVE_BOX2D Box2D/Box2D.h PATHS ${include_locations})
if(HAVE_BOX2D)
    add_definitions(-DK_USING_BOX2D=1)
    include_directories(${HAVE_BOX2D}/Box2D)
endif()

find_path(HAVE_OPENCV opencv/cv.h PATHS ${include_locations})
if(HAVE_OPENCV)
    add_definitions(-DK_USING_OPENCV=1)
    include_directories(${HAVE_OPENCV}/opencv)
    include_directories(${HAVE_OPENCV}/opencv2)
endif()

add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE} ${MOC_SRCS})

set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")

target_link_libraries(${PACKAGE_NAME} konoha gam ${PACKAGE_EXTRA_LIBRARY})

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(USE_GWT)

