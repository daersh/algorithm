#include<iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

class Node
{
    //Node 26개의 알파벳 배열을 가지고 있음
    //isword를 통해 검색 시 해당 노드까지 도착한 곳이 저장된 문자인지 확인
public:
        Node *childs[26] = { NULL };
        bool isWord = false;


        //매개변수가 없는 생성자를 선언하기 위한 의미
        Node(){}
        //아래는 매개변수가 있는 생성자로 선언할 때
        //Node(String name, int a){}
};

class Trie
{
public:
    //루트 노드 생성
    Node *root;

    //루트에 새로운 노드 생성하게함
    Trie(){ this->root = new Node();}

    //삽입과정
    
    void insert(const char *str)
    {
        Node *current_loc = this->root;

        for(int i=0;i<strlen(str);i++)
        {
            if(current_loc->childs[str[i]-'a']!=NULL)
            {
                current_loc= current_loc->childs[str[i]-'a'];
            }
            else{
                current_loc->childs[str[i]-'a']=new Node();
                current_loc = current_loc->childs[str[i]-'a'];
            }
        }
        current_loc->isWord=true;
    }

    //찾는과정
    // cur로 루트를 가리키게 한 후 루트>다음문자열이 null이 아니면 cur=자식으로이동하면서
    // 마지막에 위치한 cur에서 isword가 true인지 확인하여 단어가 있는지 확인
    bool find(const char *str)
    {
        Node *current_loc = this->root;

        for(int i=0;i<strlen(str);i++)
        {
            if(current_loc->childs[str[i]-'a']==NULL) return false;
            else current_loc = current_loc->childs[str[i]-'a'];
        }
        if(current_loc->isWord) return true;
        else return false;
    }
    

};


int main(){
    Trie trie;

    trie.insert("tree");

    cout << trie.find("tree") << '\n';
    cout << trie.find("tre") << '\n';
    return 0;
}