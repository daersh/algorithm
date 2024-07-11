#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string letter) {
    string arr[27] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string answer = "";
    map<string,string> mapp;
    for(int i=0; i< 27; i++){
        mapp[arr[i]] = (97+i);
    }
    string x;
    for(int i=0;i<letter.length();i++){
        if(letter[i]!=' '){
            x+=letter[i];
            continue;
        }
        answer += mapp[x];
        x="";
    }
        answer += mapp[x];
    
    return answer;
}