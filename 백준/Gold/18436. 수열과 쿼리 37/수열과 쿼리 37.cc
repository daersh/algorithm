#include <iostream>
#include <vector>

using namespace std;
using pii=pair<int,int> ;
vector<int> vec; // 0: 짝, 1; 홀
vector<pii> seg;

pii pii_plus(pii a, pii b){
    return {a.first+b.first, a.second+b.second};
}

pii init(int l, int s, int e){
    if(s==e) return seg[l] = (vec[s]==0 ? pii{0,1} : pii{1,0});
    int m = (s+e)/2;
    return seg[l]= pii_plus(init(l*2,s,m),init(l*2+1,m+1,e));
}

void change(int l,int s, int e, int t, int v){
    if(t<s || t>e)
        return;
    if(s==e){
        seg[l]=(vec[s]==0 ? pii{0,1} : pii{1,0});
        return;
    }
    if(v==0){
        seg[l].first--;
        seg[l].second++;
    }else{
        seg[l].first++;
        seg[l].second--;
    }
    int m = (s+e)/2;
    change(l*2,s,m,t,v);
    change(l*2+1,m+1,e,t,v);
    return ;
}
pii find(int l, int s, int e, int x, int y){
    if(x>e || y<s)
        return {0,0};
    if(x<=s && y>=e)
        return seg[l];
    int m = (s+e)/2;
    return pii_plus(find(l*2,s,m,x,y),find(l*2+1,m+1,e,x,y));
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vec.resize(n+1);
    seg.resize(n*4);
    int x;
    for(int i=1; i<= n ;i++){
        cin >> x;
        vec[i]= x%2;
    }
    // for(int i=1; i<= n ;i++)cout <<vec[i]<<' '; cout <<'\n';
    init(1,1,n);
    // for(int j=0; j<n*4;j++) cout << seg[j].first<<','<<seg[j].second<< ' '; cout << '\n';
    int m;
    cin >> m;
    int a,b,c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(a==1){
            c%=2;
            if(vec[b]!=c){
                vec[b]=c;
                change(1,1,n,b,c);
            }
            // for(int j=0; j<n*4;j++) cout << seg[i].first<<','<<seg[i].second<< ' '; cout << '\n';
        }else if(a==2){
            cout << find(1,1,n,b,c).second<<'\n';
        }else if(a==3){
            cout << find(1,1,n,b,c).first<<'\n';
        }
    }
    
}