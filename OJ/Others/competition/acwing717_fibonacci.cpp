#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int n;
int main()
{
    cin>>n;
    int f[50];
    f[1] = 0,f[2] = 1;
    for(int i=3;i<=n;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<f[i]<<" ";
    }
    cout<<endl;
    return 0;
}
