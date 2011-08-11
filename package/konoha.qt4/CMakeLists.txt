if(USE_QT4)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_C_FLAGS_RELEASE "-Wall -O2 -g")
set(CMAKE_C_FLAGS_DEBUG   "-Wall -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Weffc++ -O2 -g")
set(CMAKE_CXX_FLAGS_DEBUG   "-Wall -Weffc++ -O0 -g3")
set(CMAKE_BUILD_TYPE Release)

# it must be configured

project(qt4)
set(QT_USE_QTWEBKIT TRUE)
find_package(Qt4 REQUIRED)
#find_package(Qt4 COMPONENTS QtCore QtGui QtWebKit REQUIRED)
set(PACKAGE_SOURCE_CODE
	src/QApplication.cpp
	src/QBoxLayout.cpp
	src/QHBoxLayout.cpp
	src/QLabel.cpp
	src/QLineEdit.cpp
	src/QObject.cpp
	src/QPushButton.cpp
	src/QWebView.cpp
	src/QWidget.cpp
	)
set(PACKAGE_SCRIPT_CODE qt4.k)
set(PACKAGE_EXTRA_LIBRARY
	${QT_QTCORE_LIBRARY}
	${QT_QTWEBKIT_LIBRARY}
	${QT_QTGUI_LIBRARY}
	)

set(PACKAGE_HEADERS src/qt4commons.hpp)
qt4_wrap_cpp(PACKAGE_HEADERS_MOC ${PACKAGE_HEADERS})

include(${QT_USE_FILE})

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
target_link_libraries(${PACKAGE_NAME} ${PACKAGE_EXTRA_LIBRARY})

install(TARGETS ${PACKAGE_NAME} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(USE_QT4)
