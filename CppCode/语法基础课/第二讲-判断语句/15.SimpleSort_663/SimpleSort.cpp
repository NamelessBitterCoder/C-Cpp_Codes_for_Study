#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = a, y = b, z = c;
    if(b < a) swap(a, b);
    if(c < a) swap(a, c);
    if(c < b) swap(b, c);
    cout << a << endl << b << endl << c << endl << endl;
    cout << x << endl << y << endl << z << endl;
    return 0;
}
