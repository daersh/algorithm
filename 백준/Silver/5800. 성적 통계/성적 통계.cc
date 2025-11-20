#include <iostream>
#include <queue>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int n;
        cin >> n;
        priority_queue<int,vector<int>, greater<int> >  pq;
        for(int i=0; i< n; i++){
            int x;
            cin>> x;
            pq.push(x);
        }
        int gap=0;
        int min_v= pq.top();
        int past=min_v;

        pq.pop();

        while (pq.size()>1)
        {
            int x= pq.top();
            pq.pop();
            gap = max(gap, x-past);
            min_v= min(min_v,x);
            past=x;
        }
        int max_v= pq.top();
        pq.pop();
        gap = max(gap, max_v-past);
        cout <<"Class "<<t+1 <<'\n';
        cout << "Max "<<max_v << ", Min "<< min_v << ", Largest gap " << gap <<'\n';

    }
}