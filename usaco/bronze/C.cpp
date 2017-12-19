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

const int N = 2500;

void file(){
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
}

vector<pair<string, int> > d[N];

map<string, int> cow;

char s[N];

int main(){
	file();

	int n;

	scanf("%d", &n);

	set<string> score;

	set<string> all;

	forn(i, n){
		char c;
		int x, da;
		scanf(" %d %s %c%d", &da, s, &c, &x);
		d[da].eb(s, (c == '-' ? -1 : 1)*x);
		score.insert(s);
	}
	all = score;

	int ans = 0, mx = 0;

	fore(k, 1, 101){
		int change = 0;
		mx = -100000;
		for(auto x : d[k]) cow[x.ff] += x.ss;
		for(auto x : all) mx = max(mx, cow[x]);
		set<string> tmp;
		for(auto x : all) if(cow[x] == mx)
			tmp.insert(x);
		ans += score != tmp;
		score = tmp;
	}

	printf("%d\n", ans);

    return 0;
}
