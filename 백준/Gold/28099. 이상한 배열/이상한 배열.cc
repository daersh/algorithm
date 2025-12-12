#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> seg;
vector<vector<int>> save;

int init(int loc, int start, int end){
    if(start==end)
        return seg[loc]= vec[start];
    int mid=(start+end)/2;
    return seg[loc]= max(init(loc*2,start,mid),init(loc*2+1,mid+1,end));
}   

int find(int loc, int start, int end, int x, int y){
    if(x>end || y<start) 
        return 0;
    if(x<=start && end<=y)
        return seg[loc];
    int mid = (start+end)/2;
    return max(find(loc*2,start,mid,x,y),find(loc*2+1,mid+1,end,x,y));
}
void clear(){
    while (!vec.empty())
        vec.pop_back();
    while (!seg.empty())
        seg.pop_back();
    while (!save.empty())
        save.pop_back();
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        int n;
        cin >> n;
        vec.resize(n+1);
        seg.resize(n*4);
        save.resize(n+1);
        int x;
        for(int i=1; i<= n ;i++){
            cin >> vec[i];
            if(save[vec[i]].size()<2)
                save[vec[i]].push_back(i);
            else if(save[vec[i]].size()==2)
                save[vec[i]][1]= max(save[vec[i]][1], i);
        }
        init(1,1,n);
        bool flag=true;
        for(int i=1; i<=n;i++){
            if(save[i].size()<2)
                continue;
            int start= save[i][0];
            int end= save[i][1];
            // cout << i <<": "<< start<< ','<<end<<'\n';
            int v= find(1,1,n,start+1,end-1);
            // cout << "v: "<<v<<'\n';
            if (v>i){
                // cout << "false! \n";
                flag=false;
                break;
            }
        }
        if(flag)
            cout << "Yes\n";
        else    
            cout << "No\n";
        clear();
    }
    
}