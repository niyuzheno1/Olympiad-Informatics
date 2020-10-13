#include <iostream>
#include <vector>
using namespace std;

void findhours(vector<int> & va, int alpha){
	for(int i = 0; i < 26; ++i){
		int y = 2 * alpha +60*i;
		int z = int(i * 60*11) +int(y) ;
		if( z < 0 ||  z >= (24 * 60 * 11)){
			continue;
		}
		va.push_back(z);
	}
}

vector<int> ltime[4];
int toint(string y){
	int ret = 0;
	for(int i = 0; i < y.length(); ++ i){
		ret *= 10;
		ret += (y[i]-'0');
	}
	return ret;
}
int totime(string x){
	string hr = "", minu = ""; 
	int i;
	for( i = 0; i < x.length(); ++i){
		if(!(x[i] <= '9' && x[i] >= '0') )
			break;
		hr += x[i];
	}
	++i;
	for(; i < x.length(); ++i){
		if(!(x[i] <= '9' && x[i] >= '0') )
			break;
		minu += x[i];
	}
	return toint(hr) * 60 * 11 + toint(minu) * 11;
	
}
int smap[300];
int main() {
	smap[0] = 0;
	smap[90] = 1;
	smap[180] = 2;
	findhours(ltime[0],0);
	findhours(ltime[1],90);
	findhours(ltime[1],-90);
	findhours(ltime[2],180);
	int n ;
	cin >> n;
	for(int i = 0; i < n ; ++ i){
		string t1,t2;
		int alpha;
		cin>>t1>>t2>>alpha;
		int s1,s2;
		s1 = totime(t1);
		s2 = totime(t2);
		alpha = smap[alpha];
		int cnt = 0;
		for(int j = 0; j < ltime[alpha].size(); ++j ){
			if(ltime[alpha][j] <= s2 && ltime[alpha][j] >= s1)
				++cnt;
		}
		cout << cnt <<endl;
	}
	// your code goes here
	return 0;
}
