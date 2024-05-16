#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> mapp;
    int size = nums.size()/2;
    while(!nums.empty()){
        int v = nums.back();
        nums.pop_back();
        if(mapp[v]== 0){
            answer++;
            mapp[v]++;
        }
    }
    if(size<answer)
        answer = size;
    return answer;
}