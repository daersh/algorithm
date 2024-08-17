#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;

    cin >> m >> n;
    vector<int> vec;
    int eVal =0;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        vec.push_back(num);
        eVal = max(eVal,num);
    }

    sort(vec.begin(), vec.end());

    int l = 1;
    int r = eVal;

    while(l+1<r){
        int mid = (l+r)/2;
        int cnt = 0;

        for(int i = 0; i <n; i++){
            cnt += vec[i]/mid;
        }
        // cout << "mid: "<<mid <<" cnt: " << cnt << endl;
        if(cnt >= m)
            l=mid;
        else 
            r=mid;
    }

    int lcnt=0;
    int rcnt=0;
    for(int i = 0; i <n;i++){
        lcnt+= vec[i]/l;
        rcnt+= vec[i]/r;
    }
    // cout << "l: "<< l << " lcnt: "<< rcnt << '\n';
    // cout << "r: " << r << " rcnt: " << rcnt <<'\n';
    if(lcnt< m && rcnt < m){
        cout << 0;
        return 0;
    }else if(lcnt<m){
        cout << r;
        return 0;
    }else if(rcnt<m){
        cout << l;
        return 0;
    }
    cout << ((l<r)? r : l);
    
}