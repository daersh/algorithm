#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstring>

using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



    int n;
    int cnt=0;
    cin >> n;
    unordered_map<string,int> a;
    unordered_map<string,int> b;
    string x, y, z;
    for(int i=0; i<n;i++){
        cin >> x >> y;
        if(x=="add"){
            if(y=="A"){
                cin >> z;
                //문자별로 처리
                if(a.find(z) ==a.end()){
                    a.insert(make_pair(z,1));
                }else{
                    a[z]++;
                }
            }
            else{
                cin >> z;
                //문자별로 처리
                if(b.find(z) ==b.end()){
                    b.insert(make_pair(z,1));
                }else{
                    b[z]++;
                }
            }
        }

        else if(x=="delete"){
            if(y=="A"){
                cin >> z;
                //문자별로 처리
                a[z]--;
            }
            else {
                cin >> z;
                //문자별로 처리

            }
        }
        else if(x=="find"){
            cnt=0;
            int len = y.length();
            string left, right=y;
            for(int j=1; j< len;j++){
                left.push_back(y[j-1]);
                right.erase(0, 1);
                // reverse(right.begin(),right.end());

                if(l!=0){

                    cnt += l * r;
                }else {                    
                    break;
                }
            }
            cout << cnt<<'\n';
        }
    } 
    delete trie_x;
    delete trie_y;
    return 0;
}