#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstring>

using namespace std;

struct Trie{
    int cnt;
    unordered_map<char,Trie*> child; 
    Trie() : cnt(0){}
};

unordered_map<string,Trie*> child; 


void insert(Trie *&trie, const string &str){
        Trie *temp = trie;
        int len = str.length();
        char x;
        for(int i=0;i<len;i++){
            x = str[i]; 
            if(temp->child[x]== nullptr) 
                temp->child[x]= new Trie;
            temp = temp->child[x]; 
            temp->cnt++;
        }
}

void del(Trie *&trie, const string &str){
    Trie *temp = trie;
    int len = str.length();
    char x;
    for(int i =0; i< len;i++){
        x = str[i];
        temp=temp->child[x];
        temp->cnt--;
    }
}

int find(Trie *&trie, const string &str){
    Trie *temp = trie;
    int len = str.length();
    char x;
    for(int i =0 ; i< len;i++){
        x = str[i];
        if(temp->child[x]!=nullptr && temp->child[x]->cnt>0)
            temp=temp->child[x];
        else 
            return 0;
    }
    return temp->cnt;
}

void del2(Trie *&trie, const string &str){
    Trie *temp = trie;
    int len = str.length()-1;
    char x;
    for(int i =len ; i>=0 ;i--){
        x = str[i];
        temp=temp->child[x];
        temp->cnt--;
    }
}

void insert2(Trie *&trie, const string &str){
        Trie *temp = trie;
        int len = str.length()-1;
        char x;
        for(int i =len ; i>=0 ;i--){
        x = str[i]; 
        if(temp->child[x]== nullptr) 
            temp->child[x]= new Trie;
            temp = temp->child[x]; 
            temp->cnt++;
        }
}

int find2(Trie *&trie, const string &str){
    Trie *temp = trie;
    int len = str.length()-1;
    char x;
    for(int i =len ; i>=0 ;i--){
        x = str[i];
        if(temp->child[x]!=nullptr && temp->child[x]->cnt>0)
            temp=temp->child[x];
        else 
            return 0;
    }
    return temp->cnt;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Trie *trie_x= new Trie;
    Trie *trie_y = new Trie;

    int n;
    int cnt=0;
    cin >> n;
    for(int i=0; i<n;i++){
        string x, y, z;
        cin >> x >> y;
        if(x=="add"){
            if(y=="A"){
                cin >> z;
                insert(trie_x, z);
            }
            else{
                cin >> z;
                insert2(trie_y, z);
            }
        }

        else if(x=="delete"){
            if(y=="A"){
                cin >> z;
                del(trie_x, z);
            }
            else {
                cin >> z;
                del2(trie_y, z);
            }
        }

        else if(x=="find"){
            cnt=0;
            int len = y.length();
            string left,right;
            int l;
            int found=0;
            for(int j=1; j< len;j++){
                left= y.substr(0,j);
                right= y.substr(j);
                l = find(trie_x,left);
                if(l==0)break;
                found = find2(trie_y,right);
                cnt += l * found;
            }
            cout << cnt<<'\n';
        }
    }  
}

/*
abcba
a bcba
ab cba 
*/