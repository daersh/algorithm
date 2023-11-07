#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
typedef pair<string,int > pii;

struct Node{
    Node *next[1001]= {NULL};
    vector<string> name;
    priority_queue<pii, vector<pii>, greater<pii> > pque;

    Node(){}
};

struct Trie{
    Node *root;
    Trie(){root= new Node();}
    void insert(string a[], int m){
        Node *current_loc = root;

        for(int i=0;i<m;i++){
            if(current_loc->name.size()==0){
                current_loc->name.push_back(a[i]);
                current_loc->next[0]=new Node();
                current_loc->pque.push(make_pair(a[i],0));
                current_loc= current_loc->next[0];
            }else{
                int tf=false;
                for(int j=0;j<current_loc->name.size(); j++){
                    if(a[i]== current_loc->name[j]){
                        current_loc= current_loc->next[j];
                        tf=true;
                        break;
                    }
                }
                if(tf==false){
                    current_loc->name.push_back(a[i]);
                    current_loc->next[current_loc->name.size()-1]= new Node();
                    current_loc->pque.push(make_pair(a[i],current_loc->name.size()-1));
                    current_loc= current_loc->next[current_loc->name.size()-1];
                }
            }
        }
    }
    void print_str(int cnt){
        Node *curren_loc = root;
        while(!curren_loc->pque.empty()){
            cout << curren_loc->pque.top().first<<'\n';
            print_str(cnt+1,curren_loc->next[curren_loc->pque.top().second]);
            curren_loc->pque.pop();
        }
    }
    void print_str(int cnt, Node *a){
        Node *curren_loc = a;

        while(!curren_loc->pque.empty()){
            for(int j=0;j<cnt;j++){
                cout << "--";
            }
            cout << curren_loc->pque.top().first<<'\n';
            print_str(cnt+1,curren_loc->next[curren_loc->pque.top().second]);
            curren_loc->pque.pop();
        }
    }
    // void print_str(int cnt){
    //     Node *curren_loc = root;
    //     for(int i=0; i<curren_loc->name.size();i++){
    //         cout << curren_loc->name[i] << '\n';
    //         print_str(cnt+1, curren_loc->next[i]);
    //     }
    // }
    // void print_str(int cnt, Node *a){
    //     Node *curren_loc = a;
    //     for(int i=0; i<curren_loc->name.size();i++){
    //         for(int j=0;j<cnt;j++){
    //             cout << "--";
    //         }
    //         cout << curren_loc->name[i] << '\n';
    //         print_str(cnt+1, curren_loc->next[i]);
    //     }
    // }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    Trie trie;
    int m;
    for(int i=0;i<n;i++){
        cin >> m;
        string a[m];
        for(int i=0;i<m;i++){
            cin >> a[i];
        }
        trie.insert(a,m);
    }
    trie.print_str(0);
    return 0;
}