#include<iostream>

using namespace std;

int main()
{
    double x;
    cin >> x;
    if(x >= 0 && x <= 400)
    {
        printf("Novo salario: %.2lf\n", x + x * 0.15);
        printf("Reajuste ganho: %.2lf\n", x * 0.15);
        printf("Em percentual: 15 %\n");
    }
    else if(x > 400 && x <= 800)
    {
        printf("Novo salario: %.2lf\n", x + x * 0.12);
        printf("Reajuste ganho: %.2lf\n", x * 0.12);
        printf("Em percentual: 12 %\n");
    }
    else if(x > 800 && x <= 1200)
    {
        printf("Novo salario: %.2lf\n", x + x * 0.1);
        printf("Reajuste ganho: %.2lf\n", x * 0.1);
        printf("Em percentual: 10 %\n");
    }
    else if(x > 1200 && x <= 2000)
    {
        printf("Novo salario: %.2lf\n", x + x * 0.07);
        printf("Reajuste ganho: %.2lf\n", x * 0.07);
        printf("Em percentual: 7 %\n");
    }
    else
    {
        printf("Novo salario: %.2lf\n", x + x * 0.04);
        printf("Reajuste ganho: %.2lf\n", x * 0.04);
        printf("Em percentual: 4 %\n");
    }
    return 0;
}
