#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int a,sum=0, i,b[42] = { 0, };

	for (i = 0; i < 10; i++)
	{
		cin >> a;
		b[a % 42] = 1;

	}
	for (i = 0; i < 42; i++)
	{
		if (b[i])
			sum++;
	}
	cout << sum;
	return 0;
}