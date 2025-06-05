#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 10;
int state[N]; //�洢·����״̬
bool used[N]; //��ʾ����״̬��false:δѡ��true:��ѡ��
int n;
void dfs(int u)
{
    //�жϱ߽磻
    if(u>n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d ",state[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            state[u]=i;
            used[i]=true;
            dfs(u+1);
            
            //�ָ��ֳ���
            state[u]=0;
            used[i]=false;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
