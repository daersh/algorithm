#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int min= arr[0];
	cout << 0 << ' ';
	int past =0;
	for(int i=1;i<n;i++){
		if(arr[i]-min> past)
			past= arr[i]-min;
		cout << past  <<' ';
		if(arr[i] < min )
			min = arr[i];
	}
	
	return 0;
}
