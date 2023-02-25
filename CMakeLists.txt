cmake_minimum_required(VERSION 3.20)
project(TitanRTS VERSION 0.1.0)

#include(CTest)
#enable_testing()

include_directories(include)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")

add_executable(TitanRTS ${sources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
