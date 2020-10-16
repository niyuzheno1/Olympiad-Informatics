#include <iostream>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

#define MAXN 100000
long long s[MAXN+10], t[MAXN + 10];

typedef pair<long long, long long> pii;

double compute(long long * x,  int n ){
	
	stack<pii> sp;
	for(int i = 0; i < n; ++i){
		pii it = make_pair(x[i], 1);
		while(!sp.empty()){
			pii tx = sp.top(); sp.pop();
			//ensure monotonicity tx.first/tx.second <= it.first/ it.second
			// tx.first  * it.second <= it.first * tx.second
			// not monotonically : tx.first  * it.second  > it.first * tx.second
			if(tx.first  * it.second > it.first * tx.second){
				it.first += tx.first;
				it.second += tx.second;
			}else{
				sp.push(tx);
				break;
			}
		}
		sp.push(it);
	}
	double ret = 0;
	int i = 0;
	//cout << " === "<<endl;
	while(!sp.empty()){
		pii tx = sp.top(); sp.pop();
		//cout << tx.first << " " << tx.second << endl;
		double avg = double(tx.first)/double(tx.second);
		for(int j = 0; j < tx.second; ++j){
			ret += (double(x[n-i-1]) - avg) * (double(x[n-i-1]) - avg);
			++i;
		}
	}
	return ret;
}

int main() {
	int n;
	cout << fixed << setprecision(20);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> s[i] >> t[i];
	}
	double x1 = compute(s, n);
	x1 += compute(t,n);
	cout << x1 << endl;
	// your code goes here
	return 0;
}
