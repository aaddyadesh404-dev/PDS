#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int k;
    cin>>k;
    int n[50];
    for(int i = 0; i<50; i++)
    {
        n[i]=1;
    }
    int count = 0;
    for(int i=0; i<50; i++)
    {
        if(n[i]==1)
        {
            if(count < k)
            {
                count++;
            }
            if(count == k)
            {
                n[i] = 0;
                cout<<i+1<<" is dead"<<endl;
                count = 0;
            }
        }
        if(i == 50-1)
        {
            i = -1;
        }
        int z = 0;
        for(int j = 0; j<50;j++)
        {
            if(n[j]==1)
            {
                z++;
            }
        }
        if(z==1)
        {
            break;
        }
    }
    for(int j=0; j<50;j++)
    {
        if(n[j]==1)
        {
            cout<<j+1<< " is the survivor"<<endl;
            break;
        }
    }
}