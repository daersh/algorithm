#include <iostream>
#include <queue>
#include <string>
#include <limits> 

using namespace std;

char emo[23]={'!','?','.',':',';','-','_','\'','#','$','%','&','/','=','*','+','(',')','{','}','[',']',','};
// a~z : 0~25 
// A~Z : 26~51
// 0~9 : 52~61
// emo : 62~84
class Trie{
private:
    bool isEnd=false;
    Trie* child[85]= {nullptr,};
    Trie* fail=nullptr;
    
    int get_loc(char c){

        if(c-'a'>=0 && c-'a'<=25){
            return c-'a';
        }else if(c-'A'>=0 && c-'A'<=25){
            return c-'A'+26;
        }else if(c-'0'>=0 && c-'0'<=9){
            return c-'0'+52;
        }else {
            for(int i=0; i< 23;i++){
                if(emo[i]==c)
                   return 62+i;
            }
        }
        return -1;
    }
    
public:
    ~Trie(){
        for(Trie* c:child)
            if(c!=nullptr)
                delete c;
    }
    void insert(string s){
        Trie* curr= this;
        for(char c:s){
            int l = get_loc(c);
            if(l == -1) continue; 
            
            if(curr->child[l]==nullptr)
                curr->child[l]=new Trie();
            curr= curr->child[l];
        }
        curr->isEnd=s.length();
    }

    void aho(){
        Trie* root= this;
        queue<Trie*> q;
        
        for(int i=0; i<85;i++){ 
            Trie* t = root->child[i];
            if(t==nullptr) continue;
            t->fail=root; 
            q.push(t);
        }
        
        while (!q.empty()){
            Trie* curr = q.front();
            q.pop();

            for(int i=0; i<85;i++){ 
                Trie* next= curr->child[i];
                if(next==nullptr) continue;
                Trie* f = curr->fail;
                
                while (f!=root && f->child[i]==nullptr)
                    f= f->fail;
                
                if(f->child[i]!=nullptr){
                    next->fail = f->child[i];
                } else {
                    next->fail = root; 
                }
                
                if(next->fail->isEnd)
                    next->isEnd = true;
                    
                q.push(next);
            }
        }
    }
    
    int find(string s){
        Trie* curr= this;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            int l= get_loc(c);
            if(l==-1){
                curr= this;
                continue; 
            }
            while(curr != this && curr->child[l]==nullptr)
                curr= curr->fail;
            if(curr->child[l]!=nullptr)
                curr= curr->child[l];
            if(curr->isEnd){
                cnt++;
                curr=this;
            }
        }
        return cnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    
    int n,m;
    string x;
    while(true){
        cin >> n >> m;
        if(n==0&&m==0)
        return 0;
        
        
        Trie* root= new Trie();
        int cnt=0;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int i=0; i< n;i++){
            getline(cin,x);
            root->insert(x);
        }
        
        root->aho();
        
        for(int i=0; i< m;i++){
            getline(cin,x);
            cnt+=root->find(x);
        }
        cout << cnt <<'\n';
        delete root;
    }
    return 0;
}