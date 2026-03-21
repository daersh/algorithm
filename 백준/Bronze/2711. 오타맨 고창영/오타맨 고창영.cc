#include <iostream>
#include <string.h>
using namespace std;

int main() {

  int i,t,b;

  cin >> t;

  for(i=0;i<t;i++)
  {
    char a[81]=" ";
    cin >> b >> a;
    int length= strlen(a);
    for(int j=b-1;j<=length;j++)
    {
      a[j]=a[j+1];
    }
    cout << a <<'\n';
  }



 return 0;
}