#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

struct Node{
    bool isWord=false;
    Node *alphabet[11]={NULL};
    Node(){}
};

struct Trie{
    Node *root;

    Trie(){this->root= new Node();}
    
    bool insert(char *str){
        Node *current_loc = this->root;
        for(int i=0;i<strlen(str);i++){

            if(current_loc->isWord==true) return false;
            if(current_loc->alphabet[str[i]-'0']==NULL){
                current_loc->alphabet[str[i]-'0'] = new Node();
                current_loc= current_loc->alphabet[str[i]-'0'];
            }else {
                current_loc= current_loc->alphabet[str[i]-'0'];
            }
        }

        for(int i=0;i<11;i++){
            if(current_loc->alphabet[i]!=NULL){
                return false;
            }
        }
        current_loc->isWord= true;
        return true;
        
    }

    bool find(char *str){
        Node *current_loc = this->root;

        for(int i=0;i<strlen(str);i++){
            if(current_loc->alphabet[str[i]-'0']==NULL){
                return false;
            }else {
                current_loc= current_loc->alphabet[str[i]-'0'];
            }
        }

        if(current_loc->isWord==false){
            return false;
        }else{
            return true;
        }
    }

};



int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >>T;
    for(int t=0;t<T;t++){

        struct Trie trie;
        int n,result=true;
        cin >>n;
        for(int i=0;i<n;i++){

            char a[15];
            cin >> a;
            if(result==true){
                if(trie.insert(a)==false){
                    result=false;
                }
            }
        }
        if(result) cout << "YES\n";
        else cout << "NO\n";
    }
}