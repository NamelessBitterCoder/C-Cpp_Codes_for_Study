#include<iostream>

using namespace std;

int main()
{
    char name[10];
    double least, sale;
    scanf("%s", name);
    cin >> least >> sale;
    printf("TOTAL = R$ %.2lf\n", least + 0.15 * sale);
    return 0;
}
