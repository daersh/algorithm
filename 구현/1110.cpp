#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int arr[26]=
        {
            3,3,3, // abc
            4,4,4, // def
            5,5,5, // ghi
            6,6,6, // jkl
            7,7,7, // mno
            8,8,8,8, // pqrs
            9,9,9, // tuv
            10,10,10,10 // wxyz
        };
    
    string str;
    cin >> str;
    int result = 0;
    for(int i=0; i<str.length(); i++){
        result += arr[str[i]-'A'];
    }
    cout << result << endl;
}