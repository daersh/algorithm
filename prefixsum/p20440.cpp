#include<iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int N;
    cin >>N;
    pair<int,int> arr[N+1];
    int x,y;

    for(int i=0;i<=N;i++){
        cin >> x >>y;
        arr[i]=make_pair(x,y);
    }

    


}