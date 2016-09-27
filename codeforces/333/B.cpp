#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;
int n, q, a[100005], d[100005], le[100005], ri[100005];

long long f(int l, int r){
	long long ans = 0;
	int x, y;
	for(int i = l; i <= r; i++){
		x = max(le[i], l-1);
		y = min(ri[i], r+1);
		ans += 1LL * d[i] * (i - x) * (y - i);
	}

	return ans;
}

int main(){

	scanf("%d %d", &n, &q);

	for(int i = 0; i < n; i++)
		scanf("%d", a+i);
	
	for(int i = 0; i < n-1; i++)
		d[i] = abs(a[i+1] - a[i]);

	stack< pair<int, int> > s;

	for(int i = 0; i < n-1; i++){
		while(!s.empty() && s.top().ff < d[i]) s.pop();

		le[i] = !s.empty() ? s.top().ss : -1;

		s.push(mp(d[i], i));
	}

	while(!s.empty()) s.pop();

	for(int i = n-2; i >= 0; i--){
		while(!s.empty() && s.top().ff <= d[i]) s.pop();
		
		ri[i] = !s.empty() ? s.top().ss : n;

		s.push(mp(d[i], i));
	}

	int l, r;
	for(int i = 0; i < q; i++){
		scanf("%d %d", &l, &r); l--; r--; r--;
		printf("%lld\n", f(l, r));
	}

	return 0;
}