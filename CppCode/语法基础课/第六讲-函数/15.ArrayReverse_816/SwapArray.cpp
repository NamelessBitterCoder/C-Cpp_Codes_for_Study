#include<iostream>

using namespace std;

void reverse(int a[], int size)
{
    for(int i = 1, j = size; i < j; i++, j--)
        swap(a[i], a[j]);
        
}
int main()
{
    int a[1010] = {0};
    int n, size;
    cin >> n >> size;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    reverse(a, size);
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}
