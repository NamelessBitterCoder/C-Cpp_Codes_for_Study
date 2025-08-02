#include<iostream>

using namespace std;

int main()
{
    int a;
    int sum;
    cin >> a;
    while(1)
    {
        int n;
        cin >> n;
        if(n <= 0) continue;
        else
        {
            while(n--)
            {
                sum += a++;
            }
            cout << sum << endl;
            break;
        }
    }
    
    return 0;
}
