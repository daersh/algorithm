#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
using ll= long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        int n;
        cin >> n;
        char x;
        ll y;
        priority_queue<ll, vector<ll>, greater<ll> > front;
        priority_queue<ll, vector<ll>, less<ll> > back;
        map<ll,int> asdf;
        for(int i=0; i< n; i++){
            cin >> x >> y;
            if(x=='I'){
                front.push(y);
                back.push(y);
                asdf[y]++;
            }else if(x=='D'){
                if(y==1){
                    while(!back.empty() && asdf[back.top()]==0)
                        back.pop();
                    if( back.empty())
                        continue;
                    ll v = back.top();
                    back.pop();
                    asdf[v]--;
                }else{
                    while(!front.empty() && asdf[front.top()]==0)
                        front.pop();
                    if( front.empty())
                        continue;
                    ll v = front.top();
                    front.pop();
                    asdf[v]--;
                }
            }
        }
        ll f_v=0;
        ll b_v=0;
        bool f_f=false;
        bool b_f=false;
        while (!front.empty()){
            ll v= front.top();
            front.pop();
            if(asdf[v]>0 ){
                f_v=v;
                f_f=true;
                break;
            }
        }
        while (!back.empty()){
            ll v= back.top();
            back.pop();
            if(asdf[v]>0 ){
                b_v=v;
                b_f=true;
                break;
            }
        }
        if(!b_f && !f_f)
            cout << "EMPTY\n";
        else if(!b_f)
            cout << f_v << ' ' << f_v << '\n';
        else if(!f_f)
            cout << b_v << ' ' <<  b_v <<'\n';
        else 
            cout << b_v << ' ' <<  f_v <<'\n';

    }
    
}
