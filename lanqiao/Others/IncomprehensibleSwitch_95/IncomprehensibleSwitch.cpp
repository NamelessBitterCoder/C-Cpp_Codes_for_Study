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
		g[a][b] ^= 1; //�� 1 ��� 0���� 0 ��� 1�� 
	}
}
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		//�������ݣ�
		for(int i = 0; i < 5; i++)
		{
			cin >> g[i];  //����5���ַ����� 
		} 
		 
		 int ans = 10;
		 for(int op = 0; op < 32; op++)
		 {
		 	int step = 0;
		 	memcpy(backup, g, sizeof(g));  //���ݵ�ǰ��״̬��
			//������һ�еĿ��أ�
			for(int i = 0; i < 5; i++)
			{
				if(op >> i & 1)  //���� i λȡ���� 
				{
					turn(0, 4 - i);
					step++;
				}
			} 
			
			//����2-4�еĿ��أ�
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
			 
			 //������һ���Ƿ��й��ŵĵƣ�
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
