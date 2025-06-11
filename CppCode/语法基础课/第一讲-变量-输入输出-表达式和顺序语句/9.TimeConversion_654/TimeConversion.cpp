#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int hour = n / 3600;
    n %= 3600;
    int minute = n /60;
    int second = n % 60;
    cout << hour << ":" << minute << ":" << second << endl;
    return 0;
}
