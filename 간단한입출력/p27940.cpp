#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N,M,K;
    cin >> N >>M >>K;
    int arr=0;
    int x,y;
    int result=-1;

    for(int i=0;i<M;i++){
        cin >> x>>y;
        arr+=y;
        
        if(arr>K && result==-1){
            cout << i+1 <<' '<< 1;
            result=0;
        }
    }

    if(result==-1)
        cout << "-1";
}