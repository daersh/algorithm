#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

map<int,int> arr;
set<int> sett;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector<int> vec;
    for(int i=2; i < 25000000; i++){
        
        if(sett.find(i)==sett.end()){
            vec.push_back(i);
            int go = i+i;

            while(go<=50000000){
                sett.insert(go);
                go+=i;
            }

            //cout << vec.back() << ' ';
        }

    }
    int n;
    int b;
    int x,y;
    while(1){
        cin >> n;
        if(n%2==0){
            x=2;
            y=2;
        }else{
            x=2;
            y=3;
        }
    }

    
    
}