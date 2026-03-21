#include<iostream>
#include<cstring>

using namespace std;

int main()
{

    int x[1001],a,b,i,j;
        int c = 0,sum=0;

        for (i = 1; i < 1000; i++)
        {
            for (j = 0; j < i&&c<1000; j++)
            {
                x[c] = i;
                c=c+1;
            }
        }

        cin >> a >> b;
        for (i = a-1; i <= b-1; i++)
        {
            sum += x[i];
        }
        cout << sum;
	return 0;
}