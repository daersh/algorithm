#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, k;
long long t;
vector<long long> vec;

int lower_bound(long long t){
    int l=-1;
    int r=n;
    while (l+1<r)
    {
        int mid= (l+r)/2;
        if(vec[mid]<t){
            l=mid;
        }else{
            r=mid;
        }
    }
    
    return l;
}

int main(){
    //상어마리수, 먹을수 있는 마리수, 최초크기
    cin >> n >> k >> t;
    int used[200010]={0};
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<k;i++){
        int loc = lower_bound(t);
        if(loc==-1){
            cout <<t;
            return 0;
        }
        while(used[loc]!=0){
            loc--;
            if(loc<0){
                cout << t;
                return 0;
            }
        }

        t += vec[loc];
        used[loc]++;
        //cout << t<<' ';
    }

    cout << t;
}