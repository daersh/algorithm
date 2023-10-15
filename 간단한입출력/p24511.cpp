#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    int arr[N];

    //1: stack  filo
    //0: queue  fifo
    for(int i=0;i<N;i++){
        cin >> arr[i] ;
    }
    int arr2[N];
    deque<int> deq;

    for(int i=0;i<N;i++){
        
        cin >> arr2[i];
        if(arr[i]==0) {
            deq.push_back(arr2[i]);
        }
    }

    int c,a;
    cin >> c;
    vector<int> vec;

    for(int i=0;i<c;i++){
        cin >> a;
        deq.push_front(a);
        vec.push_back(deq.back());
        deq.pop_back();
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i]<< ' ' ;
    }
}