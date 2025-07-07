#include<iostream>

using namespace std;

int m, n;
int ans;
void dfs(int x, int y)
{
    if(x == n && y == m) ans++;
    else
    {
        if(x < n) dfs(x + 1, y);
        if(y < m) dfs(x, y + 1);
    }
    
}
int main()
{
    cin >> n >> m;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
