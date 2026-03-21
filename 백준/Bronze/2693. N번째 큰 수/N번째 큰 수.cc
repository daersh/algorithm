#include <iostream>
#include<algorithm>
using namespace std;

#define n 3

int main()
{
    int t, a[1000][10],b[10],i;

    cin >> t;

    for(i=0;i<t;i++)
    {
      for(int j=0;j<10;j++)
      {
        cin >> b[j];
      }
      sort(b,b+10);
      for(int k=0;k<10;k++)
      {
        a[i][k]=b[k];
      }      
    }
    for(i=0;i<t;i++)
    cout << a[i][7]<<'\n';


  return 0;
}