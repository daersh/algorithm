#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int x_new[4]= {1,-1,0,0};
int y_new[4]= {0,0,1,-1};

int main(){
    int t;
    cin >> t;

    while(t!=0){
        int h,w;
        cin >> h >> w; // 높이, 너비
        char arr[h][w];
        queue<pii> q;

        //insert
        for(int i=0;i<h;i++){
            string x;
            cin >> x;
            for(int j=0;j<w;j++){
                x[j]=arr[i][j];
            }
        }
        
        for(int j=0; j<w;j++){
            if(arr[0][j]=='.') q.push(make_pair(0,j));
        }
        for(int j=0; j<w;j++){
            if(arr[h-1][j]=='.') q.push(make_pair(0,j));
        }
        for(int j=1; j<h;j++){
            if(arr[j][0]=='.') q.push(make_pair(0,j));
        }
        for(int j=1; j<h;j++){
            if(arr[j][w-1]=='.') q.push(make_pair(0,j));
        }
        
                
        set<char> key;
        string key_insert;
        //키 삽입 
        for(int i=0; i< key_insert.length();i++){
            key.insert(key_insert[i]);
        }

        while (q.empty())
        {
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            if(arr[x][y]=='!') continue;
            arr[x][y]='!';
            queue<pii> find_next;
            find_next.push(make_pair(x,y));
            while (!find_next.empty())
            {
                int x= find_next.front().first;
                int y= find_next.front().second;
                for(int i=0;i<4;i++){
                    int x_next= x+x_new[i];
                    int y_next= x+y_new[i];
                    if(x_next>=0 && x_next<h && y_next>=0 && y_next<w){
                        if(arr[x_next][x_next]!='!'&&arr[x_next][x_next]!='*'){
                            if(arr[x_next][x_next]=='.'){
                                find_next.push(make_pair(x_next,y_next));
                            }else{
                                if(key.find(arr[x_next][y_next]) ==true) {

                                }
                            }
                        }
                    }
                    
                }
            }
            
        }
        
        


        t--;
    }

}