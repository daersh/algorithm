#include <iostream>
using namespace std;

int main(){

    int T;
    cin >> T;
    for(int t=0;t<T;t++){

        int x,y;
        cin >> x >>y ;
        string a,b;
        cin >> a >>b;

        int tf=false;

        
        
        int cnt=0;
        while(cnt<=10){
            cnt++;
            a.append(a);

            for(int i=0;i<=a.size();i++){
                string c=a.substr(i,b.size());
                
                if(c==b){
                    cout << cnt<<'\n';
                    tf=true;
                    break;
                }
            }
            if(tf==true)break;
        }

        if(tf==false){
            cout << -1<<'\n';
        }
    }

}