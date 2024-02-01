#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


bool compare(pair<int,int> v1 , pair<int,int> v2){
    if(v1.second<v2.second) return true;
    if(v1.second==v2.second){
        if(v1.first<v2.first) return true;
    }

    return false;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int> > vec;

    for(int i=0; i< n;i++){
        int x,y;
        cin >> x >>y;
        vec.push_back(make_pair(x,y));
    }
    sort(vec.begin(),vec.end(),compare);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << vec[i].first<<' '<<vec[i].second<<'\n';
    // }
    
    int cnt=1;
    int loc = vec[0].second;
    for(int i=1; i< n;i++){
        if(vec[i].first>=loc){
            cnt++;
            loc= vec[i].second;
        }
    }
    cout << cnt;
}