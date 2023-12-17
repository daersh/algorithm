#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

struct Loc{
    int x;
    int y;
    int dist;
};

struct compare{
    bool operator()(const Loc& s1, const Loc& s2){
        return s1.dist > s2.dist;
    }
};

int xnew[4]= {1,-1,0,0};
int ynew[4]={0,0,1,-1};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int arr[310][310];
    int d[310][310];
    int x1,y1,x2,y2;
    cin >> x1>>y1>>x2>>y2;
    for(int i=0;i<n;i++){
        fill(&d[i][0],&d[i][m],INF);
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            if(s[j]=='*'||s[j]=='#')
                s[j]='0';
            arr[i][j]=s[j]-48;
        }
    }
    
    Loc loc;
    loc.x= x1-1;
    loc.y= y1-1;
    loc.dist=0;
    d[x1-1][y1-1]=0;
    priority_queue<Loc,vector<Loc>,compare> pque;
    pque.push(loc);
    while (!pque.empty())
    {
        int x= pque.top().x;
        int y= pque.top().y;
        int dd= pque.top().dist;
        pque.pop();
        if(dd>d[x][y]) continue;
        for(int i=0;i<4;i++){
            int xx=x+xnew[i];
            int yy=y+ynew[i];
            if(xx>=0&&x<n&&yy>=0&&yy<m){
                int ddd= arr[xx][yy];
                if(ddd+dd<d[xx][yy]){
                    d[xx][yy]=ddd+dd;
                    loc.x=xx;
                    loc.y=yy;
                    loc.dist=d[xx][yy];
                    pque.push(loc);
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout <<d[i][j]<<' ';
    //     }cout <<'\n';
    // }
    cout<< d[x2-1][y2-1]+1;
}