#include<iostream>

using namespace std;

int a[110];
int main()
{
    for(int i = 1; i <= 100; i++)
        cin >> a[i];
    int max = -1;
    int maxi = 0;
    for(int i = 1; i <= 100; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
            maxi = i;
        }
    }
    cout << max << endl << maxi <<endl;
    return 0;
}
