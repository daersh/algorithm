#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int result1=-1, result2=-1;
vector<int> vec;
void dp(int cnt, int i, int past){
    if(cnt == n){
        result1 = vec[vec.size()-1];
        result2 = vec[vec.size()-2];
        // for(int j=0;j<vec.size();j++){
        //     cout << vec[j] << " ";
        // }cout<<"\n";
    }else if(cnt > n){
        return;
    }
    int next = past-i;
    if(next<=0)
        return; 
    vec.push_back(i);
    dp(cnt+1, next, i);
}

int main () {
    cin >> n >> m;

    // 6 41 
    vector<int> arr(n + 1, 0);
    for(int i=m-1;i>=1;i--){
        vec.clear();
        dp(1, i, m);

        if(result1 != -1 && result2 != -1){
            cout << result1 << "\n" << result2 << "\n";
            return 0;
        }
    }

}