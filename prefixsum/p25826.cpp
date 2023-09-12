#include <bits/stdc++.h>

using namespace std;
int N,M,L;

long long arr[1010][1010];
long long arr2[1010][1010];
long long arr3[1010][1010];
long long  insert1,insert2,insert3,insert4;
long long result;
void print_result(){
    int i,j;
    for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                arr2[i][j]+=arr2[i][j-1];
            }
        }

    //cout << "가로 쓸기 \n";
    for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
               //cout << arr2[i][j]<< ' ';
          }
          //cout << '\n';
        }

        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                arr2[j][i]+=arr2[j-1][i];
            }
        }
    //cout << "세로 쓸기 \n";
         for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
               //cout << arr2[i][j]<< ' ';
          }
          //cout << '\n';
        }
    //cout << "출력\n";
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            arr[i][j]+=arr2[i][j];
            //cout << arr[i][j]<< ' ';
        }
        //cout << '\n';
    }

    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            arr3[i][j]=arr[i][j]+arr3[i-1][j]+arr3[i][j-1]-arr3[i-1][j-1];
            //cout << arr3[i][j]<< ' ';
        }
        //cout << '\n';
    }

    cin >> insert1 >> insert2 >> insert3 >> insert4;
    insert1++;
    insert2++;
    insert3++;
    insert4++;

    for( j=insert1;j<=insert3;j++){
            result= arr3[insert3][insert4] -arr3[insert1-1][insert4]-arr3[insert3][insert2-1] +arr3[insert1-1][insert2-1];
    }
    cout << result <<'\n';


}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> N >> M;
    int i,j;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            cin >> arr[i][j];
        }
    }

    int a;
    long long x1 ,y1, x2,y2,n;
    long long k;
    for(k=1;k<=M;k++){
        //cout << "insert: ";
        cin >> a ;

        if(a==1)
            cin >> x1 >> y1 >> x2 >> y2 >> n;
        else if(a==2){
            print_result();
            continue;
        }
        arr2[x1+1][y1+1]+=n;
        arr2[x1+1][y2+2]+=-n;
        arr2[x2+2][y1+1]+=-n;
        arr2[x2+2][y2+2]+=n;
    
    }


}