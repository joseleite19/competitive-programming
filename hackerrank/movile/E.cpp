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
	int n, k;

	scanf("%d %d", &n, &k);

	vector<tuple<int, int, int> > v;

	forn(i, k){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.eb(a, 1, c);
		v.eb(b+1, -1, c);
	}

	sort(v.begin(), v.end());

	ll sum = 0, ans = 0;

	for(auto x : v){
		int a, b, c;
		tie(a, c, b) = x;
		if(c == 1){
			sum += b;
			ans = max(ans, sum);
		}
		else sum -= b;
	}

	printf("%lld\n", ans);




    return 0;
}
