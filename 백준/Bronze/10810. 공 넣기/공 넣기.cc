#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int arr[n+1];
    fill(&arr[0],&arr[n+1],0);
int x,y,z;
    for(int i=0;i<m;i++){
        cin >> x>>y>>z;
        for(int j=x;j<=y;j++) arr[j]=z;
}
    for(int i=1;i<=n;i++){
cout << arr[i] << ' ';
    }
}
