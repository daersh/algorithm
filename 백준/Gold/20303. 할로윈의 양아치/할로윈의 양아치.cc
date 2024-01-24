#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

// 아이 수, 아이친구관계, 인원제한
int n , m , k;
typedef pair<int, long long> pii;
int child[30001];
vector<pair<int,long long> > pque;
long long result=0;
int dp[3011];
int get_parent(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x]= get_parent(parent,parent[x]);
}

void union_parent(int parent[],int x,int y){
    x= get_parent(parent,x);
    y= get_parent(parent,y);
    
    if(x<y) {
        parent[y]=x;
    }
    else {
        parent[x]=y;
    }
}
bool find_parent(int parent[],int x,int y){
    x= get_parent(parent,x);
    y= get_parent(parent,y);
    if(x==y) return true;
    return false;
}

// void dp(int loc, int cnt, long long sum){
    
//     if(cnt+pque[loc].first<k && pque[loc].second+sum> result) 
//         result=pque[loc].second+sum;
    
//     if(loc+1 < pque.size()){
//         dp(loc+1,cnt, sum);
        
//         dp(loc+1, cnt+pque[loc].first, sum + pque[loc].second );
//     }
// }

bool compare(pii a, pii b){
    return a.first<b.first;
}


int main(){
    cin >> n>>m>>k;
    
    int parent[n+1];
    int person[n+1];
    for(int i=0; i<=n;i++) {
        parent[i]=i;
        person[i]=1;
    }
    
    //각 아이가 가지고 있는 사탕 수
    for(int i=1;i<=n;i++) cin >>child[i];
    
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >>y;
        union_parent(parent,x,y);
    }
    
    for(int i=1; i<=n;i++){
        if(parent[i]!=i){
            int p = get_parent(parent,i);
            child[p]+= child[i];
            person[p] += person[i];
        }
    }
    for(int i=1; i<=n;i++){
        if(parent[i]!=i) continue;
        for(int j= k-1; j-person[i]>=0;j--){
            dp[j]= max(dp[j],dp[j-person[i]]+child[i]);
        }
    }

    // for(int i=0; i<pque.size();i++){
    //     cout << pque[i].second<<'\n';
    // }
    cout << dp[k-1];
}