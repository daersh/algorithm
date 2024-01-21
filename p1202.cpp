#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> pii;

int n , k;
vector<pii> vec;
int maximum=0;


bool compare(pair<int,int> a, pair<int,int>  b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return (a.second < b.second);
}

int main(){
    cin >> n >> k;
    
    
    vector<pair<int,int> > vec;
    vector<int> insert;
    for(int i=0; i< n; i++){
        int a,b;
        // 무게 / 가격
        cin >> a>>b;
        vec.push_back(make_pair(a,b));        
    }
    
    sort(vec.begin(),vec.end());

    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        insert.push_back(x);
    }
    sort(insert.begin(),insert.end());
    // for(int i=0; i< vec.size();i++){
    //     cout << vec[i].first << ' '<< vec[i].second <<'\n';
    // }cout <<'\n';
    int loc=0;
    long long sum=0;
    priority_queue<int,vector<int> > pque2;
    for(int i=0; i< k;i++){
        while (loc<n && insert[i]>= vec[loc].first)
        {
            pque2.push(vec[loc].second);
            loc++;
        }
        if(!pque2.empty()){
            sum += pque2.top();
            pque2.pop();
        }

    }
    
    cout << sum;
}