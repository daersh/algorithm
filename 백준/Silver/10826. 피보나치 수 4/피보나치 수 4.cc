#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string n1,n2,res,ans; // 수가 크기 때문에, 문자열로 입력받음
    if(n==0) {cout<< 0;return 0;}
    if(n==1)  {cout << 1; return 0;}

    n1=0+'0';
    n2=1+'0';

    for(int i=2;i<=n;i++){
        string v;
        int car=0;  // 올림수
        int onesize=n1.size();  // 첫번째 수의 자릿수
        int twosize=n2.size();  // 두번째 수의 자릿수
        // cout<< "start: ";
        while(onesize>0||twosize>0)
        {
            int nn1=0;  // 첫번째 수의 자릿수 중 하나(일의 자리부터 시작)
            if(onesize>0)
            {
            nn1=n1[--onesize]-'0';  // 문자 0 을 빼주면 함수를 쓰지 않고도 문자를 숫자로 바꾸기 가능
            }
            int nn2=0;
            if(twosize>0)
            {
            nn2=n2[--twosize]-'0';
            }
            int cur=nn1+nn2+car;  
            car=cur/10; // 올림수 변경
            cur%=10;
            char ccar=cur+'0';  // 문자로 변환
            v+=ccar;
        }
        if(car>0) // 올림수가 마지막까지 남아있다면
        {
            v+=car+'0';
        }
        n1=n2;
        reverse(v.begin(),v.end());
        n2=v;
        res=v;
        // cout << v<<'\n';
    }
    cout << res;
}