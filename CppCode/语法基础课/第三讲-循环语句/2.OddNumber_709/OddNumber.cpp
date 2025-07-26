#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        if((i + 1) % 2 == 0)
            printf("%d\n", i);
    }
    return 0;
}
