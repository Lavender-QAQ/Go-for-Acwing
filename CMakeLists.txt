cmake_minimum_required(VERSION 3.0.0)
project(ACWING VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cpp)
add_executable(algo_main Algorithm/main.cpp)
add_executable(acwing91 Basic/Chapter_5/acwing91.cpp)
add_executable(acwing291 Basic/Chapter_5/acwing291.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
