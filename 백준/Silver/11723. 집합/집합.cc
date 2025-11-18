#include <iostream>
#include <map>
#include <set>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i;
    cin >> i;
    int ii[20]={0};

    string iiii;
    int iiiii;
    for(int iii=0;iii<i;iii++){
        cin >> iiii;
        if(iiii.find("add") != string::npos){
            cin >> iiiii;
            ii[iiiii]=1;
        }else if(iiii.find("remove") != string::npos){
            cin >> iiiii;
            ii[iiiii]=0;
        }else if(iiii.find("check") != string::npos){
            cin >> iiiii;
            if(ii[iiiii]== 1){
                cout << 1<<'\n';
            }else   
                cout << 0 <<'\n';
        }else if(iiii.find("toggle") != string::npos){
            cin >> iiiii;
            if(ii[iiiii]!= 0){
                ii[iiiii]=0;
            }else   
                ii[iiiii]=1;
        }else if(iiii.find("all") != string::npos){
            for(int iiiiii=1;iiiiii<21;iiiiii++){
                ii[iiiiii]=1;
            }
        }else if(iiii.find("empty") != string::npos){
            for(int iiiiii=1;iiiiii<21;iiiiii++){
                ii[iiiiii]=0;
            }
        }
    }

}