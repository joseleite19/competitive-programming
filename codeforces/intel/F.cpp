#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m, k[100005], forb[100005], ans[100005];
vector<pair<int, int> > x[100005];

int f(int l, int r, vector<pair<int, int> > & xx){
	pair<int,int> cant[2];
	int len, rem, tmp;

	for(int i = l; i < r; i++) forb[i] = r;

	for(int gcd = 1; gcd <= 40; gcd++){ // all possible gcd's

		cant[0] = cant[1] = mp(-1, r); // pair<gcd, position>
		for(int i = r-1; i >= l; i--){
			len = k[ xx[i].ff ];
			rem = xx[i].ss;

			if(len % gcd != 0) continue; // if gcd is not a possible gcd for len
			tmp = rem % gcd;

			if(tmp != cant[0].ff){
				forb[i] = min(forb[i], cant[0].ss);
				cant[1] = cant[0];
			}
			else forb[i] = min(forb[i], cant[1].ss);
			cant[0] = mp(tmp, i);
		}
	}
	int ans = 0, limit = r;
	for(int i = r-1; i >= l; i--){
		limit = min(limit, forb[i]);
		// printf(".%d %d\n", forb[i], i);
		ans = max(ans, limit-i);
	}

	return ans;
}

int main(){
	int a, r;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", k+i);
		for(int j = 0; j < k[i]; j++){
			scanf("%d", &a);
			x[a].push_back(mp(i, j));
		}
	}

	for(int num = 1; num <= m; num++){
		int ans = 0;

		for(int l = 0; l < x[num].size();){
			r = l;
			while(r < x[num].size() && x[num][r].ff + 1 == x[num][r+1].ff) r++; // pega linhas consecutivas

			ans = max(ans, f(l, r+1, x[num]));

			l = r+1;
		}

		printf("%d\n", ans);
	}

	return 0;
}