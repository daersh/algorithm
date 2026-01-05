#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> vec(200,vector<int>(200,0));
    vector<vector<ll>> result(200,vector<ll>(200,0));
    for(int i=0; i< n ; i++)for(int j=0; j< n ; j++)    cin >> vec[i][j];
    result[0][0]=1;
    for(int i=0; i< n ; i++)for(int j=0; j< n ; j++){
        if(result[i][j]==0 || vec[i][j]==0) continue;
        
        int next= vec[i][j];
        ll v= result[i][j];
        result[i+next][j]+=v;
        result[i][j+next]+=v;
    }
    // for(int i=0; i< n ; i++){
    //     for(int j=0; j< n ; j++)
    //     cout << result[i][j]<<' '; cout <<'\n';
    // }
    cout << result[n-1][n-1]; 

}