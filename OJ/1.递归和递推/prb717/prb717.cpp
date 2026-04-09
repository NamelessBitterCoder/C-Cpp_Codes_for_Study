#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 55;
int n;
int f[N];
int main()
{
	cin >> n;
	f[1] = 0, f[2] = 1;
	for(int i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	for(int i = 1; i <= n; i++)
		cout << f[i] << " ";
	return 0;
}
