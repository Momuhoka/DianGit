cmake_minimum_required(VERSION 3.10)

project(DianGit VERSION 0.1)

# 添加源文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 获取 src 目录下的所有 .c 文件
file(GLOB SRC_FILES "src/*.c")

# 添加可执行文件并链接头文件和所有 .c 文件
add_executable(DianGit ${SRC_FILES})

# 指定输出文件夹
set_target_properties(DianGit PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)


