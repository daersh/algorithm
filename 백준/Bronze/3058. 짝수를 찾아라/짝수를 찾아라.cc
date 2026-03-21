#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	
	int t,i;
  cin >>t;
  int a[7];
  int sum=0,min=101;
  for(int j=0;j<t;j++){
  for(i=0;i<7;i++){
    cin>>a[i];
  }
    sum=0;
    min=101;
  for(i=0;i<7;i++){
    if(a[i]%2==0){
      sum+=a[i];
      if(a[i]<min) min=a[i];
      }
    }
  cout << sum <<" "<< min<< '\n';
  }
	return 0;
}
