#include <stdio.h>
    int isPalindrome(int x) {
    if (x < 0) 
    return 0;

    int d[10], n = 0;
    for (int y = x; y > 0; y /= 10) d[n++] = y % 10;  // 低位在前

    if (n == 0) return 1;                          // x == 0
    for (int m = 0; m < n / 2; m++)
        if (d[m] != d[n - 1 - m]) return 0;
    return 1;
}
int main(void)
{
    int x;
    printf("input the number:");
    scanf("%d",&x);
    int result=isPalindrome(x);
    if(result==1)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}