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

int main(){
	int n, k, x;

	scanf("%d %d", &n, &k);

	map<int, int> m;

	forn(i, n) scanf("%d", &x), m[x]++;

	vector<int> v;
	for(pair<int, int> q : m) v.pb(q.ss);

	sort(v.begin(), v.end());

	int ans = 0;

	int l = int(v.size()) - k;

	forn(i, l) ans += v[i];

	printf("%d\n", ans);




    return 0;
}
