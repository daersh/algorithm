#include <bits/stdc++.h>

using namespace std;


 struct subin{
    int loc;
    int count;
};

int N, K;
int result=1000000000;
queue<struct subin> q;
int arr[10010000];


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int i,x;
    cin >>N >> K;
    struct subin a;
    a.loc=N;
    a.count=0;
    q.push(a);

    int result2=0;
    int outwhile=false;

    if(N==K){
        cout << "0\n";

        return 0;
    }

    while(q.empty()!=true){
        
        int z=q.size();
        for(int j=0;j<z;j++){
            struct subin x,y;
            x.loc=q.front().loc;
            x.count=q.front().count;
            if(x.loc==K) break;
            q.pop();

            arr[x.loc]=true;
            if(x.loc*2==K ){
                outwhile=true;
                //cout << x.count;
                if(result>x.count){
                    result= x.count;
                }
            }
            if(x.loc-1==K || x.loc +1 ==K ){
                outwhile=true;
                //cout << x.count+1;
                if(result>x.count+1){
                    result= x.count+1;
                }
            }
            if( arr[x.loc*2]!=true){
                if(x.loc*2<K*2){
                //  cout << x<<"*2 : " << x*2 <<'\n'; 
                    y= x;
                    y.loc*=2;
                    q.push(y);
                }
            }
            if( arr[x.loc+1]!=true){
              // cout << x<<"+1 : " << x+1 <<'\n';                 
                y=x;
                y.loc+=1;
                y.count+=1;
                q.push(y);
            }
            if(x.loc>0 && arr[x.loc-1]!=true){
            //  cout << x<<"-1 : " << x-1 <<'\n';              
                y=x;
                y.loc-=1;
                y.count+=1;
                q.push(y);
            }
        }

        //cout << result+1 <<"번 완료\n";
        //result++;
        if(outwhile==true) break;       
    }

    cout << result;
    //cout << '\n' << result2;
}