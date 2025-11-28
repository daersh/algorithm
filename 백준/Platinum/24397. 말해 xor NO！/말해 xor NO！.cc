#include <iostream>

using namespace std;
//2 4 8 16 32 64 ..1024 10
//2048 4092 8184 16368 32736 66~ 120000 17 
// 
class Trie{
private: 
    Trie* child[2]={nullptr,};
    long long cnt=0;
public:
    void insert(int input){
        Trie* curr = this;
        
        for(int i=30; i>=0;i--){
            int loc= (input>>i) & 1;

            if(curr->child[loc]==nullptr)
                curr->child[loc] = new Trie();
            curr=curr->child[loc];
            curr->cnt++;
        }
    }

    long long find(int v, int age){
        Trie* curr = this;
        long long total=0;
        int loc=30;
        while(loc>=0){
            
            int b_v = (v >> loc) & 1;
            int b_a = (age >> loc) & 1;
            if(curr==nullptr) break;;

            if(b_a==0){
                curr = curr->child[b_v];
            }else if(b_a==1){
                // age bit 1이면 더 작으려면 같은방향은 모두 작음
                if(curr->child[b_v] !=nullptr)
                    total+= curr->child[b_v]->cnt;
                // 반대 검사 
                curr= curr->child[!b_v];
            }

            loc--;
        }
        

        return total;
    }

};

int main(){
    int n, m, age;
    cin >> n >> m >> age;

    int x;
    Trie* root= new Trie();
    long long cnt=0;
    for(int i=0; i<n;i++){
        cin >>x;
        root->insert(x);
    }
    // cout << '\n';
    for(int i=0; i<m;i++){
        cin >> x;
        cnt+=root->find(x,age);
    }

    cout << cnt;

}
