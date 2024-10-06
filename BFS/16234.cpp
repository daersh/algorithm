#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int x_new[4]= {0,0,1,-1};
int y_new[4]= {1,-1,0,0};

int main() {
    
    int n , left, right;
    cin >> n >> left >> right;

    int arr[n][n];

    for (int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    int visited[n][n];

    while(1){
        // 주변 노드 연결 시키는게 나을 듯 
        
        vector<int> l;

        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < n; j++){
                
            }
        }

    }

}