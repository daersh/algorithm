//0일때 고려할 것

#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    double N;
    cin >> N;

    if(N==0){
        cout << 0;
        return 0;
    }
    int arr[(int)N];
    int cutline= round(N*0.15);
    // cout << "cutline= " << cutline <<"\n";

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+(int)N);

    // for(int i=0;i<N;i++)cout << arr[i]<< ' ';
    // cout << '\n';

    double sum=0;
    double cnt=0;
    for(int i=cutline; i< N-cutline;i++){
        sum+=arr[i];
        cnt++;
    }
    // cout << sum << ' '<< cnt << '\n';
    cout << round(sum/cnt);

}
