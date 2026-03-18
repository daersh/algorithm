#include <iostream>
#include <vector>  

using namespace std;
using pii = pair<int,int>;
vector<pii> seg;
vector<int> vec;
int angle[12]= {6,7,0,1,2,3,4,5,6,7,0,1};
int n, m;

pii init(int loc, int s, int e){
    if(s==e) return seg[loc]=make_pair(vec[s],vec[s]);
    int m = (s+e)/2;
    pii l = init(loc*2,s,m);
    pii r = init(loc*2+1,m+1,e);
    if(l.first==-1||r.first==-1)
        return seg[loc]=make_pair(-1,-1);

    if((angle[l.second+4]==angle[r.first+2]|| 
        angle[l.second]==angle[r.first+2]))
        return seg[loc]=make_pair(-1,-1);

    return seg[loc] = make_pair(l.first,r.second); 
}

pii change(int loc, int s, int e, int idx, int val){
    if(idx<s||e<idx) return seg[loc];
    if(s==e) return seg[loc]=make_pair(val,val);
    int m = (s+e)/2;
    pii l = change(loc*2,s,m,idx,val);
    pii r = change(loc*2+1,m+1,e,idx,val);
    if(l.first==-1||r.first==-1)
        return seg[loc]= make_pair(-1,-1);
    if((angle[l.second+4]==angle[r.first+2]|| 
        angle[l.second]==angle[r.first+2]))
        return seg[loc]=make_pair(-1,-1);

    return seg[loc] = make_pair(l.first,r.second); 
}

pii find(int loc, int s, int e, int st, int ed){
    if(ed<s||e<st) return {-2,-2};
    if(st<=s&&e<=ed) return seg[loc];
    int m = (s+e)/2;
    pii l = find(loc*2,s,m,st,ed);
    pii r = find(loc*2+1,m+1,e,st,ed);
    if(l.first==-2)
        return r;
    else if(r.first==-2)
        return l;
    
    if(l.first==-1||r.first==-1)
        return make_pair(-1,-1);
    if((angle[l.second+4]==angle[r.first+2]|| 
        angle[l.second]==angle[r.first+2]))
        return make_pair(-1,-1);

    return make_pair(l.first,r.second); 
}

void print(){
    int c=1;
    int d=0;
    for(int i=1; i<n*4;i++){
        if(c==d){
            c*=2;
            d=0;
            cout<<'\n';
        }
        d++;
        cout << seg[i].first<<','<<seg[i].second<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vec.resize(n);
    seg.resize(n*4);
    for(int i=0;i<n;i++) cin >> vec[i];
    init(1,0,n-1);
    // print();
    int a,b,c;
    for(int i=0;i < m;i++){
        cin >> a >> b>> c;
        if(a==1)
            change(1,0,n-1,b-1,c);
        else
            cout << (find(1,0,n-1,b-1,c-1).first==-1?0:1)<<'\n';
        // print();
    }
}