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

int arr[330][330];
int arr2[330][330];

int insert=-10000000;
int result;
void printarr(){
    int i,j;
    for(i=1;i<=N;i++){
        
        for(j=1;j<=N;j++){
            cout << arr[i][j]<< ' ';

        }
        cout << '\n';
    }

}

void printarr2(){
    int i,j;
    for(i=1;i<=N;i++){
        
        for(j=1;j<=N;j++){
            cout << arr2[i][j]<< ' ';

        }
        cout << '\n';
    }

}

void ddddd(int x){
    int i,j;
    //cout << x << "일 경우   \n";

    for(i=x;i<=N;i++){
        
        for(j=x;j<=N;j++){

            arr2[i][j] = arr[i][j]-arr[i-x][j] - arr[i][j-x] + arr[i-x][j-x];
            //최대값 비교
            if(result<arr2[i][j]){
                result=arr2[i][j];
            }
        }
    }
    //printarr2();
    
    if(x<N){
        x++;
        ddddd(x);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N;
    int i,j,x;
    int loc_x,loc_y;

    for(i=1;i<=N;i++){
        
        for(j=1;j<=N;j++){
            cin >> x;
            //자기위치 + 왼쪽 + 위 - 왼위= 현재 위치까지의 합
            arr[i][j]= x+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            if(arr[i][j]>insert){
                insert=arr[i][j];
                loc_x=j;
                loc_y=i;
            }
        }
    }
    //printarr();

    int z;
    if(loc_x<loc_y){
        z=loc_x;
    }else{
        z=loc_y;
    }
    
    //printf("가장 큰 위치: [%d,%d]\n",loc_y,loc_x);
    if(loc_x==1 && loc_y==1){
        cout << insert;
        return 0;
    }
    for(i=1;i<=z;i++){
        int cmp = insert - arr[loc_y-i][loc_x]- arr[loc_y][loc_x-i] +arr[loc_y-i][loc_x-i];

        if(cmp>result){
            result=cmp;
        }
    }    
    ddddd(0);
        cout << result;

}
