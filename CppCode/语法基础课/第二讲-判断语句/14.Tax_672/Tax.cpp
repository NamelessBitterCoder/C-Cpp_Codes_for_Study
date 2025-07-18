#include<iostream>

using namespace std;

int main()
{
    double num;
    cin >> num;
    if(num >= 0 && num <= 2000) cout << "Isento" << endl;
    if(num > 2000 && num <= 3000) printf("R$ %.2lf\n", (num - 2000) * 0.08);
    if(num > 3000 && num <= 4500) printf("R$ %.2lf\n", (num - 3000) * 0.18 + 1000 * 0.08);
    if(num > 4500) printf("R$ %.2lf\n", (num - 4500) * 0.28 + 1000 * 0.08 + 1500 * 0.18);
    return 0;
}
