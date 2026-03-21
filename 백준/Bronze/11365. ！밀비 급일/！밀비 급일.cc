#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main()
{
    char a[500];
    int i, j;
    
    while (1)
    {
        cin.getline(a, 500, '\n');
        if (a[0] == 'E' && a[1] == 'N' && a[2] == 'D') break;
        
        string b(a);
        i = b.size();
        while (i--) cout << b[i];
        cout << '\n';
    }
    

   
    return 0;

}

