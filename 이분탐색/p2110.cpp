#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void solve(){

}


int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];

    for(int i=0; i< n; i++ ){
        cin >> arr[i];
    }
    
    sort(&arr[0],&arr[n]);
    if(n==2){
        cout << arr[1]-arr[0]<<'\n';
        return 0;
    }
    int s, e, mid;
    s = arr[0];
    e = arr[n-1];
    int dist;
    int l = 0;
    int r = n;
    while(l+1<r){
        mid= (l+r)/2;
        if(arr[mid]-s < e-arr[mid])
            l = mid;
        else r= mid;
    }
    //cout << l << ' '<< r;
    int cmp1 = min(arr[l]-s, e-arr[l]);
    //cout << "cmp1= min("<<arr[l]-s<<' '<< e-arr[l]<<")\n";
    int cmp2 = min(arr[r]-s,e-arr[r]);
    //cout << "cmp2= min("<<arr[r]-s<<' '<< e-arr[r]<<")\n";
    if(cmp1 <= cmp2) cout << cmp2;
    else cout << cmp1;

}
//1 2 4 8 9
//1 3 7 15 24
// 
