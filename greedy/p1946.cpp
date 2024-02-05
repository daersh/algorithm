#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >> T;

    for(int t=0; t< T ;t++)
    {
        int n;
        cin >> n;
        int arr[n+1];
        for(int i=1; i<=n; i++){
            int x ,y;
            cin >>x>>y;
            arr[x]=y;
        }
        int cnt=1;
        int min=arr[1];
        for(int i=2; i<=n;i++){
            int cmp=arr[i];
            // cout << cmp << " vs " << min <<'\n';
            if(cmp < min){
                cnt++;
                min=cmp;
            }
        }
        cout << cnt<<'\n';
    }
}

/*  
    1 4
    2 3
    3 2
    4 1
    5 5
*/