#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Q4 */
void sort(int a[], int n, int k)
{
    int sorted = 0;
    for(int i = k; i>0; i--)
    {
        int index = n-sorted;
        while(a[i]<a[index])
        {
            index--;
        }
        int temp = a[i];
        for(int j = i; j<index; j++)
        {
            a[j] = a[j+1];
        }
        a[index] = temp;
        sorted++;
    }
}

/* Q5 */
void remove_same_char(char *s, int index,int len)
{
    //Base Condition
    if(index >= len - 1)
    {
        return;
    }
    
    if(s[index] == s[index+1])
    {
        for(int i = index; i<len-2; i++)
        {
            s[i] = s[i+2];
        }
        s[len-2] = '\0';
        printf("string is now: %s\n", s);
        remove_same_char(s,0,len-2);
    }
    else
    {
        remove_same_char(s,index+1,len);
    }
    
    return;
}

/* Q3 */
void rev(int* l, int*r)
{
    *l = (*l + *r);
    *r = (*l - *r);
    *l = (*l - *r);
    return;
}

/* Q1 */
void basechange(char *s, int n, int k, int b, int* pos)
{
    
    
    if(b<2 || b>16)
    {
        printf("INVALID BASE");
        return;
    }
    else if(b<=10)
    {
        //Base Condition
        if(k==0)
        {
            if(*pos == 0)
                *pos=k;
            s[30] = n%b + '0';
            return;
        }

        if(n>=(long long int)(pow(b,k)))
        {
            
            if(*pos == 0)
                *pos=k;
            s[30-k] = '0' + n/((long long int)(pow(b,k)));
            basechange(s, n-(n/((long long int)(pow(b,k))))*((long long int)(pow(b,k))), k-1,b,pos);
        }
        else
        {   
            s[30-k] = '0';
            basechange(s,n,k-1,b,pos);
        }
        return;
    }    
    else
    {
        //Base Condition
        if(k==0)
        {
            if(*pos == 0)
                *pos=k;
            s[30] = n%b + '0';
            return;
        }

        if(n>=(long long int)(pow(b,k)))
        {
            if(*pos == 0)
                *pos=k;
            if(n/((long long int)(pow(b,k))) < 10)
            {
                s[30-k] = '0' + n/((long long int)(pow(b,k)));
                basechange(s, n-(n/((long long int)(pow(b,k))))*((long long int)(pow(b,k))),k-1,b,pos);
            }
            else
            {
                s[30-k] = 'A' + n/((long long int)(pow(b,k))) - 10;
                basechange(s, n-(n/((long long int)(pow(b,k))))*((long long int)(pow(b,k))),k-1,b,pos);
            }
        }
        else
        {   
            s[30-k] = '0';
            basechange(s,n,k-1,b,pos);
        }
        return;
    }    
}
int main(void)
{
    /*
    
    Q4

    int n,k;
    scanf("%d %d", &n, &k);
    int* a = (int *)malloc((n+1)*sizeof(int));
    for(int i = 1; i<=n; i++)
    {
        scanf("%d", a+i);
    }
    sort(a,n,k);
    for(int i = 1; i<=n; i++)
    {
        printf("%d ", *(a+i));
    }

    */

    /*
    
    Q5
    
    char *s = (char*)malloc(1000*sizeof(char));
    scanf("%s", s);
    int len = strlen(s);
    remove_same_char(s,0,len);
    printf("%s", s);

    */

    /*

    Q6
    
    char *s = (char *)malloc(1000*sizeof(char));
    int *t = (int *)malloc(1000*sizeof(int));
    scanf("%s", s);
    int len = strlen(s);
    int j = 0;
    for(int i = 0; i<len; i++)
    {
        int count = 1;
        while( i<len && s[i]==s[i+1])
        {
            count++;
            i++;
        }
        t[j] = (int)s[i];
        t[j+1] = count;
        j = j+2;
    }
    
    for(int i = 0; i<j; i++)
    {
        if(i%2 == 0)
            printf("%c", t[i]);
        else
            printf("%d", t[i]);
    }

    */

    /*

    Q3
    
    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
    {
        scanf("%d", A+i);
    }
    int k;
    scanf("%d", &k);
    
    //Without Using rev function

    while(k--)
    {
        int temp = A[0];
        for(int i = 0; i<n-1; i++)
        {
            A[i] = A[i+1];
        }
        A[n-1] = temp;
    }

    // Using rev function

    int k_ = k%n;
    while(k_--)
    {
        for(int i = k_;i<n-(k%n-k_); i++)
        {
            rev(A+i,A+i+1);
        }       
    }

    for(int i = 0; i<n; i++)
    {
        printf("%d ", *(A+i));
    }

    */

    /*

    Q2

    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
    {
        scanf("%d", A+i);
    }

    int *B = (int *)malloc(n*sizeof(int));
    
    int j = 0;
    for(int i = 0; i<n; i++)
    {
        
        while( i<n-1 && A[i]==A[i+1])
        {
            i++;
        }
        B[j] = A[i];
        j++;
    }

    
    B = (int *)realloc(B, j*sizeof(int));

    for(int i = 0; i<j; i++)
    {
        printf("%d ", *(B+i));
    }

    */

    /*
    
    Q1

    char* baseN = (char *)malloc(31*sizeof(char));
    int n; 
    scanf("%d", &n);
    int b;
    scanf("%d", &b);
    int pos=0;
    //Add a switch depending on the base, so that you can get the appropriate base dependent value of k
    basechange(baseN,n,15,b,&pos);
    printf("%d \n", pos);
    baseN = baseN + 30 - pos;
    printf("%s", baseN);

    */

}