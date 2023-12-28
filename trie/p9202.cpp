#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

struct Node{
    Node* childs[26]= {NULL};

    bool isWord;
    Node():isWord(false){}
};

int x_new[8] = {1,-1,0,0, 1, 1, -1,-1};
int y_new[8] = {0,0,1,-1, 1, -1, 1, -1};
string max_string;
int score;
int word_cnt;
struct Trie{
    Node *root;
    bool visited[4][4];
    Trie(){root=new Node;}
    ~Trie(){}

    void init(){
        for(int i=0; i<4; i++)
            fill(&visited[i][0],&visited[i][4],false);
    }

    void insert(string input){
        Node *node = root;
        for(int i=0; i < input.length();i++){
            if(node->childs[input[i]-'A']==NULL){
                node->childs[input[i]-'A'] = new Node;
                node = node->childs[input[i]-'A'];
            }else {
                node = node->childs[input[i]-'A'];
            }
            if(i==input.length()-1){
                node->isWord= true;
            }
        }
    }
    
    void find(string *prob){
        int x=0,y=0;
        max_string="";
        score=0;
        word_cnt=0;
        for(int i=0; i<4;i++){
            for(int j=0; j < 4; j++){
                Node *node = root;
                string data;
                x= i;
                y= j;
                data+=prob[x][y];
                cout <<"["<< x <<"," <<y<<"]\n";
                if( node->childs[prob[x][y]-'A']==NULL) continue;
                else node= node->childs[prob[x][y]-'A'];
                
                init();
                dfs(node,x,y,1,prob,data);

                cout << '\n';
            }
        }
        cout<<score<<' '<< max_string<<' '<<word_cnt<<'\n';
    }

    void dfs(Node *node,int x,int y,int cnt,string *prob,string data){
        Node *past_node= node;
        if(visited[x][y]==true) {
            data.pop_back();
            return;
        }
        visited[x][y]=true;
        for(int i=1; i<cnt;i++){
            cout << ' ';
        }
        cout << prob[x][y]<<'\n';
        if(node->isWord==true){
            cout << data;
            cout << " found\n";
            word_cnt++;
            if(data.length()>max_string.length()) max_string=data;
            if(cnt==3 || cnt==4) score+=1;
            else if(cnt==5) score+=2;
            else if(cnt==6) score+=3;
            else if(cnt==7) score+=5;
            else if(cnt==8) score+=11;
            data.pop_back();
            visited[x][y]=false;
            return;
        }

        if(cnt!=9){
        for(int k=0;k<8;k++){
                    int next_x= x+x_new[k];
                    int next_y= y+y_new[k];
                    if(next_x>=0&&next_y>=0&&next_x<4&&next_y<4
                                        && visited[next_x][next_y]==false){
                        if(node->childs[prob[next_x][next_y]-'A']!=NULL){
                            data+=prob[next_x][next_y];
                            node=node->childs[prob[next_x][next_y]-'A'];
                            dfs(node,next_x,next_y,cnt+1,prob,data);
                            node= past_node;
                        }
                    }
                }
        }
        data.pop_back();
        visited[x][y]=false;
    }
};



int main(){
    int n;
    cin >> n;
    Trie trie;
    string input[n];
    for(int i =0 ; i < n; i++){
        cin >>input[i];
        trie.insert(input[i]);
    }

    int m;
    cin >> m;
    string prob[4];
    int score;
    string longWord;
    int cnt;
    for(int i=0; i< m; i++ ){
        for(int j = 0; j < 4; j ++){
            cin >> prob[j];
        }
        trie.find(prob);
    }

}