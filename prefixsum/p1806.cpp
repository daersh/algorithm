#include<iostream>

using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int arr[N+1];
    arr[0]=0;
    int aa=false;

    for(int i=1;i<=N;i++){
        cin >> arr[i];
        if(arr[i]>=M){
            aa=true;
        }
    }

    if(aa==true){
        cout << 1;
        return 0;
    }

    int cnt=INF;
    int start=1;
    int end=1;
    int sum=arr[start];

    while (start<=end && end<=N)
    {
        //sum이 목표값보다 크거나 같으면, cnt와 비교하여 저장
        if(sum>=M){
            if(cnt> end-start+1){
                cnt=end-start+1;
            }
        }
        //작다면 end 위치를 ++ 후 sum+arr[end]
        //크면 start를 --
        if(sum<M){
            end++;
            sum+=arr[end];
        }
        //크다면 sum에서 start지점 빼고 start위치 ++
        else{
            sum-=arr[start];
            start++;
        }
    }
    //cnt값 변경이 없다면 0 출력
    if(cnt>=INF){
        cout << 0;
    }else{
        cout << cnt;
    }

}