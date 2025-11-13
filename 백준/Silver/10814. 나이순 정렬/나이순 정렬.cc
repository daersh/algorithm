#include <iostream>

#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,string> pii;


int main(){
        int n;
        std::cin >> n;
        map<int, vector<string> > m;
        for(int i=0;i<n;i++){
                int a;
                string b;
                cin >> a >> b;
                m[a].push_back(b);
        }
        for(int i=1; i< 201 ;i++){
                for(int j=0; j< m[i].size(); j++){
                        cout << i << ' ' << m[i][j] << '\n';
                }
        }
}