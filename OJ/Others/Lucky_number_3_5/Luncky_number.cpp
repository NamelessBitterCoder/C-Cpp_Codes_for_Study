#include<bits/stdc++.h>
using namespace std;

bool check(int x)
{
  string s;
  while(x)
  {
    s+=(char)(x%10+'0');//从个位开始提取数字；
    x/=10;
  }
  int n=s.size();
  if(n%2==1)//约束条件1：判断数字位数是否为偶数；
  {
    return false;
  }
  int sum1=0,sum2=0;//约束条件2：判断左右两部分数字之和是否相等；
  for(int i=0;i<n/2;i++)
  {
    sum1+=s[i]-'0';
    sum2+=s[n/2+i]-'0';
  }
  return sum1==sum2;

}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  // 请在此输入您的代码
  int ans=0;
  for(int i=1;i<=100000000;i++)
  {
    if(check(i))
    {
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
