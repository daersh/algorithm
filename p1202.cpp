#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int n , k;
vector<pii> vec;
int maximum=0;

int dp(int loc, long long sum_kg, long long sum_value){
    
    
}

int main(){
    cin >> n >> k;
    for(int i=0; i< n; i++){
        int a,b;
        // 무게 / 가격
        cin >> a>>b;
        vec.push_back(make_pair(a,b));
    }
    cin >> maximum;

}