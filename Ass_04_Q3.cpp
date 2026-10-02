#include <bits/stdc++.h>
using namespace std;
int main(void)
{
     int A[100];
    int m;
    cin>>m;
    for(int i = 0;i<m; i++)
    {
        cin>>A[i];
    }
    int B[100];
    int n;
    cin>>n;
    for(int i = 0;i<n; i++)
    {
        cin>>B[i];
    }

    int C[200];
    int c=0;
    for(int i=0; i<m; i++)
    {
        int flag = 1;
        for(int j = 0; j<c ; j++)
        {
            if(A[i] == C[j])
            {
                flag = 0;
                break;
            }
           
        }
         if(flag==1)
            {
                C[c]=A[i];
                c++;
            }
    }
    for(int i=0; i<n; i++)
    {
        int flag = 1;
        for(int j = 0; j<c ; j++)
        {
            if(B[i] == C[j])
            {
                flag = 0;
                break;
            }
            
        }
        if(flag==1)
            {
                C[c]=B[i];
                c++;
            }
    }

    cout<<c<<endl;;
    for(int i=0; i<c; i++)
    {
        cout<< C[i] <<" ";
    }
    return 0;
}