#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Node{
public:
    Node *child[26]={NULL};
    bool isWord = false;
    
    Node(){}
};

class Trie{
public:
    Node *root;
    
    Trie(){root= new Node();}

    void insert(const char *str){
        Node *current_loc = root;
        for(int i=0;i<strlen(str);i++){
            if(current_loc->child[str[i]-'a']==NULL){
                current_loc->child[str[i]-'a']= new Node();
                current_loc=current_loc->child[str[i]-'a'];
            }else {
                current_loc=current_loc->child[str[i]-'a'];
            }
        }
        current_loc->isWord=true;
    }
    bool find(const char *str){
        Node *current_loc = root;
        for(int i=0;i<strlen(str);i++){
            if(current_loc->child[str[i]-'a']==NULL){
                return false;
            }else {
                current_loc=current_loc->child[str[i]-'a'];
            }
        }
        if(current_loc->isWord==true){
            return true;
        }else return false;

    }

};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    Trie trie;
    cin >> n >>m;
    int cnt=0;
    for(int i=0;i<n;i++){
        char str[510];
        cin >>str;
        trie.insert(str);
    }

    for(int i=0;i<m;i++){
        char str[510];
        cin >>str;
        if(trie.find(str)==true) cnt++;
    }
    cout <<cnt;
}