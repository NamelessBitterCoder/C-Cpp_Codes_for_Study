#include<iostream>

using namespace std;

int abs(int x)
{
    if(x < 0) return -1 * x;
    else return x;
}
int main()
{
    int x;
    cin >> x;
    cout << abs(x) << endl;
    return 0;
}
