#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int k;
int arr[20];
int visited[20];
int arr2[300000000];

vector<int> check;
//val: 접근한 위치
int val;
//num: 추 총 합
int num;
int cnt;

void dfs(int x){
    
    if(val>num){
        return;
    }

    for(int i=x+1;i<=k;i++){

        visited[arr[i]]=true;
        val+=arr[i];

        check.push_back(val);

        for(int j=0;j<=k;j++){
            if(visited[ arr[j] ] ==false){

                for(int a=0;a<check.size();a++){
                    if(val-arr[j]==check[a] && val-arr[j]>0){
                        continue;
                    }
                    check.push_back(val-arr[j]);
                }
            }

            debug(check);
        }

        dfs(i);
        visited[arr[i]]=false;
        val-=arr[i];

    }

}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> k;
    int i;
    //num: 추 무게 합
    int maxi=0;
    for(i=1;i<=k;i++){
        cin >> arr[i];
        num+=arr[i];
    }

    dfs(0);
    cout << num-check.size();

    return 0;
}