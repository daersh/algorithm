#include <iostream>
#include <string>
using namespace std;
int main() {

	int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int x,y,z;
        cin >> x >>y >>z;
        int a= z%x;
        int b = z/x +1;
        cout << a;
        if(b<10){
            cout <<0<<b;
        }else{
            cout << b;
        }
    }

	return 0;
}