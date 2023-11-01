#include <iostream>
using namespace std;

int main(){
    
    int x;
    cin >> x;
    int cnt=0;
    for(int i=0;i<x;i++){
        string a;
        cin >> a;
        for(int i=0;i<a.size()-1;i++){
            if(a[i]=='0' && a[i+1]=='1'){
                cnt++;
                break;
            }else if(a[i]=='O' && a[i+1]=='I'){
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}