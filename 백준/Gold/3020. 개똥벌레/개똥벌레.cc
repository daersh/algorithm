#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int N,M,L;

int arr[1000010];
int arr2[1000010];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    int x,y;
    int start1=0;
    int start2=M;
    for(int i=1;i<=N;i++){
        cin >> x;
        
        if(i%2==1){
            arr[start1]++;
            arr[x+1]--;
        }else{
            arr2[start1]++;
            arr2[x+1]--;
        }
        
    }
    
    for(int i=1;i<=M;i++){
        arr[i]+=arr[i-1];      
    }
    for(int i=1;i<=M;i++){
        arr2[i]+=arr2[i-1];      
    }
    int min=100000000;
    int count=1;
    for(int i=1;i<=M;i++){
        arr[i]+=arr2[M-i+1];   
        if(arr[i]<min){
            min=arr[i];
            count=1;
        }else if(arr[i]==min){
            count++;
        }
            
    }
    cout << min << ' ' <<count;
    
    return 0;
}