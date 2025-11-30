#include <iostream>

using namespace std;

int main(){
    
    int x;
    int n,m;
    int v=-1;
    for(int i =1;i<=9;i++ ){
        for (int j = 1; j <= 9; j++)
        {
            cin >> x;
            if(v<x){
                n=i;
                m=j;
                v=x;
            }
        }
        
    }

    cout << v <<'\n' << n<<' ' << m ;

    return 0;
}