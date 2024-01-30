#include <iostream>
#include <cmath>
using namespace std;

int main(){
    /*
    200
    */
   long long n;
   cin >> n;
   long long sum=0;
   int cnt=0;
   for(int i=1; i<=n;i++){
        if(sum+i<=n){
            sum+=i;
            cnt++;
        }
        else break;
   }
//    cout << sum << ' '<< cnt;
    cout << cnt;
}