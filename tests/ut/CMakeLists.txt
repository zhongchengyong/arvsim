include_directories(${CMAKE_SOURCE_DIR}/src)

ADD_EXECUTABLE(testsim main.cpp instr_test.cpp)

TARGET_LINK_LIBRARIES(testsim libgtest libgmock sim dev)

add_test(NAME testsim COMMAND testsim)