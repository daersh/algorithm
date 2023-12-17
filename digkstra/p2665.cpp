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
    cin >> n;
    m=n;
    int arr[101][101];
    int d[101][101];
    for(int i=0;i<m;i++){
        string a;
        cin >> a;
        fill(&d[i][0],&d[i][n],INF);
        for(int j=0;j<a.length();j++){
            arr[i][j]=a[j]-48;
            if(arr[i][j]==1){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
        }
    }
    priority_queue<Loc,vector<Loc>,compare> pque;
    Loc loc;
    loc.x=0;
    loc.y=0;
    loc.dist=arr[0][0];
    d[0][0]= arr[0][0];
    pque.push(loc);

    while (!pque.empty())
    {
        int x= pque.top().x;
        int y= pque.top().y;
        int dd= pque.top().dist;
        pque.pop();
        if(dd<d[y][x])continue;
        
        for(int i=0;i<4;i++){
            int xx=x+xnew[i];
            int yy=y+ynew[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m){
                int ddd= arr[yy][xx];
                if(dd+ddd<d[yy][xx]){
                    d[yy][xx]=dd+ddd;
                    loc.dist=d[yy][xx];
                    loc.x=xx;
                    loc.y=yy;
                    pque.push(loc);
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<< d[i][j]<<' ';
    //     }cout<< '\n';
    // }
    cout << d[m-1][n-1];
}