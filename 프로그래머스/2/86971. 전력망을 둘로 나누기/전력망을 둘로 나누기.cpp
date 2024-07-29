#include <string>
#include <vector>
#include <map>
using namespace std;

int arr[110];
int asize;


int find_p(int x){
    if(arr[x]!=x){
        return find_p(arr[x]);
    }
    return x;
}

void union_p(int x , int y){
    x = find_p(x);
    y = find_p(y);
    if(x<y) 
        arr[y]=x;
    else
        arr[x]=y;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    asize = wires.size()+1; // 노드 개수
    
    for(int t = 0; t<asize;t++){
        
        // 배열 초기화
        for(int i=0;i<=asize;i++){
            arr[i]=i;
        }

        // 연결
        for(int i= 0; i < asize-1 ; i++){
            if(t==i) continue;
            union_p(wires[i][0],wires[i][1]);
        }
        
        int x = find_p(1);
        int xcnt = 1;
        int ycnt = 0;
        for(int i= 2; i <= asize ; i++){
            if(x== find_p(i))
                xcnt++;
            else
                ycnt++;
        }
        int cmp = xcnt-ycnt;
        if(cmp <0)
            cmp*=-1;
        if(answer>cmp)
            answer = cmp;
    }
    
    return answer;
}