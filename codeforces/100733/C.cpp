#include <bits/stdc++.h>

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	char s[20];

	long long num = 0, dem = 100;
	scanf("%s", s);

	bool fraction = false;
	for(int i = 0; s[i]; i++){
		if(fraction) dem *= 10;
		if(s[i] != '.') num = 10*num + s[i] - '0';
		else fraction = true;
	}

	printf("%lld\n", dem / gcd(num, dem));

	return 0;
}