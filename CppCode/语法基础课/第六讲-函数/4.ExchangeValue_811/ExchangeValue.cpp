#include<iostream>

using namespace std;

void swap(int &x, int &y)
{
    if(x == y) return;
    int t = x;
    x = y;
    y = t;
}
int main()
{
    int x, y;
    cin >> x >> y;
    swap(x, y);
    cout << x <<" "<< y << endl;
    return 0;
}
