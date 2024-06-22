cmake_minimum_required(VERSION 3.1)

project(MYMUDUO)

#设置C++11标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#设置编译选项，支持debug
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 配置最终的可执行文件输出的路径
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#头文件的搜索路径
include_directories(./include)

#源文件的路径
aux_source_directory(./src SRC_LIST)

#生成可执行文件
add_executable(main main.cpp ${SRC_LIST})

# 指定可执行文件链接时需要依赖的库文件
target_link_libraries(main pthread)