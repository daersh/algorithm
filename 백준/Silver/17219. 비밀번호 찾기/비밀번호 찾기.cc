#include <iostream>
#include <map>
using namespace std; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<string,string> datas;

    for(int i=0; i< n;i++){
        string x,y;
        cin >> x >> y;
        datas[x]=y;
    }
    for(int i=0;i<m;i++){
        string x;
        cin >> x;
        cout << datas[x] << '\n';
    }

    return 0;
}