#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<long long , vector<long long>, greater<long long> > pq;
    
    for(int i=0; i< n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    long long sum=0;
    while (pq.size()!=1)
    {
        long long x= pq.top();
        pq.pop();
        long long y= pq.top();
        if(x<=y){
            pq.pop();
            x+=y;
            pq.push(x);
            sum+=x;
        }
    }
    
    cout << sum;
}  

/* 우선순위 큐 쓰면 될 듯 
    10 20 30 40
    10+20 +30+30 +60+40 = 190
    10+20 30+30 + 60+40


    1 1 1 1 1 1 1 1
    0 2 3 4 5 6 7 8  35
    0 2 0 2 0 2 0 2  
          4   6   8  26
          4   0   4  24
                  8
*/