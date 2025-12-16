#include <iostream>
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int t;
    cin >> t;
    x+=t/3600;
    y+=(t%3600)/60;
    if(y>=60){
        y-=60;
        x++;
    }
    z+=(t%3600)%60;
    if(z>=60){
        z-=60;
        y++;
        if(y>=60){
            y-=60;
            x++;
        }
    }
    cout << x%24 <<" " << y <<" " << z;
    return 0;
}