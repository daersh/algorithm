#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n ;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<6; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int t,p;
    cin >> t >> p;
    int tCnt= 0;
    int pCnt= n/p;
    int pEtc= n%p;

    for(int i=0; i<6; i++) {
        tCnt+= arr[i]%t!=0 ? arr[i]/t +1 : arr[i]/t;
    }
    
    cout << tCnt << "\n" ;
    cout << pCnt << ' '<< pEtc;
}