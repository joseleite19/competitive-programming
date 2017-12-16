#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

long long a, b, c;

long long f(long long x){
	return (a * x + (x % b)) % c;
}


long long solve(){
	long long p1 = 1, p2 = 1;

	for(int i = 0; i < 20000000; i++){
		p1 = f(p1);
		p2 = f(f(p2));
		if(p1 == p2) break;
	}
	if(p1 != p2) return -1;

	long long tam = 1;

	p2 = f(p1);
	while(p1 != p2){
		p2 = f(p2);
		tam++;
	}

	p1 = 1, p2 = 1;

	for(int i = 0; i < tam; i++) p2 = f(p2);

	long long ret = 0;
	while(p1 != p2){
		p1 = f(p1);
		p2 = f(p2);
		ret++;
	}
	return ret + tam;
}

int main(){

	scanf("%lld %lld %lld", &a, &b, &c);

	printf("%lld\n", solve());




	return 0;
}