#include<bits/stdc++.h>
using namespace std;

int arr[1010];
int arr2[1010];

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
    
    int N,M,T;
    cin >> T;
    for(int t=0;t<T;t++){
        int cnt=0;

        cin >> N >> M;
        if(N==1&& M==1){
            cin >> N && M;
            cout << "tree\n";
            continue;
        }

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
        int tf=false;

        for(int i=1;i<=N;i++){
            int node_cnt=0;
            int line_cnt=0;

            for(int j=1;j<=N;j++){
                find_p(j);
            }

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
            if(node_cnt!=0){
                if(node_cnt==line_cnt){
                    tf=true;
                }
            }

        }
        
        if(result==1 && tf==false){
            cout << "tree\n";
        }else{
            cout << "graph\n";
        }

    }
}

