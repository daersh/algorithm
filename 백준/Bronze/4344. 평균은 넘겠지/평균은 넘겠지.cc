#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        int sum=0;
        vector<int> students;
        for(int i=0; i<m;i++){
            int x;
            cin >> x;
            sum+=x;
            students.push_back(x);
        }
        double avg = (double)sum/m;
        int cnt=0;
        for(int student : students){
            if((double)student>avg){
                cnt++;
            }
        }
        double student_avg = (double) cnt/m *100;
        cout.precision(3);
        cout << fixed<< student_avg <<"%\n";
    }
}