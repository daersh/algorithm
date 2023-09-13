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


int N;
int M;
int arr[100];
int arr2[1000];
int result= 10000000;
int visited[100];
int val;
int mx = -10000000;
int xx;
vector<int> vec;
int cmp;
void dfs(int x, int count){

    //printf("    [%d]       val: %d      count: %d\n",x,val, count);
    
    //debug(val, count);

    if(count==N){
        for(int i=0;i<N-1;i++){
            cmp= arr[vec[i]]-arr[vec[i+1]];
                if(cmp<0){
                    cmp = -1* cmp;
            }
            val+=cmp;
            
        }
        //debug(vec);

        if(val>mx){
            mx=val;
        }
        //debug(val);
        val=0;
        return;
    }


    for(int i=1;i<=N;i++){

        if(visited[i]==false){
            visited[i]=true;

            /*
            if(count%2==1 ){
                xx=-arr[i];
            }else{
                xx=arr[i];
            }
            if(x<0){
                xx= -xx;
            }
            */

            //val+=arr[i];
            vec.push_back(i);
            dfs(i, count+1);
            vec.pop_back();
                
            visited[i]=false;                                   
            

        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N ;
    int i,j;
    int cnt = 1;
    for(i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    
    dfs(0,0);
    
    cout << mx;
    return 0;
}