#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
  int i, n,sum=0;
  int x[8]={0};
  int y[8]={0};
  for(i=0;i<8;i++)
  {
    cin >>n;
    x[i]=n;
    y[i]=n;
  }
  sort(x,x+8);
  for(i=7;i>2;i--)
  {
    sum+=x[i];
  }
  cout <<sum<<'\n';
  
  for(i=0;i<8;i++)
  {
    
    for(int j=7;j>2;j--)
    {
      if(x[j]==y[i])
      {
        cout << i+1<<' ';
        break;
      }
    }
  }
  return 0;
}