#include <iostream>
#include <vector>

using namespace std;


//접두사 접미사 처리 함수
vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize,0);
    int j=0;

    for(int i=1;i<patternSize;i++)
    { 
        while (j>0 && pattern[i]!=pattern[j])
        {
            j = table[j-1];
        }
        if(pattern[i]==pattern[j])
        {
            table[i]= ++j;
        }        
    }
    return table;
}

void KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for(int i=0; i< parentSize;i++){
        while (j>0 && parent[i]!= pattern[j])
        {
            j= table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j==patternSize-1){
                cout << i-patternSize+2 << " found! \n";
                j = table[j];
            }
            else{
                j++;
            }
        }
    }
}

int main(){
    //string parent = "ababacabacaabacaaba";
    //string pattern = "abacaaba";
    string pattern;
    cin >> pattern;
    int max_len = 0;
    for(int j=0;j<pattern.length();j++){
        
        vector<int> table = makeTable(pattern);
        //KMP(parent,pattern);
        // for(int i=0; i< table.size();i++){
        //     cout << table[i] << ' ';
        // }
        
        for(int i= 0 ; i < table.size();i++){
            if(table[i]>max_len) max_len= table[i];
        }
        }
    if(max_len<=1){
        cout << "0\n";
    }else {
        cout << max_len<<'\n';
    }
    return 0;
}