#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define oo 1000000

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int n;

int a[1000006];
int b[1000006];
int m2[1000006];
int m[1000006];

int vis[1000006];

int p[1000006];
int p2[1000006];

map<int, int> asdf;

int main(){


	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", m2+i);

	for(int i = 1; i <= n; i++){
		scanf("%d", a+i);
		asdf[ a[i] ] = i;
	}
	for(int i = 1; i <= n; i++){
		m[ i ] = m2[ a[i] ];
	}

	for(int i = 1; i <= n; i++){
		scanf("%d", b+i);
		p[ i ] = asdf[b[i]];
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++){
		if(i == p[i]) vis[i] = 1;
		if(vis[i]) continue;
		
		set<pair<int, pair<int, int> > > v;
		int ptr = i;

		int cnt = 0;
		while(1){
			if(vis[ptr]) break;
			vis[ptr] = 1;

			v.insert(mp(m[ptr] + m[ p[ptr] ], mp(ptr, p[ptr])));
			ptr = p[ ptr ];
		}
		// printf("\n");

		while(!v.empty()){
			pair<int, pair<int, int> > q = *v.begin(); v.erase(q);
			if(q.ss.ff == q.ss.ss) continue;
			// printf("%d %d %d %d\n", q.ff, q.ss.ff, q.ss.ss, p[q.ss.ss]);

			ans += q.ff;

			set<pair<int, pair<int, int> > >::iterator it = v.find(mp(m[ p[q.ss.ss] ] + m[ q.ss.ss ], mp(q.ss.ss, p[q.ss.ss])));
			if(it == v.end()) continue;
			pair<int, pair<int, int> > qq = *it;
			v.erase(it);

			p[q.ss.ff] = p[q.ss.ss];
			p[q.ss.ss] = q.ss.ss;

			qq.ss.ff = q.ss.ff;
			qq.ss.ss = p[q.ss.ff];
			// printf("->%d %d\n", qq.ss.ff, qq.ss.ss);
			qq.ff = m[ p[q.ss.ff] ] + m[ q.ss.ff ];

			v.insert(qq);
		}
	}

	printf("%lld\n", ans);

	return 0;
}