#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010;
int a[N];
int n, q;

int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	while(q--)
	{
		int k;
		scanf("%d", &k);
		int l, r;
		l = 0, r = n - 1;
		//先找到左侧边界点；
		while(l < r)
		{
			int mid = l + r >> 1;
			if(a[mid] >= k) r = mid;
			else l = mid + 1;
		}
		if(a[l] == k)
		{
			cout << l << " ";
			r = n - 1;
			while(l < r)
			{
				int mid = l + r + 1 >> 1;
				if(a[mid] <= k) l = mid;
				else r = mid - 1;
			}
			cout << r << endl;
		}
		else cout << -1 << " " << -1 << endl; 
	} 
	return 0;
} 
