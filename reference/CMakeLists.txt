cmake_minimum_required(VERSION 3.0.0)
project(myproject VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(mylib)
list(APPEND EXTRA_LIBS mylib)

add_executable(myproject main.cpp)

target_link_libraries(myproject PUBLIC ${EXTRA_LIBS})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
