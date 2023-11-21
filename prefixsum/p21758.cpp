#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main(){
    int n;
    cin >> n;

    int arr[n+1];
    int arr2[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    
        arr[i]+=arr[i-1];
        cout << arr[i]<< ' ';
    }
    for(int )
    cout << '\n';

    int start=1;
    int end=2;
    int max =0;

    while (end<n )
    {
        int endToEnd = arr[n]- arr[end];
        int startToEnd = arr[end-1]-arr[start]+ endToEnd;

        cout << "end -> n: " << endToEnd << "\nstart -> end: "<< startToEnd << '\n';
        cout << "sum: "<< endToEnd+startToEnd<<'\n';
        if(max<endToEnd+startToEnd){
            max=endToEnd+startToEnd;
        }
        end++;
    }

    cout << max;
}

