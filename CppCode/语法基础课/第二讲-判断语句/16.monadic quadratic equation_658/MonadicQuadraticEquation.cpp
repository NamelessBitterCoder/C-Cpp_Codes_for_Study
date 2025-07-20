#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if(b * b - 4 * a * c < 0 || a == 0) printf("Impossivel calcular\n");
    else
    {
        printf("R1 = %.5lf\n",((-1 * b) + (sqrt(b * b - 4 * a * c))) / (2 * a));
        printf("R2 = %.5lf\n",((-1 * b) - (sqrt(b * b - 4 * a * c))) / (2 * a));
    }
    return 0;
}
