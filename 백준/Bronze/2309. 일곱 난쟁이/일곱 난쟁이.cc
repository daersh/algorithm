#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
#include <bitset> //2진수 변환하기 위함 b = bitset<32>(n).tostring();
//문자열 입력 받기 stinrg a;  getline(cin,a);
using namespace std;

int main() {

  int a[9],b[7];
  int sum=0;
  int max=0;
  int f1,f2;
  for(int i=0;i<9;i++){
    cin >> a[i];
    sum+=a[i];
    }
  
  for(int i=0;i<9;i++){
    for(int j=i+1;j<9;j++){
      if(sum-a[i]-a[j]==100 ){
        f1=i, f2=j;
        }
      }
  }
  int count=0;
  for(int i=0;i<9;i++){
    if(i!=f1 && i!=f2)
    {
      b[count]=a[i];
      count++;
    }
  }
  
  sort(b,b+7);
  for(int i=0;i<7;i++){
    cout << b[i]<<'\n';
  }
	return 0;
}
