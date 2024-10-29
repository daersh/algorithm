#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int,int> pii;
int x_new[8]= {0,0,1,-1,1,1,-1,-1};
int y_new[8]= {1,-1,0,0,-1,1,-1,1};
bool visited[4][4];

struct Trie{
    bool isEnd;
    map<char,Trie*> child;
};
Trie* getNewTrieNode()
{
    Trie *node= new Trie; 
    node->isEnd = false;
    return node;
}
void insert(Trie *& root, const string &str){
    if(root==nullptr) root = getNewTrieNode();
    Trie *temp = root;
    for(int i=0;i<str.length();i++){
        char x = str[i]; 
        if(temp->child.find(x) == temp->child.end()) 
            temp->child[x]= getNewTrieNode();
        temp = temp->child[x]; 
    }
    temp->isEnd = true;
}
void init(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            visited[i][j]=false;
        }
    }
}
map<string, int> result;

void dfs(Trie* node, const string *str, int x, int y,string xx){
    Trie *node2 = node->child[str[x][y]];
    visited[x][y]=true;
    xx += str[x][y];
    if(xx.length()>8) return;
    if(node2->isEnd== true){
        if(result.find(xx)==result.end()){
            result[xx] = xx.length();
        }
    }
    for(int i=0;i<8;i++){
        int xnew=x+x_new[i];
        int ynew=y+y_new[i];
        if(xnew>=0&&ynew>=0&&xnew<4&&ynew<4
                                    && node2->child[str[xnew][ynew]]!=nullptr
                                    &&visited[xnew][ynew]!=true){
            dfs(node2,str,xnew,ynew, xx);
        }
    }
    visited[x][y]=false;
}

void search2(Trie *root, const string *str, int x,int y){
    init();

    Trie *node = root;
    if(node->child[str[x][y]] == nullptr) return;
    
    node= node->child[str[x][y]];
    if(node->isEnd){
        string xxx;
        xxx += str[x][y];
        result[xxx] = 1;
    }
    visited[x][y]=true;

    for(int i=0;i<8;i++){
        int xnew=x+x_new[i];
        int ynew=y+y_new[i];

        if(xnew>=0&&ynew>=0&&xnew<4&&ynew<4
                &&  node->child[str[xnew][ynew]]!=nullptr){
            string xx;
            xx += str[x][y];
            dfs(node,str,xnew,ynew, xx);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n;
    Trie *trie= nullptr;
    string input[n+1];
    for(int i =0 ; i < n; i++){
        cin >>input[i];
        insert(trie,input[i]);
    }
    cin >> m;
    sort(&input[0],&input[n]);
    int scores[9]= {0,0,0,1,1,2,3,5,11};

    for(int i=0; i< m; i++){
        string input2[4];

        for(int j=0;j<4;j++){
            cin >> input2[j];
        }
        result.clear();

        string max_String;
        int score = 0;
        int cnt=0;

        for(int k=0;k<4;k++){
            for(int j=0;j<4;j++){
                search2(trie,input2,k,j);
            }
        }

        for(int j=0; j<n;j++){
            if(result[input[j]]!=0){
                cnt++;
                score+=scores[input[j].length()];
                // if(result[input[j]]==3 || result[input[j]]==4) score+=1;
                // else if(result[input[j]]==5) score+=2;
                // else if(result[input[j]]==6) score+=3; 
                // else if(result[input[j]]==7) score+=5;
                // else if(result[input[j]]==8) score+=11;                
                if(input[j].length()>max_String.length()){ 
                    max_String = input[j];
                }
            }
        }

        cout << score << ' ' << max_String << ' '<< cnt <<'\n';
    }
}

// 3
// ABC
// AB
// A
// 1
// ABCX
// XXXX
// XXXX
// XXXX
