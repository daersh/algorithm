#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<int,int> pii;
// 아이 수, 아이친구관계, 인원제한
    int n , m , k;

int sum[30001];
int child[30001];
vector<pii> pque;
long long result=0;
struct Edge{
    int node[2];
    int sum;
    Edge(int x, int y, int sum){
        node[0]= x;
        node[1]= y;
        this ->sum= sum;
    }
};

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

void dp(int loc, int cnt, long long sum){
    //최대인원이상일 시 리턴
    if(loc == pque.size()|| cnt==k ) return;
    
    if(cnt+pque[loc].first<k && pque[loc].second+sum> result) result=pque[loc].second+sum;

    if(loc+1 != pque.size()){
        dp(loc+1,cnt,sum);
        dp(loc+1, cnt+pque[loc].first, sum+pque[loc].second);
    }

}

bool compare(pii a, pii b){
    return a.first<b.first;
}


int main(){
    
    cin >> n>>m>>k;
    vector<Edge> vec;
    int parent[n+1];
    for(int i=0; i<=n;i++){
        parent[i]=i;
    }
    
    //각 아이가 가지고 있는 사탕 수
    for(int i=1;i<=n;i++){
        cin >>child[i];
    }
    
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >>y;
        vec.push_back(Edge(x,y,0));
    }
    
    for(int i=0; i<vec.size();i++){
        if(!find_parent(parent,vec[i].node[0],vec[i].node[1])){
            union_parent(parent,vec[i].node[0],vec[i].node[1]);
        }
    }
    
    for(int i=1; i<=n;i++){
        if(child[i]!=0){
            int cnt=1;
            int sum=child[i];

            for(int j= i+1; j<=n;j++){
                if(parent[i]==parent[j]){
                    cnt++;
                    sum+=child[j];
                    child[j]=0;
                }
            }
            pque.push_back(make_pair(cnt,sum));
        }
    }

    if(pque.size()==0) {
        cout << 0; return 0;
    }

    //sort(pque.begin(),pque.end(),compare);
    // for(int i=0; i<pque.size();i++){
    //     cout << pque[i].second<<'\n';
    // }
    dp(0,0,0);
    cout << result;
}