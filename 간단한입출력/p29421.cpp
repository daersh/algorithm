#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n,g,r,re=0,start=g,x,s=0,cnt=0;
    cin >> n >> g >> r;
    for(int i=0;i<n-1;i++){
        cin >> x; 
        s+=x;
        if(s==g){
            s=0;
            cnt++;
        }else if(s>g){
            cnt++;
            s=x;
        }
    }
    cin >> x;
    s+=x;
    re=cnt*g + cnt*r ;    
    if(s<=g){
        cout << re+s;
    }else{
        cout << re+x+r+g;
    }
  
} 