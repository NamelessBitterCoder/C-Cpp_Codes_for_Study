#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	return b ? gcd(b, b % a) : a;
}
int main()
{
	int m, n;
	cin >> m >> n;
	cout << gcd(m, n) << endl;
	return 0;
} 
