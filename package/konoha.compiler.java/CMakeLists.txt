cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})

#add_subdirectory(java.awt)
#add_subdirectory(java.awt.event)

find_package(Java)
find_program(ANT_BIN NAMES ant DOC "ant")
if(NOT ANT_BIN)
  message(STATUS "'compiler.java': Ant is not found.")
endif(NOT ANT_BIN)

if(ANT_BIN)
project(compiler.java)
set(PACKAGE_SCRIPT_CODE java.k)
set(PACKAGE_NAME ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/build.xml.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/build.xml)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/jkonoha.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/jkonoha)

set(OUTPUT_JAR_FILE "${CMAKE_CURRENT_BINARY_DIR}/jkonoha.jar")
add_custom_command(
        OUTPUT  ${OUTPUT_JAR_FILE}
        DEPENDS ${JKONOHA_SRC}
        COMMAND ${ANT_BIN} -f ${CMAKE_CURRENT_BINARY_DIR}/build.xml)
add_custom_target(jkonoha ALL DEPENDS ${OUTPUT_JAR_FILE})
install(FILES ${OUTPUT_JAR_FILE} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/jkonoha DESTINATION bin
        PERMISSIONS
        OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})
endif(ANT_BIN)
