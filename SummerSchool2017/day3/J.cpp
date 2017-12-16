#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long read(){
	long long ret = 0;
	scanf("%lld", &ret);
	ret *= 1000000000;
	char c;

	if((c = getchar()) == '.'){
		long long tmp = 0;
		int cnt = 0;
		while(1){
			c = getchar();
			if(c < '0' || c > '9') break;
			tmp = 10*tmp + (c - '0');
			cnt++;
		}
		for(; cnt < 9; cnt++)
			tmp *= 10;
		ret += tmp;
	}
	return ret;
}

int main(){
	// long long x = read();
	// long long y = read();

	double x, y;

	scanf("%lf %lf", &x, &y);

	printf("%.0lf\n", !x || !y ? 0 : x/y);

	return 0;
}