#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    //2*5 개수 구하기 
    int o=0;

    for(int i=2;i<=n;i++){
        int x=i;
        while(x%5==0){
            o++;
            x/=5;
        }
    }
    cout << o;

    return 0;
}