#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000

using namespace std;

pair<long long, long long> dp[1 << 17];

pair<char, pair<long long, long long> > c[20];

pair<long long, long long> mini(pair<long long, long long> a, pair<long long, long long> b){
	long long ma, mb;
	ma = max(a.ff, a.ss);
	mb = max(b.ff, b.ss);
	if(ma < mb) return a;
	return b;
}

int n;
pair<long long, long long> f(int bit){
	if(bit == 0) return mp(0, 0);
	pair<long long, long long> &ret = dp[bit];
	if(ret.ff != -1) return ret;

	ret = mp(oo, oo);
	int R = 0, B = 0;
	for(int i = 0; i < n; i++){
		if((1 << i) & bit){
			if(c[i].ff == 'R') R++;
			else B++;
		}
	}

	for(int i = 0; i < n; i++){
		if((1 << i) & bit){
			int newb = bit - (1 << i);
			int r = 0, b = 0;
			if(c[i].ff == 'R'){
				r = R-1;
				b = B;
			}
			else{
				r = R;
				b = B-1;
			}

			pair<long long, long long> tmp = f(newb);
			printf("%d -> %d; %d %d; %d %d\n", bit, newb, r, b, R, B);
			printf("%lld %lld\n", tmp.ff, tmp.ss);
			tmp.ff += max(c[i].ss.ff - r, 0LL);
			tmp.ss += max(c[i].ss.ss - b, 0LL);
			printf("%lld %lld\n\n", tmp.ff, tmp.ss);
			ret = mini(ret, tmp);
		}
	}

	return ret;
}

int main(){
	memset(dp, -1, sizeof dp);

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf(" %c %lld %lld", &c[i].ff, &c[i].ss.ff, &c[i].ss.ss);

	for(int i = 0; i < n; i++)
		printf("%d; %c %lld %lld\n", i, c[i].ff, c[i].ss.ff, c[i].ss.ss);

	pair<long long, long long> ret = f((1 << n) - 1);

	printf("%lld %lld\n", ret.ff, ret.ss);

	printf("%lld\n", n+max(ret.ff, ret.ss));

	// printf("%lld\n", );

	return 0;
}