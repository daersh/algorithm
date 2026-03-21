#include <bits/stdc++.h>

using namespace std;

int N, K;
int result;
queue<int> q;
int arr[10010000];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int i,x;
    cin >>N >> K;
    q.push(N);
    int result2=0;
    int outwhile=false;
    if(N==K){
        cout << "0\n";
        cout << "1";
        return 0;
    }
    while(q.empty()!=true){
        
        int z=q.size();
        for(int j=0;j<z;j++){
            x=q.front();
            if(x==K) break;

            q.pop();
            arr[x]=true;

            if(x*2==K || x-1==K || x+1==K ){
                outwhile=true;
                result2++;
            }
            if( arr[x*2]!=true){
                if(x*2<K*2){
                //    cout << x<<"*2 : " << x*2 <<'\n'; 
                    q.push(x*2);
                }
            }
            if( arr[x+1]!=true){
              // cout << x<<"+1 : " << x+1 <<'\n';                 
                q.push(x+1);
            }
            if(x>0 && arr[x-1]!=true){
            //  cout << x<<"-1 : " << x-1 <<'\n';              
                q.push(x-1);
            }
        }

        //cout << result+1 <<"번 완료\n";
        result++;
        if(outwhile==true) break;       
    }

    cout << result;
    cout << '\n' << result2;
}