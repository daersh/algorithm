#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){

        int n,m;
        cin >> n >> m;
        int cnt=0;
        if(n==0)cnt++;
        for(int i=n;i<=m;i++){
            int x=i;
            while(x>0){
                if(x%10 ==0) cnt++;
                x/=10;
            }
        } 
        cout << cnt<<'\n';
    }

}