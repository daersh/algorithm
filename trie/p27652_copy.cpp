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
    Trie *child[26];
    Trie() :cnt(0){}
};

void insert(Trie *&trie, const string &str){
        Trie *temp = trie;
        int len = str.length();
        for(int i=0;i<len;i++){
            int x = str[i]-'a';
            if(temp->child[x]== nullptr) 
                temp->child[x]= new Trie;
            temp = temp->child[x]; 
            temp->cnt++;
        }
}

void del(Trie *&trie, const string &str){
    Trie *temp = trie;
    int len = str.length();
    for(int i =0 ; i< len;i++){
        int x = str[i]-'a';
        temp=temp->child[x];
        temp->cnt--;
    }
}

int find(Trie *&trie, const string &str){
    Trie *temp = trie;
    int len = str.length();
    for(int i =0 ; i< len;i++){
        int x = str[i]-'a';
        if(temp->child[x]!=nullptr)
            temp=temp->child[x];
        else 
            return 0;
    }
    return temp->cnt;
}

void del2(Trie *&trie, const string &str){
    Trie *temp = trie;
    int len = str.length()-1;
    for(int i =len ; i>=0 ;i--){
        int x = str[i]-'a';
        temp=temp->child[x];
        temp->cnt--;
    }
}

void insert2(Trie *&trie, const string &str){
        Trie *temp = trie;
        int len = str.length()-1;
        for(int i =len ; i>=0 ;i--){
        int x = str[i]-'a';
        if(temp->child[x]== nullptr) 
            temp->child[x]= new Trie;
            temp = temp->child[x]; 
            temp->cnt++;
        }
}

int find2(Trie *&trie, const string &str){
    Trie *temp = trie;
    int len = str.length()-1;
    for(int i =len ; i>=0 ;i--){
        int x = str[i]-'a';
        if(temp->child[x]!=nullptr && temp->child[x]->cnt!=0)
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
    string x, y, z;
    for(int i=0; i<n;i++){
        cin >> x >> y;
        if(x=="add"){
            if(y=="A"){
                cin >> z;
                //문자별로 처리
                insert(trie_x, z);
            }
            else{
                cin >> z;
                //문자별로 처리
                insert2(trie_y, z);
            }
        }

        else if(x=="delete"){
            if(y=="A"){
                cin >> z;
                //문자별로 처리
                del(trie_x, z);
            }
            else {
                cin >> z;
                //문자별로 처리
                del2(trie_y, z);
            }
        }
        else if(x=="find"){
            cnt=0;
            int len = y.length();
            string left, right=y;
            for(int j=1; j< len;j++){
                left.push_back(y[j-1]);
                right.erase(0, 1);
                // reverse(right.begin(),right.end());
                int l = find(trie_x,left);
                if(l!=0){
                    int r = find2(trie_y,right);
                    cnt += l * r;
                }else {                    
                    break;
                }
            }
            cout << cnt<<'\n';
        }
    } 
    delete trie_x;
    delete trie_y;
    return 0;
}