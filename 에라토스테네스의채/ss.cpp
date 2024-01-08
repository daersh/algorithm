#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_professor= 25;
int max_subject=384;

int max_struct_code=6;
int max_floor=7;
int max_lecture_room=9;



int main(){
    
    for(int i=498; i<501; i++){
        string name, explain, plan, date;
        bool major, face_to_face;
        int credit,time,max_capacity,recommend_grade,semester,subject_id,professor_id, lecture_room_number;
        
        major = i%2;
        //학과 랜덤 선ㅌㄱ
        int department_code= rand()%10;
        if(department_code==0) department_code++;
        int subject= rand()%33;
        if(subject==0) subject++;
        credit= rand()%2+2;
        time=credit;
        face_to_face = rand()%2;
        max_capacity = rand()%200;
        semester= rand()%2+1;
        
        int x=0;
        string t[7]= {"MON","TUE","WED","THU","FRI","SAT","SUN"};
        date = t[rand()%7];
        date +="_";
        
        int tt=0;
        while ( tt<9 || tt>16){
            tt= rand()%17;
        }
        int vv = rand()%7;
        while (vv==0)
        {
            vv=rand()%7;
        }
        vv*=10;
        while(x<=vv|| x>vv+7)
        {
            x = (rand() % 68 );    
        }
        
        x *= 100;
        x += rand()%9+1;
        
        cout << "INSERT INTO LECTURE_TB VALUES ( "<< i << ',';
        cout << "(select name from subject_tb a join curriculum_tb b on a.curriculum_id=b.id where b.department_id=" <<department_code<< " limit "<<subject<< ",1),";
        cout << "(select a.explain from subject_tb a join curriculum_tb b on a.curriculum_id=b.id where b.department_id=" <<department_code<< " limit "<<subject<< ",1),";
        cout << major<<",";
        cout << "NULL,";
        cout << "'"<<date<<tt<<":00-"<<tt+time<<":00',";
        cout << credit<<",";
        cout << time<<",";
        cout << face_to_face <<",";
        cout << max_capacity<<',';
        cout << "(select grade from subject_tb a join curriculum_tb b on a.curriculum_id=b.id where b.department_id=" <<department_code<< " limit "<<subject<< ",1),";
        cout << semester<<',';
        cout << "(select a.id from subject_tb a join curriculum_tb b on a.curriculum_id=b.id where b.department_id=" <<department_code<< " limit "<<subject<< ",1),";
        cout << "(select a.id from professor_tb a join department_tb b on a.department_id=b.id where b.id=" <<department_code<< " limit "<< "0,1),";
        cout << x;
        cout <<");\n";
    }

}