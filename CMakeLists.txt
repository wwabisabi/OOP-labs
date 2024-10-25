cmake_minimum_required(VERSION 3.30.5)

project(ooplab1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(eliminate_unset_bits_lib eliminate_unset_bits.cpp)
target_include_directories(eliminate_unset_bits_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(eliminate_unset_bits main.cpp)
target_link_libraries(eliminate_unset_bits PRIVATE eliminate_unset_bits_lib)

add_executable(eliminate_unset_bits_tests tests.cpp)
target_link_libraries(eliminate_unset_bits_tests
  PRIVATE
  eliminate_unset_bits_lib
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(eliminate_unset_bits_tests)