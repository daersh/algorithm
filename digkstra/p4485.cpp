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


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n=1;
    int cnt=1;
    while(1){
        cin >> n;
        if(n==0) return 0;
        int arr[125][125];
        int d[125][125];
        for(int i=0;i<n;i++)
            fill(&d[i][0],&d[i][n],INF);

        for( int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >>arr[i][j];
            }
        }

        priority_queue<Loc,vector<Loc>,compare > pque;
        d[0][0]=arr[0][0];
        Loc loc;
        loc.x= 0;
        loc.y= 0;
        loc.dist=d[0][0];
        pque.push(loc);

        while(!pque.empty()){
            int dd= pque.top().dist;
            Loc ll= pque.top();
            pque.pop();
            if(dd>d[ll.x][ll.y])continue;
            
            int xl[4]={1,-1,0,0};
            int yl[4]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int xnew=xl[i]+ll.x;
                int ynew=yl[i]+ll.y;
                if(xnew>=0&&xnew<n&&ynew>=0&&ynew<n){
                    int ddd= arr[xnew][ynew];
                    if(dd+ddd<d[xnew][ynew]){
                        loc.x=xnew;
                        loc.y=ynew;
                        d[xnew][ynew]=ddd+dd;
                        loc.dist=ddd+dd;
                        pque.push(loc);
                    }
                }
            }
        }

        // for( int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout <<d[i][j] <<' ';
        //     }cout <<'\n';
        // }

        cout<<"Problem "<< cnt<<": "<<d[n-1][n-1]<<'\n';
        cnt++;
    }
}