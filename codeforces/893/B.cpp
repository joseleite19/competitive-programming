#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

int test(int x){
	int c1 = 0, c0 = 0;
	for(int lg = 20; lg >= 0; lg--){
		if(x & (1 << lg)){
			c1++, c0 = 0;
		}
		else{
			
		}
	}
}

const int N = 100006;

int v[N];

int main(){

	for(int k = 1, x; (x = ((1 << k) -1) * (1 << (k-1))) < N; k++){
		v[x] = 1;
	}

	int x;

	scanf("%d", &x);

	int ans = 0;
	for(int i = 1; i*i <= x; i++) if(x % i == 0){
		if(v[i]) ans = max(ans, i);
		if(v[x/i]) ans = max(ans, x / i);
	}
	printf("%d\n", ans);

    return 0;
}
