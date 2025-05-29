#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, q;
const int N = 1010;
int sum[N][N];

int main()
{
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> sum[i][j];
			sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}
	
	while(q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << endl;
	}
	return 0;
}
