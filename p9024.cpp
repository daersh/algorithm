#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
    int N;
    cin >> N;
    int x ,y;
    for(int k=0;k<N;k++){
        cin >>x >>y;
        int arr[x];
        for(int i=0;i<x;i++){
            cin >> arr[i];
        }

        sort(arr,arr+x);
        int start=0, end = x-1;
        int cmp= INF;
        int cnt=0;
        for(int i=0;i<x;i++){
            cout <<  arr[i]<< ' ';
        }cout << '\n';

        while (start!=end)
        {
            cout << "start: "<< start << ", end: "<<end <<"일 경우\n";
            cout << "합: "<< arr[start]+arr[end] << ", cmp: "<<cmp <<'\n';
            if(abs(y-arr[start]+arr[end]) < abs(y-cmp)){
                cmp=arr[start]+arr[end];
                cnt=0;
            }
            if(abs(y-arr[start]+arr[end])== abs(y-cmp)){
                cnt++;
            }
            cout << cnt << '\n';
            if(arr[start]+arr[end]<y){
                start++;
            }else{
                end--;
            }
        }
        cout << cnt;

    }

    return 0;
}