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

int n;
ll v[N];

int main(){
	
	scanf("%d", &n);

	forn(i, n) scanf("%lld", v+i);

	int inv = 0;

	{
		ll a = 0, b = 0;
		forn(i, n) if(v[i] > 0) a = max(a, v[i]);
				   else if(v[i] < 0) b = max(b,-v[i]);
		if(b > a){
			inv = 1;
			reverse(v, v+n);
			forn(i, n) v[i] = -v[i];
		}
	}
	vector<pair<int, int> > ans;

	int id = 0;

	forn(i, n) if(v[i] >= v[id]) id = i;

	if(id != n-1){
		while(v[id] > v[n-1]){
			v[n-1] += v[id];
			ans.eb(id, n-1);
		}
	}

	for(int i = 1; i < n; i++){
		if(v[i-1] <= v[i]) continue;
		while(v[i-1] > v[i]+v[n-1]){
			v[n-1] += v[n-1];
			ans.eb(n-1, n-1);
		}
		if(v[i-1] > v[i]) v[i] += v[n-1], ans.eb(n-1, i);
	}

	printf("%d\n", int(ans.size()));

	if(inv){
		for(pair<int, int> &o : ans){
			o.ff = n-1-o.ff, o.ss = n-1-o.ss;
		}
	}

	for(pair<int, int> o : ans)
		printf("%d %d\n", o.ff+1, o.ss+1);

    return 0;
}
