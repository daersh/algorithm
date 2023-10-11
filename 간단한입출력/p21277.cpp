#include <iostream>

using namespace std;

int arr[210][210];

int main(){
    int n1,m1,n2,m2;
    cin >> n1>>m1;

    for(int i=100;i<n1+100;i++){
        string a;
        cin >> a;
        for(int j=100;j<m1+100;j++){
            arr[i][j]=a[j-100]-48;
        }        
    }
    cin >> n2>>m2;
    int arr1[n2][m2];   //0
    int arr2[m2][n2];   //90
    int arr3[n2][m2];   //180
    int arr4[m2][n2];   //270
    
    int result=1e9;

    for(int i=0;i<n2;i++){
        string a;
        cin >> a;
        for(int j=0;j<m2;j++){
            arr1[i][j]=a[j]-48;
        }
    }

    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++){
            arr2[i][j]= arr1[n2-1-j][i];
            cout << arr2[i][j] ;
        }cout <<'\n';
    }

    for(int i=0;i<n2;i++){

        for(int j=0;j<m2;j++){
            arr3[i][j]= arr2[m2-1-j][i];
            cout << arr3[i][j] ;
        }cout <<'\n';
    }

    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++){
            arr4[i][j]= arr3[n2-1-j][i];
            cout << arr4[i][j] ;
        }cout <<'\n';
    }



    //비교1 (0도) arr1
    for(int i=100-n2;i<100+n1+n2;i++){
        for(int j=100-m2;j<100+m1+m2;j++){        
            int tf=true;
             for(int k=0;k<n2;k++){
                for(int l=0;l<m2;l++){
                    if(arr[i+k][j+l]==1 && arr1[k][l]){
                        tf=false;
                        break;
                    }
                }
                if(tf==false)break;
            }           
            if(tf){
                //넓이 구한후 result보다 작으면 업데이트   
            }
        }
    }
    //비교2 (180도) arr3
    for(int i=100-n2;i<100+n2;i++){
        for(int j=100-m2;j<100+m2;j++){
            for(int k=0;k<n2;k++){
                for(int l=0;l<m2;l++){

                }
            }
        }
    }
    //비교3 (90도) arr2
    for(int i=100-m2;i<100+m2;i++){
        for(int j=100-n2;j<100+n2;j++){
            for(int k=0;k<m2;k++){
                for(int l=0;l<n2;l++){

                }
            }
        }
    }
    //비교4 (270) arr4
    for(int i=100-m2;i<100+m2;i++){
        for(int j=100-n2;j<100+n2;j++){
            
            for(int k=0;k<m2;k++){
                for(int l=0;l<n2;l++){

                }
            }

        }
    }
    
}


// 123
// 123
// 123

// 111
// 222
// 333

// 321
// 321
// 321

// 333
// 222
// 111