#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef pair<int,int> pii;

int solution(vector<int> v, int location) {
    int answer = 0;
    queue<pii> q;
    map<int,int> m;
    int max = 0;
    vector<int> vec;
    
    for(int i =0 ; i < v.size() ; i++){
        q.push(make_pair(v[i], i));
        if(v[i] > max )
            max = v[i];
        m[v[i]]++;
    }
    
    while(!q.empty()){
        int x = q.size();
        for(int i =0; i < x; i++){
            int y = q.front().first;
            int z = q.front().second;
            
            q.pop();
            
            // priority check
            if(y == max){
                // when found location 
                if(z == location){
                    return vec.size()+1;
                }
                m[max]--;
                // save to result
                vec.push_back(z);
                // when map[max] == 0 -> change max
                if(m[max]==0){
                    for(int j=max-1; j>0;j--){
                        if(m[j]!=0){
                            max = j;
                            break;
                        }
                    }
                }
                
            }else {
                q.push(make_pair(y,z));
            }
        }
    }
    
    answer = vec.size();
    return answer;
}