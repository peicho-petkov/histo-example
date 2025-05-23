cmake_minimum_required(VERSION 3.22)
project(histo_show)

include_directories(include)

add_executable(run-the-show src/main.c)
add_executable(histo1d-test src/histo1d-test.c)
add_library(histo1d STATIC src/histogram1d.c)
add_library(utils STATIC src/utils.c)

target_link_libraries(run-the-show PRIVATE histo1d utils)
target_link_libraries(histo1d-test PRIVATE histo1d utils)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_PREFIX})
install(TARGETS histo1d utils DESTINATION lib)
install(TARGETS run-the-show DESTINATION bin) 
