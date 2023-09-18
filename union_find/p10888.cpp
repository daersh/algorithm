#include <bits/stdc++.h>

using namespace std;
int arr[100010];
int visited[100010];
vector<pair<int,int> > vec;
int find_parent(int x){
    if(arr[x]!=x){
        return arr[x] = find_parent(arr[x]);
    }else{
        return x; 
    }
}
void union_parent(int x, int y){
    x=find_parent(x);
    y=find_parent(y);
    if(x>y) arr[x]=y;
    else arr[y]=x;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    long long max=0;
    for(int i=1;i<=N;i++){
        arr[i]=i;
    }
    int x,y,z;
    long long sum2[100010];
   

    for(int i=1;i<N;i++){
        cin >> x;
        union_parent(x,x+1); 

        visited[x]=true;
        visited[x+1]=true;

        for(int i=1;i<=N;i++){
            sum2[i]= sum2[i-1]+i;
        }
        if(max<x+1 ){
            max=x+1;
        }

        if(i==1){
            vec.push_back(make_pair(arr[x],2));
            cout << 1 << ' '<< 1 <<'\n';
            continue;
        }

        for(int i=1; i <=max;i++){
            find_parent(i);
        }


        int cnt=1;
        long long sum1=0;
        long long sum0=0;
        for(int i=2;i<=max;i++){
            if(visited[i]==true){
                if(arr[i]==arr[i-1]){
                    cnt++;
                    sum0+= sum2[cnt-1];
                    if(i==max){
                        sum1+= cnt*(cnt-1)/2;    
                    }
                }else{
                    sum1= sum1+ cnt*(cnt-1)/2;
                    sum0+= sum2[cnt-1];
                    cnt=1;
                }
            }
        }

        cout<<sum1<< ' '<<sum0 << '\n';
    
    }
    
}

