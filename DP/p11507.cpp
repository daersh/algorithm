#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i< n ;i++){
        cin >> arr[i];
    }

    // priority_queue<int,vector<int>,greater<int> > q;
    map<int,int> loc;
    int cnt=1;
    // q.push(arr[0]);
    loc[arr[0]-1]=1;
    for(int i=1; i< n; i++){
        if(loc[arr[i]]!=0){
            loc[arr[i]]--;
        }else {
            cnt++;
        }
        loc[arr[i]-1]++;
        
    }
    cout << cnt;
}

