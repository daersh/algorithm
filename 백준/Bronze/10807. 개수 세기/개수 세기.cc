#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int n, v, x[201] = { }, a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v;
		x[v + 100]++;
	}

	cin >> a;
	cout << x[a + 100];
	return 0;
}