cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})

if(USE_COMPILER_PKG)
add_subdirectory(js.dom)
add_subdirectory(js.jquery)
project(compiler.js)
set(PACKAGE_SCRIPT_CODE js.k)

find_library(HAVE_LIB_V8 v8)
if(HAVE_LIB_V8)
find_path(HAVE_V8_H  v8.h  PATHS ${include_locations})

include_directories(${HAVE_V8_H})
add_executable(jslint "third-party/jslint-v8/jslint.cpp")
target_link_libraries(jslint ${HAVE_LIB_V8})
install(TARGETS jslint RUNTIME DESTINATION bin)
endif(HAVE_LIB_V8)
set(PACKAGE_NAME ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})

endif(USE_COMPILER_PKG)
