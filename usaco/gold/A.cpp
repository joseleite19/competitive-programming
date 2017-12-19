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
	freopen("piepie.in", "r", stdin);
	freopen("piepie.out", "w", stdout);
}

int n, d, b[N], e[N];
int ans[N];

int main(){
	file();

	scanf("%d %d", &n, &d);

	forn(i, 2*n) scanf("%d %d", b+i, e+i);

	set<pair<int, int> > bs, es;

	forn(i, n) bs.emplace(e[i], i);
	forn(i, n) es.emplace(b[i+n], i+n);

	memset(ans, -1, sizeof ans);
	queue<int> q;
	forn(i, n) if(!e[i]){
		q.push(i);
		bs.erase(mp(e[i], i));
		ans[i] = 1;
	}

	forn(i, n) if(!b[i+n]){
		q.push(n+i);
		es.erase(mp(b[i+n], i+n));
		ans[n+i] = 1;
	}

	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u < n){
			set<pair<int, int> >::iterator it = es.lower_bound(mp(b[u]-d, 0));
			while(it != es.end()){
				if(it->ff > b[u]) break;
				if(ans[it->ss] == -1) ans[it->ss] = ans[u]+1, q.push(it->ss);
				it = es.erase(it);
			}
		
		}
		else{
			set<pair<int, int> >::iterator it = bs.lower_bound(mp(e[u]-d, 0));
			while(it != bs.end()){
				if(it->ff > e[u]) break;
				if(ans[it->ss] == -1) ans[it->ss] = ans[u]+1, q.push(it->ss);
				it = bs.erase(it);
			}
		}
	}

	forn(i, n) printf("%d\n", ans[i]);

    return 0;
}
