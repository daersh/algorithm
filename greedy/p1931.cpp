#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool compare(pair<int,int> v1 , pair<int,int> v2){
    if(v1.second==v2.second){
        if(v1.first<v2.first) return true;
    }
    return v1.second<v2.second;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,cnt=0,loc=0;
    cin >> n;
    vector<pair<int,int> > vec;
    for(int i=0; i< n;i++){
        int x,y;
        cin >> x >>y;
        vec.push_back(make_pair(x,y));
    }
    sort(vec.begin(),vec.end(),compare);
    for(int i=0; i< n;i++){
        if(vec[i].first>=loc){
            cnt++;
            loc= vec[i].second;
        }
    }
    cout << cnt;
}