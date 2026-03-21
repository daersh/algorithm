#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    int b[3] = {};
    int c[2] = {};
    int i;

    for (i = 0; i < 3; i++)
    {
        cin >> b[i];
    }
    for (i = 0; i < 2; i++)
    {
        cin >> c[i];
    }

    sort(b, b + 3);
    sort(c, c + 2);
    cout << c[0] + b[0] - 50;
    return 0;
}



