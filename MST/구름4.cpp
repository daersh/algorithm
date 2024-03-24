#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>xw
using namespace std;

typedef pair<int,int> pii;

int main() {
	
	int n, m;
	vector<int> vec[m];
    priority_queue<pii, vector<pii>, greater<pii> > pq;

	for(int i=0; i< m;i++){
		int x;
		cin >> x;
		for( int j=0; j<x; j++){
			int y;
			cin>>y;
            vec[i].push_back(y);
		}
	}


	
	return 0;
}