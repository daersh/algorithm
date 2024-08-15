#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main(int argc, char **argv){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n , m ;
        cin >> n >> m;

        vector<int> nvec;
        vector<int> mvec;

        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            nvec.push_back(x);
        }

        for(int i=0; i<m; i++){
            int x;
            cin >> x;
            mvec.push_back(x);
        }
        
        sort(mvec.begin(), mvec.end());

        map<int, int> mmap;
        for (int i = 0; i < mvec.size(); i++)
        {
            mmap[mvec[i]] = i+1;
        }

        long long cnt = 0;

        for(int i =0; i<nvec.size(); i++){
            int v = nvec[i];
            // cout << "v = " << v << endl;
            int l = 0;
            int r = mvec.size()-1;
            while(l+1<r){
                int mid = (l+r)/2;
                if(mvec[mid]< v)
                    l = mid;
                else 
                    r= mid;
            }

            // cout << "l = " << l << " r = " << r << endl;
            
            if(mvec[r] < v)
                cnt+=mmap[mvec[r]];
            else if(mvec[l] < v)
                cnt+=mmap[mvec[l]];
            // cout << "cnt = " << cnt << endl;
            // cout << "next\n";
        }
        cout << cnt << '\n';
    }

}