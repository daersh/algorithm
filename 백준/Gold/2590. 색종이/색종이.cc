#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <queue>


using namespace std;

int main(){
    vector<int> a(6);
    for(int i = 0; i < 6; i++) cin >> a[i];

    int pen =0;

    // 6일 때
    pen+= a[5];
    // cout << pen << "\n";
    
    // 5일 때 
    //가능조합: 1*11 + 5*1
    pen+= a[4];
    a[0] = max(0, a[0] - 11 * a[4]);
    
    // cout << pen << "\n";
    
    // 4일 때 
    // 가능조합
    // 2*5 + 4*1
    // 1*20 + 4*1
    while(a[3]>0){
        pen++;
        a[3]--;
        if(a[1]>0 && a[1]<5){
            int x = a[1];
            a[1] = 0;
            a[0] = max(0,  a[0]- (5-x)*4 );
        }else if(a[1]>=5){
            a[1]-=5;
        }else{
            a[0] = max(0, a[0] - 20);
        }
    }
    // cout << pen << "\n";
    
    // 3일 때 
    // 3*4
    // 3*3 + 2*3 + 1*6
    while(a[2]>0){
        pen+= a[2]/4;
        a[2] = a[2]%4;
        if(a[2]==0) break;

        if(a[2]==3){
            pen++;
            a[2] = 0;
            // 3*3 
            // 2*1 + 1*5
            // 1*9
            if(a[1]>0){
                a[1]--;
                a[0] = max(0, a[0]-5);
            }else{
                a[0] = max(0, a[0]-9);
            }
        }else if(a[2]==2){
            pen++;
            a[2] = 0;
            // 2*3 + 1*6
            if(a[1]>=3){
                a[1]-=3;
                a[0] = max(0, a[0]-6);
            }else if(a[1]>0){
                int x=a[1];
                a[1]=0;
                a[0] = max(0, a[0]-6-(3-x)*2);
            }else{
                a[0] = max(0, a[0]-18);
            }
        }else if(a[2]==1){
            pen++; 
            a[2] = 0;
            // 2*5 + 1*7
            if(a[1]>=5){
                a[1]-=5;
                a[0] = max(0, a[0]-7);
            }else if(a[1]>0){
                int x=a[1];
                a[1]=0;
                a[0] = max(0, a[0]-7-(5-x)*2);
            }else{
                a[0] = max(0, a[0]-27);
            }
        }
    }
    // cout << pen << "\n";
    
    while(a[1]>0){
        pen+= a[1]/9;
        a[1] = a[1]%9;
        if(a[1]==0) break;
        pen++;
        a[0] = max(0, a[0]- (36 - a[1]*4) );
        a[1]=0;
    }
    // cout << pen << "\n";
    
    while(a[0]>0){
        pen++;
        a[0] = max(0, a[0]-36);
    }
    
    cout << pen << "\n";
    return 0;
}