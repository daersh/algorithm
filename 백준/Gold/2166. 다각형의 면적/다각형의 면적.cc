#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    pair<long long  ,long long > arr[n];
    for(int i=0; i< n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    long double sum=0;
    int j= n-1;
    for(int i=0; i< n;i++){
        sum += arr[j].first*arr[i].second;
        sum -= arr[j].second*arr[i].first;
        j=i;
    }
    sum= abs(sum);
    sum/=2;
    sum *=10;
    sum= round(sum);
    sum/=10;
    printf("%.1Lf",sum);
    
}
