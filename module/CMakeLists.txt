set_binary_directory(${MODULE_DIRECTORY})
add_executable(Benchmark console.cpp)
#target_link_libraries(${PROJECT_NAME} PRIVATE big-integer)
target_link_libraries(Benchmark PRIVATE big-integer)
