#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a[26]={0};
  string b;
  cin >> b;
  int max=0;
  int max_loc=0;
  
  for (int i=0; i< b.length(); i++){
    if((int)b[i] >96) a[(int)b[i]-97]+=1;
    else a[(int)b[i]-65]+=1;
  }
  
  for(int i=0; i<26;i++){
    if(a[i]>max){
      max=a[i];
      max_loc=i;
    }
  }
  sort(a, a+26, greater<>());
  int c=1;
  
  while(a[c] != 0){
    if(max==a[c]){
      cout << '?';
      c=-1;
      break;
    }else{
      c++;
    }
  }
  if(c!=-1){
    cout<< (char)(max_loc+65);
  }
  return 0;
}