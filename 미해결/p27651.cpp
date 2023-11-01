// https://www.acmicpc.net/problem/27651
//이분탐색
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> vec(n+1);
    vector<long long> vec2(n+1);
    vec[0]=0;
    vec2[0]=0;
    for(int i=1;i<=n;i++){
        cin >> vec[i];
        vec[i]+=vec[i-1];
    }
    int i=1;
    int cnt=0;

    long long x,y;
    while(i<n){
        x= vec[i];
        
        i++;
    }
    
    cout << cnt;
}

