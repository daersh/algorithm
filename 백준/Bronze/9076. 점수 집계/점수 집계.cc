#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
   
  int t,i,a[5],n[5],sum[5];
  cin >>t;

  for(i=0;i<t;i++)
  {
    cin>> a[0] >> a[1] >> a[2] >> a[3]>>a[4];
    sort(a,a+5);
    n[i]= a[3]-a[1];
    sum[i]=  a[1] + a[2] + a[3];
  }

  for(i=0;i<t;i++)
  {
    if(n[i]<4) cout << sum[i] << '\n';
    else cout << "KIN"<< '\n';
  }
  return 0;
}

