#include <iostream>


using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    string x;
    cin >> x;

    pair<int,int> past;
    int arr[2]={0,0}; 
    int loc=0;
    int cnt=1;
    while (true)
    {

        if(loc==n){
            if(cnt==k || cnt ==2000) break;
            else {
                cnt ++;
                loc=0;
                continue;
            }
        }

        if(x[loc]=='U'){
            arr[0]+=1;
        }else if(x[loc]=='D'){
            arr[0]-=1;
        }else if(x[loc]=='R'){
            arr[1]+=1;
        }else if(x[loc]=='L'){
            arr[1]-=1;
        }
        if(arr[0]==0 && arr[1]==0){
            cout <<"YES";
            return 0;
        }
        loc++;
    }

    cout <<"NO";
    return 0;
}