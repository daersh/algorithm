#include <iostream>
#include <map>

using namespace std;
typedef pair<int, int> pii;

int main(){
    int n;
    cin >> n; 

    pii arr[n];
     
    for(int i=0; i<n; i++){
        int n , m ;
        cin >> n >> m;

        arr[i] = make_pair(n, m);
    }

    map<int, int> m;

    int result =0;

    for(int i=0; i<n; i++){
        
        if(arr[i].first+i>n)
            arr[i].second = m[i];
        else
            arr[i].second += m[i];

        int x = arr[i].second;
        int next = i+arr[i].first;
        for(int j=next; j<n; j++)
            if(x > m[j])
                m[j] = x;
            
    }
    
    for(int i=0; i<n; i++){

        // cout <<"arr["<<i<<"]: "<< arr[i].second<<'\n';
        result = max(result, arr[i].second);

    }

    cout << result;

    return 0;
}