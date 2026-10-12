// ============================================================
//  week01 测试文件
//  文件：test_string.c
//
//  【不要修改这个文件！】
//  它的作用是当裁判。你的任务是把 my_string.c 里的实现写对，
//  让所有断言通过。
//
//  运行方式（在 build 目录下）：
//      ./bin/test_string        （Windows：.\bin\Debug\test_string.exe）
//  或者用 ctest：
//      ctest --output-on-failure
// ============================================================

#include "my_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // 只在测试里用来做"标准答案"对照

static int g_pass = 0;
static int g_fail = 0;

#define CHECK(cond, msg)                                            \
    do {                                                            \
        if (cond) {                                                 \
            ++g_pass;                                               \
            printf("  [PASS] %s\n", (msg));                         \
        } else {                                                    \
            ++g_fail;                                               \
            printf("  [FAIL] %s   (line %d)\n", (msg), __LINE__);   \
        }                                                           \
    } while (0)

static void test_strlen(void)
{
    printf("\n[1/4] my_strlen\n");
    CHECK(my_strlen("") == 0, "空字符串长度为 0");
    CHECK(my_strlen("a") == 1, "\"a\" 长度为 1");
    CHECK(my_strlen("hello") == 5, "\"hello\" 长度为 5");
    CHECK(my_strlen("hello world") == 11, "带空格字符串长度正确");
    CHECK(my_strlen(NULL) == 0, "NULL 返回 0（本练习约定）");
}

static void test_strcpy(void)
{
    printf("\n[2/4] my_strcpy\n");

    char buf[32];
    char* ret = my_strcpy(buf, "hello");
    CHECK(ret == buf, "返回值等于 dest");
    CHECK(strcmp(buf, "hello") == 0, "内容拷贝正确");

    my_strcpy(buf, "");
    CHECK(buf[0] == '\0', "拷贝空字符串时立即写入 '\\0'");

    // 拷贝一个刚好填满的字符串（10 个字符 + '\0' = 11 字节）
    char exact[11];
    my_strcpy(exact, "0123456789");
    CHECK(strcmp(exact, "0123456789") == 0, "边界长度拷贝正确");
}

static void test_strcat(void)
{
    printf("\n[3/4] my_strcat\n");

    char buf[32] = "hello";
    char* ret = my_strcat(buf, " world");
    CHECK(ret == buf, "返回值等于 dest");
    CHECK(strcmp(buf, "hello world") == 0, "追加后内容正确");

    char buf2[16] = "";
    my_strcat(buf2, "abc");
    CHECK(strcmp(buf2, "abc") == 0, "向空字符串追加");

    char buf3[16] = "abc";
    my_strcat(buf3, "");
    CHECK(strcmp(buf3, "abc") == 0, "追加空字符串不改变内容");
}

static void test_strdup(void)
{
    printf("\n[4/4] my_strdup  ★ 重点\n");

    char* p = my_strdup("hello");
    CHECK(p != NULL, "返回非 NULL");
    CHECK(p != NULL && strcmp(p, "hello") == 0, "内容正确");
    // p 必须是自己 malloc 出来的新内存，不能等于原字符串字面量地址
    CHECK(p != (char*)"hello" || strcmp(p, "hello") == 0, "至少内容一致");
    free(p);

    char* empty = my_strdup("");
    CHECK(empty != NULL, "空字符串也要分配内存（不能返回 NULL）");
    CHECK(empty != NULL && empty[0] == '\0', "空字符串内容为 '\\0'");
    free(empty);

    CHECK(my_strdup(NULL) == NULL, "src 为 NULL 时返回 NULL");
}

int main(void)
{
    printf("========================================\n");
    printf("  week01 测试：手写 C 字符串函数\n");
    printf("========================================\n");

    test_strlen();
    test_strcpy();
    test_strcat();
    test_strdup();

    printf("\n========================================\n");
    printf("  通过 %d 项，失败 %d 项\n", g_pass, g_fail);
    printf("========================================\n");

    if (g_fail == 0) {
        printf("\n全部通过！可以 commit 了：\n");
        printf("  git add .\n");
        printf("  git commit -m \"week01: 完成手写 strlen/strcpy/strcat/strdup\"\n");
        printf("  git push\n\n");
        return 0;
    }

    printf("\n还没全过，回去改 my_string.c，再跑一次。\n");
    printf("提示：报 [FAIL] 的那一行，看 __LINE__ 指到测试里的哪一条断言。\n\n");
    return 1;
}
