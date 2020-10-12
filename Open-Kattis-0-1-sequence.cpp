#include <iostream>
#include <string>
using namespace std;
#define MAXN 6
#define MODN (long long)1000000007

long long add (long long x, long long y){
	x = x + y;
	if (x >= MODN){
		x = x % MODN;
	}
	return x;
}
long long multiply(long long x, long long y){
	x = x*y;
	if (x >= MODN){
		x = x % MODN;
	}
	return x;
}

long long countinversionzeroone(string & tmp,long long tmp1, long long & combo){
	long long cnt = 0;
	long long cntzero = 0;
	for(int i = tmp.length()-1; i >= 0; --i){
		if(tmp[i] == '0'){
			++cntzero;
		}else{
			cnt += cntzero;
		}
	}
	long long twopower = 1;
	for(int i = 0; i < tmp1; ++i){
		combo = twopower;
		twopower = add(twopower,twopower);
	}
	return multiply(cnt,twopower);
}

long long countinversionquestionmark(long long cnt){
	if(cnt == 0)
		return 0;
	if(cnt == 1)
		return 0;
	if(cnt == 2)
		return 1;
	--cnt;
	long long ret = multiply(cnt, cnt + 1);
	long long comp = 1;
	for(long long i = 0; i < cnt - 2; ++ i)
		comp = add(comp,comp);
	ret = multiply(ret, comp);
	return ret;
}

long long countinversionzeroquestionmark(string & tmp,long long tmp1){
	long long cnt = 0;
	long long cntzero = 0;
	long long cntones =0;
	
	for(int i = tmp.length()-1; i >= 0; --i){
		if(tmp[i] == '0'){
			cntzero = cntzero + 1;
		}else if(tmp[i] == '?'){
			cnt = add(cnt,multiply(tmp1 ,cntzero));
		}
	}
	
	for(int i = 0; i < tmp.length(); ++i){
		if(tmp[i] == '1'){
			cntones = cntones + 1;
		}else if(tmp[i] == '?'){
			cnt = add(cnt, multiply(tmp1 ,cntones));
		}
	}
	
	return cnt; 
}

int main() {
	string inputs;
	cin >> inputs;
	string FilteredZeroOnes;
	long long questionmarklength = 0;
	for(int i = 0; i < inputs.length(); ++i){
		if(inputs[i] == '?'){
			++questionmarklength;
			continue;
		}
		FilteredZeroOnes += inputs[i];
	}
	long long counts = 0;
	long long logger = 0;
	counts = countinversionzeroone(FilteredZeroOnes,questionmarklength,logger);
	counts = add(counts,countinversionquestionmark(questionmarklength));
	counts =add(counts,countinversionzeroquestionmark(inputs,logger));
	cout << counts;
	
	// your code goes here
	return 0;
}
