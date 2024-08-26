#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int n , m ;
int xn[4] = {0,0,1,-1};
int yn[4] = {1,-1,0,0};

int main(){

    cin >> n >> m;
    int arr[n][m];
    int visited[n][m];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
            visited[i][j] = 0;
        }
    }

    
    
}