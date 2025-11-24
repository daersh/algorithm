#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

set<int> s;
int n;
int arr[20];
set<pair<int,int>> visited;

void test(int loc, int sum){
    if(loc>=n)
        return;
    int v = arr[loc];
    s.insert(v);
    test(loc+1,sum);
    // 더하기 
    if(sum!=0){
        int p_v= v+sum;
        s.insert(p_v);
        test(loc+1,p_v);
    }
    // 빼기
    int m_v_1= v-sum;
    if(m_v_1>0) {
        s.insert(m_v_1);
        test(loc+1,m_v_1);
    }
    int m_v_2= sum-v;
    if(m_v_2>0) {
        s.insert(m_v_2);
        test(loc+1,m_v_2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum=0;
    for(int i=0; i<n;i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    
    test(0,0);

    int cnt= sum-(s.size());

    // cout << "debug: "<< loop_cnt<<'\n';
    cout << cnt;
}