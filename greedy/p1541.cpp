#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    string x;
    vector<long long> vec;
    cin >> x;


    for(int i=0; i< x.length(); i++){
        string y;
        int tf=1;

        if(x[i]=='-'){
            tf=-1;
        }
        if(i!=0) i++;

        while(true)
        {
            y+=x[i];
            if(y[0]=='0')y.erase(0);
            i++;
            if(x[i]=='-'||x[i]=='+'){
                i--;
                break;
            }
            if(i==x.length())break;
        }
        vec.push_back(tf*stoi(y));
        cout <<stoi(y)*tf<<'\n';
    }
    long long sum=0;
    sum=vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        sum+=vec[i];
                cout<<sum<<'\n';
        if(vec[i]<0){
            i++;
            while (vec[i]>=0 )
            {
                sum-=vec[i];
                i++;
                cout<<sum<<'\n';
                if(i==vec.size())break;
            }   
        }

    }
    cout << sum;
}