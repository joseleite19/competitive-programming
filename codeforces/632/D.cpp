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

const int N = 1000006;

int n, m, v[N], cnt[N], c[N];

int main(){

	scanf("%d %d", &n, &m);

	forn(i, n){
		scanf("%d", v+i);
		if(v[i] < N) cnt[ v[i] ]++;
	}

	int k = 0, l = 1;
	fore(i, 1, m+1){
		for(int j = i; j <= m; j += i)
			c[j] += cnt[i];
	}
	fore(i, 1, m+1) if(k < c[i]) k = c[i], l = i;

	printf("%d %d\n", l, k);

	if(k) forn(i, n) if(l % v[i] == 0)
		printf("%d ", i+1);


    return 0;
}
