#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
  int T;
  cin >>T;
  for(int t=0;t<T;t++){
    long long x1,y1,r1,x2,y2,r2;
    cin >> x1 >>y1>>r1>>x2>>y2>>r2;
    long long xx= x1-x2;
    long long yy=y1-y2;
    long long d= xx*xx+yy*yy;
    
    long long cmp1= (r2+r1)*(r2+r1);
    long long cmp2=(r2-r1)*(r2-r1);
    if(x1==x2&&y1==y2){
      if(r1==r2){
        cout << "-1\n";
      }else{
        cout << "0\n";
      }
    }else if(d==cmp1 || d==cmp2 && d!=0){
      cout <<"1\n";
    }else if(d>cmp2 && d<cmp1){
      cout << "2\n";
    }else{
      cout << "0\n";
    }
    
  }
}