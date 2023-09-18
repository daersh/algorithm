#include<bits/stdc++.h>
using namespace std;

int arr[510];
int arr2[510];

int find_p(int x){
    if(arr[x]!=x){
        return arr[x] = find_p(arr[x]);
    }else{
        return x;
    }
}


void union_find(int x, int y){
    x= find_p(x);
    y=find_p(y);
    if(x>y) arr[x]=y;
    else arr[y]=x;
}


int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int N,M;
    int cnt=1;
    while(1){

        cin >> N >> M;
        if(N==0&&M==0) return 0;

        //초기화
        for(int i=1;i<=N;i++){
            arr[i]=i;
            arr2[i]=0;
        }
        int x,y;

        for(int i=1;i<=M;i++){
            cin >> x >> y;
            arr2[x]++;
            arr2[y]++;
            union_find(x,y);
        }

        int result=0;

        for(int i=1;i<=N;i++){
            //노드개수 N , 간선 N-1 개나와야함 (사이클 때문)
            int node_cnt=0;
            int line_cnt=0;

            for(int j=1;j<=N;j++){
                find_p(j);
                //cout << arr[j] <<" ";
            }
            //cout << '\n';

            for(int j=1;j<=N;j++){
                if(i==arr[j]){
                    node_cnt++;
                    line_cnt+=arr2[j];
                }
            }
            line_cnt= line_cnt/2;
            //cout << "node_cnt: " << node_cnt << " line_cnt: " << line_cnt << '\n';
            if(node_cnt-line_cnt==1 ){
                    result++;
            }
        }
        
        //cout << '\n';
        cout << "Case " << cnt<<": " ;
        if(result==1){
            cout << "There is one tree.\n";
        }else if(result==0){
            cout << "No trees.\n";
        }else if(result>1){
            cout << "A forest of " << result << " trees.\n";
        }

        cnt++;
    }
}

