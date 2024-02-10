#include<iostream>
#include<map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m ;
    cin >> n >> m;
    map<string, int> pocketmon;
    map<int, string> pocketmon1;
    string x;
    for(int i=1;i<=n;i++){
        cin >> x;
        pocketmon.insert(make_pair(x,i));
        pocketmon1.insert(make_pair(i,x));
    }
    for(int i=0; i< m ;i++){
        cin >> x;
        if(pocketmon.find(x)!=pocketmon.end()){
            cout << pocketmon[x]<<'\n';
        }else{
            cout << pocketmon1[stoi(x)]<<'\n';
        }
    }
}