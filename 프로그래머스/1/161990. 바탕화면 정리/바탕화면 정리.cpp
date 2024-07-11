#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int a=1e9,b=1e9,c=0,d=0;            
    for(int i=0; i < wallpaper.size();i++){
        for(int j=0; j < wallpaper[i].length();j++){
            if(wallpaper[i][j]=='#'){
                a = a>i ? i : a;
                b = b>j ? j : b;
                c = c<i ? i : c;
                d = d<j ? j : d;
            }
        }
    }
    c = c<=0 ? a : c;
    d = d<=0 ? b : d;
    c++;
    d++;
    answer.push_back(a);
    answer.push_back(b);
    answer.push_back(c);
    answer.push_back(d);
    return answer;
}