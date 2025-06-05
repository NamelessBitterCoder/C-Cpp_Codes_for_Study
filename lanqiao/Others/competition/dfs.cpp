#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 10;
int state[N]; //存储路径的状态
bool used[N]; //表示数的状态；false:未选；true:已选；
int n;
void dfs(int u)
{
    //判断边界；
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
            
            //恢复现场；
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
