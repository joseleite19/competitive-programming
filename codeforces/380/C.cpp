#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, k, s, t, c[200005], v[200005], g[200005];

long long sum[200005], dist[200005];

int main(){

	scanf("%d %d %d %d", &n, &k, &s, &t);

	for(int i = 0; i < n; i++)
		scanf("%d %d", c+i, v+i);

	for(int i = 0; i < k; i++)
		scanf("%d", g+i);

	sort(g, g+k);

	dist[0] = g[0];

	for(int i = 1; i < k; i++)
		dist[i] = g[i] - g[i-1];
	dist[k] = s - g[k-1];
	k++;

	sort(dist, dist+k);

	sum[0] = dist[0];
	for(int i = 1; i < k; i++)
		sum[i] = sum[i-1] + dist[i];

	for(int i = 0; i < k; i++)
		dist[i] *= 2;

	int ans = 2e9;

	for(int i = 0; i < n; i++){
		if(v[i] < dist[k-1]/2) continue;
		int tmp = t-s;
		bool can = false;
		if(tmp < 0) can = true;
		else{
			int id = upper_bound(dist, dist+k, v[i]) - dist;

			long long a = (long long)(k-id)*v[i] - (sum[k-1] - sum[id]);
			long long b = sum[k-1] - a;
			printf("asd %lld %lld %lld\n", 2*b + a, a, b);
			if(2*b + a >= s) can = true;
		}

		if(can) ans = min(ans, c[i]);
	}

	if(ans == 2e9) ans = -1;

	printf("%d\n", ans);



	return 0;
}