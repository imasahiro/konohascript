if(USE_GWT)

cmake_minimum_required(VERSION 2.6)
set(CMAKE_C_FLAGS_RELEASE "-Wall -O2 -g")
set(CMAKE_C_FLAGS_DEBUG   "-Wall -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Weffc++ -O2 -g")
set(CMAKE_CXX_FLAGS_DEBUG   "-Wall -Weffc++ -O0 -g3")
set(CMAKE_BUILD_TYPE Release)

project(gwt)
set(DESIRED_QT_VERSION 4)
# TODO
set(QT_MOC_EXECUTABLE /usr/bin/moc)
set(QT_RCC_EXECUTABLE /usr/bin/rcc)
set(QT_UIC_EXECUTABLE /usr/bin/uic)

find_package(Qt COMPONENTS QtCore QtGui REQUIRED)

set(PACKAGE_SOURCE_CODE
	src/Application.cpp
	src/Brush.cpp
	src/Camera.cpp
	src/Color.cpp
	src/ComplexItem.cpp
	src/Connector.cpp
	src/Contact.cpp
	src/Ellipse.cpp
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
	src/Tracker.cpp
	src/Transform.cpp
	src/Triangle.cpp
	src/Video.cpp
	src/View.cpp
	src/World.cpp
	src/moc_visual.cpp
	src/visual.cpp)
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
set(INCLUDE_DIRS ${INCLUDE_DIRS} lib/triangle++/include/)

find_path(HAVE_QTGUI QtGui  PATHS ${include_locations})
if(HAVE_QTGUI)
	set(INCLUDE_DIRS ${INCLUDE_DIRS} ${HAVE_QTGUI})
endif()
include_directories(${INCLUDE_DIRS})

find_path(HAVE_BOX2D Box2D/Box2D.h PATHS ${include_locations})
if(HAVE_BOX2D)
    add_definitions(-DK_USING_BOX2D=1)
    include_directories(${HAVE_OPENCV}/Box2D)
endif()

find_path(HAVE_OPENCV opencv/cv.h PATHS ${include_locations})
if(HAVE_OPENCV)
    add_definitions(-DK_USING_OPENCV=1)
    include_directories(${HAVE_OPENCV}/opencv)
    include_directories(${HAVE_OPENCV}/opencv2)
endif()

add_library(triangle
	lib/triangle++/src/assert.cpp
	lib/triangle++/src/del_impl.cpp
	lib/triangle++/src/main.cpp)

#find_library(LIB_QTGUI  QtGui)
#find_library(LIB_QTCORE QtCore)
#MARK_AS_ADVANCED (LIB_QTGUI LIB_QTCORE)

qt4_wrap_cpp(MOC_SRCS ./include/visual.hpp)
add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE} ${MOC_SRCS})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PACKAGE_NAME} konoha triangle
Box2D opencv_calib3d opencv_core opencv_features2d opencv_flann opencv_gpu
opencv_highgui opencv_imgproc opencv_legacy opencv_ml
opencv_objdetect opencv_ts opencv_video
${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY}
        )

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(USE_GWT)