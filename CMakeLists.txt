# ============================================================
#  cpp-journey 顶层构建文件
#  用法：
#    cmake -S . -B build
#    cmake --build build
#    ctest --test-dir build --output-on-failure
# ============================================================
cmake_minimum_required(VERSION 3.16)

project(cpp_journey
    VERSION 0.1.0
    DESCRIPTION "My C++ learning journey"
    LANGUAGES CXX)

# ---- 全局编译选项 ----
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 把可执行文件输出到统一的 bin 目录，方便找
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# MSVC / GCC / Clang 通用的警告选项：把警告当"提醒"而不是"噪音"
if(MSVC)
    add_compile_options(/W4 /utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ---- 打开测试功能 ----
enable_testing()

# ---- 逐周添加子目录（每完成一周就加一行）----
add_subdirectory(week01-c-basics)
