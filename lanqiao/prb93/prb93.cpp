#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 55;
int way[N];
int n, m;

void dfs(int u, int start)
{
	if(n - start + u < m) return;
	if(u > m)
	{
		for(int i = 1; i <= m; i++)
		{
			cout<< way[i] <<" ";
		}
		cout << endl;
		return;
	}

	for(int i = start; i <= n; i++)
	{
		way[u] = i;
		dfs(u + 1, i + 1); 
		way[u] = 0; 
	}
}

int main()
{
	cin >> n >> m;
	dfs(1, 1);
	return 0;
}
