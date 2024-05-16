#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> vec, vector<string> vec2) {
    string answer = "";
    map<string, int> map; 
    while(!vec2.empty()){
        string v= vec2.back();
        vec2.pop_back();
        map[v] ++;
    }
    
    while(!vec.empty()){
        string v = vec.back();
        vec.pop_back();
        if(map[v]==0 ){
            return v;
        }
        map[v]--;
    }
    
    return answer;
}