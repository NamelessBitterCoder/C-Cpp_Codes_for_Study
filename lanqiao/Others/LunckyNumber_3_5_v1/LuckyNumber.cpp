#include<bits/stdc++.h>
using namespace std;

int A[5][40];//A[i][j]��ʾiλ���ֵĺ�Ϊj�����ָ���
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
  for(int i=1;i<5;i++)//����������������Ϊ4λ��
  {
    for(int j=1;j<i*9;j++)//j�ķ�ΧΪ1-9*i;
    {
      for(int k=1;k<i+1;k++)//��k��iСʱ���ұߵ���������0���䣻
      {
        ans+=A[i][j]*A[k][j];
      }
    } 
  }
  cout<<ans<<endl;
  return 0;
}
