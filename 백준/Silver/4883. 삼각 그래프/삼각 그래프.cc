#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt=1;
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        int a[n][3]; 
        for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[0][2] += a[0][1];
        a[1][0] += a[0][1];
        a[1][1] += min(a[1][0],min(a[0][1], a[0][2]));
        a[1][2] += min(a[1][1],min(a[0][1], a[0][2]));
        for(int i = 2; i < n; i++){
            a[i][0] += min(a[i-1][0], a[i-1][1]);
            a[i][1] += min(min(a[i-1][0], a[i-1][1]), min(a[i-1][2], a[i][0]));
            a[i][2] += min(min(a[i-1][1], a[i-1][2]), a[i][1]);
        }
        cout << cnt++ << ". " << a[n-1][1] << "\n";
    }
}