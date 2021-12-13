include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(arvsim simulator_main.cpp)
target_link_libraries(arvsim sim dev core)
