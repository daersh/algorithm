#include <iostream>
#include <string>
#include <vector>
#include <queue>  
using namespace std;

int N;
queue<int> q;
queue<int> vec[200000];
int cmp[200000];

//방문확인
int visited[200000];
//벡터 임시 저장 (너비 우선에서 순서 다ㅡㄹㄹ 수 있기 때문)
int level[200000];


int main(){
    int i,j;
    int x;
    int y;
    cin >> N;
    //트리 입력
    for(i=0;i<N-1;i++){
        cin >> x >> y;
        vec[x].push(y);
        vec[y].push(x);
    }

    //비교할 방문순서값 입력
    for(i=0;i<N;i++){
        cin >> cmp[i];
    }

    q.push(1);

    



    return 0;
}

