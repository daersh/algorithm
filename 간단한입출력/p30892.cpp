#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, k;
long long t;
vector<long long> vec;

int lower_bound(long long t){
    int l=-1;
    int r=n;
    while (l+1<r)
    {
        int mid= (l+r)/2;
        if(vec[mid]<t){
            l=mid;
        }else{
            r=mid;
        }
    }
    
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //상어마리수, 먹을수 있는 마리수, 최초크기
    cin >> n >> k >> t;
    int used[200010]={0};
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(),vec.end());
    vector<int>vec2;
    int loc=0;
    int cnt=0;

    while (loc<n)
    {
        if(cnt==k)break;
        if(vec[loc]<t){
            vec2.push_back(vec[loc]);
            loc++;
            continue;
        }else{
            cnt++;
            if(vec2.empty()){
                cout << t;
                return 0;
            }
            t+=vec2.back();
            vec2.pop_back();
        }
    }
    for(int i=cnt; i<k;i++){
        t+=vec2.back();
        vec2.pop_back();
    }
    cout << t;
}