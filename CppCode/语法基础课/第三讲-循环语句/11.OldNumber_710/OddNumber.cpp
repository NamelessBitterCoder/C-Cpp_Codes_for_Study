#include<iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int count = 0;
    for(int i = x; i <= 111; i++)
    {
        if(i % 2 == 1)
        {
            cout << i << endl;
            count++;
        }
        if(count == 6)
            break;
            
    }
    return 0;
}
