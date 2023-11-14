#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;


struct Node{
    Node* child[26]= {NULL};
    bool isWord;
    Node(): isWord(false){}
};

int score, sum; 

struct Trie{
    Node *root;
    Trie() {root = new Node();}

    //노드 삽입 과정 
    void insert(const char *str){
        Node * loc = root;
        for(int i=0;i<strlen(str);i++){
            if(loc->child[str[i]-'A'==NULL]){
                loc->child[str[i]-'A'] = new Node();
                loc = loc->child[str[i]-'A'];
            }else {
                loc = loc->child[str[i]-'A'];
            }
        }
    }

    void find(const char str[4][4]){
        //bfs 방문 처리, backtracking도 필요할듯 -> O
        int visited[4][4]= {0};
        
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if( root->child[str[i][j] -'A'] != NULL){
                    Node * loc = root;
                    queue<pii> q;
                    int cnt;
                    q.push( make_pair(i,j) );
                    

                    while(!q.empty()){
                        int x = i, y= j;
                        q.pop();
                        int x_new[8]={-1,0,1,
                                      -1,  1,
                                      -1,0,1};
                        int y_new[8]={-1,-1,-1,
                                       0,  0,
                                       1,1,1};

                        for(int i=0;i<8;i++){
                            int xnew= x+ x_new[i];
                            int ynew= y+ y_new[i];
                            if(xnew>=0 && xnew<4 && ynew>=0 && ynew<4 ){
                                if(loc->child[str[xnew][ynew]- 'A']!=NULL){
                                    cnt++;
                                    loc= loc->child[str[xnew][ynew]- 'A'];
                                }else {
                                    continue;
                                }
                            }
                            if(loc->isWord==true){
                                cnt++;
                            }
                        }

                    }
                    cout << "cnt = "<< cnt;
                }
            }
        }
    }
};

int main(){


    int n;
    scanf("%d",&n);
    Trie trie;
    for(int i=0;i<n;i++){
        char input[8];
        scanf("%s",input);
        trie.insert(input);

    }
    int m;
    scanf("%d",&m);

    //1,2 : 0 
    //3,4 : 1
    //5   : 2
    //6   : 3
    //7   : 5
    //8   : 11
    //bfs가 나으려나.......
    
    for(int t=0;t<m;t++){
        char arr[4][4]={NULL};
        for(int i=0;i<4;i++){
            scanf("%s",arr[t]);
        }  
        trie.find(arr);

    }
}