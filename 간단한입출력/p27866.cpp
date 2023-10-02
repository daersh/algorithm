#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a;
    cin >> a;
    int arr[26];

    fill(&arr[0],&arr[26],-1);

    for(int i=0;i<a.size();i++){
        int x= int(a[i]);
        if(arr[x-97]==-1){
            arr[x-97]=i;
        }
    }
    for(int i=0;i<26;i++){
        cout << arr[i]<< ' ';
    }
    return 0;
}