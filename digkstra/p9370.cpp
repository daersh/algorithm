
#include <bits/stdc++.h>

#define pii pair<int,int>
const int INF = 1e9;

using namespace std;

//테스트 케이스, 
int T;
// n:교차로, m:도로 , t: 목적지 후보의 개수
int n, m, t;
// s:예술가들의 시작지점,  gh:예술가들이 지나간 교차로
int s,g,h; 
// a b  사이 거리 d  * m 개
int a,b,d;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    int i;
  
    for(int wtf=0;wtf<T;wtf++){
        
        // 목적지 후보 * t 개
        vector<int> x;
        priority_queue<pii , vector<pii>, greater<pii> > pque;

        //g,h 사이 도로를 이동했는지 확인하기 위함
        int visit_g=false;
        int visit_h=false;

        vector<pii> vec[2010];
        int dist[2010];
        int dist2[2010];
        int dist3[2010];
        //g to h or h to g 거리
        int g_h=0; 
        fill(dist, &dist[2010], INF);
        fill(dist2, &dist2[2010], INF);
        fill(dist3, &dist3[2010], INF);

        cin >> n >> m >> t;
        cin >> s >>g >> h;

        for(i=0;i<m;i++){
            cin >> a >> b >> d;
            vec[a].push_back(make_pair(d,b));
            vec[b].push_back(make_pair(d,a));
            
        }
        int aa;
        for(i=0;i<t;i++){
            cin >> aa;
            x.push_back(aa);
        }
        sort(x.begin(),x.end());

        //1
        pque.push(make_pair(0,s));
        dist[s]=0;
        
        while(!pque.empty())
        {
            int distance= pque.top().first;
            int loc = pque.top().second;
            pque.pop();

            if(distance > dist[loc])
            {
               continue;
            }

            for(int j=0;j<vec[loc].size();j++)
            {
                int vec_dist= vec[loc][j].first;
                int vec_loc = vec[loc][j].second;
                
                //저장된 값보다 짧은 경로임을 확인했을 경우
                if(vec_dist+distance < dist[vec_loc])
                {
                    dist[vec_loc]= vec_dist+distance;
                    pque.push(make_pair(dist[vec_loc],vec_loc));
                }
            }
        }   

        //2
        pque.push(make_pair(0,g));
        dist2[g]=0;
        
        while(!pque.empty())
        {
            int distance= pque.top().first;
            int loc = pque.top().second;
            pque.pop();

            if(distance > dist2[loc])
            {
               continue;
            }

            for(int j=0;j<vec[loc].size();j++)
            {
                int vec_dist= vec[loc][j].first;
                int vec_loc = vec[loc][j].second;
                
                //저장된 값보다 짧은 경로임을 확인했을 경우
                if(vec_dist+distance < dist2[vec_loc])
                {
                    dist2[vec_loc]= vec_dist+distance;
                    pque.push(make_pair(dist2[vec_loc],vec_loc));
                }
            }
        }   

        //3
        pque.push(make_pair(0,h));
        dist3[h]=0;
        
        while(!pque.empty())
        {
            int distance= pque.top().first;
            int loc = pque.top().second;
            pque.pop();

            if(distance > dist3[loc])
            {
               continue;
            }

            for(int j=0;j<vec[loc].size();j++)
            {
                int vec_dist= vec[loc][j].first;
                int vec_loc = vec[loc][j].second;
                
                //저장된 값보다 짧은 경로임을 확인했을 경우
                if(vec_dist+distance < dist3[vec_loc])
                {
                    dist3[vec_loc]= vec_dist+distance;
                    pque.push(make_pair(dist3[vec_loc],vec_loc));
                }
            }
        }   
        g_h= dist2[h]; 
        

        for(int i=0;i<t;i++)
        {
            int cmp = x[i];

            if(dist[cmp] == dist[g] + g_h + dist3[cmp]  ){
                //시작지점 -> g -> h -> x[i] =  시작지점->x[i]
                cout << cmp << ' ';
            }else if(dist[cmp] == dist[h] + g_h + dist2[cmp]){
                //시작지점 -> h -> g -> x[i] =  시작지점->x[i]
                cout << cmp << ' ';
            }

        }
        cout << '\n';

    }

    return 0;
}


