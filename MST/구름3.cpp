#include <iostream>
#include <queue>
using namespace std;


int x_next[8]={-1,-1,-1,0,0,1,1,1}; //가로
int y_next[8]={-1,0,1,-1,1,-1,0,1}; //세로

int main() {
	int n;
    cin >>n;
    int arr[n][n];
    int start_x=0;
    int start_y=0;
    int cnt=0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
            if(x==2){
                start_x=j; //가로
                start_y=i;  //세로
            }
        }
    }

    while(true){
        int x=start_x;
        int y=start_y;
        int found=0;
        for(int i = 0; i < 8; i++) {
            int nx=x+x_next[i];
            int ny=y+y_next[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(arr[nx][ny]==1){
                found=1;
                cnt++;
                start_x=nx;
                start_y=ny;
                arr[nx][ny]=2;
                break;
            }
        }

        if(found==0) break;
    }

    cout << cnt;
	return 0;
}