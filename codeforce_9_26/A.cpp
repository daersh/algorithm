#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int N,M;
        cin >> N >>M;
        int tf=false;
        int x;
        for(int j=0;j<N;j++){
            cin >> x;
            if(x==M){
                tf=true;
            }
        }
        if(tf==true){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}