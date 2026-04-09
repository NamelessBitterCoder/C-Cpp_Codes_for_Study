#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110;
char start[N], aim[N];

void turn(int x)
{
	if(start[x] == '*') start[x] = 'o';
	else start[x] = '*';
 } 
 
int main()
{
 	cin >> start >> aim;
 	int ans = 0;
 	int n = strlen(start);
 	for(int i =0; i < n -1; i++)
 	{
 		if(start[i] != aim[i])
 		{
 			turn(i);
 			turn(i + 1);
 			ans++;
		 }
	 }
	 cout << ans << endl;
 	return 0;
}
