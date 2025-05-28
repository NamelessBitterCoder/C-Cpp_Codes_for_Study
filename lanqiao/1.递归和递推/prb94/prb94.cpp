#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 10;
int n;
int a[N];
bool st[N];
void dfs(int u)
{
	if(u > n)
	{
		for(int i = 1; i < u; i++)
		{
			cout << a[i] <<" ";
		}
		cout << endl;
		return;
	}
	
	//递归实现指数型枚举；
	for(int i = 1; i <= n; i++)
	{
		if(st[i] == false)
		{
			st[i] = true;
			a[u] = i;  //记录方案； 
			dfs(u + 1);
			st[i] = false;  //恢复现场； 
		}
	} 
}

int main()
{
	cin >> n;
	dfs(1);
	return 0;
 } 
