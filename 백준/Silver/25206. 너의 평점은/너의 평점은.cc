#include <iostream>

using namespace std;


int main(){
    double score_sum=0;
    double lec_sum=0;
    for(int i=0;i<20;i++){
        string x;
        double y;
        string z;
        cin >> x >> y >>z;
        if(z=="P")
            continue;
        else if(z=="F"){
            lec_sum+=y;
        }else{
            // lec_sum+= y;
            if(z=="A+"){
                lec_sum+=y;
                score_sum+= (4.5)*y;
            }
            else if(z=="A0"){
                lec_sum+=y;
                score_sum+=(4.0)*y;
            }
            else if(z=="B+"){
                lec_sum+=y;
                score_sum+=(3.5)*y;
            }
            else if(z=="B0"){
                lec_sum+=y;
                score_sum+=(3.0)*y;
            }
            else if(z=="C+"){
                lec_sum+=y;
                score_sum+=(2.5)*y;
            }
            else if(z=="C0"){
                lec_sum+=y;
                score_sum+=(2.0)*y;
            }
            else if(z=="D+"){
                lec_sum+=y;
                score_sum+=(1.5)*y;
            }
            else if(z=="D0"){
                lec_sum+=y;
                score_sum+=(1.0)*y;
            }
        }
    }
    cout << score_sum/lec_sum<<'\n';

}