#include <iostream>
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

    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr1[i];
    }
    vec.push_back(arr1[0]);
    for(int i=1; i< n ;i++){
        if(arr1[i]>vec.back()){
            vec.push_back(arr1[i]);
            end_p =vec.size()-1;
        }
        int pos = eboon(arr1[i]);
        vec[pos] = arr1[i];
    }
    cout << end_p+1;
}
//12
// 1 5 4 2 3 8 6 7 9 3 4 5