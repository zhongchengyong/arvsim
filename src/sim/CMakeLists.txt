aux_source_directory(. SIM)
add_library(sim ${SIM})
include_directories(${CMAKE_SOURCE_DIR}/src)


add_executable(arvsim simulator.cpp)

target_link_libraries(arvsim sim dev)