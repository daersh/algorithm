#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(){

    int n; 
    vector<int> vec[n+1];

    for(int i =0; i<n;i++){
        int l,ll;
        cin >> l >> ll;

        if(l<ll)
            vec[l].push_back(ll);
        else    
            vec[ll].push_back(l);

    }

}