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
	
	//�ݹ�ʵ��ָ����ö�٣�
	for(int i = 1; i <= n; i++)
	{
		if(st[i] == false)
		{
			st[i] = true;
			a[u] = i;  //��¼������ 
			dfs(u + 1);
			st[i] = false;  //�ָ��ֳ��� 
		}
	} 
}

int main()
{
	cin >> n;
	dfs(1);
	return 0;
 } 
