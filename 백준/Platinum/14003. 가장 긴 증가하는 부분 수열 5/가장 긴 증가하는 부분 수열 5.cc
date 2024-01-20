#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int arr1[1000010];
vector<int> vec;
int n;
int end_p=0;

int eboon(int v){
    int l=0;
    int r=end_p;
    while (l<r)
    {
        int mid=(l+r)/2;
        if(v > vec[mid]) l = mid+1;
        else r= mid;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector<int> back;
    vector<int> data;
    cin >> n;
    
    //for(int i=0;i<n;i++){
    cin >> arr1[0];
    int max=0;
    vec.push_back(arr1[0]);
    back.push_back(0);

    for(int i=1; i< n ;i++){
        cin >>arr1[i];
        
        if(arr1[i]>vec.back()){
            vec.push_back(arr1[i]);
            end_p =vec.size()-1;
        }
        int pos = eboon(arr1[i]);
        vec[pos] = arr1[i];
        back.push_back(pos);
        
        if(pos>max)max=pos;

        // for(int i=0;i<vec.size();i++){
        //     cout <<vec[i]<<' ';
        // }cout <<'\n';
        
        // for(int i=0;i<back.size();i++){
        //     cout <<back[i]<<' ';
        // }cout <<'\n';
        
    }   
    cout << end_p+1<<'\n';
    vector<int>  result;
    for(int i=0; i< n; i++){
        if(back[i]==max){
            max --;
            //cout << arr1[i]<<' ';
            result.push_back(arr1[i]);
            int past_val= arr1[i];
            for(int j=i-1; j>=0;j--){
                if(back[j]==max && arr1[j]< past_val){
                    // cout << arr1[j] << ' ';
                    result.push_back(arr1[j]);
                    max --;
                }
            }
        }
    }
    while (!result.empty())
    {
        cout << result.back()<<' ';
        result.pop_back();
    }
    
}
