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
	int n, m, t;
	char cc;

	int dx = 0, dy = 0;
	int c = 0, d = 0, b = 0, e = 0;

	scanf("%d %d %d", &n, &m, &t);

	while(t--){
		scanf(" %c", &cc);
		if(cc == 'C') dx++;
		if(cc == 'D') dy++;
		if(cc == 'B') dx--;
		if(cc == 'E') dy--;
		if(dx >= 0) c = max(c, dx);
		else b = max(b, -dx);
		if(dy >= 0) d = max(d, dy);
		else e = max(e, -dy);
	}

	vector<pair<int, int> > ans;
	fore(i, 1, n+1) fore(j, 1, m+1){
		if(i + c > n) continue;
		if(i - b < 1) continue;
		if(j + d > m) continue;
		if(j - e < 1) continue;
		ans.eb(i+dx, j+dy);
	}

	printf("%d\n", int(ans.size()));
	for(auto x : ans)
		printf("%d %d\n", x.ff, x.ss);

    return 0;
}
