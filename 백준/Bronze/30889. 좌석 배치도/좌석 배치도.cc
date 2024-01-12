#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    char arr[10][21];
    for(int i=0;i<10;i++){
        for(int j=1;j<21;j++){
            arr[i][j]='.';
        }
    }
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >>a;
        int x = a[0]-'A';
        int y;
        
        y = a[1]-'0';
        if(a.size()==3){
            y*=10;
            y+= a[2]-'0';
        }
        arr[x][y]='o';
    }
    
    for(int i=0;i<10;i++){
        for(int j=1;j<21;j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
}