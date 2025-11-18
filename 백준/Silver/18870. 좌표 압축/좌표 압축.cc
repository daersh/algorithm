#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    priority_queue<int,vector<int>, greater<int> > pq;
    int arr[n+1];
    for(int i=0; i< n ;i++){
        cin >> arr[i];
        pq.push(arr[i]);
    }
    map<int,int> etc; 
    int cnt=0;
    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        if(etc.find(v)==etc.end())
            etc.insert({v,cnt++});
    }
    for(int i=0; i< n ;i++){
        cout << etc[arr[i]]<< ' ';
    }
}