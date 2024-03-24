#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;


int main() {
	int n, m;
	cin >> n >> m;
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    vector<int>vec[n+1];
    int visited[n+1];

    fill(&visited[0], &visited[n+1], 0);    

	for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        visited[y]++;
        vec[x].push_back(y);
    }
    for(int i=1; i<=n; i++) {
        if(visited[i] == 0)
            pq.push(make_pair(visited[i], i));
    }
    int cnt =0 ;
    queue<int> q;

    while (!pq.empty())
    {
        
        int loc= pq.top().second;
        // cout << loc << "\n";
        q.push(loc);

        pq.pop();
        for(int i=0; i<vec[loc].size(); i++) {
            int loc2 = vec[loc][i];
            visited[loc2]--;
            // cout << "next: "<< loc2 << ','<< visited[loc2] << "\n";
            if(visited[loc2] == 0){

                pq.push(make_pair(visited[loc2], loc2));
            }
        }
    }
    
    while (!q.empty())
    {
        int loc= q.front();
        q.pop();
        cout << loc<<' ';
    }
    

	return 0;
}