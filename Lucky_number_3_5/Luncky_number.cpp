#include<bits/stdc++.h>
using namespace std;

bool check(int x)
{
  string s;
  while(x)
  {
    s+=(char)(x%10+'0');//�Ӹ�λ��ʼ��ȡ���֣�
    x/=10;
  }
  int n=s.size();
  if(n%2==1)//Լ������1���ж�����λ���Ƿ�Ϊż����
  {
    return false;
  }
  int sum1=0,sum2=0;//Լ������2���ж���������������֮���Ƿ���ȣ�
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
  // ���ڴ��������Ĵ���
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
