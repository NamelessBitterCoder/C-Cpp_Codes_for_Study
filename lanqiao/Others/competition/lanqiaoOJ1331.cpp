#include<bits/stdc++.h>
using namespace std;

int main()
{
  int x;
  cin>>x;
  int ans=0;
  for(int i=0;i<32;++i)
  {
      if(x&1)
      {
        ans++;
      }
      x>>=1;
  }
  cout<<ans<<endl;
  return 0;
}
