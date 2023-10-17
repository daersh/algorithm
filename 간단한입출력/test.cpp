#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> k{5, 8, 11, 11, 11, 11, 12, 43, 111, 13214};
    auto lower = upper_bound(k.begin(),k.end(),10)-k.begin();
    cout << lower <<"\n";

}