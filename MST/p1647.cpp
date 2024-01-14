#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

class Edge{
public:
    int node[2];
    int distance;
    Edge(int a,int b, int distance){
        this->node[0]= a;
        this->node[1]= b;
        this->distance = distance;
    }
};

bool compare(const Edge &edge1, const Edge &edge2){
        return edge1.distance < edge2.distance;
    }
//부모찾기
int getP(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x] = getP(parent,parent[x]);
}

//두 부모 노드 합치기
void unionP(int parent[],int a, int b){
    a= getP(parent,a);
    b= getP(parent,b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int findP(int parent[], int a, int b){
    a= getP(parent,a);
    b= getP(parent,b);
    if(a==b) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<Edge> vec;

    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x>> y>> z;
        vec.push_back(Edge(x,y,z));
    }
 
    int parent[n+1];
    for(int i=0; i<=n;i++){
        parent[i]=i;
    }
   sort(vec.begin(),vec.end(),compare);
    int sum = 0;
    int maxCost=0;

    for(int i=0; i<m;i++){
        //사이클 없는 경우 그래프에 포함
        if(!findP(parent,vec[i].node[0]-1 , vec[i].node[1]-1)){
            if(maxCost<vec[i].distance) maxCost=vec[i].distance;
            sum += vec[i].distance;
            unionP(parent,vec[i].node[0]-1 , vec[i].node[1]-1);
        }
    }
    cout << sum-maxCost;
}


