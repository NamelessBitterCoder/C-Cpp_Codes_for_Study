#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 6;
char g[N][N], backup[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

void turn(int x, int y)
{
	for(int i = 0; i < 5; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if(a < 0 || a >= 5 || b < 0 || b >= 5) continue;
		g[a][b] ^= 1; //把 1 变成 0，把 0 变成 1； 
	}
}
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		//读入数据；
		for(int i = 0; i < 5; i++)
		{
			cin >> g[i];  //读入5行字符串； 
		} 
		 
		 int ans = 10;
		 for(int op = 0; op < 32; op++)
		 {
		 	int step = 0;
		 	memcpy(backup, g, sizeof(g));  //备份当前的状态；
			//操作第一行的开关；
			for(int i = 0; i < 5; i++)
			{
				if(op >> i & 1)  //将第 i 位取出； 
				{
					turn(0, 4 - i);
					step++;
				}
			} 
			
			//操作2-4行的开关；
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 5; j++)
				{
					if(g[i][j] == '0')
					{
						turn (i + 1, j);
						step++;
					}
				}
			 }
			 
			 //检查最后一行是否还有关着的灯；
			 bool dark = false;
			 for(int j = 0; j < 5; j++)
			 {
			 	if(g[4][j] == '0')
				 {
				 	dark = true;
					break;	
				 }	
			 }
			 if(dark == false) ans = min(ans, step);
			 memcpy(g, backup, sizeof(backup)); 
		}
		if(ans > 6) ans = -1;
		cout << ans << endl;  
	}
	return 0;
} 
