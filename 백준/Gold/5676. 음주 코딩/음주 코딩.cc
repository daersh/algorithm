#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
vector<int> seg;

int init(int loc, int start, int end){
    if(start==end)
        return seg[loc]= vec[start];
    int mid= (start+end)/2;
    return seg[loc]= init(loc*2, start, mid)* init(loc*2+1, mid+1, end);
}
int find(int loc, int start, int end, int x, int y){
    if(x>end || y<start) return 1;
    if(x<=start && end<=y) return seg[loc];
    int mid= (start+end)/2;
    return find(loc*2, start, mid, x, y)* find(loc*2+1, mid+1, end, x, y);
}

int change(int loc, int start, int end, int index, int val){
    if(index<start || index>end) return seg[loc];
    if(start==end) {
        vec[index]= val;
        return seg[loc]= val;
    }
    int mid= (start+end)/2;
    return seg[loc]= change(loc*2, start, mid, index, val)* change(loc*2+1, mid+1, end, index, val);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    while(cin>>n>>m ){
        vec.clear();
        seg.clear();
        vec.resize(n+1);
        seg.resize(n*4);
        for(int i=1; i<= n;i++){
            cin >> vec[i];
            vec[i]=vec[i]==0? 0: vec[i]>0? 1:-1;
        }
        string result="";
        init(1,1,n);
        for(int i=0;i<m;i++){
            char a;
            int b,c;
            cin >> a >> b >> c;
            if(a=='C'){
                c= c==0? 0: c>0? 1:-1;
                change(1,0,n-1,b-1,c);
            }else{
                int res= find(1,0,n-1,b-1,c-1);
                if(res==0) result+= "0";
                else if(res>0) result+= "+";
                else result+= "-";
            }

        }
        cout << result << '\n';
    }
}