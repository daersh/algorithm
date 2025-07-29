#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <utility>

using namespace std;

//{"BBBB", 5}, {"FFFF",4},
// {"FBBB",1},{"BFBB",1},{"BBFB",1},{"BBBF",1},
// {"BBFF",2},{"BFFB",2},{"FFBB",2},{"FBFB",2},{"BFBF",2}
// BBFF
// BFBF
// BFFB
// FFBB
// FBFB
// FBBF

map<string, int> yut = {
    {"BBBF", 1}, {"BBFB",1},{"BFBB",1}, {"FBBB",1},
    {"BBFF", 2}, {"BFFB", 2}, {"FFBB", 2}, {"FBBF", 2},{"BFBF", 2},{"FBFB", 2},
    {"BFFF", 3}, {"FBFF", 3}, {"FFBF", 3}, {"FFFB", 3},
    {"FFFF", 4}, 
    {"BBBB", 5}
};

map<char, pair<int,int>> mal = {
    {'A', {0, 0}}, 
    {'B', {0, 0}}, 
    {'C', {0, 0}}, 
    {'D', {0, 0}}, 
    {'a', {0, 0}},
    {'b', {0, 0}}, 
    {'c', {0, 0}}, 
    {'d', {0, 0}}
};

map<pair<int,int>, string> board = {
    {{0, 0}, ""}, 
    {{0, 1}, ""}, 
    {{0, 2}, ""}, 
    {{0, 3}, ""}, 
    {{0, 4}, ""}, 

    {{1, 0}, ""}, 
    {{1, 1}, ""}, 
    {{1, 2}, ""}, 
    {{1, 3}, ""}, 
    {{1, 4}, ""}, 

    {{2, 0}, ""}, 
    {{2, 1}, ""}, 
    {{2, 2}, ""}, 
    {{2, 3}, ""}, 
    {{2, 4}, ""}, 

    {{3, 0}, ""}, 
    {{3, 1}, ""}, 
    {{3, 2}, ""}, 
    {{3, 3}, ""}, 
    {{3, 4}, ""}, 
    {{3, 5}, ""}, 

    {{4, 0}, ""}, 
    {{4, 1}, ""}, 
    {{4, 2}, ""}, 
    {{4, 3}, ""}, 
    {{4, 4}, ""}, 
    {{4, 5}, ""}, 

    {{5, 0}, ""}, 
    {{5, 1}, ""}, 
    {{5, 2}, ""}, 
    {{5, 3}, ""}, 
    {{5, 4}, ""}, 
    {{5, 5}, ""}
};

map<pair<int,int>, pair<int,int> > turning_point ={
    {{0,5} , {5,0}},
    {{1,5} , {6,0}},
    {{5,3}, {6,3}},
    {{5,6}, {3,0}},
    {{4,5}, {0,0}}
};

map<char, bool> is_end = {
    {'A', false}, 
    {'B', false}, 
    {'C', false}, 
    {'D', false}, 
    {'a', false},
    {'b', false}, 
    {'c', false}, 
    {'d', false}
};
char q(string ma, string a);

// F: 앞면 5개 모두 F면 전진 
// B: 뒷면 
int main(){
    int n;
    cin >> n;

    char x;
    string y;

    for(int i=0; i<n;i++){

        cin >> x >> y;
        // cout << "Input: " << x << " " << y << endl;
        // 끝난놈은 패스 
        if(is_end[x]){
            is_end[x]=false;
            mal[x]={0,0};
        }

        int count = yut[y];
        // cout << "Count: " << count << endl;

        pair<int, int> current_loc = mal[x];
        string mals = board[current_loc];

        if(mals=="")
            mals = x;
        
        board[current_loc] = ""; 
        // cout << "Current Location: " << current_loc.first << " " << current_loc.second << endl;
        // 1. 이동 
        current_loc.second += count;
        // cout << "After Move: " << current_loc.first << " " << current_loc.second << endl;
    
        // 0번줄 전환
        if (current_loc.first < 3 && current_loc.second >= 5){
            if (current_loc.first==0&& current_loc.second ==5){
                current_loc.first = 4;
                current_loc.second = 0;
            }else if(current_loc.first == 1 && current_loc.second ==5){
                current_loc.first = 5;
                current_loc.second = 0;
            }else {
                current_loc.first ++;
                current_loc.second -= 5;
            }
            
        }else if(current_loc.first == 3 && current_loc.second >= 5){
            // 3번줄 전환 - 1 
            if (current_loc.second >5){
                current_loc = {-1, -1}; // 말이 사라짐
                for(int i=0; i<mals.size(); i++)
                    is_end[mals[i]] = true; 
            }

        }else if(current_loc.first == 4 && current_loc.second == 3){
            current_loc.first++;
            current_loc.second=3;
            
        }else if (current_loc.first == 4 && current_loc.second >= 6){
            current_loc.first = 3;
            current_loc.second -= 6;
        }else if (current_loc.first == 5 && current_loc.second >= 6){
            current_loc.first = 3;
            current_loc.second -=6;
            if (current_loc.second >0){
                current_loc = {-1, -1}; // 말이 사라짐
                for(int i=0; i<mals.size(); i++)
                    is_end[mals[i]] = true; 
            }else{
                current_loc.second=5;
            }
        }

        string new_mals = board[current_loc];
        if(new_mals == ""){
            new_mals += mals;
            for(int i=0; i<new_mals.size(); i++){
                char m = new_mals[i];
                mal[m] = current_loc; // 말 위치 업데이트
            }
        }else if((isupper(new_mals[0]) && isupper(x) ) || (islower(new_mals[0]) && islower(x)) ){
            
            new_mals += mals;
            for(int i=0; i<new_mals.size(); i++){
                char m = new_mals[i];
                mal[m] = current_loc; // 말 위치 업데이트
            }
        }else{
            for(int i=0; i<new_mals.size(); i++){
                char m = new_mals[i];
                mal[m]= {0, 0}; // 말 초기화
            }
            new_mals = mals;
            for(int i=0; i<new_mals.size(); i++){
                char m = new_mals[i];
                mal[m] = current_loc; // 말 위치 업데이트
            }
        }

        board[current_loc] = new_mals;

    }

    cout <<q(board[{5,0}],"a")<<q(board[{5,0}],"b") <<"----" <<q(board[{1,4}],"a")<<q(board[{1,4}],"b") <<"----"  <<q(board[{1,3}],"a")<<q(board[{1,3}],"b") <<"----"  <<q(board[{1,2}],"a")<<q(board[{1,2}],"b") <<"----"  <<q(board[{1,1}],"a")<<q(board[{1,1}],"b") <<"----" <<q(board[{4,0}],"a")<<q(board[{4,0}],"b")<<'\n';
    cout <<q(board[{5,0}],"c")<<q(board[{5,0}],"d") <<"    " <<q(board[{1,4}],"c")<<q(board[{1,4}],"d") <<"    "  <<q(board[{1,3}],"c")<<q(board[{1,3}],"d") <<"    "  <<q(board[{1,2}],"c")<<q(board[{1,2}],"d") <<"    "  <<q(board[{1,1}],"c")<<q(board[{1,1}],"d") <<"    " <<q(board[{4,0}],"c")<<q(board[{4,0}],"d")<<'\n';
    cout <<"| \\                          / |\n";
    cout <<"|  \\                        /  |\n";
    cout <<"|   \\                      /   |\n";
    cout <<"|    "<<q(board[{5,1}],"a")<<q(board[{5,1}],"b")<<"                  "<<q(board[{4,1}],"a")<<q(board[{4,1}],"b")<< "    |\n";
    cout <<""<<q(board[{2,1}],"a")<<q(board[{2,1}],"b")<<"   "<<q(board[{5,1}],"c")<<q(board[{5,1}],"d")<<"                  "<<q(board[{4,1}],"c")<<q(board[{4,1}],"d")<< "   "<<q(board[{0,4}],"a")<<q(board[{0,4}],"b")<<"\n";
    cout <<""<<q(board[{2,1}],"c")<<q(board[{2,1}],"d")<<"     \\                /     "<<q(board[{0,4}],"c")<<q(board[{0,4}],"d")<<"\n";
    cout <<"|       \\              /       |\n";
    cout <<"|        \\            /        |\n";
    cout <<"|         "<<q(board[{5,2}],"a")<<q(board[{5,2}],"b")<<"        "<<q(board[{4,2}],"a")<<q(board[{4,2}],"b")<< "         |\n";
    cout <<"|         "<<q(board[{5,2}],"c")<<q(board[{5,2}],"d")<<"        "<<q(board[{4,2}],"c")<<q(board[{4,2}],"d")<< "         |\n";
    cout <<""<<q(board[{2,2}],"a")<<q(board[{2,2}],"b")<<"          \\      /          "<<q(board[{0,3}],"a")<<q(board[{0,3}],"b")<<"\n";
    cout <<""<<q(board[{2,2}],"c")<<q(board[{2,2}],"d")<<"           \\    /           "<<q(board[{0,3}],"c")<<q(board[{0,3}],"d")<<"\n";
    cout <<"|             \\  /             |\n";
    cout <<"|              "<<q(board[{5,3}],"a")<<q(board[{5,3}],"b")<<"              |\n";
    cout <<"|              "<<q(board[{5,3}],"c")<<q(board[{5,3}],"d")<<"              |\n";
    cout <<"|             /  \\             |\n";
    cout <<""<<q(board[{2,3}],"a")<<q(board[{2,3}],"b")<<"           /    \\           "<<q(board[{0,2}],"a")<<q(board[{0,2}],"b")<<"\n";
    cout <<""<<q(board[{2,3}],"c")<<q(board[{2,3}],"d")<<"          /      \\          "<<q(board[{0,2}],"c")<<q(board[{0,2}],"d")<<"\n";
    cout <<"|         "<<q(board[{4,4}],"a")<<q(board[{4,4}],"b")<<"        "<<q(board[{5,4}],"a")<<q(board[{5,4}],"b")<<"         |\n";
    cout <<"|         "<<q(board[{4,4}],"c")<<q(board[{4,4}],"d")<<"        "<<q(board[{5,4}],"c")<<q(board[{5,4}],"d")<<"         |\n";
    cout <<"|        /            \\        |\n";
    cout <<"|       /              \\       |\n";
    cout <<""<<q(board[{2,4}],"a")<<q(board[{2,4}],"b")<<"     /                \\     "<<q(board[{0,1}],"a")<<q(board[{0,1}],"b")<<"\n";
    cout <<""<<q(board[{2,4}],"c")<<q(board[{2,4}],"d")<<"   "<<q(board[{4,5}],"a")<<q(board[{4,5}],"b")<<"                  "<<q(board[{5,5}],"a")<<q(board[{5,5}],"b")<<"   "<<q(board[{0,1}],"c")<<q(board[{0,1}],"d")<<"\n";
    cout <<"|    "<<q(board[{4,5}],"c")<<q(board[{4,5}],"d")<<"                  "<<q(board[{5,5}],"c")<<q(board[{5,5}],"d")<<"    |\n";
    cout <<"|   /                      \\   |\n";
    cout <<"|  /                        \\  |\n";
    cout <<"| /                          \\ |\n";
    cout <<q(board[{3,0}],"a")<<q(board[{3,0}],"b") <<"    " <<q(board[{3,1}],"a")<<q(board[{3,1}],"b") <<"    "  <<q(board[{3,2}],"a")<<q(board[{3,2}],"b") <<"    "  <<q(board[{3,3}],"a")<<q(board[{3,3}],"b") <<"    "  <<q(board[{3,4}],"a")<<q(board[{3,4}],"b") <<"    " <<q(board[{3,5}],"a")<<q(board[{3,5}],"b")<<'\n';
    cout <<q(board[{3,0}],"c")<<q(board[{3,0}],"d") <<"----" <<q(board[{3,1}],"c")<<q(board[{3,1}],"d") <<"----"  <<q(board[{3,2}],"c")<<q(board[{3,2}],"d") <<"----"  <<q(board[{3,3}],"c")<<q(board[{3,3}],"d") <<"----"  <<q(board[{3,4}],"c")<<q(board[{3,4}],"d") <<"----" <<q(board[{3,5}],"c")<<q(board[{3,5}],"d")<<'\n';

}

char q(string ma, string a){
    if (ma.find(a) != std::string::npos)
    {
        return a[0];
    } else if (!isupper(a[0])&& ma.find(toupper(a[0])) != std::string::npos) {
        return toupper(a[0]);
    } 
    return '.';
}
