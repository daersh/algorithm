#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<long long> vec;


int main(){
    cin >> n;

    for(int i=0; i< n; i++){
        int x;
        cin >>x;
        vec.push_back(x);
    }
    
    long long sum =0 ;

    while(true){
        
    }

}

    /*
        12 
        1 3

        6 10 13 9 8 1
        
        1 - 8 - 13 -6   = 28
                   -10  = 32
          - 9 - 13 -6   = 29
              - 10 -6   = 26

        8 -9  - 10 -6   = 33
              - 6       = 23
          -13 - 10      = 32
              - 6       = 25
    */ 

