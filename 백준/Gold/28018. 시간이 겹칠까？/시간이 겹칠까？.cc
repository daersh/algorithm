#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int N,M,L;

int arr[1000010];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    int x,y;
    for(int i=1;i<=N;i++){
        cin >> x >>y;
        arr[x]++;
        arr[y+1]--;
        if(y>L){
            L=y;
        }
    }
    
    for(int i=1;i<=L+1;i++){
        arr[i]+=arr[i-1];   
    }
    
    cin >> x;
    for(int i=1;i<=x;i++){
        cin >> y;
        cout << arr[y] << '\n';
    }

    return 0;
}