cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})

if(USE_OPENCV)

project(opencv)
find_package(Qt4 REQUIRED)
set(PACKAGE_SOURCE_CODE
	qopencv.cpp
	moc_qopencv.cxx
	)

set(PACKAGE_SCRIPT_CODE opencv.k)
set(PACKAGE_EXTRA_LIBRARY
	${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
	)

set(PACKAGE_HEADERS qopencv.hpp)
qt4_wrap_cpp(PACKAGE_HEADERS_MOC ${PACKAGE_HEADERS})

include(${QT_USE_FILE})

find_path(HAVE_OPENCV opencv/cv.h PATHS ${include_locations})
if(HAVE_OPENCV)
    add_definitions(-DGAM_USING_OPENCV=1)
    include_directories(${HAVE_OPENCV}/opencv)
    include_directories(${HAVE_OPENCV}/opencv2)
endif()

set(PACKAGE_NAME    ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING  ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/include  ${CMAKE_CURRENT_BINARY_DIR}
		${KONOHA_INCLUDE_DIRS} ${PACKAGE_INCLUDE_DIR})
include_directories(${INCLUDE_DIRS})

add_definitions(-D_SETUP)
add_definitions(${QT_DEFINITIONS})

add_library(${PACKAGE_NAME} SHARED ${PACKAGE_SOURCE_CODE} ${PACKAGE_HEADERS_MOC})
set_target_properties(${PACKAGE_NAME} PROPERTIES PREFIX "")
target_link_libraries(${PACKAGE_NAME} konoha)
target_link_libraries(${PACKAGE_NAME} ${PACKAGE_EXTRA_LIBRARY}
opencv_calib3d opencv_core opencv_features2d opencv_flann opencv_gpu
opencv_highgui opencv_imgproc opencv_legacy opencv_ml
opencv_objdetect opencv_ts opencv_video)

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(USE_OPENCV)

