#include<iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        int sum = 0;
        if(x > y)
        {
            int t = x;
            x = y;
            y = t;
        }
        for(int i = x + 1; i < y; i++)
        {
            if(i % 2)
                sum += i;
        }
        cout << sum << endl;
    }
    return 0;
}
