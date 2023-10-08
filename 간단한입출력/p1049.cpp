#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin >> n >> m;

    pair<int,int> arr[m];
    int x,y;
    priority_queue< int, 
                    vector<int >, 
                    greater<int > > 
                    set1;
    priority_queue< int, 
                    vector<int >, 
                    greater<int > > 
                    set2;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        set1.push(x);
        set2.push(y);
    }

    x= set1.top();
    y= set2.top();

    if(x>6*y){
        x=6*y;
    }
    int sum=0;
    sum= (n/6)*x;
    sum+= (n%6)*y;

    int cmp=0;
    cmp= ((n/6)+1)*x;

    
    

    if(cmp<sum ){
        cout << cmp;
    }else{
        cout << sum;
    }
}
