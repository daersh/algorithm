#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9;
typedef pair<int,int> pii;
int n,m;
vector<pii> vec[1010];
int num[3];
int d[1010];
int back[1010][1010];
void digkstra(int start);
void init();

int backtracking(int x){
    back[x][x]=-1;
    int arr[n+1];
    fill(&arr[0],&arr[n+1],0);
    int sum=0;
    for(int i=0;i<3;i++){
        int prev = num[i];
        while (prev != x)
        {
            // cout << prev <<" - ";
            int next= back[x][prev];

            if(arr[next]==0 || arr[prev]== 0){

                for(int j=0;j<vec[prev].size();j++){
                    if(vec[prev][j].second == next){
                        sum+=vec[prev][j].first;
                        arr[prev]=1;
                        prev= next;
                        break;
                    }
                }
            }else {
                prev= next;
            }
        }
        arr[x]= 1;
        // cout <<'\n';
        //for(int j=1; j<n+1;j++){
                // cout << arr[j]<< ' ';
        // }cout << '\n';
    }
    return sum;
}

void backtracking(int x, int go){
    back[x][x]=-1;
    int arr[n+1];
    fill(&arr[0],&arr[n+1],0);
    int sum=0;
    queue<pii> Nodes;
    for(int i=0;i<3;i++){
        int prev = num[i];
        while (prev != x)
        {
            int next= back[x][prev];
            if(arr[next]==0 || arr[prev]== 0){
                for(int j=0;j<vec[prev].size();j++){
                    if(vec[prev][j].second == next){
                        sum+=vec[prev][j].first;
                        arr[prev]=1;
                        Nodes.push(make_pair(prev,next));
                        prev= next;
                        break;
                    }
                }
            }else {
                prev= next;
            }
        }
        arr[x]= 1;
    }

    int cnt=0;

    for(int i=1; i<n+1;i++){
        if(arr[i]!=0){
            cnt++;
        }
    }
    
    cout << sum << ' '<<cnt-1 <<'\n';
    while (Nodes.empty()!=true)
    {
        cout << Nodes.front().first << ' '<< Nodes.front().second<<'\n';
        Nodes.pop();
    }
    
}


void solve(){
    init();
    int min = 1e9;
    int min_loc =0;
    for(int i=1;i<=n;i++){
        fill(&d[0],&d[n+1],INF);
        digkstra(i);
        int cmp = backtracking(i);
        if(min>cmp){
            min= cmp;
            min_loc= i;
        }
    }
    backtracking(min_loc,1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

void digkstra(int start){
    priority_queue<pii, vector<pii>, greater<pii> > pque;
    d[start]= 0;
    pque.push(make_pair(0,start));
    while(!pque.empty()){
        int dd = pque.top().first;
        int ll = pque.top().second;
        pque.pop();
        if(dd > d[ll]) continue;
        for(int i=0; i< vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;
            if(ddd+dd < d[lll]){
                d[lll]= ddd+dd; 
                back[start][lll]= ll;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }
}
void init(){
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x>>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    cin >> num[0]>>num[1]>>num[2];
    
}