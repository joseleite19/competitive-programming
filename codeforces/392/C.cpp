#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000

using namespace std;

int n, m, x, y;
long long cnt[200][200], k;


int main(){

	scanf("%d %d %lld %d %d", &n, &m, &k, &x, &y); x--; y--;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(k > 0){
				cnt[i][j]++;
				k--;
			}

	if(k){
		if(n == 1){
			long long tmp = k / m;
			for(int j = 0; j < m; j++)
				cnt[0][j] += tmp;
			tmp = k % m;
			for(int j = 0; j < m; j++){
				if(tmp > 0){
					tmp--;
					cnt[0][j]++;
				}
			}

		}
		else{
			long long tmp = k / ((n-1)*m);
			for(int i = 1; i < n-1; i++)
				for(int j = 0; j < m; j++)
					cnt[i][j] += tmp;

			for(int j = 0; j < m; j++)
				cnt[0][j] += (tmp+1)/2;
			for(int j = 0; j < m; j++)
				cnt[n-1][j] += tmp/2;

			if(tmp & 1){
				tmp = k % ((n-1)*m);
				for(int i = 1; i < n; i++)
					for(int j = 0; j < m; j++)
						if(tmp > 0){
							tmp--;
							cnt[i][j]++;
						}
			}
			else{
				tmp = k % ((n-1)*m);
				for(int i = n-2; i >= 0; i--)
					for(int j = 0; j < m; j++)
						if(tmp > 0){
							tmp--;
							cnt[i][j]++;
						}
			}
		}
	}

	long long mx = cnt[0][0], mn = cnt[0][0];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mx = max(mx, cnt[i][j]), mn = min(mn, cnt[i][j]);

	printf("%lld %lld %lld\n", mx, mn, cnt[x][y]);


	return 0;
}