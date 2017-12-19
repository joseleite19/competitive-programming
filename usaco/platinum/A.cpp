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

const int N = 400005;

void file(){
	freopen("standingout.in", "r", stdin);
	freopen("standingout.out", "w", stdout);
}

char s[N];
int n, sa[N], tsa[N], lcp[N], r[N], nr[N], c[N];

void sort(int k, int mx){
    mx++;
    memset(c, 0, sizeof(int) * mx);
    forn(i, n) c[i + k < n ? r[i+k]+1 : 1]++;
    partial_sum(c, c+mx, c);
    int t;
    forn(i, n) t = sa[i]+k < n ? r[ sa[i]+k ] : 0,
               tsa[ c[t]++ ] = sa[i];
    memcpy(sa, tsa, sizeof(int) * n);
}

void build_sa(){

    forn(i, n) sa[i] = i, r[i] = s[i];

    int t = 300, a, b;
    for(int sz = 1; sz < n; sz *= 2){
        sort(sz, t), sort(0, t);
        t = nr[ sa[0] ] = 0;
        for(int i = 1; i < n; i++){
            a = sa[i]+sz < n ? r[ sa[i]+sz ] : -1;
            b = sa[i-1]+sz < n ? r[ sa[i-1]+sz ] : -1;
            nr[ sa[i] ] = r[ sa[i] ] == r[ sa[i-1] ] && a == b ? t : ++t;
        }
        if(t == n-1) break;
        memcpy(r, nr, sizeof(int) * n);
    }
}

void build_lcp(){ // lcp[i] = lcp(s[:i], s[:i+1])
    int k = 0;
    forn(i, n) r[ sa[i] ] = i;

    forn(i, n){
        if(r[i] == n-1) k = 0;
        else{
            int j = sa[r[i]+1];
            while(i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
        }
        lcp[r[i]] = k;
        if(k) k--;
    }
}

char str[N];
int owner[N];
ll ans[N];
int sz[N], asz[N];

int main(){
	file();

	int t;
	scanf("%d", &t);

	forn(i, t){
		scanf(" %s", str);
		sz[i] = strlen(str);
		for(int j = 0; j < sz[i]; j++)
			asz[n] = sz[i]-j, s[n] = str[j], owner[n++] = i;
		s[n] = 0, owner[n++] = t;
	}

	build_sa(), build_lcp();

	multiset<int> a, b;

	forn(i, n){
		if(!s[ sa[i] ]) continue;
		if(owner[sa[i-1]] != owner[sa[i]]){
			a.clear(), b.clear();
			a.insert(lcp[i-1]);
			for(int j = i; j < n && owner[sa[i]] == owner[sa[j]]; j++)
				b.insert(lcp[j]);
		}

		int mx = 0;
		if(!a.empty()) mx = max(mx, *a.begin());
		if(!b.empty()) mx = max(mx, *b.begin());
		if(owner[ sa[i-1] ] == owner[ sa[i] ]) mx = max(mx, lcp[i-1]);
		//if(owner[ sa[i] ] == owner[ sa[i+1] ]) mx = max(mx, lcp[i]);

		ans[ owner[ sa[i] ] ] += max(0, asz[ sa[i] ] - mx);
		/*for(int j = sa[i]; j < n; j++)
			printf("%c", s[j] ? s[j] : '_');
		printf(" - %d %d", mx, asz[ sa[i] ]);

		if(!a.empty()) printf(" (a = %d)", *a.begin());
		if(!b.empty()) printf(" (b = %d)", *b.begin());
		printf(". %d\n", lcp[i]);*/

		//printf("%d %d\n", i, lcp[sa[i]]);
		//printf("%d\n", *b.find(lcp[sa[i]]));
		b.erase(b.find(lcp[i]));
		//printf("%d\n", i);
		a.insert(lcp[i]);
	}


	forn(i, t) printf("%lld\n", ans[i]);


    return 0;
}
