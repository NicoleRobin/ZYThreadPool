project(zythreadpool)

set(source_files "./threadpool.cpp")
message(STATUS "source_files:${source_files}")
add_library(zythreadpool ${source_files})
