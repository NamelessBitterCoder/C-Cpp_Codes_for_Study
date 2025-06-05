#include<iostream>
using namespace std;
const int size = 10;

void findmax(int* a, int n, int i, int &pk);

int main()
{
	int a[size];
	int n = 0;
	cout << "Please input " << size <<" datas:\n";
	for(int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	
	findmax(a, size, 0, n);
	
	cout << "The maximum is " << a[n] << endl
			<<"It's index is " << n << endl;
	return 0;
}

void findmax(int* a, int n, int i, int &pk)
{
	if(i < n)
	{
		if(a[i] > a[pk])
		pk = i;
		findmax(a, n, i + 1, pk);
	}
}
