#include<iostream>

using namespace std;

void sort(int a[], int l, int r)
{
    for(int i = l + 1; i < r + 1; i++)
        for(int j = i + 1; j <= r + 1; j++)
            if(a[i] > a[j])
                swap(a[i], a[j]);
}
int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int a[1010] = {0};
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, l, r);
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
