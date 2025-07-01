#include<iostream>

using namespace std;

const int N = 110;
int a[N], b[N];
void copy(int a[], int b[], int size)
{
    for(int i = 1; i <= size; i++)
        b[i] = a[i];
}
int main()
{
    int m, n, size;
    cin >> n >> m >> size;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    copy(a, b, size);
    for(int i = 1; i <= m; i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}
