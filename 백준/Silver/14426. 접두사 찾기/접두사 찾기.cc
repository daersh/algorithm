#include <iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Trie{
private:
    bool isEnd=false;
    Trie* child[26]={nullptr,};
public:
    void insert(string data){
        Trie* curr = this;
        for(char d: data){
            int loc= d-'a';
            if(curr->child[loc]==nullptr)
                curr->child[loc]= new Trie();
            curr=curr->child[loc];
        }
        curr->isEnd=true;
    }

    bool find(string data){
        Trie* curr = this;
        for(char d: data){
            int loc = d-'a';
            if(curr->child[loc]==nullptr)
                return false;
            curr=curr->child[loc];
        }
        return true;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n>>m;
    Trie* trie= new Trie();
    string x;
    for(int i=0;i<n;i++){
        cin >> x;
        trie->insert(x);
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        cin >> x;
        if(trie->find(x)){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}