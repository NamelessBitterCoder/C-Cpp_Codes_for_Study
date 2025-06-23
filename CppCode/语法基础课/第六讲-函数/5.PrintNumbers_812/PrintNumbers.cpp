#include<iostream>

using namespace std;

const int N = 1010;
int a[N];
void print(int a[], int size)
{
    for(int i = 1; i <= size; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int n, size;
    cin >> n >> size;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    print(a, size);
    return 0;
}
