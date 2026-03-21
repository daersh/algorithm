#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    int b[5],avg=0;
    for (int i = 0; i < 5; i++)
        cin >> b[i];

    sort(b, b + 5);
    for (int i = 0; i < 5; i++)
    {
        avg += b[i];
    }
    cout << avg / 5 << '\n';
    cout << b[2];

    return 0;
}



