#include <stdio.h>
int main(void)
{
    int N = 51;
    char s[N];
    scanf("%s", s);
    for(int i=0; i<51; i++)
    {
        if(s[i]=='\0')
        {
            break;
        }
        if(90>=s[i])
        {
            s[i] = s[i] + 32;
        }
    }
    for(int i = 1; i<51; i++)
    {
        if(s[i]=='\0')
        {
            break;
        }
        if(s[i]<s[i-1])
        {
            printf("ZHED has occured\n");
            break;
        }
    }

}
