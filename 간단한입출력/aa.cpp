#include <string>
#include <vector>
#include <iostream>
using namespace std;


string solution(string s) {
    string answer = "";
    vector<int> vec;
    int booho=1;
    int min = 1e9;
    int max = -1e9;
    
    for(int i=0; i<s.length();i++){
        if(s[i]== ' ')continue;
        else if(s[i]=='-') booho=-1;
        else {

            int x=0;
            while(i<s.length()){
                x += s[i] -'0';

                if(i==s.length()-1 || s[i+1]==' ')
                {
                    break;
                }else if(i < s.length() && s[i+1]>0)
                {
                    x*=10;
                }else if (s[i+1] ==' ' || i < s.length())
                {
                    break;
                }
                i++;
            }

            x*=booho;
            booho=1;
            vec.push_back(x);
        }

    }
    // for(int i=0; i< vec.size();i++){
    //    cout << vec[i] <<' ';
    // }cout << '\n';
    sort(vec.begin(),vec.end());
    answer+= to_string(vec[0]);
    answer+= ' ';
    answer+= to_string(vec.back());
   
    return answer;
}

int main (){

        string s= "1 2 3 4 2 10 -99";
        cout << solution(s);

    
}
