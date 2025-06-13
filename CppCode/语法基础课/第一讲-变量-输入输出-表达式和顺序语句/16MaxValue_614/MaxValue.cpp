#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    b = (a + b + abs(a - b)) / 2;
    c = (b + c + abs(b - c)) / 2;
    printf("%d eh o maior\n", c);
    return 0;
}
