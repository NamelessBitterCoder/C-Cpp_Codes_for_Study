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
	//���к��в������أ�
	for(int i = 0; i < 4; i++)
	{
		turn_one(x, i);
		turn_one(i, y);
	}
	//ȷ����x, y����λ��ֻ���޸�һ�飻
	turn_one(x, y); 
}

int main()
{
	for(int i = 0; i < 4; i++) cin >> g[i];
	
	vector<PII> res;
	for(int op = 1; op < 1 << 16; op++)
	{
		//���ݵ�ǰ״̬��
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
	
		//��黹��û�й��ŵĿ��أ�
		bool has_closed = false;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(g[i][j] == '+') has_closed = true;
			}
	 	} 
	 	//���û�й��ŵĿ��أ�����һ��ʼ��Ϊ�գ�����´𰸣�
	 	if(has_closed == false)
	 	{
	 		if(res.empty() || res.size() > temp.size()) res = temp;
	 	}
	 	//��ԭ���ݣ�
	 	memcpy(g, backup, sizeof(g)); 
	}
	
	//����𰸣�
	cout << res.size() << endl;
	for(auto i : res)
	{
		cout << i.x + 1 << " " << i.y + 1 << endl;
	 } 
	
	return 0;
}




