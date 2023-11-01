#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int n;
int arr[22][22];
int arr2[22][22];
int arr3[22][22];
int arr4[22][22];

vector<int> vec;
queue<int> q;
int result=0;

void change_arr(int cnt){
    //좌
    for(int i=0;i<n;i++){
        for(int j=n-1;j>0;j--){
            if(arr[i][j]==0){
                continue;
            }else{
                vec.push_back(arr[i][j]);
            }
        }
        while (!vec.empty())
        {
            int x=vec.back();
            vec.pop_back();

            int y=0;
            if(!vec.empty()) {y=vec.back();}
            else{
                q.push(x);
                break;
            }
            if(x==y)
                q.push(x*2);
            else {
                vec.push_back(y);
            }
        } 
        int z=q.size();
        for(int j=0;j<z;j++){
            arr2[i][j]=q.front();
            q.pop();
        }
    }


}

void backtracking(int cnt){

    if(cnt==5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(result<arr4[i][j]){
                    result=arr4[i][j];
                }
            }
        }
    }else if(cnt==4){
        backtracking(5);
    }else if(cnt==3){
        backtracking(4);
    }else if(cnt==2){
        backtracking(3);
    }else if(cnt==1){
        backtracking(2);
    }
    

}

int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    }
    //n이 400칸이기 떄문에 backtracking?
    change_arr(1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<< arr2 [i][j]<<' ';
        cout <<'\n';
    }}