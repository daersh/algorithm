#include <iostream>
#include <queue>
using namespace std;

int arr[10010];

int main(){

    
    for(int i = 1; i < 10000 ; i++){
        
        int v = i;
        int x = i;
        while (x / 10!=0)
        {
            v += x%10;
            x/=10;
            // cout << x << " " << v << endl;
        }
        v+= x%10;     
        // cout << " " << v << endl;
        arr[v] = 1;
    }
    for(int i = 1; i <10000;i++){
        if(arr[i] == 0)
            cout << i << '\n';
    }
}
