#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
string a,b;
vector<string> a_data;
vector<string> b_data;
int arr[1010][1010];
int last_loc=0;

void dp1(){
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            if(a[i-1]==b[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }else{
                    arr[i][j]= max(arr[i-1][j],arr[i][j-1]);
            }
        }
   }
}

int main(){
    cin >> a;
    cin >> b;
    dp1();
    vector<char> back;
    
    int x= a.length();
    int y= b.length();

    while(x>=1 && y >=1){
        if(arr[x][y]>arr[x-1][y] && arr[x-1][y] == arr[x][y-1] && arr[x][y-1]== arr[x-1][y-1]){
            back.push_back(b[y-1]);
            x--;
            y--;
        }else {
            if(arr[x-1][y] > arr[x][y-1] &&arr[x-1][y]==arr[x][y]){
                x--;
            }else{
                y--;
            }
        }
    }

    cout << back.size()<<'\n';
    
}