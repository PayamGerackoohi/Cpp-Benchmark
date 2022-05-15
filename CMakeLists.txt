###### Project Configs ######
cmake_minimum_required(VERSION 3.16.5)
set(CMAKE_CXX_STANDARD 20)
project(Benchmark)

###### Enabling Google Test ######
include(FetchContent)
set(GOOGLE_TEST_COMMIT e2239ee6043f73722e7aa812a459f54a28552929)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/${GOOGLE_TEST_COMMIT}.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

###### Adding Libraries ######
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(MODULE_DIRECTORY ${PROJECT_SOURCE_DIR}/module)
find_package(LibUtil)
add_subdirectory(library)
add_subdirectory(module)
