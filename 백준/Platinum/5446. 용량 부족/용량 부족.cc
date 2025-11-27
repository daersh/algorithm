#include <iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

//0 ~25: a~z
//26~51: A~Z
//52: .
//53~62: 1~9
class Trie{
private:
    bool isEnd=false;
    Trie* child[63]={nullptr,};
    bool isStopword=false;
public:
    void sout(int i, int cnt){
        for(int j=0;j<cnt;j++) cout <<" ";

        for(int j=0;j<cnt;j++)
            cout <<" ";
        if(i==52)
            cout <<".\n";
        else if(i>=53){
            cout << i-53<<'\n';
        }
        else if(i>=0 && i<=25){
            char x= i+'a';
            cout << x<<'\n';
        }
        else {
            char x= i-26+'A';
            cout << x<<'\n';
        }
    }
    void insert(string data){
        Trie* curr = this;
        for(char d: data){
            int loc;

            if(d=='.') loc=52;
            else if(d-'0'>=0 && d-'0'<=9) loc= d-'0'+53;
            else if(d>='a' && d<='z') loc= d-'a';
            else  loc= d-'A'+26;

            if(curr->child[loc]==nullptr){
                curr->child[loc]= new Trie();
            }
            curr=curr->child[loc];
        }
        curr->isEnd=true;
    }

    void insert_stopword(string data){
        Trie* curr = this;
        curr->isStopword=true;
        for(char d: data){
            int loc;
            if(d=='.') loc=52;
            else if(d-'0'>=0 && d-'0'<=9) loc= d-'0'+53;
            else if(d>='a' && d<='z') loc= d-'a';
            else  loc= d-'A'+26;

            if(curr->child[loc]==nullptr){
                return;
            }
            curr=curr->child[loc];
            curr->isStopword=true;
        }
    }

    int dfs(Trie* curr, int cnt){
        if(!curr->isStopword)
            return 1;
        
        int total=0;
        if(curr->isEnd) total++;
        for (int i = 0; i < 63; i++){
            if(curr->child[i]==nullptr) continue;
                                            // sout(i, cnt);
            Trie* next = curr->child[i];
            total+= dfs(next , cnt+1);
        }

        return total;
    }

    int find(){
        Trie* curr = this;
        int total = dfs(curr,0);
        return total;
    }

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n;
    for (int t = 0; t < n; t++){
        cin >> m ;   
        Trie* root= new Trie();
        for(int i=0;i<m;i++){
            string x;
            cin >> x;
            root->insert(x);
        }
        cin >> m;
        for(int i=0;i<m;i++){
            string x;
            cin >> x;
            root->insert_stopword(x);
        }

        int total = root->find();
        cout << total<<'\n';
    }

}