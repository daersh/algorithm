#include <string>
#include <vector>

using namespace std;
//  1
//
//  1
// 2 3
//
//   1
//  2 6
// 3 4 5

int arr[1010][1010];

vector<int> solution(int n) {
    vector<int> answer;
    
    int z = n;
    
    int maximum = 0;
    
    for(int i = 1 ; i<= n ; i++){
        maximum += i;
    }
 
    int loc =0;
    int h = 0;
    int v = 1;
    bool up = true;
    
    while(v<=maximum){
        arr[h][loc] +=v;
        v++;
        // answer.push_back(h);

        if(up){
            
            // 최고높이 도달 시
            if(h+1 == n ){
                
                for(int i=loc+1; i< n;i++){
                    if(arr[h][i]!=0){
                        break;
                    }
                    arr[h][i] = v;
                    v++;
                    loc++;
                }
                up = false;
                n--;
                h--;
                loc--;
            }else{
                h++;
            }
            
        }else{
            
            // 최저 높이 도달 시 다시 올라가도록 하고 높이를 올린다.
            if(arr[h-1][loc-1] != 0){
                up=true;
                h++;
            }else{
                h--;
                loc--;
            }
        }
    }
    
    for(int i=0; i< z; i++){
        for(int j=0; j<=i ; j++ ){
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}