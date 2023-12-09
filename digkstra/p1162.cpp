#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const long long INF = 9223372036854775800;
vector<pii> vec[10010];
long long d[30][10010];
int n ,m, usable;

struct Node{
    long long dist;
    int loc;
    int use;
    Node(long long dist,int loc,int use){
        this->dist=dist;
        this->loc=loc;
        this->use=use;
    }
};
struct compare{
    bool operator()(const Node& s1, const Node& s2){
        return s1.dist > s2.dist;
    }
};

void dig(){
    priority_queue<Node,vector<Node>,compare > pque;
    Node node(0,1,0);
    pque.push(node);
    d[0][1]=0;
    while (!pque.empty())
    {
        
        long long dd= pque.top().dist;
        int ll= pque.top().loc;
        int use= pque.top().use;
        // cout << dd <<' '<<ll << ' ' << use <<'\n';
        pque.pop();
        if(dd>d[use][ll])continue;

        for(int i=0; i<vec[ll].size();i++){
            long long ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;
            if(ddd+dd<d[use][lll]){
                d[use][lll]=ddd+dd;
                node.dist= d[use][lll];
                node.loc = lll;
                node.use = use;
                // cout <<"    "<<d[use][lll]<<' '<<lll<<' '<<use <<'\n';
                pque.push(node);
            }
            if(use<usable &&dd<d[use+1][lll]){
                d[use+1][lll]=dd;
                node.dist= d[use+1][lll];
                node.loc = lll;
                node.use= use+1;
                // cout <<"    "<<d[use+1][lll]<<' '<<lll<<' '<<use+1 <<'\n';
                pque.push(node);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> usable;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >>x>>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x)); 
    }
    for(int i=0;i<usable+1;i++){
        fill(&d[i][0],&d[i][n+2],INF);
    }
    //처음-> 끝 시간
    dig();
    long long min= 9223372036854775800;
    for(int i=0; i<=usable; i++){
        // cout <<d[i][n]<<' ';
        if(min > d[i][n]){
            min = d[i][n];
        }
    }
    cout << min;
    return 0;
}