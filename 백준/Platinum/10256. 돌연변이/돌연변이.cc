#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

class Trie{
private:
    Trie* child[4]={nullptr,};
    bool isEnd= false;
    Trie* fail=nullptr;
    int set_loc(char a){
        if(a=='A') 
            return 0;
        else if(a=='C')
            return 1;
        else if(a=='G')
            return 2;
        return 3;
    }
public:
    ~Trie(){
        for(int i=0; i<4;++i){
            if(child[i]!=nullptr)
                delete child[i];
        }
    }
    void insert(string data){
        Trie* c=this;
        for(char d:data){
            int l = set_loc(d);
            if(c->child[l]==nullptr)
                c->child[l]=new Trie();
            c= c->child[l];
        }
        c->isEnd=true;
    }
    void aho(){
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
            for(int i=0;i <4;i++){
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
    int find(string data){
        Trie* curr= this;
        int flag= false;
        int cnt=0;
        for(char d: data){
            int loc = set_loc(d);
            while(curr != this && curr->child[loc]==nullptr)
                curr= curr->fail;
            
            if(curr->child[loc]!=nullptr)
                curr= curr->child[loc];

            if(curr->isEnd)
                flag++;
        }
        return flag;
    }

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        Trie* root= new Trie();
        set<string> inputs;
        int n,m;
        cin >> n >> m;
        string x,y;
        cin >> x>>y;
        
        for(int i = 0; i < m; i++) {
            for(int j = i; j < m; j++) {
                string str = y;
                reverse(str.begin() + i, str.begin() + j + 1);
                inputs.insert(str);
            }
        }
        for(string input:inputs)
            root->insert(input);
        root->aho();
        int cnt=root->find(x);
        
        cout <<cnt<<'\n';
        delete root;
    }
    
}