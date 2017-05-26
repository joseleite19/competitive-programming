#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	long long l, r;

	scanf("%lld %lld", &l, &r);

	long long diff = r - l;
	long long ans = 2;

	if(l == r){
		if(l & 1) ans = l;
	}

	printf("%lld\n", ans);

	return 0;
}