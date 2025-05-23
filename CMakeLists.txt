cmake_minimum_required(VERSION 3.22)
project(histo_show)

add_executable(run-the-show main.c)
add_executable(histo1d-test histo1d-test.c)
add_library(histo1d STATIC histogram1d.c)
add_library(utils STATIC utils.c)

target_link_libraries(run-the-show PRIVATE histo1d utils)
target_link_libraries(histo1d-test PRIVATE histo1d utils)