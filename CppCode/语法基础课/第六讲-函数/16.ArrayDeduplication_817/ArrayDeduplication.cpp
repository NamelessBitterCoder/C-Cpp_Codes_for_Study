#include<iostream>

using namespace std;

int get_unique_count(int a[], int n)
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        bool is_exist = false;
        for(int j = 1; j < i; j++)
        {
            if(a[j] == a[i])
            {
                is_exist = true;
                break;
            }
        }
        
        if(!is_exist)  //如果a[i]是第一次出现；
            cnt++;
    }
    return cnt;
}
int main()
{
    int a[1010];
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << get_unique_count(a, n) << endl;
    return 0;
}
