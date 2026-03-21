#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int a[4]={ }, sum[5]={ };
  int i;
  for(i=0;i<5;i++)
  {
    cin >> a[0] >>a[1] >>a[2] >>a[3];
    sum[i]= a[0]+a[1]+a[2]+a[3];
  }
  int temp=0;

  for(i=0;i<5;i++)
  {
    if(sum[i]>temp)
     {
       temp=sum[i];
       
     }
  }
  for(i=0;i<5;i++){
 if(sum[i]==temp)
 {
  cout <<i+1 << ' '<<temp;
  }
  }
 return 0;
}
