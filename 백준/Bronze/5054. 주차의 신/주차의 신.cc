#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
  int t,n,i,j;
  int xi[100];
  int sum[t];
  cin >>t;

  for(i=0;i<t;i++)
{
  cin >>n;
  for(j=0;j<n;j++)
  {
    cin >>xi[j];
  }
  sort(xi,xi+n);
  sum[i]= (xi[n-1]-xi[0])*2;
}

for(i=0;i<t;i++)
cout << sum[i]<<' ';

  return 0;
}