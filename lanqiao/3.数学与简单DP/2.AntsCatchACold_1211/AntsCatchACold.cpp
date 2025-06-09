#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm> 

using namespace std;

const int N = 60;
int x[N];
int main()
{
	int n;
	cin >> n;
	for(int i =1; i <= n; i++)
		cin >> x[i];
	int left = 0, right = 0;  //分别表示在生病蚂蚁的左边开始 向右走，和在生病蚂蚁右边向左走的蚂蚁数量；
	for(int i = 1; i <= n; i++)
	{
		if(abs(x[i]) < abs(x[1]) && x[i] > 0) left++;
		if(abs(x[i]) > abs(x[1]) && x[i] < 0) right++;
	}
	if(x[1] > 0 && right == 0 || x[1] < 0 && left == 0) cout << 1 << endl;
	else cout << left + right + 1 << endl; 
	return 0;
}
