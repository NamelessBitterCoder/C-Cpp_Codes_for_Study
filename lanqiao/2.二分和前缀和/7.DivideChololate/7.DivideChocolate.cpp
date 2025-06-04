#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 100010;
int n, k;
int h[N], w[N]; 
bool check(int m)
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += (h[i] / m) * (w[i] / m);
		if(sum >= k) return true;
	}
	return false;
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> h[i] >> w[i];
	
	int l = 1, r = 1e5;
	while(l < r)
	{
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
