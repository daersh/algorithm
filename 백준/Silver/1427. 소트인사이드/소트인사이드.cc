#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool desc(int i, int j)
{
    return j < i;
}

int main()
{

    char a[11]={ };
    int n;
    cin.get(a,11);
    sort(a, a + strlen(a),desc);
    cout << a;
 
    
    return 0;
}



