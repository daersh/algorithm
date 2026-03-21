#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
  int x, a[1000] , i ;
  cin >>x;
  for(i=0;i<x;i++)
  {
    cin >>a[i];
  }
  sort(a,a+x);
  
  for(i=0;i<x;i++)
  {
    cout << a[i]<<' ';
  }
  return 0;
}