#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> vec) {
    bool answer = true;
    
    map<string,int> mapp;
    
    for(int i=0; i<vec.size();i++){
        mapp[vec[i]] = 1;
    }
    
    for(int i=0; i<vec.size();i++){
        string s = vec[i];
        // cout << s <<'\n';
        
        string a = "";
        for(int j=0; j<s.length()-1; j++){
            a+=s[j];
            // cout << a <<'\n';

            if(mapp[a]==1){
                return false;
            }       
        }
    }
    
    return true;
}
int main(){
    vector<string> vec;
    for(int i=0; i<5;i++) {
        string s;
        cin>>s;
        vec.push_back(s);
    }

    cout<<solution(vec)<<endl;
    return 0;
}