#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 4;
char g[N][N], backup[N][N];

int get(int x, int y)
{
	return 4 * x + y;
}

void turn_one(int x, int y)
{
	if(g[x][y] == '-') g[x][y] = '+';
	else g[x][y] = '-';	
} 

void turn_all(int x, int y)
{
	//按行和列操作开关；
	for(int i = 0; i < 4; i++)
	{
		turn_one(x, i);
		turn_one(i, y);
	}
	//确保（x, y）的位置只被修改一遍；
	turn_one(x, y); 
}

int main()
{
	for(int i = 0; i < 4; i++) cin >> g[i];
	
	vector<PII> res;
	for(int op = 1; op < 1 << 16; op++)
	{
		//备份当前状态；
        memcpy(backup, g ,sizeof g);
        vector<PII> temp;
        for(int i = 0; i < 4; i++)
        {
        	for(int j = 0; j < 4; j++)
			{
				if(op >> get(i, j) & 1)
				{
					temp.push_back({i, j});
					turn_all(i, j);
				}
			}
		}
	
		//检查还有没有关着的开关；
		bool has_closed = false;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(g[i][j] == '+') has_closed = true;
			}
	 	} 
	 	//如果没有关着的开关，或者一开始答案为空，则更新答案；
	 	if(has_closed == false)
	 	{
	 		if(res.empty() || res.size() > temp.size()) res = temp;
	 	}
	 	//还原备份；
	 	memcpy(g, backup, sizeof(g)); 
	}
	
	//输出答案；
	cout << res.size() << endl;
	for(auto i : res)
	{
		cout << i.x + 1 << " " << i.y + 1 << endl;
	 } 
	
	return 0;
}




