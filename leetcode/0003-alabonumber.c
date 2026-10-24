#include <stdio.h>
#include <string.h>

/* ===== 修正版：把 getVal 提到文件作用域，放在调用者前面 ===== */

static int getVal(char c)
{
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;   /* '\0' 也走这里，正好当成 0，末尾无需特判 */
    }
}

int romanToInt(char* s)
{
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int cur  = getVal(s[i]);
        int next = getVal(s[i + 1]);   /* s[i+1] 最多读到 '\0'，安全 */
        if (cur < next) total -= cur;  /* 小值在大值左边 → 减 */
        else            total += cur;  /* 否则 → 加 */
    }
    return total;
}

struct Case { const char *s; int expect; };

int main(void)
{
    struct Case cases[] = {
        {"III", 3}, {"IV", 4}, {"IX", 9}, {"LVIII", 58},
        {"MCMXCIV", 1994}, {"MMMCMXCIX", 3999}, {"I", 1},
        {"XLVIII", 48}, {"CDXLIV", 444},
    };
    int n = (int)(sizeof(cases) / sizeof(cases[0])), bad = 0;
    for (int k = 0; k < n; k++) {
        int got = romanToInt((char *)cases[k].s);
        printf("%-12s expect=%-5d got=%-5d %s\n", cases[k].s, cases[k].expect, got,
               got == cases[k].expect ? "OK" : "FAIL");
        if (got != cases[k].expect) bad++;
    }
    printf("---- %d/%d passed\n", n - bad, n);
    return bad != 0;
}