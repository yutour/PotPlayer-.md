# 本示例源码结构：
# cmake_example
# ├── build
# ├── CMakeLists.txt
# ├── main.c
# └── src
#     ├── include
#     │   ├── good_luck.h
#     │   └── hello_world.h
#     ├── lib_d
#     │   └── hello_world.c
#     └── lib_s
#         └── good_luck.c

# 指定 CMake 的最低版本
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# 指定项目名称
project(cmake_example C)

# 设置 C 语言版本
set(CMAKE_C_STANDARD 11)

# 追加编译参数
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# 设置构建版本
set(CMAKE_BUILD_TYPE Debug)

# 设置导出 compile_commands.json 文件到 build 目录
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 指定头文件目录
include_directories(./src/include)

# 把项目根目录下的所有源码文件赋值给变量 DIR_MAIN
aux_source_directory(. DIR_MAIN)

# 把动态链接目录下的所有源码文件赋值给变量 DIR_LIB_D
aux_source_directory(./src/lib_d DIR_LIB_D)

# 把静态链接目录下的所有源码文件赋值给变量 DIR_LIB_S
aux_source_directory(./src/lib_s DIR_LIB_S)

# DIR_DLIBS 目录下源码文件生成动态链接库
add_library(lib_d SHARED ${DIR_LIB_D})

# DIR_SLIBS 目录下源码文件生成静态链接库
add_library(lib_s STATIC ${DIR_LIB_S})

# 设置生成可执行文件目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${PROJECT_NAME}/bin)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/cmake_example/bin)

# 设置生成链接库目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${PROJECT_NAME}/lib)
# set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/cmake_example/lib)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${DIR_MAIN})
# add_executable(cmake_example ${DIR_MAIN})

# 将动态库和静态库链接到可执行文件
target_link_libraries(${PROJECT_NAME} lib_d lib_s)
# target_link_libraries(cmake_example lib_d lib_s)

# 添加可执行文件所需要的库，比如我们用到了 libm.so（命名规则：lib+name+.so），即 math.h
# target_link_libraries(${PROJECT_NAME} m)
# target_link_libraries(cmake_example m)
