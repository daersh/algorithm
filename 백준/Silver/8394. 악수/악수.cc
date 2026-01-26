#include <iostream>
#include <vector>

using namespace std;
using pll = pair<long long,long long>;

int main(){
    int n;
    cin >> n;
    vector<pll> v(n+1);
    v[1]={1,0}; 
    for(int i=2;i<=n;i++) v[i]= {(v[i-1].first+v[i-1].second)%10, (v[i-1].first)%10};
    cout << (v[n].first + v[n].second)%10;
}
