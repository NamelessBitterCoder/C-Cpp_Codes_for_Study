#include<iostream>

using namespace std;

int main()
{
    int name1, number1;
    double price1;
    int name2, number2;
    double price2;
    cin >> name1 >> number1 >> price1;
    cin >> name2 >> number2 >> price2;
    printf("VALOR A PAGAR: R$ %.2lf\n", number1 * price1 + number2 * price2);
    return 0;
}
