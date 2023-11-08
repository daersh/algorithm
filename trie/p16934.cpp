#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

struct Node{
    Node* child[26]= {NULL};
    int isWord ;
    Node():isWord(0){
        
    }
};

struct Trie{
    Node* root;

    Trie(){ root = new Node();}

    pair<int,int> insert(const char *str){

        Node* loc = root;
        int last_loc=-1;

        for(int i=0;i<strlen(str);i++){
            //만약 다음 노드가 null이라면 새 노드 생성 후 이동
            if(loc->child[str[i]-'a']==NULL)
            {
                if(last_loc==-1){
                    last_loc=i;
                }
                loc->child[str[i]-'a'] = new Node();

                loc= loc->child[str[i]-'a'];
            }else {
                // 다음 노느 null일 경우 바로 이동;
                loc = loc->child[str[i]-'a'];
            }
        }
        if(last_loc==-1){
            last_loc = strlen(str)-1;
        }
        loc->isWord+=1;
        return make_pair(last_loc, loc->isWord);
    }
};


int main(){
    int n;
    scanf("%d",&n);
    Trie trie;
    for(int i=0;i<n;i++){
        char input[10];
        scanf("%s",input);
        pair<int,int> result;

        result= trie.insert(input);

        for(int j=0;j<=result.first;j++){
            printf("%c",input[j]);
        }
        if(result.second!=1){
            printf("%d",result.second);
        }
        printf("\n");
    }
}