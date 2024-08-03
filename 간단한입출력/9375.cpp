#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        
        map<string, string> item;
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            string name, category;
            cin >> name >> category;
            item[name] = category;
        }
        
    }
}