#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> result;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        result.push_back(x);
        pq.push(i+1);
    }

    vector<int> stack;
    string resultStr = "";
    for(int i=0; i< n; i++){
        int curr = result[i];

        if(find(stack.begin(), stack.end(), curr) == stack.end()){
            while(!pq.empty() && pq.top() <= curr){
                resultStr+="+\n";
                int next = pq.top();
                pq.pop();
                stack.push_back(next);
                if(next == curr){
                    resultStr+="-\n";
                    stack.pop_back();
                    break;
                }
            }
        }
        else{
            if(stack.back() == curr){
                stack.pop_back();
                resultStr+="-\n";
            }
            else{
                resultStr="NO";
                break;
            }
        }
    }
    cout << resultStr;

}
