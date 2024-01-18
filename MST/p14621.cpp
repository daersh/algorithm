#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
int gender[1001];
int n, m;

struct Edge{
    int node[2];
    int dist;
    Edge(int x, int y, int dist){
        this->node[0]=x;
        this->node[1]=y;
        this->dist=dist;
    }
};

bool compare(Edge &a, Edge &b){
    return a.dist< b.dist;
}

int get_parent(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x]= get_parent(parent,parent[x]);
}

void union_parent(int parent[],int x, int y){
    x= get_parent(parent,x);
    y= get_parent(parent,y);
    
    if(x<y) parent[y]=x;
    else parent[x]=y;
}

bool find_parent(int parent[],int x,int y){
    x= get_parent(parent,x);
    y= get_parent(parent,y);
    if(x==y) return true;
    return false;
}

int main(){
    cin >> n >> m;
    int parent[n+1];

    for(int i=0; i<=n;i++){
        parent[i]=i;
    }

    vector<Edge> vec;

    for(int i=1; i<=n; i++){
        // M:1, W:0
        char x ;
        cin >> x;
        if(x=='M') gender[i]=1;
        else gender[i]=0;
    }

    for(int i=0; i<m;i++){
        int x ,y,z;
        cin >> x>>y>>z;
        if(gender[x]==gender[y]) continue;
        vec.push_back(Edge(x,y,z));
    }
    
    sort(vec.begin(),vec.end(),compare);
    long long sum=0;
    int cnt=0;
    for(int i=0;i<vec.size();i++){
        int x= vec[i].node[0];  
        int y= vec[i].node[1];
        
        if(!find_parent(parent,x,y)){
            cnt++;
            sum+= vec[i].dist;
            union_parent(parent,x,y);
        }
    }
    if(cnt!=n-1) {
        cout << -1;
    }
    cout << sum;
}

