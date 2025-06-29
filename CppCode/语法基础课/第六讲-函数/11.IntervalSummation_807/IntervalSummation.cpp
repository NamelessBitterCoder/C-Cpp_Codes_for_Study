#include<iostream>

using namespace std;

int sum(int l ,int r)
{
    int sum = 0;
    for(int i = l; i <= r; i++)
        sum += i;
    return sum;
}
int main()
{
    int l, r;
    cin >> l >> r;
    cout << sum(l, r) << endl;
    return 0;
}
