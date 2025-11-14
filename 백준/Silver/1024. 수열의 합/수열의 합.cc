#include <iostream>

using namespace std;

int main(){
        long long n ,  m;
        cin >> n >> m;
        long long start= n/m;
        while(true){
                if(start<0 || m>100){
                        cout << -1;
                        return 0;
                }

                long long sum = start*m;
                for(int i=1; i<m;i++){
                        sum+=i;
                }
                if(sum<n){
                        m++;
                        start=n/m;
                }
                else if(sum>n){
                        start--;
                }
                else {
                        for(int i=start;i<start+m;i++){
                                cout<< i << ' ';
                        }
                        return 0;
                }
        }

}