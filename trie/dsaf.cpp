#include<iostream>
#include<string>

using namespace std;

class Node{
    public:
    Node *child[26]={NULL};
    bool isWord=false;
    Node(){}
};

class Trie{
    public:
    Node *root;
    Trie(){this->root= new Node();}

    void insert(const char *str){
        Node *current_loc = root;
        for(int i=0;i<strlen(str);i++){
            if(current_loc->child[str[i]-'a']==NULL){
                current_loc->child[str[i]-'a']= new Node();
                current_loc= current_loc->child[str[i]-'a'];
            }else {
                current_loc= current_loc->child[str[i]-'a'];
            }
        }
        current_loc->isWord=true;
    }
    bool find(const char *str){
        Node *current_loc = root;
        for(int i=0;i<strlen(str);i++){
            if(current_loc->child[str[i]-'a']==NULL) return false;
            else current_loc= current_loc->child[str[i]-'a'];
        }

        if(current_loc->isWord==false) return false;
        else return true;
    }
};

int main(){
    Trie trie;
    trie.insert("asdf");
    trie.insert("a");
    trie.insert("bcd");

    cout << trie.find("asdf")<<'\n';
    cout << trie.find("a")<<'\n';
    cout << trie.find("bcd")<<'\n';
    cout << trie.find("bc")<<'\n';
    

}