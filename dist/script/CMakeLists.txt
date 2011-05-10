cmake_minimum_required(VERSION 2.6)

project(dist)
set(KONOHA_SCRIPT_DIR konoha/script/${KONOHA_VERSION})

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/[a-zA-Z]*")

set(DistFiles)
foreach(f ${files})
#	elseif("${f}" MATCHES ".svn")
	if("${f}" MATCHES "[Cc]?[Mm]ake")
	else()
		set(DistFiles ${DistFiles} ${f})
	endif()
endforeach()

install(FILES ${DistFiles} DESTINATION ${KONOHA_SCRIPT_DIR})

