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

void file(){
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
}

vector<pair<int, int> > d[N];

map<int, int> cow;

char s[N];

int main(){
	file();

	int n, g;

	scanf("%d %d", &n, &g);

	map<int, int> val;

	forn(i, n){
		char c;
		int x, da, id;
		scanf(" %d %d %c%d", &da, &id, &c, &x);
		d[da].eb(id, (c == '-' ? -1 : 1)*x);
	}

	int ans = 0, mx = -1, amx = -1;

	val[0] = N+N;

	fore(k, 1, N){
		if(d[k].empty()) continue;
		int change = 0;
		map<int, int> before;
		int t = val[mx];;
		for(auto x : d[k]){
			val[ cow[x.ff] ]--;
			if(!before.count(x.ff)) before[x.ff] = cow[x.ff];
			cow[x.ff] += x.ss;
			val[ cow[x.ff] ]++;
		}
		while(prev(val.end())->ss == 0) val.erase(prev(val.end()));
		amx = mx;
		mx = prev(val.end())->ff;
		if(val[mx] != t) change = 1;

		for(auto x : d[k]){
			int a = before[x.ff] == amx;
			int b = cow[x.ff] == mx;
			//printf("%d %d - %d %d\n", k, x.ff, a, b);
			if(a != b) change = 1;
		}

		ans += change;
		//if(tmp != score) printf("$%d\n", k);
	}

	printf("%d\n", ans);

    return 0;
}
