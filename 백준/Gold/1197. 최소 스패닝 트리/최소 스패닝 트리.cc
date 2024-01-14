#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int node[2];
    int dist;
    Edge(int a, int b, int d){
        node[0]= a;
        node[1]= b;
        dist=d;
    }
};
bool compare(Edge &edge1, Edge &edge2){
    return edge1.dist<edge2.dist;
}
int get_parent(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x]= get_parent(parent,parent[x]);
}
void union_parent(int parent[],int a,int b){
    a= get_parent(parent,a);
    b= get_parent(parent,b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}
bool find_parent(int parent[],int a, int b){
    if(get_parent(parent,a)== get_parent(parent,b))
        return true;
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<Edge> vec;
    for(int i=0; i<m;i++){
        int x,y,z;
        cin >> x>>y>>z;
        vec.push_back(Edge(x,y,z));
    }
    sort(vec.begin(),vec.end(),compare);
    int parent[n+1];
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int sum=0;
    for(int i=0; i< vec.size();i++){
        if(!find_parent(parent,vec[i].node[0], vec[i].node[1])){
            sum+= vec[i].dist;
            union_parent(parent,vec[i].node[0] , vec[i].node[1]);
        }
    }
    cout << sum;

}