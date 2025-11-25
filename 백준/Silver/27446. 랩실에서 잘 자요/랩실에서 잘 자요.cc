#include <iostream>

using namespace std;

int n;
int m;
int arr[101]={0};

int main(){
    cin >> n >> m;
    int x; 
    for(int i=0;i<m;i++){
        cin >> x;
        arr[x]=1;
    }
    int sum=0;
    int cnt=0;
    for(int i=1; i<=n;i++){
        if(arr[i]){
            if(cnt==0) continue;
            if(i<n && !arr[i+1]){
                cnt++;
                continue;
            }else if(i<n-1 && !arr[i+2]){
                cnt++;
                continue;
            }
            sum+= 5+ 2*cnt;
            cnt=0;
            continue;
        }
        cnt++;
        if(i==n){
            sum += 5+ 2*cnt;
        }
    }
    cout << sum;
}