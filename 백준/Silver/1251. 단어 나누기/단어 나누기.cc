#include<iostream>
#include<cstring>
using namespace std;

string reverse(string x,int start, int end){
    string y;
    
    for(int i=start;i<=end;i++){
        y+= x[end-i+start];
    }
    
    // cout << "start: "<<start <<"  end: "<<end <<" y: "<<y<<'\n';
    return y;
}

int main(){
    string x;
    cin >> x;

    string result;
    for(int i=0; i< x.length(); i++){
        result+='z';
    }

    for(int i=0; i< x.length()-2 ;i++){

        for(int j=i+1;j<x.length()-1;j++){
            
            string cmp;
            cmp = reverse(x,0,i);
            cmp += reverse(x,i+1,j);
            cmp += reverse(x,j+1,x.length()-1);
            // cout << cmp <<'\n';
            if(result>cmp ) result=cmp;
        
        }
    }

     cout << result;
}
