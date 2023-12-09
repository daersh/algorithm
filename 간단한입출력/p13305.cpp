#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >>n;
    long long result=0;
    int min_loc;
    long long min = 9223372036854775800;
    vector<int> dist;
    vector<int> loc;
    long long toEnd=0;

    for(int i=0;i<n-1;i++){
        int x;
        cin >>x;
        toEnd+=x;
        dist.push_back(x);
    }
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        loc.push_back(x);
        if(x<min) {
            min = x;
            min_loc= i;
        }
    }

    if(min_loc==0){
        cout << toEnd*min;
        return 0;
    }
    
    //cout <<"총거리: "<< toEnd<<'\n';
    int past_loc=0;
    result=loc[0]*dist[0];
    toEnd-=dist[0];
    //cout << result << ' '<< toEnd <<'\n';

    for(int i=1; i<=min_loc;i++){
        if(i==min_loc){
            result+= toEnd*min;
            //cout << result << ' '<< toEnd <<'\n';
            break;
        }
        if(loc[i]<loc[past_loc]){
            past_loc=i;

        }
        result+=loc[past_loc]*dist[i];
        toEnd -= dist[i];
        //cout << result << ' '<< toEnd <<'\n';
    }
    cout << result;
}