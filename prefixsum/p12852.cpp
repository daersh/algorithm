#include <bits/stdc++.h>

using namespace std;
int N;

int arr[1000100];
queue<int> q;
vector<int> vec;
int count1;
void dp(){
    while(!q.empty()){
        int z= q.size();

        
        for(int i=0;i<z;i++){

            int x= q.front();
            if(x==1){
                return;
            }
            q.pop();

            if(x>=3 && x%3==0 && arr[x/3]==0){
                arr[x/3]=x;
                q.push(x/3);
            }
            if(x>=2 && x%2==0 && arr[x/2]==0){
                arr[x/2]= x;
                q.push(x/2);
            }
            if( x-1!=0 && arr[x-1]==0){
                arr[x-1]= x;
                q.push(x-1);
            }
        }
        count1++;
    }
}

int main(){
    cin >> N;
    
    q.push(N);

    dp();
    int x=1;
    arr[N]=N;
    while( x != N){
        vec.push_back(x);
        x=arr[x];
    }
    
    cout << count1 << '\n';

    cout << N << ' ';

    while(vec.empty()!=true){
        cout << vec.back() << ' ';
        vec.pop_back();
    }
}