#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int parent[100010];


struct Data{
    int loc_num;
    int x;
    int y;
    int z;
    Data(int loc_num, int x,int y,int z){
        this->loc_num= loc_num;
        this->x=x;
        this->y=y;
        this->z=z;
    }
};

struct Edge{
    int node[2];
    int dist;

    Edge(int x, int y, int dist){
        node[0]=x;
        node[1]=y;
        this->dist=dist;
    }
};

bool compare(Edge &a, Edge &b){
    return a.dist<b.dist;
}
bool compare_x(Data &a, Data &b){
    return a.x<b.x;
}
bool compare_y(Data &a, Data &b){
    return a.y<b.y;
}
bool compare_z(Data &a, Data &b){
    return a.z<b.z;
}

int get_parent(int x){
    if(parent[x]==x) return x;
    return parent[x]= get_parent(parent[x]);
}

void union_parent(int x,int y){
    x = get_parent(x);
    y = get_parent(y);
    if(x<y) parent[y]=x;
    else parent[x]=y;
}

bool find_parent(int x,int y){
    x = get_parent(x);
    y = get_parent(y);
    if(x==y) return true;
    return false;
}


int main(){
    cin >>n;
    vector<Edge> edge;
    vector<Data> data;
    
    for(int i=0; i<= n; i++){
        parent[i]=i;
    }

    for(int i=0; i<n; i++){
        int x,y,z;
        cin >> x>> y>> z;
        data.push_back(Data(i,x,y,z));
    }
    
    sort(data.begin(),data.end(),compare_x);
    // cout << "x\n";
    for(int i=0; i<n-1;i++){
        Data data1= data[i];
        Data data2= data[i+1];
        int dist = abs(data1.x-data2.x);
        // cout << data1.loc_num<<' '<<data2.loc_num <<" = "<<dist<<'\n';
        edge.push_back(Edge(data1.loc_num,data2.loc_num,dist) );
    }
    
    // cout << "y\n";

    sort(data.begin(),data.end(),compare_y);
    for(int i=0; i<n-1;i++){
        Data data1= data[i];
        Data data2= data[i+1];
        int dist = abs(data1.y-data2.y);
                // cout << data1.loc_num<<' '<<data2.loc_num <<" = "<<dist<<'\n';
        edge.push_back(Edge(data1.loc_num,data2.loc_num,dist) );
    }

    // cout << "z\n";

    sort(data.begin(),data.end(),compare_z);
    for(int i=0; i<n-1;i++){
        Data data1= data[i];
        Data data2= data[i+1];
        int dist = abs(data1.z-data2.z);
                // cout << data1.loc_num<<' '<<data2.loc_num <<" = "<<dist<<'\n';
        edge.push_back(Edge(data1.loc_num,data2.loc_num,dist) );
    }

    sort(edge.begin(),edge.end(),compare);
    int sum=0;

    for(int i=0; i< edge.size(); i++){
        // cout << edge[i].node[0]<<' '<<edge[i].node[1]<< ' '<<edge[i].dist<<'\n';
        
        if(!find_parent(edge[i].node[0],edge[i].node[1])){
            //cout << "sum= "<<sum<<'\n';
            sum+=edge[i].dist;
            union_parent(edge[i].node[0],edge[i].node[1]);
        }
    }
    cout << sum;
}