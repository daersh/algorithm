#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
string x;
int cnt[2];
char past='0';

int main(){
    
    cin >> x;

    if(x[0]=='0'){
        cnt[0]++;
    }else{
        cnt[1]++;
        past='1';
    }

    for(int i=1; i< x.length();i++){
        if(x[i]!=past){
            if(x[i]=='0'){
                cnt[0]++;
                past='0';
            }else{
                cnt[1]++;
                past='1';
            }
        }
    }

    cout << min(cnt[0],cnt[1]);

}