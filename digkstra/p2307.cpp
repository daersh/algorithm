#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;
vector<pii> vec[1010];
int d[1010];
int n ,m;
//도둑 시작 무조건 1, 도착지 무조건 n
//벡트래킹
int back[1010];

void dig(){
    
    priority_queue<pii,vector<pii>, greater<pii> > pque;
    
    pque.push(make_pair(0,1));
    d[1]=0;

    while (!pque.empty())
    {
        int dd= pque.top().first;
        int ll = pque.top().second;
        pque.pop();
        if(dd>d[ll])continue;

        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;
           
            if(ddd+dd <d[lll]){
                d[lll]=ddd+dd;
                back[lll]= ll;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }
}

void dig( int block1,int block2){
    
    priority_queue<pii,vector<pii>, greater<pii> > pque;
    
    pque.push(make_pair(0,1));
    d[1]=0;

    while (!pque.empty())
    {
        int dd= pque.top().first;
        int ll = pque.top().second;
        pque.pop();
        if(dd>d[ll])continue;

        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;
            if(block1==ll &&block2==lll) continue;
            if(block1==lll &&block2==ll) continue;
            
            if(ddd+dd <d[lll]){
                d[lll]=ddd+dd;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<pii> vec2;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >>x>>y>>z;
        vec2.push_back(make_pair(x,y));
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x)); 
    }
    
    fill(&d[0],&d[n+1],INF);
    //처음-> 끝 시간
    dig();
    int first= d[n];
    int cmp= -1;
    
    int loc = n;
    back[1]=1;
    while (loc!=1)
    {   
        //cout << loc<<'\n';
        fill(&d[0],&d[n+1],INF);
        dig(loc,back[loc]);
        loc= back[loc];
        if(d[n]==1e9){
            // cout << -1;
            // return -1;
            cmp=-1;
            break;
        }else if(cmp< d[n]-first){
            cmp = d[n]-first;
        }
    }
    

    cout << cmp;
    return 0;
}