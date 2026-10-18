# ============================================================
#  week01 构建文件
#  编译 my_string.c + test_string.c，生成可执行文件并注册测试
# ============================================================

# 生成可执行文件（源文件列表里已经包含 my_string.c，不用单独建库）
add_executable(test_string
    my_string.c
    test_string.c
)

# 让 #include "my_string.h" 能找到（当前目录）
target_include_directories(test_string PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 把测试注册到 ctest，名字叫 week01-string
add_test(NAME week01-string COMMAND test_string)

add_executable(practise practise.c)