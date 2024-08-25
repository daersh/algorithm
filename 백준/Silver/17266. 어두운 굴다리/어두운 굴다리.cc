#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n , m ;
    cin >> n >> m;
    vector<int> vec;
    for(int i =0 ; i < m ; i++){
        int x ;
        cin >> x ;

        vec.push_back(x);
    }
    
    sort(vec.begin(), vec.end());

    int l = 1;
    int r = 100000;

    while(l+1 < r){
        int mid = (l + r) / 2;
        int count = 0;
        int visited[100010] = {0};
        
        // cout << mid<<'\n';
        for(int i = 0 ; i < m ; i++){
            int x = vec[i]-mid;
            if(x<0)
                x=0;
            int y = vec[i]+mid;
            if(y > n+1)
                y=n+1;
            visited[x]++;
            visited[y]--;
            // cout <<"x: "<< x << "y: " << y<<'\n';
        }

        bool found = false;
        if(visited[0]==0){
            l=mid;
            continue;
        }

        for(int i=1;i<=n;i++){

            visited[i] += visited[i-1];

            if(visited[i]==0){
                l=mid;
                found= true;
                break;
            }
        }

        if(found==false)
            r=mid;
    }


    int visited[100010] = {0};
    
    for(int i = 0 ; i < m ; i++){
        int x = vec[i]-l;
        if(x<0)
            x=0;
        int y = vec[i]+l;
        if(y > n+1)
            y=n+1;
        visited[x]++;
        visited[y]--;
        // cout <<"x: "<< x << "y: " << y<<'\n';
    }

    bool found = false;
    if(visited[0]==0){
        l=l;
        found=true;
    }
    for(int i=1;i<=n-1;i++){
        visited[i] += visited[i-1];
        if(visited[i]==0){
            found= true;
        }
    }
    if(found)
        cout << r;
    else
        cout << l;
    return 0;
}