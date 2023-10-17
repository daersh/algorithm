#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    int arr2[m];
    deque<int> q;
    
    for(int i=1;i<=n;i++){
        q.push_back(i);
    }

    for(int i=0;i<m;i++){
        cin >> arr2[i];
    }
    int cnt=0;
    
    for(int i=0;i<m;i++){
        int x= arr2[i];
        int cmp1=0,cmp2=0;

        int idx = find(q.begin(),q.end(),x) - q.begin();
        int qsize = q.size();

        if(idx < qsize-idx){
            for(int j=0;j<idx ; j++){
                rotate(q.begin(),q.begin()+1,q.end());
            }
            cnt+=idx;
        }else{
            for(int j=0;j<qsize-idx;j++){
                rotate(q.rbegin(),q.rbegin()+1,q.rend());
            }
            cnt+=qsize-idx;
        }

        q.pop_front();
    }

    cout << cnt;

}