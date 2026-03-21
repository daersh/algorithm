#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;



int main(){

  int a[10],b[10],c[10];
  int i,j=0,temp=0;
  for(i=0;i<10;i++)
  {
    cin >>a[i]>>b[i];
    c[i]=b[i]-a[i];

  }

for(i=1;i<10;i++)
{
  c[i]=c[i]+c[j];
  j++;
}
  for(i=0;i<10;i++)
  {
    if(c[i]>temp)
    temp=c[i];
  }
  cout << temp;
  return 0;
}