#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF  = 1e9;
typedef pair<int,int> pii;

// struct NODE{
//     int dist;
//     int loc;
//     bool stop=false;
//     int next;
// };

// struct compare{
//     bool operator()(const NODE& s1, const NODE& s2){
//         return s1.dist > s2.dist;
//     }
// };

int s,e,n,m;
int d[510];

void dig(vector<pii> *vec, int *back, vector<int> *saved){
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(make_pair(0,s));
    d[s]=0;
    while(!pq.empty())
    {
        int dd = pq.top().first;
        int ll = pq.top().second;
        pq.pop();
        if(dd>d[ll]) continue;

        for(int i=0; i< vec[ll].size(); i ++){
            int ddd = vec[ll][i].first;
            int lll = vec[ll][i].second;
            int tf=true;
            for(int j=0; j<saved[ll].size();j++){
                if(saved[ll][j]==lll){
                    tf=false;
                }
            }
            if(ddd+dd<d[lll] && tf ==true){
                back[lll]=ll;
                d[lll]=ddd+dd;    
                pq.push(make_pair(d[lll],lll));
            }
        }
    }
    int temp = e;
    while (temp != s)
    {
        int x = back[temp];
        saved[x].push_back(temp);
        temp=x;
    }
    
}

int main(){
    
    while (1)
    {
        n= 1; m= 1;
        //insert
        cin >> n >> m;

        if ( n== 0 && m == 0) break;

        vector<pii> vec[n];
        vector<int> saved[n];
        cin >> s >> e;
        //cout << n <<' '<<m<<' '<<s<<' '<<e<<'\n';
        for(int i=0; i< m; i++){
            int x, y, z;
            cin >> x >> y >> z;
            vec[x].push_back(make_pair(z,y));
        }

        fill(&d[0],&d[n],INF);
        int back[n];
        fill(&back[0],&back[n],0);
        
        dig(vec,back,saved);
        int min_val = d[e];
        int cmp_val = min_val;
        // cout <<" d : ";
        // for(int i = 0 ; i < n; i++){
        //     cout << d[i] << ' ';
        // }cout << '\n';
        // for(int i = 0 ; i < n; i++){
        //     cout << back[i] << ' ';
        // }cout << '\n';
        int cnt=0;
        while(1){

            fill(&d[0],&d[n],INF);

            dig(vec,back,saved);
            cmp_val= d[e];
            
            if(cmp_val >= INF) {
                cout << -1 << '\n';
                break;
            }else if (cmp_val!=min_val){
                cout << cmp_val <<'\n';
                break;
            }

        }
        
    }
    
}
