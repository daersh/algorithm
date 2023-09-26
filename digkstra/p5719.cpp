#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> pii;

const int INF = 1e9;

int N,M;
int startp,endp;
int d[510];
int used[510];

void digkstra(int start , vector<pii> vec[]){
    priority_queue<pii,vector<pii>,greater<pii> > pque;

    pque.push(make_pair(0,start));
    d[startp]=0;
    
    while (!pque.empty())
    {
        int dd= pque.top().first;
        int l=pque.top().second;
        pque.pop();

        if(dd>d[l]) continue;

        for(int i=0;i<vec[l].size();i++){
            int ddd = vec[l][i].first;
            int lll = vec[l][i].second;
            if(ddd+dd < d[lll]){
                d[lll]=ddd+dd;
                used[lll]=l;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }
}

int main(){
    
    while (1)
    {
        cin >> N >> M;
        cin >> startp >> endp;

        int arr[N+1];
        vector<pii> vec[N+1];
        vector<pii> ld;
        fill(&d[0],&d[N+1],INF);
        fill(&used[0],&used[N+1],false );

        int x,y,z;
        for(int i=0;i<M;i++){
            cin >> x >> y >> z;
            vec[x].push_back(make_pair(z,y));
            if(y==endp){
                ld.push_back(make_pair(z,x));
            }
        }
        digkstra(startp,vec);

        for(int i=0;i<ld.size();i++){

            int dist= ld[i].first;
            int loc= ld[i].second;

            if(d[loc]+dist== d[endp]){
                cout << "같은 경로 발견\n";
                ld[i].first=-1;
                int x= used[loc];

                while(1){
                    if(d[x]==INF || d[x]==-1){
                        break;
                    }
                    d[x]=-1;
                    if(x== used[x] || startp == used[x]){
                        break;
                    }
                    x=used[x];
                    
                }
            }
        }
        

        for(int i=0;i<N;i++){
            cout << d[i] << ' ';
        }cout << '\n';
       

        int min =INF;

        for(int i=0;i<ld.size();i++){
            cout << i<< '\n';
            //d[x]+z == M ? 
            int loc= ld[i].second;
            int dist= ld[i].first;
            if(dist==-1){
                continue;
            }

            if(d[loc]+dist>d[endp]){

                int x= used[loc];

                while(d[x]!=INF || d[x]!=0 ){
                    if(d[x]==-1 || x== used[x]){
                        break;
                    }
                    x=used[x];
                }

                if(x!=false){
                    if(min>dist){
                        min=dist;
                    }
                }

            }
        }

        cout << "min fin \n";

        cout << min << '\n';

    }
}
