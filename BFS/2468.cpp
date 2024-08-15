#include  <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int xn1[4] = {0,0,1,-1};
int yn1[4] = {1,-1,0,0};


int main(){
    
    int n ;
    cin >> n;
    vector<int> v[n];
    int visited[n][n];

    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    int result = 0;

    // 높이 1부터 검사
    for(int i = 0; i < 101; i++){

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                visited[j][k] = false;
            }
        }

        int h = i;

        int cnt = 0;


        for(int j= 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int x=j;
                int y = k;

                if(visited[j][k] == true || v[x][y] <= h)
                    continue;
                
                // cout << "x = "<< x << " y = " << y << "\n";

                queue<pair<int, int> > q;
                q.push(make_pair(j, k));
                cnt++;

                while(!q.empty()){
                    x= q.front().first;
                    y = q.front().second;

                    q.pop();

                    if(visited[x][y]== true)
                        continue;
                    
                    visited[x][y] = true;

                    for(int z = 0; z < 4; z++){
                        
                        int x2 = x+xn1[z];
                        int y2 = y+yn1[z];

                        if( x2>=0 && x2<n && 
                            y2>=0 && y2<n 
                            &&visited[x2][y2] == false
                            && v[x2][y2]>h
                            ){
                            // cout << "     " << x2 << " " << y2 << "\n" ;
                            q.push(make_pair(x2, y2));
                        }
                    }
                }

            }
        }
        if(cnt ==0)
            break;
        if(result<cnt)  
            result = cnt;
    }
    cout << result;
}