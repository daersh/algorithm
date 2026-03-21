#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
#include <bitset> //2진수 변환하기 위함 b = bitset<32>(n).tostring();
//문자열 입력 받기 stinrg a;  getline(cin,a);
using namespace std;

int main() {

  int n, t,i,j;
  cin >> n;
  int num[n];
  for( i=0;i<n;i++){
    cin >> num[i];
  }
  sort(num,num+n);
  if(n==1) cout << num[0]*num[0];
  else cout << num[0]*num[n-1];
	return 0;
}
