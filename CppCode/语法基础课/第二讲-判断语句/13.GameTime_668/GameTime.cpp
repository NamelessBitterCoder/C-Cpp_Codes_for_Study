#include<iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t1 = a * 60 + b;
    int t2 = c * 60 + d;
    int t = t2 - t1;
    if(t <= 0) t += 24 * 60;
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", t / 60, t % 60);
    return 0;
}
