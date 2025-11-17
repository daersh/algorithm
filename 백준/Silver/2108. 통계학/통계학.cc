#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

struct cmp{
    bool operator()(pii a, pii b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    int sum=0;
    
    int maxVal = -1e9;
    int minVal = 1e9;
    pii asdfasdf;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
        sum+=x;
        // 최빈값
        maxVal = max(maxVal, x);
        minVal = min(minVal, x);
    }
    // 1. 산술평균
    int one = round((double)sum/n);
    cout << one <<'\n';
    // 2. 중앙값
    sort(vec.begin(), vec.end());
    cout << vec[n/2] << '\n';
    // 3. 최빈값
    // 여러개 있음 두번째꺼 
    int arr[8002] = {0};

    for(int i=0;i<n;i++){
        if(vec[i]<0)
            arr[abs(vec[i])+4000]++;
        else
            arr[vec[i]]++;
    }

    priority_queue<pii, vector<pii>, cmp> pq;
    for(int i=0; i<n;i++){
        if (vec[i]<0)
        {
            pq.push({arr[abs(vec[i])+4000],vec[i]});
            continue;
        }
        pq.push({arr[vec[i]],vec[i]});
    }
    pii asdf = pq.top();
    pq.pop();
    int past = asdf.second;
    int pastCount =asdf.first;
    // cout << "past: " << past << " pastCount: " << pastCount << '\n';
    if(pq.empty()){
        cout << past << '\n';
    }else {
        while(true){
            pii asdf2 = pq.top();
            int next = asdf2.second;
            int nextCount = asdf2.first;
            pq.pop();
            // cout << "next: " << next << " nextCount: " << nextCount << '\n';
            if(next == past)
                continue;
            if(nextCount == pastCount){
                cout << next << '\n';
                break;
            }else{
                cout << past << '\n';
                break;
            }
        }
    }
    // 4. 범위
    cout << maxVal - minVal;
}