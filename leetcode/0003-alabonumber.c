int romanToInt(char* s) {
    int getVal(char c)
    {
        switch(c){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default:return 0;
        }
    }
    int res=0,i=0;
    while(s[i]!='\0'){
        int cur = getVal(s[i]);
        int next = getVal(s[i+1]);
        if(cur < next) res -= cur;
        else res += cur;
        i++;
    }
    return res;
}
int main(void)
{
    char s[20];
    printf("input the roman number:");
    scanf("%s",s);
    int result=romanToInt(s);
    printf("%d\n",result);
    return 0;
}