#include <iostream>

using namespace std;

int main(){
    int n, m, k;

    cin >> n >> m>> k;
    k-=n;
    int minus= n-m;
    int result=k/minus+1;

    if(k%minus!=0){
        result+=1;
    }
    cout << result << endl;
    
    return 0;

}
