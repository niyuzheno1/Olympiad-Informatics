#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;

map<long long, int> vmp[100010];

long long encode(string & t){
	long long ret = 0;
	for(int i = 0; i < t.length(); ++i){
		ret *= (long long)27;
		ret += (long long)(t[i]-'a'+1);
		
	}
	return ret;
}

vector<long long> itlist ;

vector<int> pathstwo;
vector<int> pathsone;

int main() {
	string test = "z";
	int n, k, m;
	cin >> n>>k;
	for(int i = 0; i <k; ++i){
		int pos = 0;
		string input; 
		cin >> pos >> input;
		vmp[pos][encode(input)] =  1;
	}
	cin >> m;
	for(int i =0;i < m; ++i){
		string input; 
		cin >> input;
		long long en = encode(input);
		itlist.push_back(en);
	}
	int curpos = 0;
	for(int i =0;i < m; ++i){
		
		while(vmp[curpos][itlist[i]] == 0){
			curpos = curpos + 1;
			if(curpos >= n)
				break;
		}
		if(curpos >= n)
			break;
		pathsone.push_back(curpos);
	}
	curpos = n-1;
	if(pathsone.size() < m){
		cout << "impossible" <<endl;
		return 0;
	}
	for(int i =m-1;i >=0; --i){
		while(vmp[curpos][itlist[i]] == 0){
			curpos = curpos - 1;
			if(curpos < 0)
				break;
		}
		if(curpos < 0)
			break;
		pathstwo.push_back(curpos);
	}
	std::reverse(pathstwo.begin(),pathstwo.end());
	
	for(int i = 0; i < pathstwo.size(); ++i){
	
		if(pathstwo[i] != pathsone[i])
		{
			cout << "ambiguous"<<endl;
			return 0;
		}
	}
	
	cout << "unique"<<endl;
	
	// your code goes here
	return 0;
}
