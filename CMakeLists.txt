cmake_minimum_required(VERSION 3.10.0)
project(learnOpenGL VERSION 0.1.0 LANGUAGES C CXX)

add_library(glfw3 STATIC IMPORTED)
set_target_properties(glfw3 PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/glfw-3.4/build/src/libglfw3.a"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/lib/glfw-3.4/include"
)

add_library(glad STATIC ${CMAKE_SOURCE_DIR}/lib/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/lib/glad/include)

add_library(stb_image STATIC ${CMAKE_SOURCE_DIR}/lib/stb_image/src/stb_image.cpp)
target_include_directories(stb_image PUBLIC ${CMAKE_SOURCE_DIR}/lib/stb_image/include)

#include_directories(${CMAKE_SOURCE_DIR}/lib/stb_image)
include_directories(${CMAKE_SOURCE_DIR}/lib/)

add_executable(learnOpenGL examples/05_camera.cpp)
#add_executable(exercise exercises/00_triangles.cpp)
target_include_directories(learnOpenGL PUBLIC ${CMAKE_SOURCE_DIR}/lib/learnOpenGL)

target_link_libraries(learnOpenGL glad glfw3 stb_image)
#target_link_libraries(exercise glad glfw3)


include(CTest)
enable_testing()

