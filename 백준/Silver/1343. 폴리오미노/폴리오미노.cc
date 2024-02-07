#include<iostream>
#include<vector>
using namespace std;

int main(){
    string x;
    cin >> x;
    vector<string> vec;

    int cnt=0;
    for(int i=0; i< x.length() ; i++){
        
        if(x[i]=='X') {
            cnt++;
            if(cnt==4){
                vec.push_back("AAAA");
                cnt=0;
            }
        }else{
            if(cnt==2){
                vec.push_back("BB");
            }else if(cnt%2!=0){
                cout <<"-1";
                return 0;
            }
            vec.push_back(".");
            cnt=0;
        }
    }
    if(cnt==2){
        vec.push_back("BB");
    }else if(cnt%2!=0){
        cout << "-1";
        return 0;
    }
    for(int i=0; i< vec.size();i++){
        cout<<vec[i];
    }
}