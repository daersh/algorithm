#include <iostream>
using namespace std;
int arr[51];
int arr2[1010];
int result[51];

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        arr2[arr[i]]=true;
    }
    int cnt=0;    
    for(int i=0;i<=1000;i++){
        if(arr2[i]==false) continue;
        for(int j=0;j<N;j++){
            if(i==arr[j]){
                result[j]=cnt;
                cnt++;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout << result[i]<< ' ';
    }
}