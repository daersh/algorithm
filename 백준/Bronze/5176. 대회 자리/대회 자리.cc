#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int K, P,M;
    int i,j;
    int count;
    int b;

    cin >> K;
    int ca[K];
    bool seat[501]; 
    for(i=0; i<K; i++){
  
        count=0;
        cin >> P >> M;
        
        for(j=0; j<P; j++){
            seat[j]=false;
        }

        for(j=0;j<P;j++){

            cin >> b;   

            if(seat[b-1]==false)
                seat[b-1]=true;
            else
               count ++;
        }
        cout << count<<'\n';
    }


}