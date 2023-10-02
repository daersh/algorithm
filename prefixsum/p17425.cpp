#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        int N;
        cin >> N;

        int a= sqrt(N);
        if(N<100){
            a=N;
        }
        int i;
        int sum=0;

        if(N==1){
            cout << 1 << '\n';
            continue;
        }

        for(int i=0;i<=a;i++){
            if(a%i==0){
                sum+=i;
            }
        }
        cout<<sum << '\n';
    }


}