cmake_minimum_required(VERSION 3.5.0)

# set CXX
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Set Clang as the compiler
# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

# output compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set vcpkg
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

# 
project(my_test VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR}/lib)

add_library(foo STATIC ${PROJECT_SOURCE_DIR}/lib/foo.cc)

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cc)
target_link_libraries(main PRIVATE foo)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(test1 ${PROJECT_SOURCE_DIR}/tests/test1.cc)
target_link_libraries(test1 PRIVATE foo GTest::gtest_main)

add_test(NAME Test1 COMMAND test1)

