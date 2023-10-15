#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n;
    for(int t=0;t<n;t++){
        cin >> m;
        char arr[m][m];
        pii s,d;
        int result[m][m];
        for(int i=0;i<m;i++){
            string x;
            cin >> x;
            for(int j=0;j<x.size();j++){
                arr[i][j]=x[j];
                if(x[j]=='s') s= make_pair(i,j);
                else if(x[j]=='d') d= make_pair(i,j);
                result[i][j]=0;
            }
        }

        queue<pii> q;
        q.push(s);
        
    
        while (!q.empty())
        {
            int x= q.front().first;
            int y= q.front().second;
            int dist= result[x][y];
            q.pop();
            int xx[4]={1,-1,0,0};
            int yy[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int x_new = x+xx[i];
                int y_new = y+yy[i];
                if(x_new>=0&&x_new<m &&y_new>=0 &&y_new<m && arr[x_new][y_new]!= '*' &&result[x_new][y_new]==false){
                    q.push(make_pair(x_new,y_new));
                    result[x_new][y_new]=dist+1;
                }
            }
        }
 
        if(result[m-1][m-1]==0){
            cout << -1 <<'\n';
        }else{
            cout << result[m-1][m-1]<<'\n';
        }
        
        
    }

    
}
