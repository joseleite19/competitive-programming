#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long n, q, u;
char s[100005];

long long up(long long u){
	long long x = u & -u;
	if(u == (n+1)/2) return u;

	if((2*x) & u) return u - x;
	return u + x;
}

long long lf(long long u){
	long long x = u & -u;
	x /= 2;

	return u - x;
}

long long rg(long long u){
	long long x = u & -u;
	x /=2;
	
	if(x == 0) return u;
	return u + x;
}

int main(){

	scanf("%lld %lld", &n, &q);

	while(q--){
		scanf("%lld %s", &u, s);

		for(int i = 0; s[i]; i++){
			if(s[i] == 'U') u = up(u);
			if(s[i] == 'L') u = lf(u);
			if(s[i] == 'R') u = rg(u);
		}

		printf("%lld\n", u);
	}

	return 0;
}