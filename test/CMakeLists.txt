project(testThreadPool)

set(source_files "./testThreadPool.cpp")
message(STATUS "source_files:${source_files}")
add_executable(testThreadPool ${source_files})
target_link_libraries(testThreadPool zythreadpool pthread)
