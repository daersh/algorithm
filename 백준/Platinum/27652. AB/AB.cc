#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int n;

class TRIE{
private:
    TRIE* child[26] = { nullptr, };
    bool isEnd=false;
    int cnt=0;
public:
    TRIE(){}
    void insert(string data){
        TRIE* next = this;
        for(char a: data){
            int loc = a-'a';
            if(next->child[loc]==nullptr){
                next->child[loc] = new TRIE();
            }
            next=next->child[loc];
            next->cnt++;
        }
        next->isEnd=true;
    }

    void erase(string data){
        TRIE* next =this;
        for(char a: data){
            int loc= a-'a';
            if(next->child[loc]==nullptr || next->child[loc]->cnt <= 0) 
                return;
            next=next->child[loc];
            next->cnt--;
        }
        next->isEnd=false;
    }

    int find(string data, vector<long long>& vec){
        TRIE* next = this;
        bool flag = true;
        int vec_loc=0;
        for(char a: data){
            int loc = a-'a';
            if(next->child[loc]==nullptr || next->child[loc]->cnt<=0){
                return 0;
            }
            next = next->child[loc];
            vec[vec_loc++]=next->cnt;

            // cout << a<<":"<< next->cnt<<'\n';
        }
        return next->cnt;
    }
};

TRIE* A= new TRIE();
TRIE* B= new TRIE();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string action;
    char who;
    string data;
    
    for(int i=0;i<n;i++){
        cin >> action;
        if(action=="add"){
            cin >> who >> data;
            if(who=='A')
                A->insert(data);
            else if(who=='B'){
                reverse(data.begin(),data.end());
                B->insert(data);
            }
        }else if(action=="delete"){
            cin >> who >> data;
            if(who=='A')
                A->erase(data);
            else if(who=='B'){
                reverse(data.begin(),data.end());
                B->erase(data);
            }
        }else if(action=="find"){
            cin >> data;
            long long found=0;
            //for(int i=1; i< data.length();i++){
            string front=data;
            string back= data;
            vector<long long> front_vec(data.length(),0);
            vector<long long> back_vec(data.length(),0);
            A->find(front, front_vec);
            reverse(back.begin(),back.end());
            B->find(back,back_vec);
            for(int i=1;i< data.length();i++){
                found += front_vec[i-1]*back_vec[data.length()-i-1];
            }
            //if(front_flag && back_flag)
                // found+=front_flag*back_flag;
            //}
            cout << found<<'\n';
        }
    }
    
}