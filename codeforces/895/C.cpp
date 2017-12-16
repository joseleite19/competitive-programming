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

const int N = 100005;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int n, v[N], oc[20];

int m[N];

int main(){

	scanf("%d", &n);

	forn(i, n) scanf("%d", v+i);

	forn(i, n){
		forn(j, 19){
			int c = 0;
			while(v[i] % p[j] == 0) c ^= 1, v[i] /= p[j];
			if(c) m[i] |= (1 << j);
		}
	}

	int t = 0;
	forn(i, 19){
		int j = t;
		while(j < n && (m[j] & (1 << i)) == 0) j++;
		if(j == n) { continue; }
		swap(m[t], m[j]);

		forn(k, n) if(k != t && m[k] & (1 << i))
			m[k] ^= m[t];
		t++;
	}

	ll ans = 1;

	t = n - t;
	while(t--) ans = (ans * 2) % 1000000007;
	ans = (ans - 1 + 1000000007) % 1000000007;
	printf("%lld\n", ans);

    return 0;
}
