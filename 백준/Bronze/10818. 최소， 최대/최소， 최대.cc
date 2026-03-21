#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	
	int x, max = -1000000, min = 1000000,n;
	cin >> x;
	for (int i = 1; i <= x; i++)
	{
		cin >> n;
		if (n >= max) max = n;
	 if (n <= min) min = n;

		
	}
	cout << min << ' ' << max;
	return 0;
}