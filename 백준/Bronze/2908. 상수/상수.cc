#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;



int main(){

  string a,b;

  cin >> a >> b;
  int i=2;

 while(i>=0)
  {
      if(a[i]==b[i])
      {
        cout << a[i--];
        continue;
      }


    if(a[i]>b[i])
    {
      while(i>=0)
      cout << a[i--];
    }
    else
        {
      while(i>=0)
      cout << b[i--];
    }
  
  }
  
  
  return 0;
}
