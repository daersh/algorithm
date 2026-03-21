#include <iostream>

using namespace std;

int main() {

 int H,M;
 
 cin>>H >> M;
 
 
 if(M<45){
  if(H>0)
 cout << H-1 <<" " << 60-45+M;
 else
  cout << 23 << " "<< 60-45+M;
 }
 else cout << H << " "<< M-45;
 
 return 0;
}
