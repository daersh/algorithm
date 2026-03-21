#include <bits/stdc++.h>>

using namespace std;

int main() {

  string line;

  while (1) {
    vector<int> vec;
    bool correct = true;

    getline(cin, line);
    if (line.length() == 1 && line[0] == '.')
      break;

    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '(')
        vec.push_back(1);
      else if (line[i] == '[')
        vec.push_back(2);
        
      else if(vec.empty()==false ){
        if (vec.back() == 1 && line[i] == ')') vec.pop_back();
        else if (vec.back() == 2 && line[i] == ']') vec.pop_back();  
        else if (vec.back() != 1 && line[i] == ')') {correct = false; break;} 
        else if (vec.back() != 2 && line[i] == ']') {correct = false; break;}
      }
      else if (vec.size() == 0 && line[i] == ')') {
        correct = false;
        break;
      } else if (vec.size() == 0 && line[i] == ']') {
        correct = false;
        break;
      }
        
    }
    
    if (correct == false )
      cout << "no" << '\n';
    else if (vec.size() == 0 ) {
      cout << "yes" << '\n';
    } else {
      cout << "no" << '\n';
    }
    
  }
}