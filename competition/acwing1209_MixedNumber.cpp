#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
const int N = 10;
int way[N];
bool st[N];
int ans=0;

int get(int left,int right)
{
    int num = 0;
    for(int i = left;i <= right;i++)
    {
        num = num*10 + way[i];
    }
    return num;
}
bool check(int a,int b,int c)
{
    if(n*c-a*c==b) return true;
    return false;
}
void dfs(int u)
{
    //判断边界；
    if(u>9)
    {
        for(int i=1;i<=7;i++)
        {
            for(int j=i+1;j<=8;j++)
            {
                int a = get(1, i);
                int b = get(i+1, j);
                int c = get(j+1, 9);
                
                if(check(a, b, c)) ans++;
            }
        }
        return;
    }
    //全排列1-9；
    for(int i=1;i<=9;i++)
    {
        if(!st[i])
        {
            way[u] = i;
            st[i] = true;
            dfs(u+1);
            //恢复现场
            st[i] = false;
            way[u] = 0;
        }
    }
}

int main()
{
    cin>>n;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
