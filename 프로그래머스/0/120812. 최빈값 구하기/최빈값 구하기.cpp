#include <string>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
int arr[1010];
bool isMax=false;
int cnt;
int solution(vector<int> array) {
    int answer = 0;
    for(int i =0; i < array.size();i++){
        int x= array[i];
        arr[x]++;
        if(arr[x]>cnt){
            cnt=arr[x];
            answer=x;
            isMax=false;
        }
        else if(arr[x]==cnt){
            isMax=true;
        }
    }
    
    if(isMax)
        return -1;
    return answer;
}