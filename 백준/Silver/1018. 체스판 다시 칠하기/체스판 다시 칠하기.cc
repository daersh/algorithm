#include <iostream>

using namespace std;

char arr1[8][8]= {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'}
};
char arr2[8][8]= {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

int main() {
    int n,m;
    cin >> n >> m;

    char board[50][50];
    for(int i=0; i<n; i++) {
        string line;
        cin >> line;
        for(int j=0; j<m; j++) {
            board[i][j] = line[j];
        }
    }
    int result = 1e9;
    for(int i=0; i<n-7; i++) {
        for(int j=0; j<m-7; j++) {
            int count1 = 0;
            int count2 = 0;
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    if(board[i+x][j+y] != arr1[x][y]) {
                        count1++;
                    }
                    if(board[i+x][j+y] != arr2[x][y]) {
                        count2++;
                    }
                }
            }
            int temp = min(count1, count2);
            result = min(result, temp);
        }
    }
    cout << result << endl;


    return 0;
}