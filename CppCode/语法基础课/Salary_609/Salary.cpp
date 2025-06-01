#include<iostream>
using namespace std;

int main()
{
    int number, time;
    double salary;
    cin >> number >> time >> salary;
    cout << "NUMBER = " << number << endl;
    printf("SALARY = U$ %.2lf\n", time * salary);
    return 0;
}
