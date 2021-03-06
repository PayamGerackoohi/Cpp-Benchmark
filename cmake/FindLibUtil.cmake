macro(set_output_dir directory)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${directory})
endmacro()

macro(make_library library_name)
    set(CD ${CMAKE_CURRENT_SOURCE_DIR})
    set(LIBRARY_TEST_NAME ${library_name}-test)
    set(INCLUDE_DIRECTORY ${CD}/include)
    file(GLOB_RECURSE sources ${CD}/source/*.cpp)
    set(LIBRARY_OUTPUT_PATH ${CD}/library)
    set_output_dir(${CD}/test)
    include_directories(${INCLUDE_DIRECTORY})
    add_library(${library_name} ${sources})
    target_include_directories(${library_name} PUBLIC ${INCLUDE_DIRECTORY})
    add_executable(${LIBRARY_TEST_NAME} test/${LIBRARY_TEST_NAME}.cpp)
    target_link_libraries(${LIBRARY_TEST_NAME} ${library_name} gtest_main)
endmacro()

macro(set_binary_directory directory)
    set_output_dir(${directory}/binary)
endmacro()
