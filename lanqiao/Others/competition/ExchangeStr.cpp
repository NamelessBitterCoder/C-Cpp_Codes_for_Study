#include<iostream>
using namespace std;

void ExchangeStr(char* &a, char* &b);
int main()
{
	char* ap = "hello";
	char* bp = "how are you?"; 
	cout << "Before: " << endl;
	cout << "ap:\t" << ap <<endl;
	cout << "bp:\t" << bp << endl;
	ExchangeStr(ap, bp);
	cout << "After: " << endl;
	cout << "ap:\t" << ap <<endl;
	cout << "bp:\t" << bp << endl;
	return 0;
}
void ExchangeStr(char* &a, char* &b)
{
	char* t = a;
	a = b;
	b = t;
}
