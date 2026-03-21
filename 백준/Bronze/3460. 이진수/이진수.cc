#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
#include <bitset>
//문자열 입력 받기 stinrg a;  getline(cin,a);
using namespace std;

int main() {

  int t, n;
  cin >> t;
  string b;
  for(int i;i<t;i++){
    cin >> n;
    b= bitset<32>(n).to_string();
    for(int j=31;j>=0;j--){
      if(b[j]=='1') 
        cout << 31-j <<' ';
    }
    cout << '\n';
  }
  
	return 0;
}
