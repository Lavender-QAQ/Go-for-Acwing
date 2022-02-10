cmake_minimum_required(VERSION 3.0.0)
project(ACWING VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main Advance/Chapter_1/acwing524.cpp)
add_executable(algo_main Algorithm/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
