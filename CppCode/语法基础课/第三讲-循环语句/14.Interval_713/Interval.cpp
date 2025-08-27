#include<iostream>

using namespace std;

int main()
{
    int in = 0;
    int out = 0;
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        if(x >= 10 && x <= 20)
            in++;
        else
            out++;
    }
    cout << in <<" "<< "in" << endl;
    cout << out << " " << "out" << endl;
    return 0;
}
