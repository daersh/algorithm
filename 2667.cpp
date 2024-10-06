#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){

    int n;

    cin >> n;

    int arr[n+1][n+1];
    int visited[n+1][n+1];

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            arr[i][j] = str[j]-'0';
            visited[i][j] = 0;
        }
    }

    priority_queue<int, vector<int>, greater<int> > result;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(arr[i][j] && !visited[i][j] ){
                
                int sum = 1;
                queue<pair<int,int> > q;
                
                q.push(make_pair(i,j));

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    visited[x][y] = true;

                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(nx>=0 && ny>=0 && nx<n && ny<n 
                            && arr[nx][ny] 
                            && !visited[nx][ny]){
                            visited[nx][ny] = true;
                            sum++;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }
                result.push(sum);
                
            }
        }
    }
    cout << result.size() <<'\n';

    while(!result.empty()){
        int a = result.top();
        result.pop();
        cout << a <<'\n';
    }

}