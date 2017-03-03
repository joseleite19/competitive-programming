#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000

using namespace std;

int n, r;

pair<int, int> p[55];

bitset<55> b[55], t[55], tmp, tmp2;

int solve(){
	int ret = 0;

	for(int i = 0; i < n; i++)
		b[i].reset();

	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			if(abs(p[i].ff - p[j].ff) <= r && abs(p[i].ss - p[j].ss) <= r)
				b[i].set(j), b[j].set(i);

	for(int i = 0; i < n; i++){
		tmp = b[i];
		for(int j = 0; j < n; j++)
			if(b[i][j])
				tmp &= b[j];

		for(int k = 0; k < n; k++)
			t[k] = b[k] & (~tmp);

		int ans = 0;
		for(int k = 0; k < n; k++){
			tmp2 = t[k];
			for(int j = 0; j < n; j++)
				if(t[k][j])
					tmp2 &= t[j];
			ans = max(ans, (int)tmp2.count());
		}
		ret = max(ret, ans + (int)tmp.count());
	}
	return ret;
}

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &n, &r);

		for(int i = 0; i < n; i++)
			scanf("%d %d", &p[i].ff, &p[i].ss);

		printf("Case #%d: %d\n", tc, solve());
	}

	return 0;
}