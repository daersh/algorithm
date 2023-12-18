#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9;
typedef pair<int,int> pii;

int n, m;
int s, e;
int d[510]; //거리
int min_len= INF;
int cnt=0;

void digkstra(vector<pii> vec[], int *back, int *endPoint){
    priority_queue<pii, vector<pii>,greater<pii> > pque;
    d[s]= 0;
    pque.push(make_pair(0,s));

    while (!pque.empty())
    {
        int dd= pque.top().first;
        int ll= pque.top().second;
        pque.pop();

        if(dd>d[ll])continue;

        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;            
            if(ddd+dd<d[lll]){
                back[lll]=ll;
                d[lll]=ddd+dd;
                if(lll==e){
                    if(min_len>d[lll]){
                        cnt=0;
                        min_len=d[lll];
                    }
                    endPoint[cnt]=ll;
                    cnt++;
                }
                pque.push(make_pair(d[lll],lll));
           }else if(d[lll]==ddd+dd &&e==lll){
                endPoint[cnt]=ll;
                cnt++;
           }
        }
        
    }   
}

void digkstra2(vector<pii> vec[], int *back, int *endPoint, vector<int> *enabled){
    priority_queue<pii, vector<pii>,greater<pii> > pque;
    d[s]= 0;
    pque.push(make_pair(0,s));

    while (!pque.empty())
    {
        int dd= pque.top().first;
        int ll= pque.top().second;
        pque.pop();

        if(dd>d[ll])continue;

        for(int i=0;i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;            
            if(ddd+dd<d[lll]){

                int tf= false;
                if(enabled[ll].size()!=0){
                    for(int j=0;j<enabled[ll].size();j++){
                        if(lll==enabled[ll][j]) {
                            tf= true;
                            break;
                        }
                    }
                }
                if(tf== true) continue;
                back[lll]=ll;
                d[lll]=ddd+dd;
                pque.push(make_pair(d[lll],lll));
           }
        }
    }   
}

void backtracking(int *back, int *endPoint, vector<int> *enabled){
    //
    for(int i=0; i<cnt;i++){
        
        int loc = endPoint[i];
        enabled[loc].push_back(e);
        cout <<e <<' '<< loc<<'\n';
        while (loc!=s)
        {
            int temp = back[loc];
            enabled[temp].push_back(loc);
            cout <<loc <<' '<<temp <<'\n';
            loc = temp;
        }
    }
}


int main(){

    while(1){
        int back[510]={0}; //역추적s
        vector<int>back2[510];

        int endPoint[510]={0};
        vector<pii> vec[510];
        vector<int> enabled[510]; //1일때 통과  불가
        min_len= INF;
        cnt= 0;
        //insert
        cin >> n >> m;
        if(n==0 && m==0) return 0;
        cin >> s >> e;
        for(int i=0 ;i<m;i++){
            int x,y,z;
            cin >> x>>y>>z;
            vec[x].push_back(make_pair(z,y));
        }
        fill(&d[0],&d[n],INF);
        //insert end
        
        //
        digkstra(vec,back,endPoint);
        backtracking(back,endPoint,enabled);
        fill(&d[0],&d[n],INF);
        digkstra2(vec,back,endPoint,enabled);

        while(d[e]==min_len){
            
        }
        if(d[e]==INF) cout << "-1\n";
        else cout << d[e]<<'\n';

    }
    
}