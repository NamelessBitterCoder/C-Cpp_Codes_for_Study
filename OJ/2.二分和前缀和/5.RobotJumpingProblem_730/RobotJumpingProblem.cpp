#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010;
int h[N];
int n;
bool check(int e)
{
	for(int i = 1; i <= n; i++)
	{
		e = 2 * e - h[i];
		if(e >= 1e5) return true;
		if(e < 0) return false;
	}
	return true;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> h[i];
	
	int l = 0, r = 1e5;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << l << endl;
	return 0;
} 
