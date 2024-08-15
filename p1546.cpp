#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    double result;
    cin >> n;
    double arr[1010]= {0};
    double max = 0.0;
    for(int i =0 ; i<n;i++) {
        double x;
        cin >> x;
        if(x>max) max = x;
        arr[i]=x;
    }

    for(int i =0 ; i<n;i++) {
        arr[i]= arr[i]/max*100;
        result+=arr[i];
    }
    cout << (double)result/n;
}