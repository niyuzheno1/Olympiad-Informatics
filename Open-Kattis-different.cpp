#include <iostream>
using namespace std;


int main() {
	int howmangargs = 0;
	while(true){
		unsigned long long ax = 0, bx = 0;
		howmangargs = scanf("%lld%lld",&ax,&bx);
		if(howmangargs < 2)
			break;
		printf("%lld\n", ax > bx? ax-bx : bx -ax);
	}
	// your code goes here
	return 0;
}
