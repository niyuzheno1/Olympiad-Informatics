#include <iostream>
using namespace std;

int sum[50];

int main() {
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			++sum[i+j];
		}
	int cursum = 0;
	for(int i = 1;i <= n +m ;++i){
		if(sum[i] > cursum){
			cursum = sum[i];
		}
	}
	for(int i = 1;i <= n +m ;++i){
		if(sum[i] == cursum){
			cout << i <<endl;
		}
	}
	// your code goes here
	return 0;
}
