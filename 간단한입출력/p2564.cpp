#include <iostream>

using namespace std;

int main(){
    int N;
    int x,y;
    cin >> x>>y;
    cin >> N;

    vector<pair<int,int> > vec;
    int a,b;
    for(int i=0;i<N;i++){
        cin>> a>>b;
        vec.push_back(make_pair(a,b));
    }
    
    pair<int,int> dong;
    cin >> a>>b;
    dong= make_pair(a,b);

    

}