#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> vec[510];
int n;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;

   for (int i = 0; i < n; i++)
   {
        for(int j=0; j<=i;j++){
            int x;
            cin>>x;
            vec[i].push_back(x);
        }
   }

    for(int i= n-2; i>=0;i--){
        for(int j=0; j<=i;j++){
            vec[i][j]+= max(vec[i+1][j],vec[i+1][j+1]);
        }

    }
   cout <<vec[0][0];
}