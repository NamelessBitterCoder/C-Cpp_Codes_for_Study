#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
const int N = 16;
int a[N];
int st[N]; //0:δѡ��1��ѡ��2����ѡ��
void dfs(int u)
{
    if(u>n)
    {
        for(int i=1;i<=n;i++)
        {
            if(st[i]==1)
            {
                printf("%d ",a[i]);
            }
        }
        printf("\n");
        return;
    }
    
    //1.ѡ��
    st[u]=1;
    a[u]=u;
    dfs(u+1);
    
    //2.��ѡ��
    st[u]=2;
    a[u]=0;
    dfs(u+1);
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
