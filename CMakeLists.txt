cmake_minimum_required(VERSION 2.6)
project (myOpenGL)

file(GLOB my_open_gl_src "*.c" "*.cpp")
file(GLOB my_open_gl_include "*.h" "*.hpp")

add_executable(myOpenGL ${my_open_gl_src} ${my_open_gl_include})
