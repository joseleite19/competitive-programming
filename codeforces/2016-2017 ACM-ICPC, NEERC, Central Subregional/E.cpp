#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int n;
long long k;

long long sum;
long long v[100005];

int main(){
	// file();

	scanf("%d %lld", &n, &k);

	long long mx = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld", v+i);
		mx = max(mx, v[i]);
	}

	long long a = 0, b = 0;
	long long tmpa = 0, tmpb = 0;
	for(int i = 0; i < n; i++){
		if(v[i] == mx) break;
		a++;
		b += v[i];
	}


	for(int i = 0; i < n; i++){
		if(v[i] != mx) tmpa++;
		else tmpa += v[i];

		tmpb += v[i];
	}

	bool can = true;
	bool stop = false;
	if(a <= k && k <= b){
		can = true;
		stop = true;
	}
	else if(a > k){
		can = false;
		stop = true;
	}
	// a += tmpa;
	// b += tmpb;
	a += mx;
	b += mx;

	while(!stop){

		if(k < a+tmpa-mx){
			can = false;
			stop = true;
		}
		else if(k <= b+tmpb-mx){
			can = true;
			stop = true;
		}

		a += tmpa;
		b += tmpb;
	}

	printf("%s\n", can ? "YES" : "KEK");

	return 0;
}