#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main()
{
    int t, i;
    char a[1000];
    cin >> t;

while(t--)    {

    cin >> a;
    string b(a);
    i = b.size();
    cout << b[0] << b[i - 1]<<'\n';
}
    

   
    return 0;

}

