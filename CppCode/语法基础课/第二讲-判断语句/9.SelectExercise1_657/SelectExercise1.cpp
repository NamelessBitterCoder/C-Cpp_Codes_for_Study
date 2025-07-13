#include<iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b > c)
    {
        if(d > a)
        {
            if(c + d > b + a)
            {
                if(c > 0 && d >0)
                {
                    if(a % 2 == 0)
                    {
                        printf("Valores aceitos\n");
                    }
                    else
                    {
                        printf("Valores nao aceitos\n");
                    }
                }
                else
                {
                    printf("Valores nao aceitos\n");
                }
            }
            else
            {
                printf("Valores nao aceitos\n");
            }
        }
        else
        {
            printf("Valores nao aceitos\n");
        }
    }
    else
    {
        printf("Valores nao aceitos\n");
    }
    return 0;
}
