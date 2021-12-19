aux_source_directory(. CORE)
include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(core ${CORE})
target_link_libraries(core dev)
