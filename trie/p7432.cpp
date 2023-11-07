#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

struct Node{
    priority_queue<pii,vector<pii>, greater<pii> > child;
    bool isend=false;
    Node(): isend(false){}
};

struct Trie{
    Node* root;
    Trie(){root= new Node();}

    void insert(){

    }
    void find(){

    }
};

int main(){
    Trie trie;
    int n;
    cin >> n;
    char *arr[n];
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        for(int j=0;j<x.size();j++){
            
        }
    }
}