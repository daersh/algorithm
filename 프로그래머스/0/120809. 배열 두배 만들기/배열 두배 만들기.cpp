#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    for(int i =0; i<numbers.size();i++){
        numbers[i]*=2;
    }
    
    return numbers;
}