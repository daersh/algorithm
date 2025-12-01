#include <iostream>
#include <queue>

using namespace std; 

class Trie{
private:
    Trie* child[26]={nullptr,};
    bool isEnd=false;
    Trie* fail=nullptr;
public:
    void insert(string data){
        Trie* curr = this;
        for(char d: data){
            int loc = d-'a';
            if(curr->child[loc]==nullptr)
                curr->child[loc]=new Trie();
            curr = curr->child[loc];
        }
        curr->isEnd=true;
    }
    void ahocorasick(){
        Trie* root = this;
        queue<Trie*> q;
        for (Trie* trie: root->child){
            if(trie==nullptr) continue;
            trie->fail = root;
            q.push(trie);
        }
        while(!q.empty()){
            Trie* curr = q.front();
            q.pop();
            for(int i=0;i <26;i++){
                Trie* child = curr->child[i];
                if(child==nullptr) continue;

                Trie* next = curr->fail;

                while(next!=root && next->child[i] ==nullptr){
                    next = next->fail;
                }
                if(next->child[i]!=nullptr){
                    next = next->child[i];
                }
                child->fail = next;
                if(child->fail->isEnd)
                    child->isEnd = true;

                q.push(child);
            }
        }
    }

    bool find(string data){
        Trie* curr = this;
        bool flag= false;
        for(char d: data){
            int loc = d-'a';
            while(curr != this && curr->child[loc]==nullptr)
                curr= curr->fail;
            
            if(curr->child[loc]!=nullptr)
                curr= curr->child[loc];

            if(curr->isEnd){
                flag=true;
            }
        }
        return flag;
    }

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    Trie* root = new Trie();
    int n,m;
    cin >> n;
    string x;
    for(int i=0; i< n;i++){
        cin >>x;
        root->insert(x);
    }
    root->ahocorasick();
    cin >> m;
    for(int i=0; i<m;i++){
        cin >> x;
        if(root->find(x)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }


    return 0;
}