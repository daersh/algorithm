// 분할정복을 이용한 거듭제곱 
// 절반으로 식을 쪼개는 아이디어.
// O(logb)
// 재귀 함수를 통해 빠르게 구현 가능

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//재귀 사용
int fpow(int C, int n){
    if(n==1)
        return C;
    else{
        int x = fpow(C, n/2);
        if(n%2 ==0)
            return x*x;
        else    
            return x*x*C;
    }
}

