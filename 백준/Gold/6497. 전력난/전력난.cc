#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct Edge{
    int node[2];
    int dist;
    Edge(int x,int y,int dist){
        node[0]=x;
        node[1]=y;
        this->dist=dist;
    }
};

int get_parent(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x]= get_parent(parent,parent[x]);
}

void union_parent(int parent[],int x,int y){
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
bool compare(Edge &a, Edge &b){
    return a.dist< b.dist;
}

int main(){
    
    int n, m;
    while(1){
    vector<Edge> vec;
    cin >> n >> m;
    if(n==0 && m==0) break;
    long long dist=0;
    for(int i=0; i< m;i++){
        int x,y,z;
        cin >> x>> y>>z;
        vec.push_back(Edge(x,y,z));
        vec.push_back(Edge(y,x,z));
        dist+=z;
    }
    
    int parent[n];
    for(int i=0; i< n;i++){
        parent[i]=i;
    }
    sort(vec.begin(),vec.end(),compare);
    long long sum=0;
    for(int i=0; i< vec.size();i++){
        if(!find_parent(parent,vec[i].node[0],vec[i].node[1])){
            sum+=vec[i].dist;
            union_parent(parent,vec[i].node[0],vec[i].node[1]);
        }
    }
    // cout<<dist<<'\n';
    // cout << sum;
    cout <<dist-sum<<'\n';
    
    }
}