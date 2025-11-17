#include <iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    int sum=0;
    int starLoc=-1;
    for(int i=0;i<str.length();i++){
        if(str[i]!='*'){
            int val = str[i]-'0';
            if (val==0) 
                continue;
            sum+= val* (i%2==1 ? 3 : 1);
        }
        else
            starLoc = i;
    }
    int res = sum%10;
    int result=-1;
    // cout << "sum: " << sum << " res: " << res << " starLoc: " << starLoc << '\n';
    if(res==0){
        result=0;
    }else {
        for(int i=1;i<=9;i++){
            int val = (starLoc%2==1 ? i*3 : i*1);
            if((res + val)%10==0){
                result = i;
                break;
            }
        }
    }
    
    cout << result;
    return 0;
}