#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n=0;
    cin >> n;
    long long arr[n];
    map<long long,int> val;

    for(int i=0; i< n;i++){
        cin >> arr[i];
        val[arr[i]]++;
    }
    
    if(n==1 || n==2){
        cout << 0;
        return 0;
    }
    sort(&arr[0],&arr[n]);
    int result=0;
    for(int i=0; i< n-1; i++){
        for(int j = i+1; j <n;j++){
            long long cmp = arr[i]+arr[j];
            //cout << cmp<<"("<<val[cmp] <<")"<<"= "<< arr[i]<<" + "<< arr[j]<< '\n';
            if(cmp>arr[n-1]) break;
            if(val[cmp]==0) continue;

            if(cmp == arr[i] || cmp == arr[j]){
                if(cmp== arr[i] && cmp ==arr[j]){
                    if(val[cmp]<3) continue;
                }else if(cmp == arr[i]){
                    if(val[cmp]<2) continue;
                }else if(cmp==arr[j]){
                    if(val[cmp]<2) continue;
                }
            }

            result+=val[cmp];
            val[cmp]=0;
        }
    }
    cout << result;
}
