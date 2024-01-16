#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

struct Edge{
    long long node[2];
    double dist;
    
    Edge(int a, int b, double dist){
        node[0]=a;
        node[1]=b;
        this->dist=dist;
        
    }
    
};

bool compare(Edge& a, Edge& b){
    return a.dist<b.dist;
}

int get_parent(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x]= get_parent(parent,parent[x]);
}

void union_parent(int parent[], int x,int y){
    x= get_parent(parent,x);
    y= get_parent(parent,y);
    if(x<y) parent[y]=x;
    else parent[x]=y;
}
bool find_parent(int parent[], int x, int y){
    x= get_parent(parent,x);
    y= get_parent(parent,y);
    if(x==y)return true;

    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    pair<int,int> arr[n+1]; // xy 위치 저장
    vector<Edge> vec;          // 노드 저장
    vector<Edge> vec2;
    int parent[n+1];
    for(int i=0; i<=n;i++){
        parent[i]=i;
    }
    for(int i=1; i<=n; i++){
        cin >> arr[i].first >>arr[i].second;
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x>> y;
        double dist= sqrt(pow(arr[y-1].first-arr[x-1].first,2)
                            +pow(arr[y-1].second-arr[x-1].second,2) );
        vec2.push_back(Edge(x,y,dist));
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1;j<=n;j++){
            double dist= sqrt( pow(arr[j].first-arr[i].first,2)+pow(arr[j].second-arr[i].second,2) );
            
            vec.push_back(Edge(i,j,dist));
        }
    }
    sort(vec2.begin(),vec2.end(),compare);
    sort(vec.begin(),vec.end(),compare);
    
    double sum=0;

    for(int i=0; i<vec2.size();i++){
        // cout <<vec2[i].node[0] <<' '<< vec2[i].node[1]<<'\n';
        if(!find_parent(parent,vec2[i].node[0],vec2[i].node[1])){
                // cout << "sum: "<< sum<<'\n';
            union_parent(parent,vec2[i].node[0], vec2[i].node[1]);
        }
    }

    for(int i=0; i<vec.size();i++){
        // cout <<vec[i].node[0] <<' '<< vec[i].node[1]<<'\n';
        if(!find_parent(parent,vec[i].node[0],vec[i].node[1])){
                sum += vec[i].dist;
                // cout << "sum: "<< sum<<'\n';
            union_parent(parent,vec[i].node[0], vec[i].node[1]);
        }
    }

    sum*=100;
    sum = round(sum);
    sum/=100;
    printf("%.2lf",sum);

}