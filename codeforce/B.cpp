#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int N;
        vector<int> vec;
        cin >> N;
        int x=5;
        vec.push_back(3);
        vec.push_back(4);
        int loc=2;

        while(vec.size()<=N){
            if((3*x)%(vec[loc-1]+vec[loc-2]) !=0 ){
                vec.push_back(x);
                x++;
                loc++;
            }else{
                x++;
            }
        }

        for(int j=0;j<N;j++){
            cout << vec[j] << ' ';
        }cout << '\n';

    }
}