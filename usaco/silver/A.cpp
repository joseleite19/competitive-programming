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

void file(){
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
}

int mn[N], sum[N], v[N];



int main(){
	file();

	int n;

	scanf("%d", &n);
	
	forn(i, n) scanf("%d", v+i);

	ford(i, n) mn[i] = min(mn[i+1], v[i]), sum[i] = sum[i+1] + v[i];

	vector<int> ans;
	pair<int, int> mx(0, 1);

	forn(i, n-2){
		pair<int, int> t = mp(sum[i+1] - mn[i+1], n - i - 1);;
		int g = __gcd(t.ff, t.ss);
		if(g) t.ff /= g, t.ss /= g;
		if(1LL * mx.ff * t.ss == 1LL * t.ff * mx.ss) ans.pb(i+1);
		else if(1LL * mx.ff * t.ss < 1LL * t.ff * mx.ss){
			ans.clear();
			mx = t;
			ans.pb(i+1);
		}
	}

	for(int k : ans) printf("%d\n", k);




    return 0;
}
