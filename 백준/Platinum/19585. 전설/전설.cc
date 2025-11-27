#include <iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_set>
#include<algorithm>

using namespace std;
unordered_set<string> name;

class Trie{
private:
    bool isEnd=false;
    Trie* child[26]={nullptr,};
public:
    void insert(string data){
        Trie* curr = this;
        for(char d: data){
            int loc= d-'a';

            if(curr->child[loc]==nullptr){
                curr->child[loc]= new Trie();
            }
            curr=curr->child[loc];
        }
        curr->isEnd=true;
    }

    bool find(string data){
        Trie* curr = this;
        for(int i=0;i<data.length();i++){
            char x= data[i];
            int loc = x-'a';
            if (curr->child[loc]==nullptr){
                return false;
            }
            curr= curr->child[loc];
            if(curr->isEnd){
                if(name.find(data.substr(i+1))!=name.end())
                    return true;
            }
        }
        return false;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n;
    cin >> m;   
    Trie* color= new Trie();
    // Trie* name= new Trie();
    string x;
    for(int i=0;i<n;i++){
        cin >> x;
        color->insert(x);
    }
    for(int i=0;i<m;i++){
        cin >> x;
        name.insert(x);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> x;
        bool res1= color->find(x);
        if (res1) {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }

}