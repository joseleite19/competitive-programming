#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int n;
long long v[100005];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);
	{
		long long tmp = 0;
		for(int i = 0; i < n; i++)
			tmp = gcd(tmp, v[i]);
		if(tmp > 1) return printf("YES\n0\n"), 0;
	}

	long long qnt = 0;

	for(int i = 0; i+1 < n; i++){
		while(v[i] & 1){
			long long a = v[i] - v[i+1], b = v[i] + v[i+1];
			v[i] = a, v[i+1] = b;
			qnt++;
		}
	}

	for(int i = n-1; i-1 >= 0; i--){
		while(v[i] & 1){
			long long a = v[i] - v[i+1], b = v[i] + v[i+1];
			v[i] = a, v[i+1] = b;
			qnt++;
		}
	}

	printf("YES\n");
	printf("%lld\n", qnt);



	return 0;
}