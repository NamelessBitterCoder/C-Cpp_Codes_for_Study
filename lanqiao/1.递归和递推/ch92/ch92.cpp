#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 16;
int n;
int st[N];

void dfs(int u)
{
	if(u > n)
	{
		for(int i = 1; i <= n; i++)
			if(st[i] == 1)
				printf("%d ", i);
		printf("\n");
		return;
	 } 
	 
	 st[u] = 2;
	 dfs(u + 1); //第一个分支，不选；
	 st[u] = 0;  //恢复现场；
	 
	 st[u] = 1;  //第一个分支，选；
	 dfs(u + 1);
	 st[u] = 0; 
}
int main()
{
	cin >> n;
	
	dfs(1);
	
	return 0;
} 
