#include <bits/stdc++.h>

using namespace std;
int N,M;

long long result;
int arr[101000];
int arr2[101000];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    

    for(int i=1;i<=N;i++){
        cin >> arr[i];
        arr2[i]= arr2[i-1]+arr[i];
    }
    int x, y;
    int count=0;
    
    for(int i=1;i<=N;i++){
        
        if(arr2[i]<M)continue;

        for(int j=0;j<i;j++){
            if(arr2[i]-arr2[j]==M){
                count++;
               // printf("%d위치의 값 [%d] 에서 %d 위치의 값 [%d]를 빼면 같음! \n",i,arr2[i],j,arr2[j]);
                continue;
            }
            if(arr2[i]-arr2[j]<M){
                break;
            }
                //printf("%d위치의 값 [%d] 에서 %d 위치의 값 [%d]를 빼면 다름! \n",i,arr2[i],j,arr2[j]);
        }
    }
    cout << count;
    return 0;
}