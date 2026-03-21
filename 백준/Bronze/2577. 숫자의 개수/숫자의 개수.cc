#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;



int main(){

  int a,b,c,d;
  int x[10]={0};

  cin >>a;
  cin >>b;
  cin >>c;

  d=a*b*c;

  while(d>0)
  {
    a=d%10;
    x[a]=x[a]+1;
    d=d/10;
  }

  for(int i=0;i<10;i++)
  cout << x[i]<<'\n';

  return 0;
}
