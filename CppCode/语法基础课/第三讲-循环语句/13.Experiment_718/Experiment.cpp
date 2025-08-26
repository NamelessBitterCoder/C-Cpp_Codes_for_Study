#include<iostream>

using namespace std;

int main()
{
    int total = 0, frog = 0, coney = 0, rat = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num = 0;
        char opt;
        cin >> num >> opt;
        total += num;
        if(opt == 'C') coney += num;
        else if(opt == 'R')  rat += num;
        else  frog += num;
    }
    printf("Total: %d animals\n", total);
    printf("Total coneys: %d\n", coney);
    printf("Total rats: %d\n", rat);
    printf("Total frogs: %d\n", frog);
    printf("Percentage of coneys: %.2lf %\n", coney * 100.0 / total);
    printf("Percentage of rats: %.2lf %\n", rat * 100.0 / total);
    printf("Percentage of frogs: %.2lf %\n", frog * 100.0 /total);
    return 0;
}
