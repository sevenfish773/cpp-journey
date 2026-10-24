// ============================================================
//  week01 练习：手写 C 标准库函数
//  文件：my_string.c
//
//  👉 这个文件现在是空的实现骨架，请你自己填。
//  👉 填完跑测试：见 test_string.c 和 00-自测清单.md
//  👉 写完之后再 commit，提交信息写清"做了什么"
// ============================================================

#include "my_string.h"

#include <stdlib.h>   // malloc / free

// ------------------------------------------------------------
// 练习 1：手写 strlen
// 提示：用一个计数器从 0 开始，逐个字符往后走，直到遇到 '\0'
// ------------------------------------------------------------
size_t my_strlen(const char* str)
{
    if (str == NULL) {
        return 0;
    }

    size_t len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

// ------------------------------------------------------------
// 练习 2：手写 strcpy
// 提示：先把 dest 存一份，循环拷贝，最后返回最初存的那份
// ------------------------------------------------------------
char* my_strcpy(char* dest, const char* src)
{
    if (dest == NULL || src == NULL) {
        return dest;
    }

    char* original_dest = dest;  // 保存 dest 的起始位置
    while (*src != '\0') {
        *dest++ = *src++;  // 拷贝字符并移动指针
    }
    *dest = '\0';  // 添加字符串结束符

    return original_dest;  // 返回最初的 dest 指针
}

// ------------------------------------------------------------
// 练习 3：手写 strcat
// 提示：先找到 dest 的结尾（'\0' 的位置），从那里开始拷贝 src
// ------------------------------------------------------------
char* my_strcat(char* dest, const char* src)
{
    if (dest == NULL || src == NULL) {
        return dest;
    }

    char* original_dest = dest;  // 保存 dest 的起始位置
    while (*dest != '\0') {
        dest++;  // 移动到 dest 的结尾
    }
    while (*src != '\0') {
        *dest++ = *src++;  // 拷贝字符并移动指针
    }
    *dest = '\0';  // 添加字符串结束符

    return original_dest;  // 返回最初的 dest 指针
}

// ------------------------------------------------------------
// 练习 4：手写 strdup  ★ 本周重点
//
// 分解成 3 步，别想一步写完：
//   步骤 1：src 为 NULL 就直接返回 NULL
//   步骤 2：算出需要多少字节 = strlen(src) + 1（+1 是给 '\0' 的）
//   步骤 3：malloc 这块内存；如果返回 NULL（内存不够），返回 NULL
//   步骤 4：把 src 拷进新内存，返回新指针
//
// 写完之后问自己：谁负责 free 这块内存？如果忘了 free 会发生什么？
// ------------------------------------------------------------
char* my_strdup(const char* src)
{
    if (src == NULL) {
        return NULL;  // 步骤 1
    }

    size_t len = my_strlen(src) + 1;  // 步骤 2
    char* new_str = (char*)malloc(len);  // 步骤 3
    if (new_str == NULL) {
        return NULL;  // 内存分配失败
    }

    my_strcpy(new_str, src);  // 步骤 4
    return new_str;
}
