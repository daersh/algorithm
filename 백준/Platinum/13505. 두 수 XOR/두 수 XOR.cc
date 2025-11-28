#include <iostream>

using namespace std;

long long result=0;

class Trie{
private:
    Trie* child[2]={nullptr,};
public:
    void insert(long long v){
        Trie* curr= this;
        for(int i=40;i>=0;i--){
            int vv = (v>>i) &1;
            if(curr->child[vv]==nullptr)
                curr->child[vv]= new Trie();
            curr= curr->child[vv];
        }
    }

    void find(long long v){
        Trie* curr= this;
        long long res=0;
        for(int i=40;i>=0;i--){
            int vv = v>>i & 1;
            if(curr->child[!vv]!=nullptr){
                curr= curr->child[!vv];
                res += (1LL<<i);
                continue;
            }
            curr=curr->child[vv];
        }
        // cout << res<<'\n';
        result = max(res,result);
    }

};

int main(){
    int n;
    cin >> n;
    long long arr[n];
    Trie* root= new Trie();
    for(int i=0;i<n;i++){
        cin >> arr[i];
        root->insert(arr[i]);
    }
    for(int i=0;i<n;i++){
        root->find(arr[i]);
    }
    cout << result;
}