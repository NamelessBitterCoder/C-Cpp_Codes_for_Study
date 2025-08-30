#include<iostream>

using namespace std;

int main()
{
    while(1)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        if(x <= 0 || y <= 0) break;
        if(x > y) swap(x, y);
        int sum = 0;
        for(int i = x; i <= y; i++)
        {
            sum += i;
            cout << i << " ";
        }
        cout << "Sum=" << sum << endl; 
    }
    return 0;
}
