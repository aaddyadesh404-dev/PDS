
#include <stdio.h>
int per(int);
int main(void)
{
    int a;
    int b;
    scanf("%d %d", &a, &b);
    int max = 0;
    int num = 0;
    for(int i = a; i<=b; i++)
    {
        int per_i=i;
        int count = 0;
        do
        {
            per_i = per(per_i);
            count++;
        } while ((per_i)>=10);
        if(count>max)
        {
            max = count;
            num = i;
        }
        
    }
    printf("%d %d", num , max);
}
int per(int n)
{
    int product = 1;
    while(n)
    {
        int digit = n%10;
        product*=digit;
        n/=10;
    }
    return product;
}