#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)

using namespace std;

typedef long long ll;

const int N = 200005;

char s[N];
int n, sa[N], tsa[N], lcp[N], r[N], nr[N], c[N];

void sort(int k, int mx){
	mx++;
	memset(c, 0, sizeof(int)*mx);
	forn(i, n) c[i + k < n ? r[i+k]+1 : 1]++;
	partial_sum(c, c+mx, c);
	int t;
	forn(i, n) t = sa[i]+k < n ? r[ sa[i]+k ] : 0,
			   tsa[ c[t]++ ] = sa[i];
	memcpy(sa, tsa, sizeof(int)*n);
}

void build_sa(){
	forn(i, n) sa[i] = i, r[i] = s[i];

	int t = 300, a, b;

	for(int sz = 1; sz <= n; sz *= 2){
		sort(sz, t);
		sort(0, t);
		t = nr[ sa[0] ] = 0;
		fore(i, 1, n-1){
			a = sa[i]+sz < n ? r[ sa[i]+sz ] : -1;
			b = sa[i-1]+sz < n ? r[ sa[i-1]+sz ] : -1;
			nr[ sa[i] ] = (r[ sa[i] ] == r[ sa[i-1] ] && a == b) ? t : ++t;
		}
		if(t == n-1) break;
		memcpy(r, nr, sizeof(int)*n);
	}
}

void build_lcp(){
	int k = 0;
	forn(i, n) r[ sa[i] ] = i;

	forn(i, n){
		if(r[i] == n-1) k = 0;
		else{
			int j = sa[ r[i]+1 ];
			while(i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
		}
		lcp[ r[i] ] = k;
		if(k) k--;
	}
}

int L[N], R[N], ans[N];

int main(){
	
	int t;

	scanf("%d", &t);

	while(t--){
		scanf(" %s", s);
		n = strlen(s);

		build_sa(), build_lcp();

		stack<int> ss;
		forn(i, n-1){
			while(!ss.empty() && lcp[ ss.top() ] >= lcp[i]) ss.pop();
			if(ss.empty()) L[i] = 0;
			else L[i] = ss.top()+1;
			ss.push(i);
		}
		while(!ss.empty()) ss.pop();
		for(int i = n-2; i >= 0; i--){
			while(!ss.empty() && lcp[ ss.top() ] >= lcp[i]) ss.pop();
			if(ss.empty()) R[i] = n-2;
			else R[i] = ss.top()-1;
			ss.push(i);
		}
		while(!ss.empty()) ss.pop();
		memset(ans, 0, sizeof(int)*n);
		forn(i, n-1){
			ans[ R[i] - L[i]+2 ] += (R[i] - L[i]+2) * lcp[i];
			printf("%d %d %d %d\n", lcp[i], L[i], R[i], R[i] - L[i] - 1);
		}
		for(int i = n; i >= 0; i--) ans[i] += ans[i+1];
		int q;

		scanf("%d", &q);

		int x;
		while(q--){
			scanf("%d", &x);
			if(x > n) printf("0\n");
			else printf("%d\n", ans[x]);
		}
	}

}
