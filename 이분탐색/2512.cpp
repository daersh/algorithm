#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;
    long long sum = 0;
    long long maxVal = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
        if(x > maxVal) maxVal = x;
    }

    int m;
    cin >> m;

    if(m>=sum){
        cout << maxVal << '\n';
        return 0;
    }
    
    int l = 0;
    int r = maxVal; 

    while(l+1<r){
        int mid = (l+r)/2;
        sum = 0;

        for(int i = 0; i < n; i++){
            sum+= (v[i] < mid) ? v[i] : mid;
        }
        if(sum > m)
            r = mid;
        else 
            l = mid;

    }
    
    sum = 0;

    for(int i = 0; i < n; i++){
        sum+= (v[i] < r) ? v[i] : r;
    }
    if(sum <= m)
        r = m;
    else 
        r = l;
    
    cout << r << '\n';

    return 0;
}