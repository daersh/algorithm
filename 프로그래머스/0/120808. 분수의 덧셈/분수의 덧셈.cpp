#include <string>
#include <vector>

using namespace std;

vector<int> solution(int a1, int b1, int a2, int b2) {
    vector<int> answer;
    
    long long x1=a1*b2;
    long long y1=b1*b2;
    long long x2=a2*b1;
    long long y2=b2*b1;
    
    x1+=x2;
    
    bool tf=false;
    if(x1==y1){
        answer.push_back(1);
        answer.push_back(1);
        return answer;
    }
        
    if(y2>x1){
        tf=true;
    }
    int x =0;
    if(tf){
        x=x1;
    }else{
        x=y1;
    }
    
    for(int i =x; i>=1;i--){
        if(x1%i == 0 && y1%i ==0){
            x1/=i;
            y1/=i;
        }
    }
    answer.push_back(x1);
    answer.push_back(y1);
    return answer;
}