#include<iostream>

using namespace std;

const int N = 110;
int a[N][N];

void print2D(int a[][N], int row, int col)
{
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int col, row;
    cin >> row >> col;
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++)
            cin >> a[i][j];
    print2D(a, row, col);
    return 0;
}
