#include<bits/stdc++.h>
using namespace std;

int A[5][40];//A[i][j]表示i位数字的和为j的数字个数
void num(int x)
{
  int sum=0;
  int t=0;
  while(x)
  {
    sum+=x%10;
    x/=10;
    t++;
  }
  A[t][sum]+=1;
}
int main()
{
  int ans=0;
  for(int i=0;i<10000;i++)
  {
    num(i);
  }
  for(int i=1;i<5;i++)//左右两侧的数字最多为4位；
  {
    for(int j=1;j<i*9;j++)//j的范围为1-9*i;
    {
      for(int k=1;k<i+1;k++)//当k比i小时，右边的数可以用0补充；
      {
        ans+=A[i][j]*A[k][j];
      }
    } 
  }
  cout<<ans<<endl;
  return 0;
}
