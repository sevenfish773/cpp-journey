#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) return false;   /* 奇数长度不可能配对 */

    char stack[10000];              /* n <= 10^4 */
    int top = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;                    /* 左括号压栈 */
        }
        else {
            if (top == 0) return false;          /* 右括号来了，栈却是空的 */
            char need = (c == ')') ? '('
                      : (c == ']') ? '[' : '{';
            if (stack[top - 1] != need) return false;  /* 类型不匹配，如 "(]" */
            top--;                               /* 配对成功，弹出 */
        }
    }
    return top == 0;                /* 栈必须为空，否则还有左括号没闭合 */
}
 int main(void)
 {
    char s[10000];
    printf("input the string:");
    scanf("%s",s);
    bool result=isValid(s);
    printf("%d\n",result);
    return 0;}