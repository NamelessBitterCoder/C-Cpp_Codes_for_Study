#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    for(int i = 1000; i > 0; i--)
    {
        if(a % i == 0 && b % i == 0)
            return i;
    }
    return -1;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
