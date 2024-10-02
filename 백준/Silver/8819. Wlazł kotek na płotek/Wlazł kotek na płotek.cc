// 그는 새끼 고양이를 울타리에 올라가서 점프했다.

// 박차는 원 계획에 고르게 분포된 N 레일로 구성되어 있다. 
//새끼 고양이는 모든 K 레일을 울타리에 점프한다 
//(즉, N = 8과 K = 3의 경우 새끼 고양이는 레일에서 연속적으로 점프한다: 1, 4, 7, 2, ... ).

//새끼 고양이는 아직 방문하지 않은 레일 위에 서 있는 한 점프한다. 
//그가 이미 뛰어내린 막대기에 닿자마자, 그는 즉시 울타리에서 벗어났다.
// 레일 N의 수를 알면, 위에서 설명한 방식으로 점프하는 새끼 고양이가 울타리의 모든 레일을 
//방문하는 모든 가능한 K ( 1 <= K <= N )를 결정하십시오.

// 입력
// 첫 번째 줄에는 테스트 세트 Z의 수가 있습니다 ( 1 <= Z <= 10). 그런 다음 후속 세트에 대한 설명이 제공됩니다.
// 세트의 유일한 줄에는 본문에 설명된 자연수 N ( 1 <= N <= 1000000 )이 있다.

// 출력
// 별도의 줄에 있는 각 세트에 대해, 가능한 모든 K 값( 본문에 설명된 대로)을 오름차순으로 적고, 숫자를 공백으로 구분하십시오.
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >>N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        int arr[x];

        fill(&arr[0],&arr[x],true);

        if(x==1){
            cout << x << '\n';
            continue;
        }
        
        for(int j=2;j<x;j++){
            if(x==false) continue;
            if(x%j==0){
                for(int k=1;k*j<x;k++){
                    arr[k*j]=false;
                }
            }
        }

        for(int j=1;j<x;j++){
            if(arr[j]==true){
                cout <<j<<' ';
            }
        }
        cout << '\n';
    }
}

