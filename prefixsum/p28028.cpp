#include <bits/stdc++.h>

using namespace std;
int N,M,L;

int arr[1000010];
queue<pair<int,int> > q;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> N;
    int x,y;
    
    for(int i=1;i<=N;i++){
        cin >> x >>y;

        for(int j=x;j<=y;j++){
            arr[j]++;
        }
    }

    cin >> x;

    for(int i=1;i<=x;i++){
        cin >> y;
        cout << arr[y] << '\n';
    }

    return 0;
}