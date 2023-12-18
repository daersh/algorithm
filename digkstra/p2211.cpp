#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9;
typedef pair<int,int> pii;

int n, m;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //값 입력, 초기화
    cin >> n >> m;
    vector<pii> vec[n+1];
    for(int i=0; i<m;i++){
        int x, y, z;
        cin >> x>>y>>z;
        vec[x].push_back(make_pair(z,y));
        vec[y].push_back(make_pair(z,x));
    }
    int d[n+1]; //거리
    int back[n+1];
    int used[n+1];
    fill(&d[0],&d[n+1],INF);
    //입력, 초기화 완료

    //다익스트라 시작
    d[1]=0;
    priority_queue<pii,vector<pii>,greater<pii> >pque;
    pque.push(make_pair(0,1));
    while (!pque.empty())
    {
        int dd= pque.top().first;
        int ll= pque.top().second;
        pque.pop();
        if(dd>d[ll])continue;
        for(int i=0; i<vec[ll].size();i++){
            int ddd= vec[ll][i].first;
            int lll= vec[ll][i].second;
            if(ddd+dd<d[lll]){
                d[lll]=ddd+dd;
                back[lll]=ll;
                pque.push(make_pair(d[lll],lll));
            }
        }
    }
    //다익스트라 완료

    //역추적값 저장할 변수, 카운트
    vector<pii> result;
    int cnt=0;
    //역추적시작
    for(int i=n;i>0;i--){
        int loc= i;
        while(loc!=1){
            int temp= back[loc];
            if(used[loc]!= 1){
                used[loc]=1;
                cnt++;
                result.push_back(make_pair(loc,temp));
                loc=temp;
            }else{
                break;
            }
        }
    }
    //역추적 완료

    //결과값 출력
    cout << cnt<<'\n';
    for(int i=0; i<result.size();i++){
        cout << result[i].first << ' '<<result[i].second<<'\n';
    }
}

