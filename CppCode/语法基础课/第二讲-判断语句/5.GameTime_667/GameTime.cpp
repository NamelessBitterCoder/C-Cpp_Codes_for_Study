#include<iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if(a == b) printf("O JOGO DUROU %d HORA(S)\n", 24);
    else if(a > b) printf("O JOGO DUROU %d HORA(S)\n", b + 24 - a);
    else printf("O JOGO DUROU %d HORA(S)\n", b - a);
    return 0;
}
