#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        
        long long x,y,z;

        cin >> x >>y >>z;
        
        long long max=0;
        long long min=0;
        
        min= y*(y+1)/2;
        max= x*(x+1)/2 - (x-y)*(x-y+1)/2;

        //cout<< i+1 << "번째  min: " << min <<" max: "<< max <<' ';

        if(z>=min && z<=max)    {
            cout <<"YES\n";
        }else{
            cout << "NO\n";
        }
    }
}