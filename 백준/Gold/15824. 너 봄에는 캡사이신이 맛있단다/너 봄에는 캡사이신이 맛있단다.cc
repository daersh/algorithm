#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long asdf = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> vec;
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(),vec.end());
    vector<long long> ii;
    ii.push_back(1);
    for(int i=1; i<= n; i++)
        ii.push_back((ii[i-1]*2)%asdf);
    long long sum=0;
    for(int i=0; i< n ;i++){
        long long v= vec[i];
        int r=n-i-1;
        int l=i;
        sum = (sum+(v* (ii[i]-1))-(v * (ii[r] -1)))%asdf;
    }

    cout <<  sum;

}

