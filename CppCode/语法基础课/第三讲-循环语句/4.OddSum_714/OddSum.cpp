#include<iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if(x > y) swap(x, y);
    int sum = 0;
    for(int i = x + 1; i < y; i++)
        if((i + 1) % 2 == 0)
            sum += i;
    cout << sum << endl;
    return 0;
}
