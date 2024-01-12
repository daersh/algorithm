#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Node{
    Node *child[26];
    int branch;
    int words;
    bool isWord;
    Node(): branch(0), words(0), isWord(false) {
        fill(child, child + 26, nullptr);
    }
    ~Node(){
        for(int i = 0; i < 26; i++) {
            if(child[i]) {
                delete child[i];
            }
        }
    }
};

struct Trie{
    Node *root;
    Trie(){root = new Node;}
    ~Trie(){
        delete root;
    }

    void insert(const char *str){
        Node *loc = root;
        for(int i=0;i<strlen(str);i++){
            if(!loc->child[str[i]-'a']){
                loc->child[str[i]-'a'] = new Node;
                loc->branch++;
            }
            loc->words++;
            loc= loc->child[str[i]-'a'];
        }
        loc->isWord=true;
    }

    
    int sol(Node *loc, bool isRoot = false) {
        int cnt = 0;
        // cout << "branch= "<<loc->branch << "\n";
        // cout << "words= "<<loc->words << "\n";
        if(isRoot || loc->branch > 1 || loc->isWord) cnt += loc->words;     

        for(int i=0;i<26;i++)
        {
            if(loc->child[i])
            {
                //cout << "current loc="<< (char)(i+'a')<<'\n';
                cnt+=sol(loc->child[i]);
            }
        }

        return cnt;
    }

};

int main(){
    int n;
    while(scanf("%d", &n) > 0){
        Trie *trie = new Trie;
        char a[n][82];
        for(int i=0;i<n;i++){
            scanf("%s", a[i]);
            char* tmp = a[i];
            trie->insert(tmp);
        }
        int cnt= trie->sol(trie->root, true);
        printf("%.2lf\n",1.0*cnt/n);      
        delete trie;  
        //if(cin.eof()) break;
    }

}