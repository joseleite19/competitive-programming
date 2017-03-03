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

long long MOD = 1000000009;
long long a = 1009;
long long w[200];

char s[1003][102];

long long h[200];
int ans[200];

int last[1004];
int n, l, m, p1, p2, w1, w2;

int main(){

	w[0] = 1;

	for(int i = 1; i < 200; i++)
		w[i] = (w[i-1] * a) % MOD;

	scanf("%d %d %d", &n, &l, &m);

	for(int i = 0; i < n; i++){
		scanf(" %s", s[i]);
		// printf("%s\n", s[i]);
		for(int j = 0; s[i][j]; j++){
			h[i] = (h[i] + s[i][j]*w[j]) % MOD;
		}
		ans[i] = 1;
	}


		map<long long, int> qwe;
	{
		// for(int j = 0; j < l; j++)
		// 	printf("%lld\n", h[j]);
		// printf("\n");

		for(int j = 0; j < n; j++)
			qwe[ h[j] ]++;
		for(int j = 0; j < n; j++)
			ans[j] = max(ans[j], qwe[ h[j] ]);
	}

	memset(last, -1, sizeof last);

	for(int q = 0; q < m; q++){
		scanf("%d %d %d %d", &p1, &w1, &p2, &w2); p1--, w1--, p2--, w2--;
		// printf("%c %c\n", s[p1][w1], s[p2][w2]);
		long long x = (s[p1][w1] * w[w1]) % MOD;
		long long y = (s[p2][w2] * w[w2]) % MOD;
		long long xx = (s[p1][w1] * w[w2]) % MOD;
		long long yy = (s[p2][w2] * w[w1]) % MOD;


		// lower_bound(mp(last[ p1 ], 0));
		// lower_bound(mp(last[ p2 ], 0));
		
		qwe[ h[p1] ]--;
		qwe[ h[p2] ]--;

		// mp(q, qwe[ h[p1] ]);
		// mp(q, qwe[ h[p2] ]);


		h[p1] = (h[p1] - x + yy + MOD) % MOD;
		h[p2] = (h[p2] + xx - y + MOD) % MOD;
		swap(s[p1][w1], s[p2][w2]);
		qwe[ h[p1] ]++;
		qwe[ h[p2] ]++;

		// mp(q, qwe[ h[p1] ]);
		// mp(q, qwe[ h[p2] ]);

	}

	for(int i = 0; i < n; i++)
		printf("%d\n", ans[i]);



	return 0;
}