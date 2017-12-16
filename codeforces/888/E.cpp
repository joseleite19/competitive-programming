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
int n, m;
int v[N];

inline int add(int a, int b){
	return a + b >= m ? a + b - m : a + b;
}

int main(){

	scanf("%d %d", &n, &m);

	forn(i, n) scanf("%d", v+i), v[i] %= m;

	int lf = n / 2;
	int rg = n - lf;

	set<int> s;
	for(int bit = 0; bit < (1 << lf); bit++){
		int tmp = 0;
		forn(i, lf) if(bit & (1 << i)){
			tmp = add(tmp, v[i]);
		}
		s.insert(tmp);
	}

	int ans = 0;
	for(int bit = 0; bit < (1 << rg); bit++){
		int tmp = 0;
		fore(i, lf, n) if(bit & (1 << (i-lf))){
			tmp = add(tmp, v[i]);
		}
		auto x = s.lower_bound(m - tmp);
		if(x != s.end()) ans = max(ans, add(*x, tmp));
		if(x == s.begin()) continue;
		x--;
		ans = max(ans, add(*x, tmp));
	}

	printf("%d\n", ans);


    return 0;
}
