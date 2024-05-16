#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 자신의 부모 노드 확인
int get_parent(int parent[],int x){
    // 자기 자신이면 return
    if(parent[x]==x) return x;
    
    return parent[x]= get_parent(parent,parent[x]);
}
// 두 노드의 부모를 합침
void union_parent(int parent[],int a,int b){
    a= get_parent(parent,a);
    b= get_parent(parent,b);
    // 위치가 더 작은 노드로 부모 설정
    if(a<b) parent[b]=a;
    else parent[a]=b;  
}
// 같은 부모인지 확인
int find_parent(int parent[],int a,int b){
    a= get_parent(parent,a);
    b= get_parent(parent,b);
    //서로 같은 부모면 true
    if(a==b) return true;
    return false;
}
struct Edge{
    int node[2];
    int distance;
    Edge(int a, int b, int dist){
        this->node[0]= a;
        this->node[1]=b;
        this->distance=dist;
    }
};

bool compare(Edge &edge1, Edge &edge2){
    return edge1.distance< edge2.distance;
}

int main(){
    int n,m;
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    vector<Edge> vec;

    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x>> y>> z;
        vec.push_back(Edge(x,y,z));
    }
    // 부모 초기화
    int parent[n+1];
    for(int i=0; i<=n;i++){
        parent[i]=i;
    }

    // dist 오름차순으로 정렬
    sort(vec.begin(),vec.end(),compare);

    int sum = 0;
    int maxCost=0;

    for(int i=0; i<m;i++){   
        //사이클 없는 경우 그래프에 포함
        if(!find_parent(parent,vec[i].node[0]-1 , vec[i].node[1]-1)){
            if(maxCost<vec[i].distance) 
                maxCost=vec[i].distance;
            sum += vec[i].distance;
            union_parent(parent,vec[i].node[0]-1 , vec[i].node[1]-1);
        }
    }
    
    cout << sum << ' ' << maxCost << endl;

    cout << sum-maxCost;

}