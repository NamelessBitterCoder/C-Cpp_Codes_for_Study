#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 25000010;
int m, n;
struct Sum
{
	int s, c, d;
	bool operator< (const Sum &t)const  //重载小于号，用于排序； 
	{
		if(s != t.s) return s < t.s;
		if(c != t.c) return c < t.c;
		return d < t.d;
	} 
}Sum[N];

int main()
{
	cin >> n;
	//先算出 c^2 + d^2;
	for(int c = 0; c * c <= n; c++)
	{
		for(int d = c; c * c + d * d <= n; d++)
		{
			Sum[m++] = {c * c + d * d, c, d};
		}
	}
	
	sort(Sum, Sum + m);
	
	for(int a = 0; a * a <= n; a++)
	{
		for(int b = a; a * a + b * b <= n; b++)
		{
			int t = n - a * a - b * b;
			int l = 0, r = m - 1;
			while(l < r)
			{
				int mid = l + r >> 1;
				if(Sum[mid].s >= t) r = mid;
				else l = mid + 1;
			}
			if(Sum[l].s == t)
			{
				printf("%d %d %d %d\n", a, b, Sum[l].c, Sum[l].d);
				return 0;
			}
		}
	} 
	return 0;
} 
