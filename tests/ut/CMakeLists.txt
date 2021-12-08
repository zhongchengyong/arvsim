include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testsim ${SRCS})

TARGET_LINK_LIBRARIES(testsim libgtest libgmock sim dev)

add_test(NAME testsim COMMAND testsim)