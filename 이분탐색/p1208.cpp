#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
int arr[41];
long long cnt;
map<int,int> result;
// 모든 경우의 수를 반반 나누어 더함.
void left(int loc, int sum){
    //끝에 도달하면 종료
    if(loc== n/2){
        result[sum]++;
        return;
    }
    //다음위치
    left(loc+1,sum);
    //현재위치+다음위치
    left(loc+1,sum+arr[loc]);
}
void right(int loc, int sum){
    if(loc==n){
        //끝에 도달하면 종료
        cnt+= result[m-sum];
        return;
    }
    right(loc+1,sum);
    right(loc+1,sum+arr[loc]);
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];      
    }
    left(0,0);
    right(n/2,0);
    if(m==0) cnt--;
    cout << cnt;
}