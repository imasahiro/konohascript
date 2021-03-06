cmake_minimum_required(VERSION 2.6)
set(CMAKE_BUILD_TYPE ${KONOHA_BUILD_TYPE})

add_subdirectory(js.dom)
add_subdirectory(js.jquery)
add_subdirectory(js.math)
add_subdirectory(js.websocket)
project(compiler.js)
set(PACKAGE_SCRIPT_CODE js.k)
set(PACKAGE_RUNTIME_DIR runtime)
set(PACKAGE_RUNTIME_CODE runtime/konoha.js runtime/js.js runtime/js.dom.js runtime/js.jquery.js runtime/js.math.js)

if(LIB_V8_DIR)
LINK_DIRECTORIES(${LIB_V8_DIR})
add_executable(jslint "third-party/jslint-v8/jslint.cpp")
target_link_libraries(jslint v8)
enable_testing()
set(js ${CMAKE_CURRENT_SOURCE_DIR}/konoha2js)
set(opt "-j" "-i")
set(opt2 "-o")
set(jslint ${CMAKE_CURRENT_BINARY_DIR}/jslint)
set(jslint_opt "--cap")
set(DIR "${CMAKE_CURRENT_SOURCE_DIR}/js_test")
add_test(NAME "transpile_toplevelexp.k"    COMMAND ${js} ${opt} "${DIR}/toplevelexp.k" "-o ${DIR}/toplevelexp.js")
add_test(NAME "jslint_toplevelexp.k"    COMMAND ${jslint} ${jslint_opt} "${DIR}/toplevelexp.js")
add_test(NAME "transpile_map.k"    COMMAND ${js} ${opt} "${DIR}/map.k" ${opt2} "${DIR}/map.js")
add_test(NAME "jslint_map.k"    COMMAND ${jslint} ${jslint_opt} "${DIR}/map.js")
add_test(NAME "transpile_array.k"    COMMAND ${js} ${opt} "${DIR}/array.k" ${opt2} " ${DIR}/array.js")
add_test(NAME "jslint_array.k"    COMMAND ${jslint} ${jslint_opt} "${DIR}/array.js")
add_test(NAME "transpile_aobench_canvas.k"    COMMAND ${js} ${opt} "${DIR}/aobench_canvas.k" "-o ${DIR}/aobench_canvas.js")
add_test(NAME "jslint_aobench_canvas.k"    COMMAND ${jslint} ${jslint_opt} "${DIR}/aobench_canvas.js")
add_test(NAME "transpile_jquery.k"    COMMAND ${js} ${opt} "${DIR}/jquery.k" ${opt2} "${DIR}/jquery.js")
add_test(NAME "jslint_jquery.k"    COMMAND ${jslint} ${jslint_opt} "${DIR}/jquery.js")
add_test(NAME "transpile_memory.k"    COMMAND ${js} ${opt} "${DIR}/memory.k" ${opt2} "${DIR}/memory.js")
add_test(NAME "jslint_memory.k"    COMMAND ${jslint} ${jslint_opt} "${DIR}/memory.js")


endif(LIB_V8_DIR)
set(PACKAGE_NAME ${PROJECT_NAME})
set(PACKAGE_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
set(PACKAGE_STRING ${CMAKE_PROJECT_NAME}-${PACKAGE_VERSION})
set(KONOHA_PACKAGE_DIR konoha/package/${KONOHA_VERSION}/konoha.${PROJECT_NAME})

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_SCRIPT_CODE} DESTINATION ${KONOHA_PACKAGE_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${PACKAGE_RUNTIME_CODE} DESTINATION ${KONOHA_PACKAGE_DIR}/${PACKAGE_RUNTIME_DIR})
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/konoha2js DESTINATION bin
        PERMISSIONS 
        OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE)
