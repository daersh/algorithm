#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

pair<double,double> arr[100];

struct Edge{
    int node[2];
    double dist;
    Edge(int a, int b, double dist){
        node[0]=a;
        node[1]=b;
        this->dist= dist;
    }
};
bool compare(Edge &edge1,Edge &edge2){
    return edge1.dist<edge2.dist;
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
    if(x==y)return true;
    return false;
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i< n; i++){
        double x,y;
        cin>> x>>y;
        arr[i]=make_pair(x,y);
    }
    vector<Edge> vec;
    for(int i=0; i< n; i++){
        for(int j=i+1;j<n;j++){
            double dist= sqrt( pow(arr[j].first-arr[i].first,2)+pow(arr[j].second-arr[i].second,2) );
            //cout << i<<" to "<<j <<" = "<<dist<<'\n';
            vec.push_back(Edge(i,j,dist));
        }
    }

    sort(vec.begin(),vec.end(),compare);
    int parent[n];
    for(int i=0; i< n; i++){
        parent[i]=i;
    }
    double sum =0;

    for(int i=0; i<vec.size();i++){
        if(!find_parent(parent,vec[i].node[0],vec[i].node[1])){
            sum += vec[i].dist;
            union_parent(parent,vec[i].node[0], vec[i].node[1]);
        }
    }

    sum*=100;
    sum = round(sum);
    sum/=100;
    printf("%.2lf",sum);
}