#include<iostream>
using namespace std;

int main()
{
	int distance;
	double pertrol;
	cin >> distance >> pertrol;
	printf("%.3lf km/l\n", distance / pertrol);
	return 0;
} 
