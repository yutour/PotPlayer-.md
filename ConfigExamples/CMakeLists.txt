# 本示例源码结构：
# cmake_simple
# ├── build
# ├── CMakeLists.txt
# ├── include
# │   ├── good_luck.h
# │   └── hello_world.h
# ├── main.c
# └── src
#     ├── dlibs
#     │   └── hello_world.c
#     └── slibs
#         └── good_luck.c

# 指定 CMake 的最低版本
cmake_minimum_required(VERSION 3.20)

# 指定项目的名称
project(hello_world)

# 追加编译参数
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# 设置构建版本
set(CMAKE_BUILD_TYPE Debug)

# 设置导出 compile_commands.json 文件到 build 目录
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 指定头文件目录
include_directories(include)

# 把项目根目录下的所有源码文件赋值给变量 DIR_MAIN
aux_source_directory(. DIR_MAIN)

# 把动态链接目录下的所有源码文件赋值给变量 DIR_DLIBS
aux_source_directory(./src/dlibs DIR_DLIBS)

# 把静态链接目录下的所有源码文件赋值给变量 DIR_SLIBS
aux_source_directory(${PROJECT_SOURCE_DIR}/src/slibs DIR_SLIBS)

# DIR_DLIBS 目录下源码文件生成动态链接库
add_library(dlibs SHARED ${DIR_DLIBS})

# DIR_SLIBS 目录下源码文件生成静态链接库
add_library(slibs STATIC ${DIR_SLIBS})

# 设置生成可执行文件目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/cmake_simple/bin)

# 设置生成链接库目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/cmake_simple/libs)

# 生成可执行文件
add_executable(main ${DIR_MAIN} ${DIR_DLIBS} ${DIR_SLIBS})

# 将动态库或静态库链接到可执行文件，本示例中不添加也可以
target_link_libraries(main dlibs slibs)
