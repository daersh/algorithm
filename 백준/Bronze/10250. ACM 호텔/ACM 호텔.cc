#include <iostream>

using namespace std;

int main(){

    int T;
    cin >> T;

    for(int t= 0; t < T; t++){
        int h,w,n;
        cin >> h >> w >> n;
        
        int endv = n/h + 1;
        int startv = n%h;
        if(startv == 0){
            startv = h;
            endv --;
        }
        
        cout << startv << (endv<10 ? "0"+to_string(endv) : to_string(endv)) <<'\n';
    }

    return 0;
}