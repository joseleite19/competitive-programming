#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)
#define MOD 1000000007

using namespace std;

typedef long long ll;

const int N = 2005;

char st[N], en[N];
int n, k, tmp;

inline int add(int a, int b){
	return a + b >= MOD ? a + b - MOD : a + b;
}

int main(){
	
	scanf(" %s %s %d", st, en, &k);

	n = strlen(st);

	forn(i, n) st[n+i] = st[i], tmp += !strncmp(en, st+i, n);

	int ans = !strncmp(en, st, n), x = n - 1;
	while(k--) ans = add(tmp, MOD - ans), tmp = (1LL * tmp * x) % MOD;
	printf("%d\n", ans);

    return 0;
}
