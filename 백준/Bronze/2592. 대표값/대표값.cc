#include <iostream>

using namespace std;

int main() {

  int a[10],b[1001]={},i;
  int avg,x=0,y=0,temp=0,z;

  for(i=0;i<10;i++)
  cin >> a[i];
  
  for(i=0;i<10;i++)
  {
    x+=a[i];
  }
  avg=x/10;

  for(i=0;i<10;i++)
  {
    y=a[i];
    b[y]=b[y]+1;
  }

  for(i=0;i<1001;i++)
  {
    if(b[i]>temp)
    {
    temp=b[i];
    }
  }

  cout << avg << '\n';
  for(i=0;i<1001;i++)
  {
    if(b[i]==temp)
    cout << i <<'\n';
  }


 return 0;
}

