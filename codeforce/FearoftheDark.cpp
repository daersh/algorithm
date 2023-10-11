//https://codeforces.com/contest/1886/problem/B

#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    cout.precision(9); // 3자리로 설정

    for(int t=0;t<T;t++){
        double x1,x2,y1,y2, d1,d2;
        cin >> x1>>y1>>x2>>y2 >> d1 >> d2;
        

        //두 꼭짓점 사이 거리
        double a= (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
        //한 꼭짓점에서 목표 거리
        double b= (d1-x1)*(d1-x1) + (d2-y1)*(d2-y1);
        //다른 꼭짓점에서 목표 거리
        double c= (d1-x2)*(d1-x2) + (d2-y2)*(d2-y2);
        cout << "반지름: "<< sqrt(a)<<"\n";
        cout << "점1과의 거리" << sqrt(b)<< '\n';
        cout << "점2과의 거리" << sqrt(c)<< '\n';
        double result =0;
        //두 원 안에 있는지 확인
        if(a>=b || a>=c){  
            //두 꼭짓점 사이 점: 두점빼고/2
            double x_loc=(x2-x1)/2;
            double y_loc=(y2-y1)/2;
            if(b>c){
                cout << "b>c\n";
                //두번째 꼭짓점에서 목표가 가깝다
                result = x_loc*x_loc+y_loc*y_loc;
                result += (x_loc-d1)*(x_loc-d1) + (y_loc-d2)*(y_loc-d2);

            }else{
                cout << "b<=c\n";
                result= d1*d1 + d2*d2;
            }
            cout << result << '\n';
            result= sqrt(result);
            cout << result<<'\n';
            continue;

        }else{
            //두 원 안에 없는 경우 -> 접점 두개가될듯
            //

        }

        
    }

}