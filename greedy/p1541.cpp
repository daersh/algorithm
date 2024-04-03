#include <iostream>

using namespace std;


const int INF = 1e9;

int main(){
    string x;
    cin >> x;
    int result=0;
    int isNum=false;
    int val =0;
    int past = 0;   // 0: +  1: -

    for(int i=0; i < x.length();i++) {
        if(x[i]!='-' && x[i]!='+'){
            if(!isNum){
                if(x[i]=='0' ){
                    continue;
                }else{
                    isNum=true;
                }
            }
            val*=10;
            val+=x[i]-'0';
            // cout<< "val: "  << val<< '\n';
        }
        else{

            if(past == 0){
                result+=val;
            }else {
                result-=val;
            }

            if(x[i]=='-'){
                past = 1;
            }
            // cout << result<<'\n';
            val=0;
            isNum=false;
        }
    }

    if(past == 0){
        result+=val;
    }else {
        result-=val;
    }
    cout << result<<'\n';

    return 0;
}