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

int ai[N], ap[N], bi[N], bp[N], t[N], n, m;

char s[N];

pair<int, int> oc[N];

pair<int, int> dp[N];

pair<int, int> cmp(pair<int, int> a, pair<int, int> b){
	if(a.ff != b.ff) return max(a, b);
	return min(a, b);
}

pair<int, int> operator+(pair<int, int> a, pair<int, int> b){
	return mp(a.ff + b.ff, a.ss+b.ss);
}

pair<int, int> f(int i){
	if(i == n) return mp(0, 0);
	if(~dp[i].ff) return dp[i];
	dp[i] = f(i+1);
	if(oc[i].ff){
		dp[i] = cmp(dp[i], f(i+m) + oc[i]);
	}
	return dp[i];
} 

int main(){

	scanf("%d %s %d", &n, s, &m);

	forn(i, n){
		if(i & 1){
			ai[i] = s[i] == 'a';
			bi[i] = s[i] == 'b';
		}
		else{
			ap[i] = s[i] == 'a';
			bp[i] = s[i] == 'b';
		}
		t[i] = s[i] == '?';
	}

	partial_sum(ai, ai+n, ai);
	partial_sum(ap, ap+n, ap);
	partial_sum(bi, bi+n, bi);
	partial_sum(bp, bp+n, bp);
	partial_sum(t, t+n, t);
	memset(dp, -1, sizeof dp);

	for(int i = m-1; i < n; i++){
		int j = i - (m-1); //[j, i];
		if(j & 1){
			if(bi[i] - (j ? bi[j-1] : 0) > 0) continue;
			if(ap[i] - (j ? ap[j-1] : 0) > 0) continue;
			oc[j] = mp(1, t[i] - (j ? t[j-1] : 0));
		}
		else{
			if(bp[i] - (j ? bp[j-1] : 0) > 0) continue;
			if(ai[i] - (j ? ai[j-1] : 0) > 0) continue;
			oc[j] = mp(1, t[i] - (j ? t[j-1] : 0));
		}
	}

	pair<int, int> ans = f(0);

	printf("%d\n", ans.ss);

    return 0;
}
