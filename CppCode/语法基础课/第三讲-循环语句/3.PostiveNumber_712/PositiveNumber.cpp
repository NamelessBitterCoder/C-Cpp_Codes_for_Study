#include<iostream>

using namespace std;

int main()
{
    double a[6];
    for(int i = 0; i < 6; i++)
        cin >> a[i];
    int count = 0;
    for(int i = 0; i < 6; i++)
        if(a[i] > 0)
            count++;
    printf("%d positive numbers\n", count);
    
}
