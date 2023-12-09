#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const long long INF = 9223372036854775800;
typedef long long int ll;
typedef pair<int,int> pii;
vector<pii> vec[1010];

long long d[1010][1010];

int n , m,k;
int start, end_val;
int val;

struct Node{
    long long dist;
    int loc;
    int cnt;
    Node(long long dist,int loc,int cnt){
        this->dist=dist;
        this->loc=loc;
        this->cnt=cnt;
    }
};
struct compare{
    bool operator()(const Node& s1, const Node& s2){
        return s1.dist > s2.dist;
    }
};


void dig(){
    priority_queue<Node,vector<Node>,compare> pque;
    Node node(0,start,0);
    
    pque.push(node);
    d[0][start]=0;
    while (!pque.empty())
    {
        long long dd= pque.top().dist;
        int ll= pque.top().loc;
        int cnt = pque.top().cnt;
        pque.pop();
        if(dd>d[cnt][ll])continue;

        for(int i=0;i<vec[ll].size();i++){
            long long ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;

            if(ddd+dd<d[cnt+1][lll]){
                d[cnt+1][lll]=ddd+dd;
                node.cnt=cnt+1;
                node.dist=d[cnt+1][lll];
                node.loc=lll;
                pque.push(node);
            }
        }
    }
    
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    cin >> start >> end_val;
    for(int i=0; i<m;i++){
        int x ,y ,z;
        cin >> x>>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    for(int i=0;i<=n;i++){
        fill(&d[i][0],&d[i][n+1],INF);
    }

    vector<long long> val_vec;
    for(int i=0;i<k;i++){
        cin >> val;
        val_vec.push_back(val);
    }

    dig();
    // for(int i=0; i<n;i++){
    //     cout << d[i][end_val] <<' '; 
    // }
    long long min_val =9223372036854775800;

    for(int j=1;j<=n;j++){
        if(min_val>d[j][end_val]){
            min_val = d[j][end_val];
        }
    }

    cout << min_val <<'\n';

    for(int i=0; i<k;i++){
        min_val =9223372036854775800;
        int v= val_vec[i];
        for(int j=0;j<=n;j++){
            if(d[j][end_val]==9223372036854775800)continue;
            long long cmp = d[j][end_val]+ v*j;
            d[j][end_val]+= v*j;
            if(min_val>cmp){
                min_val = cmp;
            }
        }
        cout << min_val<<'\n';
    }

   
}  
