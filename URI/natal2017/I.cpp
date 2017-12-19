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

int vis[N], pass;
int x[N], y[N];

inline int cost(int i, int j){
	return __gcd(abs(x[i]-x[j]), abs(y[i]-y[j]))-1;
}

int main(){

	int t;

	scanf("%d", &t);

	while(t--){
		pass++;
		int n, k;
		scanf("%d %d", &n, &k);
		ll ans = 0;
		forn(i, n) scanf("%d %d", x+i, y+i);

		vis[0] = pass;
		priority_queue<pair<int, int> > q;
		forn(i, n) if(i != 0)
			q.emplace(-cost(i, 0), i);
		while(!q.empty()){
			int d, u;
			tie(d, u) = q.top(); d = -d; q.pop();
			if(vis[u] == pass) continue;
			vis[u] = pass;
			ans += d;
			forn(i, n) if(i != u && vis[i] != pass)
				q.emplace(-cost(i, u), i);
		}
		printf("%lld\n", ans * k);
	}



    return 0;
}
