#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    map<long long,int> mmap;
    int n,m;
    cin >> n >> m;

    long long arr[n+1];
    arr[0]= 0;

    for(int i=1; i<=n;i++){
        cin >> arr[i];
        arr[i]+=arr[i-1];
    }
    
    long long arr2[n+1];

    for(int i=0;i<=n;i++){
        arr2[i]=arr[i];
    }
    sort(&arr2[1],&arr2[n+1]);
    int x= m-1;

    while(x>=0){
        mmap[ arr2[n-x] ]++;
        // cout <<  arr2[n-x]<<' '<<mmap[ arr2[n-x] ]<<'\n';
        x--;
    }

    int cnt=m;
    long long sum=0;

    for(int i=1;i<=n;i++){
        if(cnt==0) break;

        if(mmap[arr[i]] !=0 && cnt != 0){  
            
            // cout << (arr[i]-arr[i-1]) * cnt<<'\n';          
            sum +=  (arr[i]-arr[i-1]) * cnt;
            mmap[arr[i]]--;
            cnt --;
            
        }else{
            // cout <<arr[i] <<" not found"<<'\n';
            sum+= (arr[i]-arr[i-1]) * cnt;
        }
        //  cout << "sum: "<<sum <<'\n';
    }
    cout << sum;
}


//3 -2 0 -1 4    
//1 2 3 -10 1  
//1 3 6 -4 -3
//-10 1 2 3 4
//-10 -9 -7 -4 0

//10 20 -100 30 -20
//10 30 -70 -40 -60

// 3 -5 2 -100 97
// 3 -2 0 -100 -3
