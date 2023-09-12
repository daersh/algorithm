#include <bits/stdc++.h>

using namespace std;

int N, K;
int result;
queue<int> q;
int arr[2000100];
vector<int> vec;
int count1;


void cout_result(){
    cout << count1 <<'\n';
    int a=K;
    vec.push_back(a);
    for(int i=1;i<=count1;i++){
        vec.push_back(arr[a]);
        a = arr[a];
    }

    while(!vec.empty()){
        if(N==0 && vec.size()==count1+1) {cout << "0 "; vec.pop_back();}
        
        cout << vec.back()<<' ';
        vec.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int i,x;
    cin >>N >> K;

    if(N!=0)q.push(N);
    else if(N==0){
        count1++;
        
        q.push(1);
    }
    if(N==0 && K==1){
        cout << "1\n";
        cout << "0 1";
        return 0;
    }
    int z=0;
    if(N==K) {cout << "0 \n"<<K; return 0;}

    while(!q.empty()){
        
        z=q.size();
        count1++;        
        for(i=0;i<z;i++){
            x=q.front();
            q.pop();
            
            if(x==K){
                cout_result();
                return 0;
            }
            
            if(arr[x*2]==0 && x*2< 2*K){
                arr[x*2]=x;
                q.push(x*2);
                if(x*2==K){
                    cout_result();
                    return 0;
                }
            }
            if(arr[x+1]==0 && x+1 <=K){
                arr[x+1]=x;
                q.push(x+1);
                if(x+1==K){
                    cout_result();
                    return 0;
                }
            }
            if(arr[x-1]==0 && x>0){
                arr[x-1]=x;
                q.push(x-1);
                if(x-1==K){
                    cout_result();
                    return 0;
                }
            }

        }
    }
    return 0;
}
