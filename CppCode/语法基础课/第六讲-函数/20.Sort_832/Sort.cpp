#include<iostream>

using namespace std;

int n;
bool st[10];
int way[10];

void dfs(int u)
{
    if(u > n)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << way[i] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            way[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
            way[u] = 0;
        }
        
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
