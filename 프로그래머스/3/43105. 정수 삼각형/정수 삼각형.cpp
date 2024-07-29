#include <string>
#include <vector>

using namespace std;



int solution(vector<vector<int>> triangle) {
    
    int h = triangle.size()-2;
    
    for(int i = h; i>=0 ; i--){
        
        for(int j = 0 ; j <= i ; j++){
            
            int x = triangle[i+1][j];
            int y = triangle[i+1][j+1];
            
            if(x>y){
                triangle[i][j] += x;
            }else{
                triangle[i][j] += y;
            }
            
        }
    }
    
    return triangle[0][0];
}