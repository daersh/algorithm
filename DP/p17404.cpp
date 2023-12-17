#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int arr[1010][3];
int n;
int start[3];

int compare(int x, int y){
    if(x==0) return y;
    else if(y==0) return x;

    return min(x,y);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin >> x>>y >>z;
        arr[i][0]=x;
        arr[i][1]=y;
        arr[i][2]=z;
    }

    vector<pair<int,int> > pii;
    pii.push_back(make_pair(0,1));
    pii.push_back(make_pair(0,2));
    pii.push_back(make_pair(1,0));
    pii.push_back(make_pair(1,2));
    pii.push_back(make_pair(2,0));
    pii.push_back(make_pair(2,1));
    int result = 1e9;

    for(int i=0; i<6;i++){
        int arr2[1010][3]={0};
        int start= pii[i].first;
        int end= pii[i].second;

        arr2[0][start]=arr[0][start]+arr[n-1][end];
        // cout <<"start,end= "<<start <<' '<<end<<'\n';

        for(int i=1;i<n-1;i++){
            if(compare(arr2[i-1][1],arr2[i-1][2])!=0)
            arr2[i][0]= compare(arr2[i-1][1],arr2[i-1][2])+arr[i][0];
            
            if(compare(arr2[i-1][0],arr2[i-1][2])!=0)
            arr2[i][1]=compare(arr2[i-1][0],arr2[i-1][2])+  arr[i][1];
            
            if(compare(arr2[i-1][0],arr2[i-1][1])!=0)
            arr2[i][2]= compare(arr2[i-1][0],arr2[i-1][1])+arr[i][2]; 

            // cout<< arr2[i][0] << ' '<<arr2[i][1]<<' '<<arr2[i][2]<<'\n';
        }

        if(end==0){
            if(arr2[n-2][1]<result && arr2[n-2][1]!=0) result= arr2[n-2][1];
            if(arr2[n-2][2]<result&& arr2[n-2][2]!=0) result= arr2[n-2][2];            
        }else if(end==1){
            if(arr2[n-2][0]<result&& arr2[n-2][0]!=0) result= arr2[n-2][0];
            if(arr2[n-2][2]<result&& arr2[n-2][2]!=0) result= arr2[n-2][2];
        }else if(end==2){
            if(arr2[n-2][0]<result&& arr2[n-2][0]!=0) result= arr2[n-2][0];
            if(arr2[n-2][1]<result&& arr2[n-2][1]!=0) result= arr2[n-2][1];            
        }
    }
    cout << result;
}