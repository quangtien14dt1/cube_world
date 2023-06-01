# Copyright (C) 2023 QuangTien

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(CubeWorld)


# link_directories(${CMAKE_SOURCE_DIR}/lib) // this for prebuild libs on window system
add_definitions(-D GLM_ENABLE_EXPERIMENTAL)

# Configure assets header file
configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)

# Define the include DIRs
include_directories( ${CMAKE_SOURCE_DIR}/src/ , ${CMAKE_SOURCE_DIR}/include/ )

# Define the executable
file(GLOB_RECURSE SOURCE ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

# We need a CMAKE_DIR with some code to find external dependencies
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# OpenGL
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# GLM
find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

# GLFW
find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

# ASSIMP
find_package(ASSIMP REQUIRED)
message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")

add_library(STB_IMAGE "thirdparty/stb_image.cpp")
add_library(GLAD "thirdparty/glad.c")

# Put all libraries into a variable
set(LIBS ${GLFW3_LIBRARY} ${OPENGL_LIBRARY} GLAD ${CMAKE_DL_LIBS} ${ASSIMP_LIBRARY} STB_IMAGE)


# Define the link libraries
target_link_libraries(${PROJECT_NAME} ${LIBS})

# Create virtual folders to make it look nicer in VS
if(MSVC_IDE)
	# Macro to preserve source files hierarchy in the IDE
	macro(GroupSources curdir)
		file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

		foreach(child ${children})
			if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
				GroupSources(${curdir}/${child})
			else()
				string(REPLACE "/" "\\" groupname ${curdir})
				string(REPLACE "src" "Sources" groupname ${groupname})
				source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
			endif()
		endforeach()
	endmacro()

	# Run macro
	GroupSources(src)
endif()

# Copy dlls
if(WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		"${PROJECT_SOURCE_DIR}/dlls"
		$<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()
