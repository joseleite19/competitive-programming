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

const int N = 1000005;

void file(){
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
}

int n, f[N], s[N];

int main(){
	file();

	ll m;
	scanf("%d %lld", &n, &m);

	forn(i, n) scanf("%d %d", f+i, s+i);

	int ans = 1e9+7, R = 0;
	ll sum = 0;

	multiset<int> val;

	forn(i, n){
		while(R < n && sum < m){
			sum += f[R];
			val.insert(s[R]);
			R++;
		}
		if(sum < m) break;
		ans = min(ans, *prev(val.end()));

		sum -= f[i];
		val.erase(val.find(s[i]));
	}

	printf("%d\n", ans);

    return 0;
}
