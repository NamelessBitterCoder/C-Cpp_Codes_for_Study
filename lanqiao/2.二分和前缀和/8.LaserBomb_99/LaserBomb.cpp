#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 5050;
int s[N][N];
int n, m;

int main()
{
	int cnt, R;
	cin >> cnt >> R;
	R = min(R, 5001);
	n = m = R;
	while(cnt--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x++, y++;  //������� 1 ��ʼ��
		n = max(n, x), m = max(m, y);
		s[x][y] += w; 
	}
	
	//����ǰ׺�ͣ�
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
		}
	}
	
	//ö�����еľ��Σ�������Ӧ��Ȩ�أ�
	int res = 0;
	for(int i = R; i <= n; i++)
		for(int j = R; j <= m; j++)
			res = max(res, s[i][j] - s[i][j - R] - s[i - R][j] + s[i - R][j - R]);
	cout << res << endl; 
	return 0;
} 
