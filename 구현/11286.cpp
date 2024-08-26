#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

struct compare{
    bool operator()(int a, int b) const {
        if(abs(a) == abs(b)) 
            return a > b;
        return abs(a) > abs(b);
    }
};

int main (){
        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, compare > pq;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num!= 0){
            // cout <<num<< " push\n";
            pq.push(num);
        }else{
            if(pq.empty()){
                cout << "0\n";
            }else{
                int x = pq.top();
                cout << x <<'\n';
                pq.pop();
            }
        }
    }

}