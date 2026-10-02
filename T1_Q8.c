#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[51];
    char t[51];
    scanf("%s %s", s, t);
    printf("%s, %s\n" , s , t);
    int m = strlen(s);
    int n = strlen(t);
    int min = (m<n)?m:n;
    int s_=0;
    int t_=0;
    for(int i = 0 ;i<m ; i++)
    {
        s_ = s_*10 + (s[i]-'0');
    }
    for(int i = 0 ;i<n ; i++)
    {
        t_ = t_*10 + (t[i]-'0');                                              
    }
    printf("%d", s_+t_);
}
