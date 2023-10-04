#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    pair<int,int> arr[N];

    int x,y;
    for(int i=0;i<N;i++){
        cin >> x >>y;
        arr[i]= make_pair(x,y);
    }
    int g=0;
    int sum=N*100;
    for(int i=0;i<N;i++){
        int x1= arr[i].first;
        int x2= x1+10;
        int y1= arr[i].second;
        int y2= y1+10;

        for(int j=i+1;j<N;j++){
            int xx1= arr[j].first;
            int xx2= xx1+10;
            int yy1= arr[j].second;
            int yy2= yy1+10;

            if(x1>xx1 && x1<xx2 && y1>yy1 && y1 < yy2){
                g+= (xx2-x1)*(yy2-y1);
            }else if(x1>xx1 && x1<xx2 &&y2>yy1 && y2 < yy2){
                g+= (xx2-x1)*(y2-yy1);
            }else if(x2>xx1 && x2<xx2 &&y1>yy1 && y1 < yy2){
                g+= (x2-xx1)*(yy2-y1);
            }else if(x2>xx1 && x2<xx2 &&y2>yy1 && y2 < yy2){
                g+=(x2-xx1)*(y2-yy1);
            }else if(x1== xx1 && y1==yy1){
                g+= 100;
            }
        }
    }
    
    cout << "g: " <<g << "  result= "<<sum-g;
}