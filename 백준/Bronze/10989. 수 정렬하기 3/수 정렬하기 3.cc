#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    // priority_queue<int,vector<int>,greater<int> > pq;
    map<int,int> insert;
    for(int i=0; i<n; i++){
        int x;
        cin >>x;
        insert[x]++;
    }

    for(int i=0;i<=10000;i++){
        if(insert[i]!=0)
            for(int j=0; j<insert[i]; j++){
                cout<<i<<'\n';
            }
    }
    
    return 0;
}